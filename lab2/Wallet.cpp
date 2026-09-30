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