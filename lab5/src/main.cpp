/**
 * @file main.cpp
 * @brief Лабораторная работа №5. Геометрические примитивы (вариант 7).
 * @details Программа читает 10 фигур из файла, считает площадь и центроид,
 * проверяет выпуклость четырехугольников и перемещает фигуры.
 * Стандарт языка — C++14.
 * @note Вершины задаются по порядку вдоль границы без самопересечений.
 */
// Лабораторная 5. Многоугольники, C++14.
// В файле сначала идет число вершин, затем их координаты X и Y.
// Вершины должны идти по порядку вдоль границы фигуры, без пересечений.
#include <iostream>
#include <fstream>
#include <array>
#include <type_traits> // Проверка типов в шаблонном классе.
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <cstddef>
using namespace std;

// Точка на плоскости.
/**
 * @brief Точка с двумя координатами на плоскости.
 * @tparam T Тип координат, например int или double.
 */
template <typename T>
struct Point {
    /// Координата по горизонтали.
    T x; // Координата X.
    /// Координата по вертикали.
    T y; // Координата Y.
};

// Вычисляет часть формулы Гаусса: x1*y2 - x2*y1.
/**
 * @brief Вычисляет выражение x1*y2 - x2*y1.
 * @details Используется в формуле площади, центроида и при проверке поворота сторон.
 * @tparam T Тип координат.
 * @param a Первая точка или вектор.
 * @param b Вторая точка или вектор.
 * @return Знаковое векторное произведение.
 */
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

// Шаблонный класс позволяет использовать один код для int, double и других числовых типов.
// T — тип координат, V — нетиповой параметр (число вершин известно при компиляции).
/**
 * @brief Шаблонный класс многоугольника с фиксированным числом вершин.
 * @details Хранит вершины в массиве, считает площадь и число созданных объектов.
 * static_assert запрещает неподходящие типы и число вершин меньше трех.
 * @tparam T Числовой тип координат (кроме bool).
 * @tparam V Количество вершин; задается при компиляции.
 */
template <typename T, size_t V>
class Polygon {
    // Ограничение типов: is_arithmetic из type_traits проверяет, что T — числовой тип.
    // bool исключаем отдельно. Если тип не подходит, static_assert остановит компиляцию.
    static_assert(is_arithmetic<T>::value && !is_same<T, bool>::value,
                  "Coordinates must be numeric");
    // static_assert также запрещает создавать фигуры с числом вершин меньше трех.
    static_assert(V >= 3, "Minimum 3 vertices");
private:
    /// Массив вершин фиксированного размера.
    array<Point<T>, V> vertices; // V задает фиксированный размер массива.
    /// Накопленный счетчик объектов для данной комбинации T и V.
    static size_t totalPolygonsDefined; // Статическое поле: одно на все объекты с одинаковыми T и V.
public:
    /**
     * @brief Создает многоугольник и увеличивает счетчик.
     * @param points Массив из V вершин.
     */
    // Сохраняет вершины и увеличивает счетчик.
    Polygon(const array<Point<T>, V>& points) : vertices(points) {
        totalPolygonsDefined++;
    }

    /**
     * @brief Создает новый объект с такими же координатами.
     * @param other Исходный многоугольник.
     */
    // Создает копию и учитывает ее как новый объект.
    Polygon(const Polygon& other) : vertices(other.vertices) {
        totalPolygonsDefined++;
    }

    /**
     * @brief Возвращает координаты выбранной вершины.
     * @param i Индекс вершины (от 0 до V-1).
     * @return Точка с координатами X и Y.
     */
    // Возвращает вершину, не изменяя фигуру.
    Point<T> getVertex(size_t i) const {
        return vertices[i];
    }

    /**
     * @brief Вычисляет площадь по формуле Гаусса.
     * @details Складывает произведения соседних вершин, включая последнюю и первую.
     * Модуль суммы делится на два, чтобы площадь была неотрицательной.
     * @return Площадь фигуры.
     */
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

    /**
     * @brief Показывает, сколько объектов данного T и V было создано.
     * @return Накопленное значение счетчика, включая копии.
     */
    // Статическая функция возвращает счетчик; вызывается через имя класса, без объекта.
    static size_t getTotalPolygonsDefined() {
        return totalPolygonsDefined;
    }

    /**
     * @brief Предоставляет функции translate доступ к закрытым вершинам.
     */
    // Дружественная шаблонная функция: friend дает translate доступ к закрытому массиву vertices.
    friend void translate<T, V>(Polygon<T, V>& p, T dx, T dy);
};

// Каждый набор шаблонных параметров имеет отдельный счетчик.
template <typename T, size_t V>
size_t Polygon<T, V>::totalPolygonsDefined = 0;

// Полная специализация шаблонного класса: для double и 4 вершин компилятор выбирает этот класс.
// Обычный шаблон здесь не используется: площадь считаем без цикла, добавляем проверку выпуклости.
/**
 * @brief Полная специализация класса для четырех вершин типа double.
 * @details Площадь вычисляется без цикла, поскольку число вершин известно заранее.
 * Дополнительно можно проверить строгую выпуклость.
 */
