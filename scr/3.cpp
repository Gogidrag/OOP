#include <iostream>
using namespace std;

struct SafeArray {
    int* data;  
    int size;   
};
SafeArray createArray(int size) {
    SafeArray arr;
    arr.size = size;
    arr.data = new int[size]{};   // {} — обнуляем
    return arr;
}
int& getElement(SafeArray& arr, int index) {
    static int dummy = 0; 

    if (index < 0 || index >= arr.size) {
        cout << "ОШИБКА: индекс " << index
             << " вне границ [0.." << arr.size - 1 << "]\n";
        return dummy;
    }
    return arr.data[index];
}
void printSafe(const SafeArray& arr) {
    cout << "[ ";
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i] << " ";
    }
    cout << "]\n";
}

void reSizeArray(SafeArray& arr, int newSize) {
    int* newData = new int[newSize]{};   // новый массив (обнулён)

    
    if (newSize < arr.size) {
        cout << "Удаляемые элементы: ";
        for (int i = newSize; i < arr.size; i++) {
            cout << arr.data[i] << " ";
        }
        cout << endl;
    }

    // Копируем
    int count = (newSize < arr.size) ? newSize : arr.size;
    for (int i = 0; i < count; i++) {
        newData[i] = arr.data[i];
    }

    delete[] arr.data;   // освобождаем старую память
    arr.data = newData;  // переключаем указатель
    arr.size = newSize;  // обновляем размер
}
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



