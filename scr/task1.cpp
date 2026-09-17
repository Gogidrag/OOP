/**
 * @file task1.cpp
 * @brief Задание 1: работа со статическим массивом и функциями
 * 
 * Программа создаёт статический массив из 10 целых чисел,
 * заполняет его случайными числами, выводит на экран,
 * меняет местами два элемента и умножает все элементы на 2.
 * 
 * @author Gogidrag Минаев Дмитрий 606-42
 * @date 2026
 * @version первая
 * 
 * @mainpage Диаграмма деятельности (PlantUML)
 * 
 * @startuml
 * start
 * :srand(time(0));
 * :int arr[10];
 * :fillArray(arr);
 * :printArray(arr);
 * :swapElement(arr, 0, 9);
 * :printArray(arr);
 * :multiplyByTwo(arr);
 * :printArray(arr);
 * stop
 * @enduml
 */

#include <iostream>
#include <cstdlib>   
#include <ctime>     

/**
 * @brief Заполняет массив случайными числами от 0 до 99
 * 
 * @param arr Ссылка на массив из 10 целых чисел
 * @return void
 */
void fillArray(int (&arr)[10]) {  // int (&arr)[10] — ссылка на массив из 10 чисел
    // заполняем массив случайными числами
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
}

/**
 * @brief Выводит массив на экран через пробел
 * 
 * Использует range-based for (C++11) и auto для краткости.
 * 
 * @param arr Ссылка на массив из 10 целых чисел
 * @return void
 */
void printArray(int (&arr)[10]) {  // вывод на экран массива
    for (auto x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Меняет местами два элемента массива по индексам
 * 
 * @param arr Ссылка на массив из 10 целых чисел
 * @param i1  Ссылка на первый индекс
 * @param i2  Ссылка на второй индекс
 * @return void
 */
void swapElement(int (&arr)[10], int& i1, int& i2) {
    int temp = arr[i1];   // сохраняем значение из i1
    arr[i1] = arr[i2];    // в i1 кладём значение из i2
    arr[i2] = temp;       // во i2 кладём сохранённое
}

/**
 * @brief Умножает каждый элемент массива на 2
 * 
 * Использует range-based for с неконстантной ссылкой,
 * чтобы можно было изменять элементы.
 * 
 * @param arr Ссылка на массив из 10 целых чисел
 * @return void
 */
void multiplyByTwo(int (&arr)[10]) {
    for (int& x : arr) {
        x = x * 2;
    }
}

/**
 * @brief Главная функция программы
 * 
 * @return 0 при успешном завершении
 */
int main() {
    srand(time(0));

    int arr[10];  // массив из 10 чисел

    std::cout << "Задание 1\n\n";

    // Заполняем
    fillArray(arr);
    std::cout << "Массив: ";
    printArray(arr);

    // Меняем элементы 0 и 9 местами
    int a = 0;
    int b = 9;
    swapElement(arr, a, b);
    std::cout << "После обмена: ";
    printArray(arr);

    // Умножаем каждый элемент на 2
    multiplyByTwo(arr);
    std::cout << "После умножения: ";
    printArray(arr);

    return 0;
}