template <>
class Polygon<double, 4> {
private:
    /// Массив четырех вершин.
    array<Point<double>, 4> vertices; // Четыре вершины.
    /// Отдельный накопленный счетчик специализации.
    static size_t totalPolygonsDefined; // Счетчик четырехугольников.
public:
    /**
     * @brief Создает четырехугольник и увеличивает счетчик.
     * @param points Массив из четырех вершин.
     */
    // Создает четырехугольник.
    Polygon(const array<Point<double>, 4>& points) : vertices(points) {
        totalPolygonsDefined++;
    }

    /**
     * @brief Создает копию и учитывает ее как новый объект.
     * @param other Исходный четырехугольник.
     */
    // Создает копию четырехугольника.
    Polygon(const Polygon& other) : vertices(other.vertices) {
        totalPolygonsDefined++;
    }

    /**
     * @brief Возвращает выбранную вершину.
     * @param i Индекс вершины (от 0 до 3).
     * @return Точка с координатами типа double.
     */
    // Возвращает вершину четырехугольника.
    Point<double> getVertex(size_t i) const {
        return vertices[i];
    }

    /**
     * @brief Считает площадь по развернутой формуле Гаусса.
     * @details Вычисляет четыре слагаемых AB, BC, CD и DA напрямую, без цикла.
     * @return Площадь четырехугольника.
     */
    // Площадь четырехугольника считаем напрямую по четырем парам вершин, без цикла.
    long double area() const {
        long double ab = crossProduct(vertices[0], vertices[1]);
        long double bc = crossProduct(vertices[1], vertices[2]);
        long double cd = crossProduct(vertices[2], vertices[3]);
        long double da = crossProduct(vertices[3], vertices[0]);
        return abs(ab + bc + cd + da) / 2;
    }

    /**
     * @brief Проверяет, является ли четырехугольник строго выпуклым.
     * @details Для каждой тройки соседних вершин вычисляет векторное произведение
     * сторон. Если все повороты одного ненулевого знака, фигура строго выпуклая.
     * @return true — строго выпуклый; false — разные знаки или нулевой поворот.
     */
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

    /**
     * @brief Возвращает счетчик созданных четырехугольников.
     * @return Общее количество созданных объектов данной специализации, включая копии.
     */
    // Возвращает число созданных четырехугольников.
    static size_t getTotalPolygonsDefined() {
        return totalPolygonsDefined;
    }
    /**
     * @brief Предоставляет функции translate доступ к четырем закрытым вершинам.
     */
    // Для специализации тоже открываем доступ функции translate.
    friend void translate<double, 4>(Polygon<double, 4>& p, double dx, double dy);
};
size_t Polygon<double, 4>::totalPolygonsDefined = 0;

// Дружественная шаблонная функция: сдвигает все вершины на dx и dy.
// Площадь при этом не меняется.
/**
 * @brief Перемещает многоугольник по плоскости.
 * @details Прибавляет dx к X и dy к Y каждой вершины. Доступ к массиву
 * vertices открыт через friend. Форма и площадь при переносе сохраняются.
 * @tparam T Тип координат.
 * @tparam V Количество вершин.
 * @param[in,out] p Изменяемый многоугольник.
 * @param dx Смещение по X.
 * @param dy Смещение по Y.
 */
template <typename T, size_t V>
void translate(Polygon<T, V>& p, T dx, T dy) {
    for (size_t i = 0; i < V; i++) {
        p.vertices[i].x += dx;
        p.vertices[i].y += dy;
    }
}

// Глобальная шаблонная функция: считает центроид (центр площади), не являясь методом класса.
// Один и тот же алгоритм работает для разных типов координат и числа вершин.
/**
 * @brief Вычисляет центроид — центр площади фигуры.
 * @details Суммирует произведения соседних вершин по формуле Гаусса.
 * Каждую сумму для координат центра делит на утроенную знаковую сумму.
 * Даже при целых координатах вершин центр может быть дробным.
 * @tparam T Тип координат.
 * @tparam V Количество вершин.
 * @param p Исходный многоугольник.
 * @return Координаты центра типа long double.
 * @exception domain_error Если знаковая площадь равна нулю.
 */
template <typename T, size_t V>
Point<long double> calculateCentroid(const Polygon<T, V>& p) {
    long double sum = 0, centerX = 0, centerY = 0;
    for (size_t i = 0; i < V; i++) {
        Point<T> a = p.getVertex(i);
        Point<T> b = p.getVertex((i + 1) % V);
        long double cross = crossProduct(a, b);
        // Знаковая удвоенная площадь и суммы для центра.
        sum += cross;
        long double ax = a.x, ay = a.y;
        centerX += (ax + b.x) * cross;
        centerY += (ay + b.y) * cross;
    }
    if (sum == 0) throw domain_error("Нулевая площадь");
    // sum = 2 * знаковая площадь, поэтому делим на 3 * sum.
    return {centerX / (3 * sum), centerY / (3 * sum)};
}

