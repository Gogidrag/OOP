/**
 * @file 3.cpp
 * @brief Задание 3: безопасный массив (SafeArray)
 * 
 * Программа демонстрирует работу со структурой SafeArray,
 * которая хранит динамический массив и его размер.
 * Реализованы функции:
 * - createArray — создаёт массив
 * - getElement — безопасный доступ по индексу
 * - printSafe — вывод массива
 * - reSizeArray — изменение размера
 * 
 * @author Gogidrag Минаеев дима 606-42 
 * @date 2026
 * @version 1
 * 
 * @mainpage Диаграмма деятельности (PlantUML)
 * 
 * @startuml
 * start
 * :createArray(5);
 * :Заполнить массив;
 * :printSafe(arr);
 * :getElement(arr, 2) = 999;
 * :printSafe(arr);
 * :getElement(arr, 10) — ошибка;
 * :reSizeArray(arr, 3);
 * :printSafe(arr);
 * :reSizeArray(arr, 7);
 * :printSafe(arr);
 * :delete[] arr.data;
 * :arr.data = nullptr;
 * stop
 * @enduml
 */

#include <iostream>
using namespace std;

/**
 * @brief Структура безопасного массива
 * 
 * Хранит указатель на данные и размер массива.
 */
struct SafeArray {
    int* data;   ///< указатель на массив
    int size;    ///< размер массива
};

/**
 * @brief Создаёт динамический массив заданного размера
 * 
 * @param size Размер массива
 * @return SafeArray Структура с выделенной памятью (обнулённой)
 */
SafeArray createArray(int size) {
    SafeArray arr;
    arr.size = size;
    arr.data = new int[size]{};   // {} — обнуляем
    return arr;
}

/**
 * @brief Безопасный доступ к элементу массива по индексу
 * 
 * Если индекс вне границ — возвращает ссылку на статическую
 * переменную-заглушку (программа не падает).
 * 
 * @param arr   Ссылка на структуру SafeArray
 * @param index Индекс элемента
 * @return int& Ссылка на элемент или на заглушку
 */
int& getElement(SafeArray& arr, int index) {
    static int dummy = 0;   // заглушка (живёт всю программу)

    if (index < 0 || index >= arr.size) {
        cout << "ОШИБКА: индекс " << index
             << " вне границ [0.." << arr.size - 1 << "]\n";
        return dummy;
    }
    return arr.data[index];
}

/**
 * @brief Выводит массив на экран
 * 
 * @param arr Константная ссылка на SafeArray
 * @return void
 */
void printSafe(const SafeArray& arr) {
    cout << "[ ";
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i] << " ";
    }
    cout << "]\n";
}

/**
 * @brief Изменяет размер массива
 * 
 * Если массив уменьшается — выводит удалённые элементы.
 * Если увеличивается — новые элементы = 0.
 * 
 * @param arr     Ссылка на SafeArray
 * @param newSize Новый размер
 * @return void
 */
void reSizeArray(SafeArray& arr, int newSize) {
    int* newData = new int[newSize]{};   // новый массив (обнулён)

    // Если уменьшаем — показываем удалённые
    if (newSize < arr.size) {
        cout << "Удаляемые элементы: ";
        for (int i = newSize; i < arr.size; i++) {
            cout << arr.data[i] << " ";
        }
        cout << endl;
    }

    // Копируем столько, сколько влезает
    int count = (newSize < arr.size) ? newSize : arr.size;
    for (int i = 0; i < count; i++) {
        newData[i] = arr.data[i];
    }

    delete[] arr.data;   // освобождаем старую память
    arr.data = newData;  // переключаем указатель
    arr.size = newSize;  // обновляем размер
}

/**
 * @brief Главная функция программы
 * 
 * @return 0 при успешном завершении
 */
int main() {
    cout << "Задание 3\n\n";

    // Создаём массив из 5 элементов
    SafeArray arr = createArray(5);

    // Заполняем
    for (int i = 0; i < arr.size; i++) {
        arr.data[i] = (i + 1) * 10;
    }

    cout << "Исходный: ";
    printSafe(arr);

    // Меняем 2 элемент через getElement
    cout << "\nМеняем элемент с индексом 2 на 999:\n";
    getElement(arr, 2) = 999;   // ← работает слева от =
    printSafe(arr);

    // Проверка выхода за границы
    cout << "\nПроверка выхода за границы (индекс 10):\n";
    getElement(arr, 10) = 777;
    printSafe(arr);

    // Уменьшаем размер
    cout << "\nУменьшаем размер с 5 до 3:\n";
    reSizeArray(arr, 3);
    printSafe(arr);

    // Увеличиваем размер
    cout << "\nУвеличиваем размер с 3 до 7:\n";
    reSizeArray(arr, 7);
    printSafe(arr);

    // Освобождение
    delete[] arr.data;
    arr.data = nullptr;

    return 0;
}