#pragma once

#include "MusicalInstrument.h"

/**
 * @brief Промежуточный класс духовых инструментов.
 */
class WindInstrument : public MusicalInstrument {
protected:
    std::string diaphragm_; ///< Тип диафрагмы
    std::string material_;  ///< Материал корпуса

public:
    /**
     * @brief Создаёт духовой инструмент.
     * @param name Название
     * @param diaphragm Тип диафрагмы
     * @param material Материал
     */
    WindInstrument(
        const std::string& name,
        const std::string& diaphragm,
        const std::string& material
    );

    /// Конструктор копирования.
    WindInstrument(const WindInstrument& other);

    /// Оператор присваивания.
    WindInstrument& operator=(const WindInstrument& other);

    /// Виртуальный деструктор.
    ~WindInstrument() override = default;

    /// Настройка духового инструмента.
    void tune() override;
};