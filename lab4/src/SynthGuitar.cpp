#include "SynthGuitar.h"

#include <iostream>
#include <stdexcept>

/**
 * @brief Создаёт синтезатор-гитару с начальным пресетом.
 */
SynthGuitar::SynthGuitar(const std::string& name,
                         int strings,
                         double tension,
                         const std::string& patch)
    : Guitar(name, strings, tension),
      poweredOn_(false),
      patch_(patch) {
    if (patch.empty()) {
        throw std::invalid_argument("Patch cannot be empty");
    }
}

/**
 * @brief Создаёт копию синтезатор-гитары.
 */
SynthGuitar::SynthGuitar(const SynthGuitar& other)
    : Guitar(other),
      poweredOn_(other.poweredOn_),
      patch_(other.patch_) {}

/**
 * @brief Копирует параметры гитары и электронной части.
 */
SynthGuitar& SynthGuitar::operator=(const SynthGuitar& other) {
    if (this != &other) {
        Guitar::operator=(other);
        poweredOn_ = other.poweredOn_;
        patch_ = other.patch_;
    }
    return *this;
}

/**
 * @brief Выводит название инструмента и выбранный звуковой пресет.
 */
void SynthGuitar::play() {
    std::cout << "Синтезатор-гитара " << getName()
              << ": пресет " << patch_ << '\n';
    registerPlay(getType());
}

/**
 * @brief Возвращает строковое обозначение типа синтезатор-гитары.
 */
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
 * @brief Устанавливает новый звуковой пресет.
 */
void SynthGuitar::setPatch(const std::string& patch) {
    if (patch.empty()) {
        throw std::invalid_argument("Patch cannot be empty");
    }

    patch_ = patch;
    std::cout << "Установлен пресет: " << patch_ << '\n';
}
