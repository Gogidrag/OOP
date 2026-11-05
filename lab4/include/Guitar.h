#ifndef GUITAR_H
#define GUITAR_H

#include "StringInstrument.h"

/**
 * @brief Класс гитары.
 *
 * Гитара является конкретным струнным инструментом. Она наследует
 * параметры струн от StringInstrument и реализует воспроизведение звука.
 */
class Guitar : public StringInstrument {
public:
    /**
     * @brief Создаёт гитару.
     * @param name Название или модель гитары.
     * @param strings Количество струн.
     * @param tension Натяжение струн.
     */
    Guitar(const std::string& name, int strings, double tension);

    /**
     * @brief Создаёт копию гитары.
     * @param other Копируемая гитара.
     */
    Guitar(const Guitar& other);

    /**
     * @brief Присваивает параметры другой гитары.
     * @param other Гитара-источник.
     * @return Ссылка на текущую гитару.
     */
    Guitar& operator=(const Guitar& other);

    /**
     * @brief Имитирует воспроизведение звука гитары.
     *
     * Метод выводит сообщение и регистрирует воспроизведение
     * в общей статистике базового класса.
     */
    void play() override;

    /**
     * @brief Возвращает тип инструмента.
     * @return Строка "Guitar".
     */
    std::string getType() const override;
};

#endif
