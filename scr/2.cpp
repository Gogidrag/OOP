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











}
