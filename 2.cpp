#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

// Функция для безопасного ввода чисел
double getValidInput(const string& prompt) {
    double value;
    cout << prompt;
    if (cin >> value && value > 0) {
        return value;
    }
    else {
        cout << "Ошибка: введено некорректное значение. Завершение программы.\n";
        exit(1);
    }
}

// Функция для вычисления третьей стороны по теореме косинусов
double calculateThirdSide(double a, double b, double angleRad) {
    return sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(angleRad));
}

// Функция для вычисления площади треугольника
double calculateArea(double a, double b, double angleRad) {
    return 0.5 * a * b * sin(angleRad);
}

// Функция для вычисления радиуса описанной окружности
double calculateCircumradius(double a, double b, double c, double area) {
    return (a * b * c) / (4 * area);
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Ввод данных с проверкой
    cout << "Введите данные треугольника:\n";
    double a = getValidInput("Сторона a = ");
    double b = getValidInput("Сторона b = ");
    double angle = getValidInput("Угол между сторонами (в градусах) = ");

    // Преобразование угла в радианы
    double angleRad = angle * M_PI / 180.0;

    // Вычисление третьей стороны
    double c = calculateThirdSide(a, b, angleRad);

    // Вычисление площади
    double area = calculateArea(a, b, angleRad);

    // Вычисление радиуса описанной окружности
    double radius = calculateCircumradius(a, b, c, area);

    // Вывод результатов
    cout << fixed << setprecision(4);
    cout << "\nРезультаты вычислений:\n";
    cout << "Третья сторона (c) = " << c << endl;
    cout << "Площадь треугольника = " << area << endl;
    cout << "Радиус описанной окружности = " << radius << endl;

    return 0;
}
