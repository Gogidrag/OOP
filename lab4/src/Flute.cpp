#include "Flute.h"

#include <iostream>
#include <stdexcept>

/**
 * @brief Создаёт флейту и задаёт количество клапанов.
 */
Flute::Flute(const std::string& name,
             const std::string& diaphragm,
             const std::string& material,
             int keys)
    : WindInstrument(name, diaphragm, material), keys_(keys) {
    // У флейты должно быть хотя бы одно управляющее отверстие/клапан.
    if (keys <= 0) {
        throw std::invalid_argument("Invalid number of keys");
    }
}

/**
 * @brief Создаёт копию флейты.
 */
Flute::Flute(const Flute& other)
    : WindInstrument(other), keys_(other.keys_) {}

/**
 * @brief Копирует характеристики другой флейты.
 */
Flute& Flute::operator=(const Flute& other) {
    if (this != &other) {
        WindInstrument::operator=(other);
        keys_ = other.keys_;
    }
    return *this;
}

/**
 * @brief Выводит сообщение о воспроизведении флейты.
 */
void Flute::play() {
    std::cout << "Флейта " << getName() << ": играет мелодию\n";
    registerPlay(getType());
}

/**
 * @brief Возвращает строковое обозначение типа флейты.
 */
std::string Flute::getType() const {
    return "Flute";
}
