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
// КОНСТРУКТОР КОПИРОВАНИЯ
RGBColor::RGBColor(const RGBColor& other)
    : red(other.red), green(other.green), blue(other.blue), viewCount(0)
{
    ++colorCount;
    std::cout << "✅ Создан цвет (копия). Всего: " << colorCount << "\n";
}

// ДЕСТРУКТОР
RGBColor::~RGBColor() {
    --colorCount;
    std::cout << "🗑️  Удалён цвет. Осталось: " << colorCount << "\n";
}

// ГЕТТЕРЫ
int RGBColor::getRed() const { return red; }
int RGBColor::getGreen() const { return green; }
int RGBColor::getBlue() const { return blue; }
int RGBColor::getBrightness() const { return red + green + blue; }
int RGBColor::getColorCount() { return colorCount; }

// ПРЕФИКСНЫЙ ++
RGBColor& RGBColor::operator++() {
    if (red < 255) ++red;
    if (green < 255) ++green;
    if (blue < 255) ++blue;
    return *this;
}

// ПОСТФИКСНЫЙ ++
RGBColor RGBColor::operator++(int) {
    RGBColor old = *this;   // копия ДО изменения
    ++(*this);              // используем префиксный
    return old;
}

// ПРЕФИКСНЫЙ --
RGBColor& RGBColor::operator--() {
    if (red > 0) --red;
    if (green > 0) --green;
    if (blue > 0) --blue;
    return *this;
}

// ПОСТФИКСНЫЙ --
RGBColor RGBColor::operator--(int) {
    RGBColor old = *this;
    --(*this);
    return old;
}

// ОПЕРАТОР +=
RGBColor& RGBColor::operator+=(const RGBColor& other) {
    red += other.red;
    green += other.green;
    blue += other.blue;
    
    // Обрезаем до 255
    if (red > 255) red = 255;
    if (green > 255) green = 255;
    if (blue > 255) blue = 255;
    
    return *this;
}

// ОПЕРАТОР -=
RGBColor& RGBColor::operator-=(const RGBColor& other) {
    red -= other.red;
    green -= other.green;
    blue -= other.blue;
    
    // Обрезаем до 0
    if (red < 0) red = 0;
    if (green < 0) green = 0;
    if (blue < 0) blue = 0;
    
    return *this;
}

// ОПЕРАТОР *=
RGBColor& RGBColor::operator*=(int factor) {
    red *= factor;
    green *= factor;
    blue *= factor;
    
    if (red > 255) red = 255;
    if (green > 255) green = 255;
    if (blue > 255) blue = 255;
    
    return *this;
}

// ОПЕРАТОР /=
RGBColor& RGBColor::operator/=(int factor) {
    // Проверка деления на 0
    if (factor == 0) {
        std::cout << "❌ Ошибка: деление на 0\n";
        return *this;
    }
    red /= factor;
    green /= factor;
    blue /= factor;
    return *this;
}

// БИНАРНЫЙ + (через +=)
RGBColor operator+(RGBColor lhs, const RGBColor& rhs) {
    lhs += rhs;     // используем уже написанный +=
    return lhs;
}

// БИНАРНЫЙ - (через -=)
RGBColor operator-(RGBColor lhs, const RGBColor& rhs) {
    lhs -= rhs;
    return lhs;
}

// БИНАРНЫЙ * (через *=)
RGBColor operator*(RGBColor lhs, int factor) {
    lhs *= factor;
    return lhs;
}

// БИНАРНЫЙ / (через /=)
RGBColor operator/(RGBColor lhs, int factor) {
    lhs /= factor;
    return lhs;
}
