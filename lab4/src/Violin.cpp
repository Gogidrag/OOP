#include "Violin.h"

#include <iostream>

/**
 * @brief Создаёт скрипку и инициализирует параметры струн.
 */
Violin::Violin(const std::string& name, int strings, double tension)
    : StringInstrument(name, strings, tension) {}

/**
 * @brief Создаёт копию скрипки.
 */
Violin::Violin(const Violin& other)
    : StringInstrument(other) {}

/**
 * @brief Копирует параметры другой скрипки.
 */
Violin& Violin::operator=(const Violin& other) {
    if (this != &other) {
        StringInstrument::operator=(other);
    }
    return *this;
}

/**
 * @brief Выводит сообщение о воспроизведении скрипки.
 */
void Violin::play() {
    std::cout << "Скрипка " << getName() << ": играет мелодию\n";
    registerPlay(getType());
}

/**
 * @brief Возвращает строковое обозначение типа скрипки.
 */
std::string Violin::getType() const {
    return "Violin";
}
