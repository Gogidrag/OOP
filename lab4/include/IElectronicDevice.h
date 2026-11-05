#pragma once

#include <string>

/**
 * @brief Интерфейс электронного устройства.
 */
class IElectronicDevice {
public:
    /// Включает электронную часть устройства.
    virtual void powerOn() = 0;

    /**
     * @brief Устанавливает звуковой пресет.
     * @param patch Название пресета
     */
    virtual void setPatch(const std::string& patch) = 0;

    /// Виртуальный деструктор интерфейса.
    virtual ~IElectronicDevice() = default;
};