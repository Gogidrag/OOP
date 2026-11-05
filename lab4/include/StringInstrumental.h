#pragma once

#include "MusicalInstrument.h"
#include <vector>

/**
 * @brief Промежуточный класс струнных музыкальных инструментов.
 */
class StringInstrument : public MusicalInstrument {
protected:
    int strings_;                       ///< Количество струн
    double tension_;                    ///< Общее натяжение струн
    std::vector<double> stringTensions_;///< Натяжение каждой струны

public:
    /**
     * @brief Создаёт струнный инструмент.
     * @param name Название инструмента
     * @param strings Количество струн
     * @param tension Натяжение
     */
    StringInstrument(const std::string& name, int strings, double tension);

    /// Конструктор копирования.
    StringInstrument(const StringInstrument& other);

    /// Оператор присваивания.
    StringInstrument& operator=(const StringInstrument& other);

    /// Виртуальный деструктор.
    ~StringInstrument() override = default;

    /// Выводит информацию о струнах.
    virtual void tune() override;
};