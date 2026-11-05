#ifndef I_ELECTRONIC_DEVICE_H
#define I_ELECTRONIC_DEVICE_H

#include <string>

/**
 * @brief Интерфейс электронного устройства.
 *
 * Описывает минимальный набор операций для устройства,
 * которое имеет питание и позволяет выбирать звуковой пресет.
 * Интерфейс не хранит состояние — реализация находится в классе-наследнике.
 */
class IElectronicDevice {
public:
    /**
     * @brief Включает электронную часть устройства.
     */
    virtual void powerOn() = 0;

    /**
     * @brief Устанавливает звуковой пресет.
     * @param patch Название выбранного пресета.
     */
    virtual void setPatch(const std::string& patch) = 0;

    /**
     * @brief Виртуальный деструктор интерфейса.
     *
     * Нужен для безопасного удаления объектов через указатель
     * на интерфейс.
     */
    virtual ~IElectronicDevice() = default;
};

#endif
