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
    delete[] arr;   // delete  потому что массив

    //  ПЕРЕКЛЮЧАЕМ указатель на новый массив 
    arr = newArr;

    //  ОБНОВЛЯЕМ размер 
    size = newSize;
}

int main() {
    cout << "Задание 2\n\n";

    int N;
    cout << "Размер массива: ";
    cin >> N;

    // Выделяем память 
    int* arr = new int[N]{};   //  обнуляем массив

    // Заполняем 
    cout << "Введи " << N << " чисел:\n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    //ыводим исходный 
    cout << "\nИсходный: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    
    process(arr, N);
     process(arr, N);

    // выводим 
    cout << "Результат: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    //  освобождаем память 
    delete[] arr;

    // обнуляем указатель 
    arr = nullptr;

    //Проверка
    if (arr == nullptr) {
        cout << "\nУказатель обнулён — безопасно\n";
    }

    return 0;
}











