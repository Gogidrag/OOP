#ifndef SYNTH_GUITAR_H
#define SYNTH_GUITAR_H

#include "Guitar.h"
#include "IElectronicDevice.h"

/**
 * @brief Класс электрогитары с функциями синтезатора.
 *
 * Демонстрирует множественное наследование:
 * от Guitar получает свойства и поведение струнного инструмента,
 * а от IElectronicDevice — интерфейс управления электронной частью.
 */
class SynthGuitar : public Guitar, public IElectronicDevice {
private:
    bool poweredOn_;   ///< Показывает, включено ли электронное устройство.
    std::string patch_; ///< Название текущего звукового пресета.

public:
    /**
     * @brief Создаёт синтезатор-гитару.
     * @param name Название или модель инструмента.
     * @param strings Количество струн.
     * @param tension Натяжение струн.
     * @param patch Начальный звуковой пресет.
     */
    SynthGuitar(const std::string& name,
                int strings,
                double tension,
                const std::string& patch);

    /**
     * @brief Создаёт копию синтезатор-гитары.
     * @param other Копируемый объект.
     */
    SynthGuitar(const SynthGuitar& other);

    /**
     * @brief Копирует параметры другой синтезатор-гитары.
     * @param other Объект-источник.
     * @return Ссылка на текущий объект.
     */
    SynthGuitar& operator=(const SynthGuitar& other);

    /**
     * @brief Имитирует воспроизведение звука синтезатор-гитары.
     *
     * Выводит название инструмента и активный пресет,
     * после чего регистрирует воспроизведение в статистике.
     */
    void play() override;

    /**
     * @brief Возвращает тип инструмента.
     * @return Строка "SynthGuitar".
     */
    std::string getType() const override;

    /**
     * @brief Включает электронную часть инструмента.
     *
     * После вызова poweredOn_ принимает значение true.
     */
    void powerOn() override;

    /**
     * @brief Меняет текущий звуковой пресет.
     * @param patch Название нового пресета.
     * @throw std::invalid_argument Если передана пустая строка.
     */
    void setPatch(const std::string& patch) override;
};

#endif
