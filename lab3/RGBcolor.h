#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#include <iostream>

/**
 * @brief Класс цвета в модели RGB
 * 
 * Хранит три канала: red, green, blue (0-255).
 * Поддерживает перегрузку операторов:
 * - унарные ++, --
 * - арифметические +=, -=, *=, /=
 * - бинарные +, -, *, /
 * - сравнение <, >, <=, >=, ==, !=
 * 
 * @details
 * Класс обеспечивает корректность каналов (0-255),
 * использует explicit для запрета неявного преобразования,
 * mutable для счётчика обращений.
 * 
 * @author Минаев Дмитрий, 606-42
 * @date 2026
 * @version 1.0
 */
class RGBColor {
private:
    int red;                ///< Красный канал (0-255)
    int green;              ///< Зелёный канал (0-255)
    int blue;               ///< Синий канал (0-255)
    
    mutable int viewCount;  ///< Счётчик обращений (mutable — можно менять в const)
    
    static int colorCount;  ///< Статический счётчик созданных цветов

public:
    //  КОНСТРУКТОРЫ

    /**
     * @brief Конструктор по умолчанию
     * 
     * Создаёт чёрный цвет (0, 0, 0).
     */
    RGBColor();

    /**
     * @brief Параметризованный конструктор
     * 
     * @param r Красный канал (0-255)
     * @param g Зелёный канал (0-255)
     * @param b Синий канал (0-255)
     * 
     * @note Значения вне диапазона 0-255 обрезаются
     */
    RGBColor(int r, int g, int b);

    /**
     * @brief Explicit-конструктор (серый цвет)
     * 
     * @param brightness Яркость (0-255)
     * 
     * @note explicit запрещает неявное преобразование int → RGBColor
     */
    explicit RGBColor(int brightness);

    /**
     * @brief Конструктор копирования
     * 
     * @param other Копируемый объект
     */
    RGBColor(const RGBColor& other);

    // ДЕСТРУКТОР

    /**
     * @brief Деструктор
     * 
     * Уменьшает статический счётчик и выводит сообщение.
     */
    ~RGBColor();

    // ГЕТТЕРЫ 

    /**
     * @brief Получить красный канал
     * @return Значение 0-255
     */
    int getRed() const;

    /**
     * @brief Получить зелёный канал
     * @return Значение 0-255
     */
    int getGreen() const;

    /**
     * @brief Получить синий канал
     * @return Значение 0-255
     */
    int getBlue() const;

    /**
     * @brief Получить яркость (сумма каналов)
     * @return red + green + blue
     */
    int getBrightness() const;

    /**
     * @brief Получить количество созданных цветов
     * @return Значение статического счётчика
     */
    static int getColorCount();

    // УНАРНЫЕ ОПЕРАЦИИ 
    /**
     * @brief Префиксный инкремент ++c
     * @return Ссылка на изменённый объект
     * 
     * Увеличивает каждый канал на 1 (до 255).
     */
    RGBColor& operator++();

    /**
     * @brief Постфиксный инкремент c++
     * @param int Маркер постфиксной формы
     * @return Копия объекта ДО изменения
     */
    RGBColor operator++(int);

    /**
     * @brief Префиксный декремент --c
     * @return Ссылка на изменённый объект
     * 
     * Уменьшает каждый канал на 1 (до 0).
     */
    RGBColor& operator--();

    /**
     * @brief Постфиксный декремент c--
     * @param int Маркер постфиксной формы
     * @return Копия объекта ДО изменения
     */
    RGBColor operator--(int);

    //  АРИФМЕТИЧЕСКОЕ ПРИСВАИВАНИЕ 

    /**
     * @brief Сложение с присваиванием
     * @param other Другой цвет
     * @return Ссылка на изменённый объект
     */
    RGBColor& operator+=(const RGBColor& other);

    /**
     * @brief Вычитание с присваиванием
     * @param other Другой цвет
     * @return Ссылка на изменённый объект
     */
    RGBColor& operator-=(const RGBColor& other);

    /**
     * @brief Умножение на число
     * @param factor Множитель
     * @return Ссылка на изменённый объект
     */
    RGBColor& operator*=(int factor);

    /**
     * @brief Деление на число
     * @param factor Делитель (не 0)
     * @return Ссылка на изменённый объект
     */
    RGBColor& operator/=(int factor);

    //  БИНАРНЫЕ ОПЕРАЦИИ 

    /**
     * @brief Сложение (через +=)
     * @param lhs Левый операнд (копия)
     * @param rhs Правый операнд
     * @return Новый цвет
     */
    friend RGBColor operator+(RGBColor lhs, const RGBColor& rhs);

    /**
     * @brief Вычитание (через -=)
     * @param lhs Левый операнд (копия)
     * @param rhs Правый операнд
     * @return Новый цвет
     */
    friend RGBColor operator-(RGBColor lhs, const RGBColor& rhs);

    /**
     * @brief Умножение (через *=)
     * @param lhs Левый операнд (копия)
     * @param factor Множитель
     * @return Новый цвет
     */
    friend RGBColor operator*(RGBColor lhs, int factor);

    /**
     * @brief Деление (через /=)
     * @param lhs Левый операнд (копия)
     * @param factor Делитель
     * @return Новый цвет
     */
    friend RGBColor operator/(RGBColor lhs, int factor);

    //  СРАВНЕНИЕ 

    /**
     * @brief Меньше (по яркости)
     * @param other Другой цвет
     * @return true если яркость меньше
     */
    bool operator<(const RGBColor& other) const;

    /**
     * @brief Больше (по яркости)
     */
    bool operator>(const RGBColor& other) const;

    /**
     * @brief Меньше или равно (по яркости)
     */
    bool operator<=(const RGBColor& other) const;

    /**
     * @brief Больше или равно (по яркости)
     */
    bool operator>=(const RGBColor& other) const;

    /**
     * @brief Равенство (по всем каналам)
     */
    bool operator==(const RGBColor& other) const;

    /**
     * @brief Неравенство
     */
    bool operator!=(const RGBColor& other) const;

    // ВЫВОД И ПРОВЕРКА

    /**
     * @brief Вывести информацию о цвете
     * 
     * @note Метод const, но увеличивает mutable viewCount
     */
    void printInfo() const;

    /**
     * @brief Проверить корректность (каналы 0-255)
     * @return true если корректно
     */
    bool isValid() const;
};

#endif