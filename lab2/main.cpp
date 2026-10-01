#include "Wallet.h"
#include <iostream>
#include <stdexcept>

/**
 * @brief Точка входа — тест класса Wallet
 * 
 * Проверяет все требования лабораторной:
 * - создание объектов тремя способами
 * - корректные операции
 * - некорректные операции
 * - независимость объектов
 * - работу деструктора и счётчика
 * 
 * @return 0 при успешном завершении
 */
int main() {
    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout << "║   ТЕСТ КЛАССА WALLET (вариант 11)   ║\n";
    std::cout << "╚══════════════════════════════════════╝\n\n";

    // ЭТАП 1: СОЗДАНИЕ ОБЪЕКТОВ
    std::cout << "=== ЭТАП 1: СОЗДАНИЕ ОБЪЕКТОВ ===\n\n";

    Wallet w1;
    std::cout << "\n";

    Owner owner2{"Иванов Иван Иванович", "1234 567890"};
    Wallet w2(42, owner2, 5000.0, Currency::RUB);
    std::cout << "\n";

    Wallet w3(w2);
    std::cout << "\n";

    std::cout << "Всего объектов: " << Wallet::getObjectCount() << "\n\n";

    // ЭТАП 2: НАЧАЛЬНОЕ СОСТОЯНИЕ
    std::cout << "=== ЭТАП 2: НАЧАЛЬНОЕ СОСТОЯНИЕ ===\n\n";
    
    std::cout << "Кошелёк 1:\n";
    w1.printInfo();
    
    std::cout << "\nКошелёк 2:\n";
    w2.printInfo();
    
    std::cout << "\nКошелёк 3 (копия второго):\n";
    w3.printInfo();
    std::cout << "\n";

    // ЭТАП 3: КОРРЕКТНЫЕ ОПЕРАЦИИ
    std::cout << "=== ЭТАП 3: КОРРЕКТНЫЕ ОПЕРАЦИИ ===\n\n";

    w1.deposit(1000);
    w2.deposit(2000);
    w2.withdraw(500);
    w2.transfer(w1, 300);

    std::cout << "\nСостояние после корректных операций:\n\n";
    std::cout << "Кошелёк 1:\n";
    w1.printInfo();
    std::cout << "\nКошелёк 2:\n";
    w2.printInfo();
    std::cout << "\n";

    // ЭТАП 4: НЕКОРРЕКТНЫЕ ОПЕРАЦИИ
    std::cout << "=== ЭТАП 4: НЕКОРРЕКТНЫЕ ОПЕРАЦИИ ===\n\n";

    double before = w1.getBalance();
    std::cout << "Баланс w1 до ошибок: " << before << "\n\n";

    w1.deposit(-500);
    w1.withdraw(-100);
    w1.withdraw(99999);

    std::cout << "\n";
    w1.block();
    w1.deposit(100);
    w1.withdraw(50);
    w1.unblock();

    double after = w1.getBalance();
    std::cout << "\nБаланс w1 после ошибок: " << after << "\n";
    std::cout << (before == after ? "✅ Баланс не изменился!" : "❌ Баланс изменился!") << "\n\n";

    // ЭТАП 5: СОСТОЯНИЕ ПОСЛЕ ОШИБОК
    std::cout << "=== ЭТАП 5: СОСТОЯНИЕ ПОСЛЕ ОШИБОК ===\n\n";
    std::cout << "Кошелёк 1:\n";
    w1.printInfo();
    std::cout << "\n";

    // ЭТАП 6: НЕЗАВИСИМОСТЬ ОБЪЕКТОВ
    std::cout << "=== ЭТАП 6: НЕЗАВИСИМОСТЬ ОБЪЕКТОВ ===\n\n";

    double w1Before = w1.getBalance();
    double w3Before = w3.getBalance();

    std::cout << "До изменения:\n";
    std::cout << "  w1 баланс: " << w1Before << "\n";
    std::cout << "  w3 баланс: " << w3Before << "\n\n";

    w1.deposit(999);

    std::cout << "\nПосле пополнения w1 на 999:\n";
    std::cout << "  w1 баланс: " << w1.getBalance() << "\n";
    std::cout << "  w3 баланс: " << w3.getBalance() << "\n";
    
    if (w3.getBalance() == w3Before) {
        std::cout << "✅ w3 не изменился — объекты независимы!\n\n";
    } else {
        std::cout << "❌ w3 изменился — ошибка!\n\n";
    }

    // ЭТАП 7: ПРОВЕРКА ИНВАРИАНТОВ
    std::cout << "=== ЭТАП 7: ПРОВЕРКА ИНВАРИАНТОВ ===\n\n";
    std::cout << "w1 корректен: " << (w1.isValid() ? "✅ да" : "❌ нет") << "\n";
    std::cout << "w2 корректен: " << (w2.isValid() ? "✅ да" : "❌ нет") << "\n";
    std::cout << "w3 корректен: " << (w3.isValid() ? "✅ да" : "❌ нет") << "\n\n";

    // ЭТАП 8: ПРОВЕРКА ИСКЛЮЧЕНИЙ
    std::cout << "=== ЭТАП 8: ПРОВЕРКА ИСКЛЮЧЕНИЙ ===\n\n";
    
    try {
        Wallet bad(0, {"Тест", "0000"}, 100, Currency::RUB);
    } catch (const std::exception& e) {
        std::cout << "✅ Поймано исключение: " << e.what() << "\n";
    }
    
    try {
        Wallet bad(1, {"", "0000"}, 100, Currency::RUB);
    } catch (const std::exception& e) {
        std::cout << "✅ Поймано исключение: " << e.what() << "\n";
    }
    
    try {
        Wallet bad(1, {"Тест", "0000"}, -100, Currency::RUB);
    } catch (const std::exception& e) {
        std::cout << "✅ Поймано исключение: " << e.what() << "\n";
    }

    std::cout << "\n";
    std::cout << "=== КОНЕЦ ТЕСТА ===\n";
    std::cout << "Всего объектов перед выходом: " << Wallet::getObjectCount() << "\n\n";

    return 0;
}