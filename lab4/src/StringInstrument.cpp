#include "StringInstrument.h"

#include <iostream>
#include <stdexcept>

/**
 * @brief Создаёт струнный инструмент и заполняет параметры струн.
 */
StringInstrument::StringInstrument(
    const std::string& name, int strings, double tension)
    : MusicalInstrument(name),
      strings_(strings),
      tension_(tension),
      stringTensions_(strings > 0 ? strings : 0, tension) {
    // Проверяем параметры, чтобы у инструмента не было нулевого числа струн.
    if (strings <= 0 || tension <= 0) {
        throw std::invalid_argument("Invalid string parameters");
    }
}

/**
 * @brief Копирует все параметры струнного инструмента.
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
    // Защита от присваивания объекта самому себе.
    if (this != &other) {
        MusicalInstrument::operator=(other);
        strings_ = other.strings_;
        tension_ = other.tension_;
        stringTensions_ = other.stringTensions_;
    }
    return *this;
}

/**
 * @brief Выводит сообщение о настройке струн.
 */
void StringInstrument::tune() {
    std::cout << "Настройка струн инструмента: " << getName() << '\n';
}
