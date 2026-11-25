// Лабораторная 5. Многоугольники, C++14.
// В файле сначала идет число вершин, затем их координаты X и Y.
// Вершины должны идти по порядку вдоль границы фигуры, без пересечений.
#include <iostream>
#include <fstream>
#include <array>
#include <type_traits>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <cstddef>
using namespace std;

// Точка на плоскости.
template <typename T>
struct Point {
    T x; // Координата X.
    T y; // Координата Y.
};

// Вычисляет часть формулы Гаусса: x1*y2 - x2*y1.
template <typename T>
long double crossProduct(Point<T> a, Point<T> b) {
    // Преобразуем координаты до умножения для точности.
    long double x1 = a.x, y1 = a.y;
    long double x2 = b.x, y2 = b.y;
    return x1 * y2 - x2 * y1;
}

// Объявления нужны, чтобы класс мог указать функцию friend.
template <typename T, size_t V> class Polygon;
template <typename T, size_t V>
void translate(Polygon<T, V>& p, T dx, T dy);

// Шаблонный класс: T — тип координат, V — количество вершин.
// V — нетиповой параметр, его значение известно при компиляции.
template <typename T, size_t V>
class Polygon {
    // static_assert проверяет тип и число вершин еще при компиляции.
    // Разрешаем числа, кроме bool.
    static_assert(is_arithmetic<T>::value && !is_same<T, bool>::value,
                  "Coordinates must be numeric");
    // Для многоугольника нужно минимум три вершины.
    static_assert(V >= 3, "Minimum 3 vertices");
private:
    array<Point<T>, V> vertices; // Массив из V точек.
    static size_t totalPolygonsDefined; // Общий счетчик для объектов с одинаковыми T и V.
public:
    // Сохраняет вершины и увеличивает счетчик.
    Polygon(const array<Point<T>, V>& points) : vertices(points) {
        totalPolygonsDefined++;
    }