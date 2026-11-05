#pragma once

#include "Guitar.h"
#include "IElectronicDevice.h"

/**
 * @brief Гибрид гитары и электронного синтезатора.
 *
 * Наследуется от Guitar и интерфейса IElectronicDevice.
 */
class SynthGuitar : public Guitar, public IElectronicDevice {
private:
    bool poweredOn_;  ///< Состояние питания
    std::string patch_; ///< Выбранный звуковой пресет

public:
    SynthGuitar(const std::string& name,
                int strings,
                double tension,
                const std::string& patch);

    SynthGuitar(const SynthGuitar& other);
    SynthGuitar& operator=(const SynthGuitar& other);

    /// Воспроизводит звук синтезатора-гитары.
    void play() override;

    /// Возвращает тип инструмента.
    std::string getType() const override;

    /// Включает электронную часть.
    void powerOn() override;

    /**
     * @brief Устанавливает пресет.
     * @param patch Название пресета
     */
    void setPatch(const std::string& patch) override;
};