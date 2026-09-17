#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Выделение памяти под матрицу
int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}

// Заполнение матрицы случайными числами
void fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

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


// Освобождение памяти
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    srand(time(0));

    cout << "Задание 4\n";

    int rows = 3;
    int cols = 4;

    // Создаём и заполняем
    int** matrix = allocateMatrix(rows, cols);
    fillMatrix(matrix, rows, cols);

    //  Без доп. параметров
    printMatrix(matrix, rows, cols);

    // С заголовком
    printMatrix(matrix, rows, cols, true, "Моя матрица");

    // Без рамки
    printMatrix(matrix, rows, cols, false, "Без рамки");

    // Освобождаем
    freeMatrix(matrix, rows);

    return 0;
}
