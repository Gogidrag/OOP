#include "Violin.h"
#include <iostream>

/**
 * @brief Создаёт скрипку.
 */
Violin::Violin(const std::string& name, int strings, double tension)
    : StringInstrument(name, strings, tension) {}

Violin::Violin(const Violin& other)
    : StringInstrument(other) {}

Violin& Violin::operator=(const Violin& other) {
    if (this != &other)
        StringInstrument::operator=(other);
    return *this;
}

/**
 * @brief Воспроизводит звук скрипки.
 */
void Violin::play() {
    std::cout << "Скрипка " << getName() << ": играет мелодию\n";
    registerPlay(getType());
}

std::string Violin::getType() const {
    return "Violin";
}