#include <iostream>
#include <cstdlib>
#include <ctime>
void fillArray(int(&arr)[10]){ //int arr 10 ssilka na masiv iz 10 chisel
    // заполняем массив случайными числами 
    for (int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
    }
}
