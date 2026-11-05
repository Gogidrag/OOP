#include "WindInstrument.h"

#include <iostream>
#include <stdexcept>

/**
 * @brief Создаёт духовой инструмент с заданными характеристиками.
 */
WindInstrument::WindInstrument(
    const std::string& name,
    const std::string& diaphragm,
    const std::string& material)
    : MusicalInstrument(name),
      diaphragm_(diaphragm),
      material_(material) {
    // Пустые значения не позволяют корректно описать инструмент.
    if (diaphragm.empty() || material.empty()) {
        throw std::invalid_argument("Invalid wind instrument parameters");
    }
}

/**
 * @brief Копирует базовые и собственные параметры духового инструмента.
 */
WindInstrument::WindInstrument(const WindInstrument& other)
    : MusicalInstrument(other),
      diaphragm_(other.diaphragm_),
      material_(other.material_) {}

/**
 * @brief Присваивает параметры другого духового инструмента.
 */
WindInstrument& WindInstrument::operator=(const WindInstrument& other) {
    // Не выполняем копирование, если источник и приёмник — один объект.
    if (this != &other) {
        MusicalInstrument::operator=(other);
        diaphragm_ = other.diaphragm_;
        material_ = other.material_;
    }
    return *this;
}

/**
 * @brief Выводит сообщение о настройке духового инструмента.
 */
void WindInstrument::tune() {
    std::cout << "Настройка духового инструмента: " << getName() << '\n';
}
