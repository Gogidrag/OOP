#ifndef WIND_INSTRUMENT_H
#define WIND_INSTRUMENT_H

#include "MusicalInstrument.h"

/**
 * @brief Промежуточный класс духовых музыкальных инструментов.
 *
 * Содержит общие характеристики духовых инструментов: тип диафрагмы
 * и материал корпуса. Конкретный способ воспроизведения звука
 * определяется в производных классах.
 */
class WindInstrument : public MusicalInstrument {
protected:
    std::string diaphragm_; ///< Тип диафрагмы.
    std::string material_;  ///< Материал корпуса.

public:
    /**
     * @brief Создаёт духовой инструмент.
     * @param name Название инструмента.
     * @param diaphragm Тип диафрагмы.
     * @param material Материал корпуса.
     * @throw std::invalid_argument Если диафрагма или материал не заданы.
     */
    WindInstrument(const std::string& name,
                   const std::string& diaphragm,
                   const std::string& material);

    /**
     * @brief Создаёт копию духового инструмента.
     * @param other Копируемый объект.
     */
    WindInstrument(const WindInstrument& other);

    /**
     * @brief Копирует параметры другого духового инструмента.
     * @param other Объект-источник.
     * @return Ссылка на текущий объект.
     */
    WindInstrument& operator=(const WindInstrument& other);

    /// Виртуальный деструктор.
    ~WindInstrument() override = default;

    /**
     * @brief Выводит сообщение о настройке духового инструмента.
     */
    void tune() override;
};

#endif
