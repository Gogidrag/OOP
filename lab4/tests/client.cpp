#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>

#include "MusicalInstrument.h"
#include "Guitar.h"
#include "Violin.h"
#include "Flute.h"
#include "SynthGuitar.h"

/**
 * @brief Загружает музыкальные инструменты из файла.
 * @param filename Путь к файлу
 * @return Вектор указателей на музыкальные инструменты
 */
std::vector<std::unique_ptr<MusicalInstrument>>
loadInstruments(const std::string& filename) {
    std::vector<std::unique_ptr<MusicalInstrument>> instruments;
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Не удалось открыть файл: " + filename);

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#')
            continue;

        std::stringstream ss(line);
        std::string type, name, p1, p2, p3;

        std::getline(ss, type, '|');
        std::getline(ss, name, '|');
        std::getline(ss, p1, '|');
        std::getline(ss, p2, '|');
        std::getline(ss, p3, '|');

        if (type == "Guitar") {
            instruments.push_back(std::make_unique<Guitar>(
                name, std::stoi(p1), std::stod(p2)));
        }
        else if (type == "Violin") {
            instruments.push_back(std::make_unique<Violin>(
                name, std::stoi(p1), std::stod(p2)));
        }
        else if (type == "Flute") {
            instruments.push_back(std::make_unique<Flute>(
                name, p1, p2, std::stoi(p3)));
        }
        else if (type == "SynthGuitar") {
            instruments.push_back(std::make_unique<SynthGuitar>(
                name, std::stoi(p1), std::stod(p2), p3));
        }
        else {
            std::cerr << "Неизвестный тип: " << type << '\n';
        }
    }

    return instruments;
}

/**
 * @brief Главная функция тестирования лабораторной работы.
 */
int main() {
    try {
        std::cout << "ЛАБОРАТОРНАЯ РАБОТА №4\n";
        std::cout << "Тема: Музыкальные инструменты\n\n";

        auto orchestra = loadInstruments("data/instruments.txt");

        std::cout << "Загружено инструментов: "
                  << orchestra.size() << "\n\n";

        std::cout << "ПОЛИМОРФИЗМ \n";

        for (const auto& instrument : orchestra) {
            instrument->tune();
            instrument->play();
        }

        std::cout << "\n СТАТИСТИКА \n";
        std::cout << "Количество инструментов: "
                  << MusicalInstrument::getInstrumentCount() << '\n';

        std::cout << "Самый часто используемый тип: "
                  << MusicalInstrument::getMostPlayedType() << '\n';

        std::cout << "\n=== ДРУЖЕСТВЕННАЯ ФУНКЦИЯ ===\n";
        if (!orchestra.empty())
            printInstrumentDetails(*orchestra.front());

        std::cout << "\n КОПИРОВАНИЕ \n";

        Guitar original("Test Guitar", 6, 12.0);
        Guitar copy(original);

        std::cout << "Исходный объект: ";
        printInstrumentDetails(original);

        std::cout << "Копия: ";
        printInstrumentDetails(copy);

        Guitar assigned("Another Guitar", 6, 10.0);
        assigned = original;

        std::cout << "После присваивания: ";
        printInstrumentDetails(assigned);

        assigned = assigned;
        std::cout << "Самоприсваивание проверено.\n";

        std::cout << "\n МНОЖЕСТВЕННОЕ НАСЛЕДОВАНИЕ\n";

        SynthGuitar synth("Test Synth", 6, 12.0, "Rock");
        synth.powerOn();
        synth.setPatch("Jazz");
        synth.play();

        std::cout << "\n ИТОГ \n";
        std::cout << "Тестирование завершено.\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
        return 1;
    }

    return 0;
}