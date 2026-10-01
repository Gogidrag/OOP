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
    Wallet();
    Wallet(int id, Owner owner, double balance, Currency currency);
    Wallet(const Wallet& other);
    ~Wallet();

    int getId() const;
    Owner getOwner() const;
    double getBalance() const;
    Currency getCurrency() const;
    bool getIsBlocked() const;
    static int getObjectCount();

    bool deposit(double amount);
    bool withdraw(double amount);
    bool transfer(Wallet& other, double amount);
    void block();
    void unblock();

    void printInfo() const;
    bool isValid() const;
};
#endif