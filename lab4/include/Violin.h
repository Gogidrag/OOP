#ifndef VIOLIN_H
#define VIOLIN_H

#include "StringInstrument.h"

/**
 * @brief Класс скрипки.
 *
 * Скрипка относится к струнным инструментам, поэтому получает
 * общие параметры и операции от класса StringInstrument.
 */
class Violin : public StringInstrument {
public:
    /**
     * @brief Создаёт скрипку.
     * @param name Название или модель скрипки.
     * @param strings Количество струн.
     * @param tension Натяжение струн.
     */
    Violin(const std::string& name, int strings, double tension);

    /**
     * @brief Создаёт копию скрипки.
     * @param other Копируемая скрипка.
     */
    Violin(const Violin& other);

    /**
     * @brief Присваивает параметры другой скрипки.
     * @param other Скрипка-источник.
     * @return Ссылка на текущий объект.
     */
    Violin& operator=(const Violin& other);

    /**
     * @brief Имитирует воспроизведение звука скрипки.
     *
     * После вывода сообщения увеличивает статистику воспроизведений.
     */
    void play() override;

    /**
     * @brief Возвращает тип инструмента.
     * @return Строка "Violin".
     */
    std::string getType() const override;
};

#endif
