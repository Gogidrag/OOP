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

    // Создает копию и учитывает ее как новый объект.
    Polygon(const Polygon& other) : vertices(other.vertices) {
        totalPolygonsDefined++;
    }

    // Возвращает вершину, не изменяя фигуру.
    Point<T> getVertex(size_t i) const {
        return vertices[i];
    }

    // Вычисляет площадь по формуле Гаусса.
    // Складывает произведения соседних вершин.
    long double area() const {
        long double sum = 0;
        for (size_t i = 0; i < V; i++) {
            // После последней вершины возвращаемся к первой.
            size_t next = (i + 1) % V;
            sum += crossProduct(vertices[i], vertices[next]);
        }
        return abs(sum) / 2;
    }

    // Статический метод можно вызвать без создания объекта.
    static size_t getTotalPolygonsDefined() {
        return totalPolygonsDefined;
    }

    // friend разрешает внешней функции изменять private-поле vertices.
    friend void translate<T, V>(Polygon<T, V>& p, T dx, T dy);
};

// Каждый набор шаблонных параметров имеет отдельный счетчик.
template <typename T, size_t V>
size_t Polygon<T, V>::totalPolygonsDefined = 0;

// Полная специализация: отдельная версия класса для double и 4 вершин.
// Для нее считаем площадь без цикла и проверяем выпуклость.
template <>
class Polygon<double, 4> {
private:
    array<Point<double>, 4> vertices; // Четыре вершины.
    static size_t totalPolygonsDefined; // Счетчик четырехугольников.
public:
    // Создает четырехугольник.
    Polygon(const array<Point<double>, 4>& points) : vertices(points) {
        totalPolygonsDefined++;
    }

    // Создает копию четырехугольника.
    Polygon(const Polygon& other) : vertices(other.vertices) {
        totalPolygonsDefined++;
    }

    // Возвращает вершину четырехугольника.
    Point<double> getVertex(size_t i) const {
        return vertices[i];
    }

    // Развернутая формула Гаусса без цикла.
    long double area() const {
        long double ab = crossProduct(vertices[0], vertices[1]);
        long double bc = crossProduct(vertices[1], vertices[2]);
        long double cd = crossProduct(vertices[2], vertices[3]);
        long double da = crossProduct(vertices[3], vertices[0]);
        return abs(ab + bc + cd + da) / 2;
    }

    // Проверяет строгую выпуклость четырехугольника.
    // Все повороты должны иметь одинаковый ненулевой знак.
    bool isConvex() const {
        bool positive = false;
        bool negative = false;
        for (size_t i = 0; i < 4; i++) {
            Point<double> a = vertices[i];
            Point<double> b = vertices[(i + 1) % 4];
            Point<double> c = vertices[(i + 2) % 4];
            // Координаты двух соседних сторон AB и BC.
            long double ax = a.x, ay = a.y;
            long double bx = b.x, by = b.y;
            long double cx = c.x, cy = c.y;
            Point<long double> ab = {bx - ax, by - ay};
            Point<long double> bc = {cx - bx, cy - by};
            long double turn = crossProduct(ab, bc);
            if (turn == 0) return false; // Три точки на одной прямой.
            if (turn > 0) positive = true;
            if (turn < 0) negative = true;
        }
        // Если есть и правые, и левые повороты, фигура не выпуклая.
        return !(positive && negative);
    }