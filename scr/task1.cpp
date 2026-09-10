#include <iostream>
#include <cstdlib>
#include <ctime>
void fillArray(int(&arr)[10]){ //int arr 10 ssilka na masiv iz 10 chisel
    // заполняем массив случайными числами 
    for (int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
    }
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

int main(){
    srand(time(0));
    int arr[10]; //10 massiv 4isel
    std::cout << "Task 1\n\n";

    fillArray(arr);
    std::cout << "Massiv";
    printArray(arr);

}