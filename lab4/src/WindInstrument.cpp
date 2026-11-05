#include "WindInstrument.h"
#include <iostream>
#include <stdexcept>

/**
 * @brief Конструктор духового инструмента.
 */
WindInstrument::WindInstrument(
    const std::string& name,
    const std::string& diaphragm,
    const std::string& material)
    : MusicalInstrument(name),
      diaphragm_(diaphragm),
      material_(material) {
    if (diaphragm.empty() || material.empty())
        throw std::invalid_argument("Invalid wind instrument parameters");
}

/**
 * @brief Конструктор копирования.
 */
WindInstrument::WindInstrument(const WindInstrument& other)
    : MusicalInstrument(other),
      diaphragm_(other.diaphragm_),
      material_(other.material_) {}

/**
 * @brief Оператор присваивания.
 */
WindInstrument& WindInstrument::operator=(const WindInstrument& other) {
    if (this != &other) {
        MusicalInstrument::operator=(other);
        diaphragm_ = other.diaphragm_;
        material_ = other.material_;
    }
    return *this;
}

/**
 * @brief Настраивает духовой инструмент.
 */
void WindInstrument::tune() {
    std::cout << "Настройка духового инструмента: "
              << getName() << std::endl;
}