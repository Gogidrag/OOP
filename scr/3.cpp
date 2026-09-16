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



