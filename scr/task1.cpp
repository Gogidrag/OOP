#include <iostream>
#include <cstdlib>
#include <ctime>
void fillArray(int(&arr)[10]){ //int arr 10 ssilka na masiv iz 10 chisel
    // заполняем массив случайными числами 
    for (int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
    }
}
void printArray(int (&arr)[10]) { // вывод на экран массива 
    for (auto x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
// вывод на экран массива 
void swapElement(int(&arr)[10], int& i1,int& i2){
    for (auto x : arr){ // каждый элемент проходим
        std::cout << x << " ";
    }
    std::cout << std::endl;

}

void multiplyByTwo(int(&arr)[10]){
    for (int& x : arr){
        x = x * 2;
    }
}
int main() {
    srand(time(0));

    int arr[10];  // массив из 10 чисел

    std::cout << "Задание 1\n\n";

    // Заполняем
    fillArray(arr);
    std::cout << "Массив: ";
    printArray(arr);

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
