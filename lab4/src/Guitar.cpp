#include "Guitar.h"
#include <iostream>

/**
 * @brief Создаёт гитару.
 */
Guitar::Guitar(const std::string& name, int strings, double tension)
    : StringInstrument(name, strings, tension) {}

Guitar::Guitar(const Guitar& other)
    : StringInstrument(other) {}

Guitar& Guitar::operator=(const Guitar& other) {
    if (this != &other)
        StringInstrument::operator=(other);
    return *this;
}

/**
 * @brief Воспроизводит звук гитары.
 */
void Guitar::play() {
    std::cout << "Гитара " << getName() << ": играет мелодию\n";
    registerPlay(getType());
}

std::string Guitar::getType() const {
    return "Guitar";
}