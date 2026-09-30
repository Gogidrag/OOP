#include "Wallet.h"
#include <iostream>
#include <stdexcept>

//  ИНИЦИАЛИЗАЦИЯ СТАТИЧЕСКОГО ПОЛЯ
int Wallet::objectCount = 0;

// КОНСТРУКТОР ПО УМОЛЧАНИЮ 
Wallet::Wallet()
    : id(1),
      owner{"Неизвестный", "0000 000000"},
      balance(0.0),
      currency(Currency::RUB),
      isBlocked(false)
{
    ++objectCount;
    std::cout << "✅ Создан кошелёк #" << id 
              << " (по умолчанию). Всего: " << objectCount << "\n";
}
 //ПАРАМЕТРИЗОВАННЫЙ КОНСТРУКТОР
Wallet::Wallet(int id, Owner owner, double balance, Currency currency)
    : id(id),
      owner(owner),
      balance(balance),
      currency(currency),
      isBlocked(false)
{
    // Проверка инварианта: ID > 0
    if (id <= 0) {
        throw std::invalid_argument("ID должен быть больше 0");
    }
    // Проверка инварианта: имя не пустое
    if (owner.fullName.empty()) {
        throw std::invalid_argument("Имя владельца не может быть пустым");
    }
    // Проверка инварианта: баланс >= 0
    if (balance < 0) {
        throw std::invalid_argument("Баланс не может быть отрицательным");
    }

    ++objectCount;                              // увеличиваем счётчик
    std::cout << "✅ Создан кошелёк #" << id 
              << " (параметризованный). Всего: " << objectCount << "\n";
}
Wallet::~Wallet() {
    --objectCount;
    std::cout << "  Удалён кошелёк #" << id 
              << ". Осталось: " << objectCount << "\n";
}
//  МЕТОДЫ ЧТЕНИЯ 
int Wallet::getId() const { return id; }
Owner Wallet::getOwner() const { return owner; }
double Wallet::getBalance() const { return balance; }
Currency Wallet::getCurrency() const { return currency; }
bool Wallet::getIsBlocked() const { return isBlocked; }
int Wallet::getObjectCount() { return objectCount; }

//  ПОПОЛНЕНИЕ 
bool Wallet::deposit(double amount) {
    // Проверка блокировки
    if (isBlocked) {
        std::cout << "❌ Ошибка: кошелёк #" << id << " заблокирован\n";
        return false;
    }
    // Проверка суммы
    if (amount <= 0) {
        std::cout << "❌ Ошибка: сумма пополнения должна быть > 0\n";
        return false;
    }
    balance += amount;
    std::cout << " Кошелёк #" << id << " пополнен на " << amount 
              << ". Баланс: " << balance << "\n";
    return true;
}