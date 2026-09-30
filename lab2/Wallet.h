#ifndef WALLET_H
#define WALLET_H

#include <string>

struct Owner {
    std::string fullName;   ///< ФИО владельца
    std::string passport;   ///< Паспортные данные
};

enum class Currency {
    RUB,   
    USD,   
    EUR   
};

class Wallet {
private:
    int id;                  ///< Уникальный идентификатор кошелька
    Owner owner;            
    double balance;          ///< Текущий баланс
    Currency currency;       
    bool isBlocked;          ///< Флаг блокировки

    static int objectCount;  ///< Счётчик существующих объектов

public:
}