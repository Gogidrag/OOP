#pragma once

#include "WindInstrument.h"

/**
 * @brief Класс флейты.
 */
class Flute : public WindInstrument {
private:
    int keys_; ///< Количество клапанов

public:
    Flute(const std::string& name,
          const std::string& diaphragm,
          const std::string& material,
          int keys);

    Flute(const Flute& other);
    Flute& operator=(const Flute& other);

    /// Воспроизводит звук флейты.
    void play() override;

    /// Возвращает тип инструмента.
    std::string getType() const override;
};