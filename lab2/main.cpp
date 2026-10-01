#include "Wallet.h"
#include <iostream>
#include <stdexcept>

int main() {
    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout << "║   ТЕСТ КЛАССА WALLET (вариант 11)   ║\n";
    std::cout << "╚══════════════════════════════════════╝\n\n";

    std::cout << "=== ЭТАП 1: СОЗДАНИЕ ОБЪЕКТОВ ===\n\n";

    // 1. Конструктор по умолчанию
    Wallet w1;
    std::cout << "\n";

    // 2. Параметризованный конструктор
    Owner owner2{"Иванов Иван Иванович", "1234 567890"};
    Wallet w2(42, owner2, 5000.0, Currency::RUB);
    std::cout << "\n";

    // 3. Конструктор копирования
    Wallet w3(w2);
    std::cout << "\n";

    std::cout << "Всего объектов: " << Wallet::getObjectCount() << "\n\n";
