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