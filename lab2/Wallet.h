#ifndef WALLET_H
#define WALLET_H

#include <string>

/**
 * @brief Пользовательский тип — владелец кошелька
 * 
 * Хранит ФИО и паспортные данные владельца.
 */
struct Owner {
    std::string fullName;   ///< ФИО владельца
    std::string passport;   ///< Паспортные данные
};

/**
 * @brief Пользовательский тип — валюта кошелька
 * 
 * Перечисление доступных валют.
 */
enum class Currency {
    RUB,   ///< Российский рубль
    USD,   ///< Доллар США
    EUR    ///< Евро
};

/**
 * @brief Класс электронного кошелька
 * 
 * Хранит информацию о владельце, балансе, валюте и состоянии.
 * Позволяет пополнять, списывать, переводить, блокировать.
 * 
 * @details
 * Класс обеспечивает корректность собственного состояния
 * через проверку инвариантов в конструкторах и методах изменения.
 * 
 * @author Минаев Дмитрий, 606-42
 * @date 2026
 * @version 1.0
 */
class Wallet {
private:
    int id;                  ///< Уникальный идентификатор кошелька
    Owner owner;             ///< Владелец (пользовательский тип)
    double balance;          ///< Текущий баланс
    Currency currency;       ///< Валюта (пользовательский тип)
    bool isBlocked;          ///< Флаг блокировки

    static int objectCount;  ///< Счётчик существующих объектов

public:
    /**
     * @brief Конструктор по умолчанию
     * 
     * Создает кошелёк с корректным начальным состоянием:
     * id=1, owner="Неизвестный", balance=0, currency=RUB, isBlocked=false
     */
    Wallet();

    /**
     * @brief Параметризованный конструктор
     * 
     * @param id ID кошелька (должен быть > 0)
     * @param owner Владелец (ФИО не должно быть пустым)
     * @param balance Баланс (не может быть отрицательным)
     * @param currency Валюта
     * 
     * @throw std::invalid_argument если данные некорректны
     */
    Wallet(int id, Owner owner, double balance, Currency currency);

    /**
     * @brief Конструктор копирования
     * 
     * @param other Копируемый объект
     */
    Wallet(const Wallet& other);

    /**
     * @brief Деструктор
     * 
     * Уменьшает счётчик объектов и выводит сообщение.
     */
    ~Wallet();

    /**
     * @brief Получить ID кошелька
     * @return ID
     */
    int getId() const;

    /**
     * @brief Получить владельца
     * @return Структура Owner
     */
    Owner getOwner() const;

    /**
     * @brief Получить баланс
     * @return Текущий баланс
     */
    double getBalance() const;

    /**
     * @brief Получить валюту
     * @return Валюта кошелька
     */
    Currency getCurrency() const;

    /**
     * @brief Получить статус блокировки
     * @return true если заблокирован
     */
    bool getIsBlocked() const;

    /**
     * @brief Получить количество существующих объектов
     * @return Число объектов Wallet
     */
    static int getObjectCount();

    /**
     * @brief Пополнить кошелёк
     * 
     * @param amount Сумма (должна быть > 0)
     * @return true если успешно
     * 
     * @note Заблокированный кошелёк не может пополняться
     */
    bool deposit(double amount);

    /**
     * @brief Списать средства
     * 
     * @param amount Сумма (должна быть > 0 и <= баланса)
     * @return true если успешно
     * 
     * @note Заблокированный кошелёк не может списывать
     */
    bool withdraw(double amount);

    /**
     * @brief Перевести средства другому кошельку
     * 
     * @param other Кошелёк-получатель
     * @param amount Сумма перевода
     * @return true если успешно
     * 
     * @note Валюты должны совпадать, оба кошелька активны
     */
    bool transfer(Wallet& other, double amount);

    /**
     * @brief Заблокировать кошелёк
     */
    void block();

    /**
     * @brief Разблокировать кошелёк
     */
    void unblock();

    /**
     * @brief Вывести информацию о кошельке
     */
    void printInfo() const;

    /**
     * @brief Проверить корректность состояния
     * @return true если все инварианты выполнены
     */
    bool isValid() const;
};

#endif