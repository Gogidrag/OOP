#include "Guitar.h"

#include <iostream>

/**
 * @brief Создаёт гитару и передаёт параметры струн базовому классу.
 */
Guitar::Guitar(const std::string& name, int strings, double tension)
    : StringInstrument(name, strings, tension) {}

/**
 * @brief Создаёт копию гитары.
 */
Guitar::Guitar(const Guitar& other)
    : StringInstrument(other) {}

/**
 * @brief Копирует параметры другой гитары.
 */
Guitar& Guitar::operator=(const Guitar& other) {
    // Сначала проверяем, что не присваиваем объект самому себе.
    if (this != &other) {
        StringInstrument::operator=(other);
    }
    return *this;
}

/**
 * @brief Выводит сообщение о воспроизведении гитары.
 */
void Guitar::play() {
    std::cout << "Гитара " << getName() << ": играет мелодию\n";

    // Сохраняем факт воспроизведения для общей статистики.
    registerPlay(getType());
}

/**
 * @brief Возвращает строковое обозначение типа гитары.
 */
std::string Guitar::getType() const {
    return "Guitar";
}
