#include "StringInstrument.h"
#include <iostream>
#include <stdexcept>

/**
 * @brief Конструктор струнного инструмента.
 */
StringInstrument::StringInstrument(
    const std::string& name, int strings, double tension)
    : MusicalInstrument(name),
      strings_(strings),
      tension_(tension),
      stringTensions_(strings, tension) {
    if (strings <= 0 || tension <= 0)
        throw std::invalid_argument("Invalid string parameters");
}

/**
 * @brief Копирует струнный инструмент.
 */
StringInstrument::StringInstrument(const StringInstrument& other)
    : MusicalInstrument(other),
      strings_(other.strings_),
      tension_(other.tension_),
      stringTensions_(other.stringTensions_) {}

/**
 * @brief Присваивает параметры другого струнного инструмента.
 */
StringInstrument& StringInstrument::operator=(const StringInstrument& other) {
    if (this != &other) {
        MusicalInstrument::operator=(other);
        strings_ = other.strings_;
        tension_ = other.tension_;
        stringTensions_ = other.stringTensions_;
    }
    return *this;
}

/**
 * @brief Настраивает струны.
 */
void StringInstrument::tune() {
    std::cout << "Настройка струн инструмента: "
              << getName() << std::endl;
}