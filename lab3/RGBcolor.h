#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#include <iostream>

class RGBColor {
private:
    int red;                
    int green;          
    int blue;              
    
    mutable int viewCount;  // Счётчик обращений mutable можно менять в const
    
    static int colorCount;  // Статический счётчик созданных цветов

public:
    // КОНСТРУКТОРЫ
    RGBColor();                             //(0 0 0)
    RGBColor(int r, int g, int b);          // Параметризованный
    explicit RGBColor(int brightness);      // серый цвет
    RGBColor(const RGBColor& other);        // Копирования
    
    //  ДЕСТРУКТОР
    ~RGBColor();                            // Уменьшает счётчик
    
    //  ГЕТТЕРЫ 
    int getRed() const;
    int getGreen() const;
    int getBlue() const;
    int getBrightness() const;              // Сумма каналов
    static int getColorCount();
    
    