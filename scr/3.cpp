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
