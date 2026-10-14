#include "RGBсolor.h"

// Инициализация статического поля
int RGBColor::colorCount = 0;

// КОНСТРУКТОР ПО УМОЛЧАНИЮ (0, 0, 0)
RGBColor::RGBColor()
    : red(0), green(0), blue(0), viewCount(0)
{
    ++colorCount;
    std::cout << "✅ Создан цвет по умолчанию (0,0,0). Всего: " << colorCount << "\n";
}

// ПАРАМЕТРИЗОВАННЫЙ КОНСТРУКТОР
RGBColor::RGBColor(int r, int g, int b)
    : red(r), green(g), blue(b), viewCount(0)
{
    // Обрезаем значения до 0-255
    if (red < 0) red = 0;
    if (red > 255) red = 255;
    if (green < 0) green = 0;
    if (green > 255) green = 255;
    if (blue < 0) blue = 0;
    if (blue > 255) blue = 255;
    
    ++colorCount;
    std::cout << "✅ Создан цвет (" << red << "," << green << "," << blue 
              << "). Всего: " << colorCount << "\n";
}

// EXPLICIT КОНСТРУКТОР (серый цвет)
RGBColor::RGBColor(int brightness)
    : red(brightness), green(brightness), blue(brightness), viewCount(0)
{
    if (red < 0) red = 0;
    if (red > 255) red = 255;
    green = red;
    blue = red;
    
    ++colorCount;
    std::cout << "✅ Создан серый цвет (" << red << "," << green << "," << blue 
              << "). Всего: " << colorCount << "\n";
}