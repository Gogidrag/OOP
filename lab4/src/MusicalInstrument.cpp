#include "MusicalInstrument.h"

#include <iostream>

// Начальные значения статических полей общие для всех объектов класса.
int MusicalInstrument::instrumentCount_ = 0;
std::map<std::string, int> MusicalInstrument::playCounts_;

/**
 * @brief Создаёт новый инструмент и увеличивает общий счётчик.
 */
MusicalInstrument::MusicalInstrument(const std::string& name)
    : name_(name) {
    ++instrumentCount_;
}

/**
 * @brief Создаёт копию базовой части инструмента.
 *
 * Копия считается отдельным объектом, поэтому счётчик увеличивается.
 */
MusicalInstrument::MusicalInstrument(const MusicalInstrument& other)
    : name_(other.name_) {
    ++instrumentCount_;
}

/**
 * @brief Копирует название инструмента.
 *
 * Статистику воспроизведений и число объектов при присваивании
 * не изменяем: меняется только содержимое уже существующего объекта.
 */
MusicalInstrument& MusicalInstrument::operator=(const MusicalInstrument& other) {
    if (this != &other) {
        name_ = other.name_;
    }
    return *this;
}

/**
 * @brief Уменьшает счётчик при уничтожении объекта.
 */
MusicalInstrument::~MusicalInstrument() {
    --instrumentCount_;
}

/**
 * @brief Выполняет общую настройку инструмента.
 */
void MusicalInstrument::tune() {
    std::cout << name_ << ": выполнена стандартная настройка.\n";
}

/**
 * @brief Возвращает сохранённое название.
 */
std::string MusicalInstrument::getName() const {
    return name_;
}

/**
 * @brief Возвращает количество существующих объектов.
 */
int MusicalInstrument::getInstrumentCount() {
    return instrumentCount_;
}

/**
 * @brief Увеличивает счётчик воспроизведений указанного типа.
 */
void MusicalInstrument::registerPlay(const std::string& type) {
    ++playCounts_[type];
}

/**
 * @brief Возвращает тип, который воспроизводили чаще остальных.
 */
std::string MusicalInstrument::getMostPlayedType() {
    if (playCounts_.empty()) {
        return "Нет данных";
    }

    auto best = playCounts_.begin();

    for (auto it = playCounts_.begin(); it != playCounts_.end(); ++it) {
        if (it->second > best->second) {
            best = it;
        }
    }

    return best->first;
}

/**
 * @brief Печатает количество воспроизведений каждого типа.
 */
void MusicalInstrument::printPlayStatistics() {
    if (playCounts_.empty()) {
        std::cout << "Статистика пока пуста.\n";
        return;
    }

    for (const auto& item : playCounts_) {
        std::cout << item.first << ": " << item.second << '\n';
    }
}

/**
 * @brief Выводит сведения об инструменте через дружественную функцию.
 */
void printInstrumentDetails(const MusicalInstrument& instrument) {
    std::cout << "Название: " << instrument.name_
              << ", тип: " << instrument.getType() << '\n';
}