// Общий вывод вершин, площади и центроида.
/**
 * @brief Выводит вершины, площадь и центроид.
 * @details Общая часть вывода, чтобы не повторять код в двух функциях printPolygon.
 * @tparam T Тип координат.
 * @tparam V Количество вершин.
 * @param p Многоугольник для вывода.
 */
template <typename T, size_t V>
void printBasic(const Polygon<T, V>& p) {
    cout << "Вершины: ";
    for (size_t i = 0; i < V; i++) {
        Point<T> point = p.getVertex(i);
        cout << "(" << point.x << "; " << point.y << ") ";
    }
    Point<long double> center = calculateCentroid(p);
    cout << "\nПлощадь: " << p.area();
    cout << "\nЦентроид: (" << center.x << "; " << center.y << ")\n";
}

// Вторая глобальная шаблонная функция: выводит данные многоугольника с любыми допустимыми T и V.
/**
 * @brief Универсальная шаблонная функция вывода фигуры.
 * @tparam T Тип координат.
 * @tparam V Количество вершин.
 * @param p Многоугольник для вывода.
 */
template <typename T, size_t V>
void printPolygon(const Polygon<T, V>& p) {
    printBasic(p);
}

// Явная специализация шаблонной функции printPolygon для double и 4 вершин.
// Компилятор выбирает ее вместо обычной функции, чтобы вывести еще и выпуклость.
/**
 * @brief Явная специализация функции вывода для Polygon<double, 4>.
 * @details Выводит общие характеристики, затем результат проверки выпуклости.
 * @param p Четырехугольник для вывода.
 */
template <>
void printPolygon<double, 4>(const Polygon<double, 4>& p) {
    printBasic(p); // Не повторяем общий код вывода.
    if (p.isConvex()) cout << "Выпуклый: Да\n";
    else cout << "Выпуклый: Нет\n";
}

// Шаблонная функция читает координаты одного объекта из файла и проверяет его перемещение.
/**
 * @brief Считывает один многоугольник и проверяет его работу.
 * @details Читает V пар координат, создает объект и выводит его характеристики.
 * Затем сдвигает фигуру на (2; 1) и повторно выводит результат.
 * @tparam T Тип координат.
 * @tparam V Количество вершин.
 * @param file Открытый файл, расположенный на первой координате фигуры.
 * @param number Порядковый номер фигуры.
 * @exception runtime_error Если координаты не удалось прочитать.
 */
template <typename T, size_t V>
void testPolygon(ifstream& file, int number) {
    array<Point<T>, V> points;
    // Считываем V пар координат X и Y из текстового файла.
    for (size_t i = 0; i < V; i++) {
        if (!(file >> points[i].x >> points[i].y))
            throw runtime_error("Ошибка чтения координат");
    }
    Polygon<T, V> p(points);
    cout << "\nМногоугольник №" << number << '\n';
    printPolygon(p);
    // Приводим сдвиг к типу T, чтобы подходил любому шаблону.
    translate(p, T(2), T(1));
    cout << "После перемещения (2; 1):\n";
    printPolygon(p);
}

// Открываем файл, считываем 10 фигур и проверяем работу функций.
/**
 * @brief Главная функция программы.
 * @details Открывает polygons.txt, считывает ровно 10 фигур и выбирает шаблон
 * по числу вершин: 3 — int, 4 и 5 — double. В конце выводит счетчики объектов.
 * @return 0 при успешной работе, 1 при ошибке.
 */
int main() {
    // Файловый ввод: исходные данные берем из polygons.txt, а не задаем в программе.
    ifstream file("polygons.txt");
    if (!file) {
        cerr << "Не удалось открыть polygons.txt\n";
        return 1;
    }
    cout << fixed << setprecision(2);
    try {
        // При запуске читаем ровно 10 объектов из файла и тестируем каждый.
        for (int i = 1; i <= 10; i++) {
            int count;
            if (!(file >> count)) throw runtime_error("Недостаточно объектов");
            // V известен при компиляции, поэтому выбираем готовый шаблон.
            if (count == 3) testPolygon<int, 3>(file, i);
            else if (count == 4) testPolygon<double, 4>(file, i);
            else if (count == 5) testPolygon<double, 5>(file, i);
            else throw runtime_error("Неверное число вершин");
        }
        // После десяти объектов проверяем, что в файле не осталось лишних данных.
        string extra;
        if (file >> extra) throw runtime_error("Лишние данные в файле");
    } catch (const exception& error) {
        cerr << "Ошибка: " << error.what() << '\n';
        return 1;
    }
    // Вызываем статические методы через имя класса, отдельно для каждого T и V.
    // Складываем счетчики, чтобы получить общее число созданных многоугольников.
    size_t triangles = Polygon<int, 3>::getTotalPolygonsDefined();
    size_t quads = Polygon<double, 4>::getTotalPolygonsDefined();
    size_t pentagons = Polygon<double, 5>::getTotalPolygonsDefined();
    cout << "\nТреугольников: " << triangles;
    cout << "\nЧетырехугольников: " << quads;
    cout << "\nПятиугольников: " << pentagons;
    cout << "\nВсего объектов: " << triangles + quads + pentagons << '\n';
    return 0;
}
