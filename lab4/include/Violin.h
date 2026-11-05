#pragma once

#include "StringInstrument.h"

/**
 * @brief Класс скрипки.
 */
class Violin : public StringInstrument {
public:
    Violin(const std::string& name, int strings, double tension);
    Violin(const Violin& other);
    Violin& operator=(const Violin& other);

    /// Воспроизводит звук скрипки.
    void play() override;

    /// Возвращает тип инструмента.
    std::string getType() const override;
};