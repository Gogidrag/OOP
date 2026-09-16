#include <iostream>
using namespace std;

void process(int*& arr, int& size) {

    //  ПОИСК первый отрицательный 
    int negIndex = -1;   // -1 = не нашли
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            negIndex = i;
            break;   // как ашли  выходим из цикла
        }
    }
    if (negIndex == -1) {
        cout << "Отрицательных элементов нет\n";
        return;
    }

    // Вывод на какой позиции нашли
   cout << "Первый отрицательный на позиции " << negIndex << "\n";

    //  СОЗДАЁМ новый массив 
    int newSize = negIndex;              
    int* newArr = new int[newSize]{};    // бнуляем элементы

    for (int i = 0; i < newSize; i++) {
        newArr[i] = arr[i];
    }

    //  ОСВОБОЖДАЕМ старую память 
    delete[] arr;   // delete[], потому что массив

    //  ПЕРЕКЛЮЧАЕМ указатель на новый массив 
    arr = newArr;

    //  ОБНОВЛЯЕМ размер 
    size = newSize;
}











}
