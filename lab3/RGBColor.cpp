#include "RGBColor.h"

/**
 * @brief Инициализация статического поля
 */
int RGBColor::colorCount = 0;

/**
 * @brief Конструктор по умолчанию (0,0,0)
 */
RGBColor::RGBColor()
    : red(0), green(0), blue(0), viewCount(0)
{
    ++colorCount;
    std::cout << "✅ Создан цвет по умолчанию (0,0,0). Всего: " << colorCount << "\n";
}

/**
 * @brief Параметризованный конструктор
 * @param r Красный (0-255)
 * @param g Зелёный (0-255)
 * @param b Синий (0-255)
 */
RGBColor::RGBColor(int r, int g, int b)
    : red(r), green(g), blue(b), viewCount(0)
{
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

/**
 * @brief Explicit-конструктор (серый)
 * @param brightness Яркость (0-255)
 */
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

/**
 * @brief Конструктор копирования
 * @param other Копируемый объект
 */
RGBColor::RGBColor(const RGBColor& other)
    : red(other.red), green(other.green), blue(other.blue), viewCount(0)
{
    ++colorCount;
    std::cout << "✅ Создан цвет (копия). Всего: " << colorCount << "\n";
}

/**
 * @brief Деструктор
 */
RGBColor::~RGBColor() {
    --colorCount;
    std::cout << "🗑️  Удалён цвет. Осталось: " << colorCount << "\n";
}

int RGBColor::getRed() const { return red; }
int RGBColor::getGreen() const { return green; }
int RGBColor::getBlue() const { return blue; }
int RGBColor::getBrightness() const { return red + green + blue; }
int RGBColor::getColorCount() { return colorCount; }

/**
 * @brief Префиксный ++
 * @return Ссылка на изменённый объект
 */
RGBColor& RGBColor::operator++() {
    if (red < 255) ++red;
    if (green < 255) ++green;
    if (blue < 255) ++blue;
    return *this;
}

/**
 * @brief Постфиксный ++
 * @return Копия ДО изменения
 */
RGBColor RGBColor::operator++(int) {
    RGBColor old = *this;
    ++(*this);
    return old;
}

/**
 * @brief Префиксный --
 */
RGBColor& RGBColor::operator--() {
    if (red > 0) --red;
    if (green > 0) --green;
    if (blue > 0) --blue;
    return *this;
}

/**
 * @brief Постфиксный --
 */
RGBColor RGBColor::operator--(int) {
    RGBColor old = *this;
    --(*this);
    return old;
}

/**
 * @brief Сложение с присваиванием
 * @param other Другой цвет
 */
RGBColor& RGBColor::operator+=(const RGBColor& other) {
    red += other.red;
    green += other.green;
    blue += other.blue;
    
    if (red > 255) red = 255;
    if (green > 255) green = 255;
    if (blue > 255) blue = 255;
    
    return *this;
}

/**
 * @brief Вычитание с присваиванием
 * @param other Другой цвет
 */
RGBColor& RGBColor::operator-=(const RGBColor& other) {
    red -= other.red;
    green -= other.green;
    blue -= other.blue;
    
    if (red < 0) red = 0;
    if (green < 0) green = 0;
    if (blue < 0) blue = 0;
    
    return *this;
}

/**
 * @brief Умножение на число
 * @param factor Множитель
 */
RGBColor& RGBColor::operator*=(int factor) {
    red *= factor;
    green *= factor;
    blue *= factor;
    
    if (red > 255) red = 255;
    if (green > 255) green = 255;
    if (blue > 255) blue = 255;
    
    return *this;
}

/**
 * @brief Деление на число
 * @param factor Делитель (не 0)
 */
RGBColor& RGBColor::operator/=(int factor) {
    if (factor == 0) {
        std::cout << "❌ Ошибка: деление на 0\n";
        return *this;
    }
    red /= factor;
    green /= factor;
    blue /= factor;
    return *this;
}

/**
 * @brief Бинарный + (через +=)
 */
RGBColor operator+(RGBColor lhs, const RGBColor& rhs) {
    lhs += rhs;
    return lhs;
}

/**
 * @brief Бинарный - (через -=)
 */
RGBColor operator-(RGBColor lhs, const RGBColor& rhs) {
    lhs -= rhs;
    return lhs;
}

/**
 * @brief Бинарный * (через *=)
 */
RGBColor operator*(RGBColor lhs, int factor) {
    lhs *= factor;
    return lhs;
}

/**
 * @brief Бинарный / (через /=)
 */
RGBColor operator/(RGBColor lhs, int factor) {
    lhs /= factor;
    return lhs;
}

/**
 * @brief Меньше (по яркости)
 */
bool RGBColor::operator<(const RGBColor& other) const {
    return getBrightness() < other.getBrightness();
}

/**
 * @brief Больше (по яркости)
 */
bool RGBColor::operator>(const RGBColor& other) const {
    return getBrightness() > other.getBrightness();
}

/**
 * @brief Меньше или равно
 */
bool RGBColor::operator<=(const RGBColor& other) const {
    return getBrightness() <= other.getBrightness();
}

/**
 * @brief Больше или равно
 */
bool RGBColor::operator>=(const RGBColor& other) const {
    return getBrightness() >= other.getBrightness();
}

/**
 * @brief Равенство (по каналам)
 */
bool RGBColor::operator==(const RGBColor& other) const {
    return red == other.red && green == other.green && blue == other.blue;
}

/**
 * @brief Неравенство (через ==)
 */
bool RGBColor::operator!=(const RGBColor& other) const {
    return !(*this == other);
}

/**
 * @brief Вывести информацию (увеличивает mutable viewCount)
 */
void RGBColor::printInfo() const {
    ++viewCount;
    
    std::cout << "RGB(" << red << ", " << green << ", " << blue << ")"
              << " | Яркость: " << getBrightness()
              << " | Просмотров: " << viewCount << "\n";
}

/**
 * @brief Проверка корректности (каналы 0-255)
 */
bool RGBColor::isValid() const {
    return red >= 0 && red <= 255
        && green >= 0 && green <= 255
        && blue >= 0 && blue <= 255;
}