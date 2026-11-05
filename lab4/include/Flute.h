#ifndef FLUTE_H
#define FLUTE_H

#include "WindInstrument.h"

/**
 * @brief Класс флейты.
 *
 * Флейта является конкретным духовым инструментом. Помимо общих
 * параметров духовых инструментов хранит количество клапанов.
 */
class Flute : public WindInstrument {
private:
    int keys_; ///< Количество клапанов (клавиш) флейты.

public:
    /**
     * @brief Создаёт флейту.
     * @param name Название или модель флейты.
     * @param diaphragm Тип диафрагмы.
     * @param material Материал корпуса.
     * @param keys Количество клапанов.
     * @throw std::invalid_argument Если количество клапанов не положительное.
     */
    Flute(const std::string& name,
          const std::string& diaphragm,
          const std::string& material,
          int keys);

    /**
     * @brief Создаёт копию флейты.
     * @param other Копируемая флейта.
     */
    Flute(const Flute& other);

    /**
     * @brief Присваивает параметры другой флейты.
     * @param other Флейта-источник.
     * @return Ссылка на текущую флейту.
     */
    Flute& operator=(const Flute& other);

    /**
     * @brief Имитирует воспроизведение звука флейты.
     *
     * Выводит сообщение и обновляет статистику базового класса.
     */
    void play() override;

    /**
     * @brief Возвращает тип инструмента.
     * @return Строка "Flute".
     */
    std::string getType() const override;
};

#endif
