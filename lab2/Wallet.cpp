#include "Wallet.h"
#include <iostream>
#include <stdexcept>

// Инициализация статического поля
int Wallet::objectCount = 0;

/**
 * @brief Конструктор по умолчанию
 */
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

/**
 * @brief Параметризованный конструктор
 */
Wallet::Wallet(int id, Owner owner, double balance, Currency currency)
    : id(id),
      owner(owner),
      balance(balance),
      currency(currency),
      isBlocked(false)
{
    // Проверка инвариантов
    if (id <= 0) {
        throw std::invalid_argument("ID должен быть больше 0");
    }
    if (owner.fullName.empty()) {
        throw std::invalid_argument("Имя владельца не может быть пустым");
    }
    if (balance < 0) {
        throw std::invalid_argument("Баланс не может быть отрицательным");
    }

    ++objectCount;
    std::cout << "✅ Создан кошелёк #" << id 
              << " (параметризованный). Всего: " << objectCount << "\n";
}

/**
 * @brief Конструктор копирования
 */
Wallet::Wallet(const Wallet& other)
    : id(other.id),
      owner(other.owner),
      balance(other.balance),
      currency(other.currency),
      isBlocked(other.isBlocked)
{
    ++objectCount;
    std::cout << "✅ Создан кошелёк #" << id 
              << " (копия). Всего: " << objectCount << "\n";
}

/**
 * @brief Деструктор
 */
Wallet::~Wallet() {
    --objectCount;
    std::cout << "🗑️  Удалён кошелёк #" << id 
              << ". Осталось: " << objectCount << "\n";
}

/**
 * @brief Получить ID
 */
int Wallet::getId() const { return id; }

/**
 * @brief Получить владельца
 */
Owner Wallet::getOwner() const { return owner; }

/**
 * @brief Получить баланс
 */
double Wallet::getBalance() const { return balance; }

/**
 * @brief Получить валюту
 */
Currency Wallet::getCurrency() const { return currency; }

/**
 * @brief Получить статус блокировки
 */
bool Wallet::getIsBlocked() const { return isBlocked; }

/**
 * @brief Получить счётчик объектов
 */
int Wallet::getObjectCount() { return objectCount; }

/**
 * @brief Пополнить кошелёк
 */
bool Wallet::deposit(double amount) {
    if (isBlocked) {
        std::cout << "❌ Ошибка: кошелёк #" << id << " заблокирован\n";
        return false;
    }
    if (amount <= 0) {
        std::cout << "❌ Ошибка: сумма пополнения должна быть > 0\n";
        return false;
    }
    balance += amount;
    std::cout << "💰 Кошелёк #" << id << " пополнен на " << amount 
              << ". Баланс: " << balance << "\n";
    return true;
}

/**
 * @brief Списать средства
 */
bool Wallet::withdraw(double amount) {
    if (isBlocked) {
        std::cout << "❌ Ошибка: кошелёк #" << id << " заблокирован\n";
        return false;
    }
    if (amount <= 0) {
        std::cout << "❌ Ошибка: сумма списания должна быть > 0\n";
        return false;
    }
    if (amount > balance) {
        std::cout << "❌ Ошибка: недостаточно средств (баланс: " 
                  << balance << ", запрошено: " << amount << ")\n";
        return false;
    }
    balance -= amount;
    std::cout << "💸 Кошелёк #" << id << " списано " << amount 
              << ". Баланс: " << balance << "\n";
    return true;
}

/**
 * @brief Перевести средства
 */
bool Wallet::transfer(Wallet& other, double amount) {
    if (isBlocked || other.isBlocked) {
        std::cout << "❌ Ошибка: один из кошельков заблокирован\n";
        return false;
    }
    if (currency != other.currency) {
        std::cout << "❌ Ошибка: разные валюты\n";
        return false;
    }
    if (amount <= 0 || amount > balance) {
        std::cout << "❌ Ошибка: неверная сумма перевода\n";
        return false;
    }
    
    balance -= amount;
    other.balance += amount;
    std::cout << "🔄 Перевод " << amount << " с #" << id 
              << " на #" << other.id << "\n";
    return true;
}

/**
 * @brief Заблокировать кошелёк
 */
void Wallet::block() {
    isBlocked = true;
    std::cout << "🔒 Кошелёк #" << id << " заблокирован\n";
}

/**
 * @brief Разблокировать кошелёк
 */
void Wallet::unblock() {
    isBlocked = false;
    std::cout << "🔓 Кошелёк #" << id << " разблокирован\n";
}

/**
 * @brief Вывести информацию
 */
void Wallet::printInfo() const {
    std::cout << "┌─────────────────────────────┐\n";
    std::cout << "│ ID:       " << id << "\n";
    std::cout << "│ Владелец: " << owner.fullName << "\n";
    std::cout << "│ Паспорт:  " << owner.passport << "\n";
    std::cout << "│ Баланс:   " << balance << " ";
    
    switch (currency) {
        case Currency::RUB: std::cout << "RUB"; break;
        case Currency::USD: std::cout << "USD"; break;
        case Currency::EUR: std::cout << "EUR"; break;
    }
    
    std::cout << "\n";
    std::cout << "│ Статус:   " << (isBlocked ? "🔒 заблокирован" : "✅ активен") << "\n";
    std::cout << "└─────────────────────────────┘\n";
}

/**
 * @brief Проверить корректность состояния
 */
bool Wallet::isValid() const {
    return balance >= 0 
        && id > 0 
        && !owner.fullName.empty()
        && !owner.passport.empty();
}