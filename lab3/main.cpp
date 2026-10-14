#include "RGBColor.h"
#include <iostream>

int main() {
    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout << "║   ЛАБА 3: RGBColor (вариант 9)      ║\n";
    std::cout << "╚══════════════════════════════════════╝\n\n";
    
    // : 3 КОНСТРУКТОРА 
    std::cout << "=== ЭТАП 1: СОЗДАНИЕ (3 конструктора) ===\n\n";
    RGBColor c1;
    RGBColor c2(100, 150, 200);
    RGBColor c3(c2);
    RGBColor c4(120);
    
    std::cout << "\n--- Начальное состояние ---\n";
    c1.printInfo();
    c2.printInfo();
    c3.printInfo();
    c4.printInfo();
    
    // УНАРНЫЕ
    std::cout << "\n=== ЭТАП 2: УНАРНЫЕ ОПЕРАЦИИ ===\n\n";
    std::cout << "c2 до: ";
    c2.printInfo();
    
    ++c2;
    std::cout << "++c2: ";
    c2.printInfo();
    
    c2++;
    std::cout << "c2++: ";
    c2.printInfo();
    
    --c2;
    std::cout << "--c2: ";
    c2.printInfo();
    
    c2--;
    std::cout << "c2--: ";
    c2.printInfo();
     
    //  += -= *= /= 
    std::cout << "\n=== ЭТАП 3: АРИФМЕТИЧЕСКОЕ ПРИСВАИВАНИЕ ===\n\n";
    RGBColor t1(50, 50, 50);
    RGBColor t2(30, 30, 30);
    
    std::cout << "t1: ";
    t1.printInfo();
    
    t1 += t2;
    std::cout << "t1 += t2: ";
    t1.printInfo();
    
    t1 -= t2;
    std::cout << "t1 -= t2: ";
    t1.printInfo();
    
    t1 *= 2;
    std::cout << "t1 *= 2: ";
    t1.printInfo();
    
    t1 /= 2;
    std::cout << "t1 /= 2: ";
    t1.printInfo();
    
    // БИНАРНЫЕ 
    std::cout << "\n=== ЭТАП 4: БИНАРНЫЕ ОПЕРАЦИИ ===\n\n";
    RGBColor a(10, 20, 30);
    RGBColor b(40, 50, 60);
    
    RGBColor s = a + b;
    std::cout << "a + b: ";
    s.printInfo();
    
    RGBColor d = b - a;
    std::cout << "b - a: ";
    d.printInfo();
    
    RGBColor m = a * 3;
    std::cout << "a * 3: ";
    m.printInfo();
    
    RGBColor q = b / 2;
    std::cout << "b / 2: ";
    q.printInfo();
    