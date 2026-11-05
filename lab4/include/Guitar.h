#pragma once

#include "StringInstrument.h"

/**
 * @brief Класс гитары.
 */
class Guitar : public StringInstrument {
public:
    Guitar(const std::string& name, int strings, double tension);
    Guitar(const Guitar& other);
    Guitar& operator=(const Guitar& other);

    /// Воспроизводит звук гитары.
    void play() override;

    /// Возвращает тип инструмента.
    std::string getType() const override;
};