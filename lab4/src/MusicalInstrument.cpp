#include "MusicalInstrument.h"

#include <iostream>

// Инициализация статических переменных.
int MusicalInstrument::instrumentCount_ = 0;

std::map<std::string, int> MusicalInstrument::playCounts_;

/**
 * @brief Создаёт музыкальный инструмент.
 * @param name Название инструмента.
 */
MusicalInstrument::MusicalInstrument(const std::string& name)
    : name_(name) {

    ++instrumentCount_;
}

/**
 * @brief Уничтожает музыкальный инструмент.
 */
MusicalInstrument::~MusicalInstrument() {

    --instrumentCount_;
}

/**
 * @brief Стандартная настройка инструмента.
 */
void MusicalInstrument::tune() {

    std::cout << name_
              << ": выполнена стандартная настройка.\n";
}

/**
 * @brief Возвращает название инструмента.
 * @return Название инструмента.
 */
std::string MusicalInstrument::getName() const {

    return name_;
}

/**
 * @brief Возвращает количество существующих инструментов.
 * @return Количество объектов.
 */
int MusicalInstrument::getInstrumentCount() {

    return instrumentCount_;
}

/**
 * @brief Регистрирует воспроизведение инструмента.
 * @param type Тип инструмента.
 */
void MusicalInstrument::registerPlay(const std::string& type) {

    ++playCounts_[type];
}

/**
 * @brief Определяет наиболее часто воспроизводимый тип.
 * @return Название типа инструмента.
 */
std::string MusicalInstrument::getMostPlayedType() {

    if (playCounts_.empty()) {
        return "Нет данных";
    }

    auto best = playCounts_.begin();

    for (auto it = playCounts_.begin();
         it != playCounts_.end(); ++it) {

        if (it->second > best->second) {
            best = it;
        }
    }

    return best->first;
}

/**
 * @brief Выводит статистику воспроизведений.
 */
void MusicalInstrument::printPlayStatistics() {

    if (playCounts_.empty()) {

        std::cout << "Статистика пока пуста.\n";
        return;
    }

    for (const auto& item : playCounts_) {

        std::cout << item.first
                  << ": "
                  << item.second
                  << '\n';
    }
}

/**
 * @brief Дружественная функция вывода информации.
 * @param instrument Музыкальный инструмент.
 */
void printInstrumentDetails(
    const MusicalInstrument& instrument
) {

    std::cout << "Название: "
              << instrument.name_
              << ", тип: "
              << instrument.getType()
              << '\n';
}