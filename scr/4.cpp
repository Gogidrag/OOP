/**
 * @file task4.cpp
 * @brief Задание 4: двумерный динамический массив (матрица)
 * 
 * Программа демонстрирует работу с двумерным динамическим
 * массивом: выделение памяти, заполнение, вывод с рамкой
 * и заголовком, освобождение памяти.
 * 
 * Реализованы функции:
 * - allocateMatrix — выделяет память под матрицу
 * - fillMatrix — заполняет случайными числами
 * - printMatrix — красивый вывод (с параметрами по умолчанию)
 * - freeMatrix — освобождает память
 * 
 * @author Gogidrag минаев дима 606 -42 
 * @date 2026
 * @version 1
 */

#include <iostream>
#include <string>    
#include <cstdlib>   
#include <ctime>    

using namespace std;

/**
 * @brief Выделяет память под двумерный массив (матрицу)
 * 
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @return int** Указатель на матрицу (все элементы = 0)
 */
int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];       // массив указателей
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]{};     // каждая строка обнулена
    }
    return matrix;
}

/**
 * @brief Заполняет матрицу случайными числами от 0 до 9
 * 
 * @param matrix Указатель на матрицу
 * @param rows   Количество строк
 * @param cols   Количество столбцов
 * @return void
 */
void fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

/**
 * @brief Выводит матрицу на экран с рамкой и заголовком
 * 
 * @param matrix       Указатель на матрицу
 * @param rows         Количество строк
 * @param cols         Количество столбцов
 * @param showBorders  Показывать ли рамку (по умолчанию true)
 * @param title        Заголовок (по умолчанию "Matrix")
 * @return void
 */
void printMatrix(int** matrix, int rows, int cols,
                 bool showBorders = true,
                 string title = "Matrix") {
    cout << "\n" << title << ":\n";

    if (showBorders) {
        for (int j = 0; j < cols * 3 + 2; j++) cout << "-";
        cout << "\n";
    }

    for (int i = 0; i < rows; i++) {
        if (showBorders) cout << "| ";
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "  ";
        }
        if (showBorders) cout << "|";
        cout << "\n";
    }

    if (showBorders) {
        for (int j = 0; j < cols * 3 + 2; j++) cout << "-";
        cout << "\n";
    }
}

/**
 * @brief Освобождает память матрицы
 * 
 * Сначала удаляются вложенные массивы (строки),
 * потом массив указателей.
 * 
 * @param matrix Указатель на матрицу
 * @param rows   Количество строк
 * @return void
 */
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];   // сначала строки
    }
    delete[] matrix;          // потом массив указателей
}

/**
 * @brief Главная функция программы
 * 
 * @return 0 при успешном завершении
 */
int main() {
    srand(time(0));   // инициализация генератора случайных чисел

    cout << "Задание 4\n";

    int rows = 3;
    int cols = 4;

    // Создаём и заполняем
    int** matrix = allocateMatrix(rows, cols);
    fillMatrix(matrix, rows, cols);

    // 1. Без доп. параметров
    printMatrix(matrix, rows, cols);

    // 2. С заголовком
    printMatrix(matrix, rows, cols, true, "Моя матрица");

    // 3. Без рамки
    printMatrix(matrix, rows, cols, false, "Без рамки");

    // Освобождаем
    freeMatrix(matrix, rows);

    return 0;
}