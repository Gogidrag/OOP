#ifndef MUSICAL_INSTRUMENT_H
#define MUSICAL_INSTRUMENT_H

#include <map>
#include <string>

/**
 * @brief Абстрактный базовый класс музыкального инструмента.
 *
 * Содержит общие свойства и методы музыкальных инструментов.
 * Является корнем иерархии наследования.
 */
class MusicalInstrument {
public:

    /**
     * @brief Конструктор музыкального инструмента.
     * @param name Название инструмента.
     */
    explicit MusicalInstrument(const std::string& name);

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~MusicalInstrument();

    /**
     * @brief Воспроизводит звук инструмента.
     *
     * Чисто виртуальная функция.
     */
    virtual void play() = 0;

    /**
     * @brief Настраивает музыкальный инструмент.
     */
    virtual void tune();

    /**
     * @brief Возвращает тип инструмента.
     * @return Строка с типом инструмента.
     */
    virtual std::string getType() const = 0;

    /**
     * @brief Возвращает название инструмента.
     * @return Название инструмента.
     */
    std::string getName() const;

    /**
     * @brief Возвращает количество созданных инструментов.
     * @return Количество объектов.
     */
    static int getInstrumentCount();

    /**
     * @brief Определяет наиболее часто воспроизводимый тип.
     * @return Название типа инструмента.
     */
    static std::string getMostPlayedType();

    /**
     * @brief Выводит статистику воспроизведений.
     */
    static void printPlayStatistics();

protected:

    std::string name_; ///< Название музыкального инструмента.

    /**
     * @brief Регистрирует воспроизведение инструмента.
     * @param type Тип инструмента.
     */
    static void registerPlay(const std::string& type);

private:

    static int instrumentCount_; 
    ///< Статический счётчик существующих объектов.

    static std::map<std::string, int> playCounts_;
    ///< Статистика количества воспроизведений.

    /**
     * @brief Дружественная функция для доступа к закрытым данным.
     */
    friend void printInstrumentDetails(
        const MusicalInstrument& instrument
    );
};

/**
 * @brief Выводит подробную информацию об инструменте.
 * @param instrument Объект музыкального инструмента.
 */
void printInstrumentDetails(
    const MusicalInstrument& instrument
);

#endif