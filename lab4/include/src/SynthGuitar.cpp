#include "SynthGuitar.h"
#include <iostream>
#include <stdexcept>

/**
 * @brief Создаёт синтезатор-гитару.
 */
SynthGuitar::SynthGuitar(const std::string& name,
                         int strings,
                         double tension,
                         const std::string& patch)
    : Guitar(name, strings, tension),
      poweredOn_(false),
      patch_(patch) {
    if (patch.empty())
        throw std::invalid_argument("Patch cannot be empty");
}

SynthGuitar::SynthGuitar(const SynthGuitar& other)
    : Guitar(other),
      poweredOn_(other.poweredOn_),
      patch_(other.patch_) {}

SynthGuitar& SynthGuitar::operator=(const SynthGuitar& other) {
    if (this != &other) {
        Guitar::operator=(other);
        poweredOn_ = other.poweredOn_;
        patch_ = other.patch_;
    }
    return *this;
}

/**
 * @brief Воспроизводит звук синтезатор-гитары.
 */
void SynthGuitar::play() {
    std::cout << "Синтезатор-гитара " << getName()
              << ": пресет " << patch_ << '\n';
    registerPlay(getType());
}

std::string SynthGuitar::getType() const {
    return "SynthGuitar";
}

/**
 * @brief Включает электронную часть инструмента.
 */
void SynthGuitar::powerOn() {
    poweredOn_ = true;
    std::cout << "Электронная часть включена\n";
}

/**
 * @brief Меняет звуковой пресет.
 */
void SynthGuitar::setPatch(const std::string& patch) {
    if (patch.empty())
        throw std::invalid_argument("Patch cannot be empty");

    patch_ = patch;
    std::cout << "Установлен пресет: " << patch_ << '\n';
}