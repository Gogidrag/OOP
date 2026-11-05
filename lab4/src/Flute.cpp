#include "Flute.h"
#include <iostream>
#include <stdexcept>

/**
 * @brief Создаёт флейту.
 */
Flute::Flute(const std::string& name,
             const std::string& diaphragm,
             const std::string& material,
             int keys)
    : WindInstrument(name, diaphragm, material), keys_(keys) {
    if (keys <= 0)
        throw std::invalid_argument("Invalid number of keys");
}

Flute::Flute(const Flute& other)
    : WindInstrument(other), keys_(other.keys_) {}

Flute& Flute::operator=(const Flute& other) {
    if (this != &other) {
        WindInstrument::operator=(other);
        keys_ = other.keys_;
    }
    return *this;
}

/**
 * @brief Воспроизводит звук флейты.
 */
void Flute::play() {
    std::cout << "Флейта " << getName() << ": играет мелодию\n";
    registerPlay(getType());
}

std::string Flute::getType() const {
    return "Flute";
}