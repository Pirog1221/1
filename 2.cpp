#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>

using namespace std;


/**
 * @brief Получает числовое значение от пользователя с проверкой ввода
 * @return Введённое пользователем число
 * @throw invalid_argument Если ввод не является числом
 */
double getValue();

/**
 * @brief Проверяет, что значение является положительным числом
 * @param value Число для проверки
 * @throw invalid_argument Если значение меньше или равно нулю
 */
void checkValue(const double value);

/**
 * @brief Вычисляет евклидово расстояние между двумя точками на плоскости
 * @param x1 Координата X первой точки
 * @param y1 Координата Y первой точки
 * @param x2 Координата X второй точки
 * @param y2 Координата Y второй точки
 * @return Расстояние между точками (x1,y1) и (x2,y2)
 * @note Формула расчета: sqrt((x2-x1)² + (y2-y1)²)
 */
double calculateDistance(const double x1, const double y1, 
                        const double x2, const double y2);

/**
 * @brief Главная функция программы
 * @return 0 при успешном выполнении, 1 при ошибке
 * @details Программа запрашивает координаты двух точек и вычисляет расстояние между ними
 * с проверкой корректности вводимых данных
 */
int main() {
    setlocale(LC_ALL, "rus");

    try {
        cout << "Введите координаты первой точки (x1, y1):" << endl;
        double x1 = getValue();
        double y1 = getValue();
        
        cout << "Введите координаты второй точки (x2, y2):" << endl;
        double x2 = getValue();
        double y2 = getValue();

        // Проверка положительности координат
        checkValue(x1);
        checkValue(y1);
        checkValue(x2);
        checkValue(y2);

        double distance = calculateDistance(x1, y1, x2, y2);
        cout << "Расстояние между точками: " << distance << endl;
        
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "Неизвестная ошибка" << endl;
        return 1;
    }

    return 0;
}

double getValue() {
    double value = 0.0;
    cin >> value;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Ошибка: введено некорректное значение. Ожидается число.");
    }
    
    return value;
}


void checkValue(const double value) {
    if (value <= 0) {
        throw invalid_argument("Ошибка: значение должно быть положительным.");
    }
}

double calculateDistance(const double x1, const double y1, 
                        const double x2, const double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
