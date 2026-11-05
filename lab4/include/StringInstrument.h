#ifndef STRING_INSTRUMENT_H
#define STRING_INSTRUMENT_H

#include "MusicalInstrument.h"
#include <vector>

/**
 * @brief Промежуточный класс струнных музыкальных инструментов.
 *
 * Хранит общие параметры струнных инструментов: количество струн,
 * натяжение и значения натяжения отдельных струн. Класс сам по себе
 * не задаёт способ извлечения звука — это делают конкретные наследники.
 */
class StringInstrument : public MusicalInstrument {
protected:
    int strings_;                        ///< Количество струн.
    double tension_;                     ///< Условное общее натяжение струн.
    std::vector<double> stringTensions_; ///< Натяжение каждой струны.

public:
    /**
     * @brief Создаёт струнный инструмент.
     * @param name Название инструмента.
     * @param strings Количество струн.
     * @param tension Значение натяжения, задаваемое для каждой струны.
     * @throw std::invalid_argument Если количество струн или натяжение не положительные.
     */
    StringInstrument(const std::string& name, int strings, double tension);

    /**
     * @brief Создаёт копию струнного инструмента.
     * @param other Копируемый объект.
     */
    StringInstrument(const StringInstrument& other);

    /**
     * @brief Копирует параметры другого струнного инструмента.
     * @param other Объект-источник.
     * @return Ссылка на текущий объект.
     */
    StringInstrument& operator=(const StringInstrument& other);

    /// Виртуальный деструктор; освобождение vector выполняется автоматически.
    ~StringInstrument() override = default;

    /**
     * @brief Выводит сообщение о настройке струн.
     *
     * Метод переопределяет стандартную настройку базового класса.
     */
    void tune() override;
};

#endif
