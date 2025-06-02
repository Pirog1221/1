#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

// Функция для безопасного ввода числа с проверкой
double getValidInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }
        cout << "Ошибка ввода! Пожалуйста, введите число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Функция для вычисления значения y
double calculateY(double x) {
    return 3 * x - 4 * log(x) - 5;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Табуляция функции y = 3x - 4ln(x) - 5\n";

    // Ввод параметров с проверкой
    double start = getValidInput("Введите начало интервала: ");
    double end = getValidInput("Введите конец интервала: ");
    double step = getValidInput("Введите шаг табуляции: ");

    // Проверка корректности введенных значений
    if (start > end) {
        cout << "Ошибка: начало интервала должно быть меньше или равно концу!\n";
        return 1;
    }
    if (step <= 0) {
        cout << "Ошибка: шаг должен быть положительным!\n";
        return 1;
    }

    // Вывод заголовка таблицы
    cout << "\nРезультаты табуляции:\n";
    cout << "----------------------------\n";
    cout << "    x    |    y(x)\n";
    cout << "----------------------------\n";

    // Табуляция функции
    cout << fixed << setprecision(2);
    for (double x = start; x <= end + numeric_limits<double>::epsilon(); x += step) {
        cout << setw(8) << x << " | ";

        // Проверка области определения с учетом точности double
        if (x <= numeric_limits<double>::epsilon()) {
            cout << "не определено (x ≤ 0)\n";
            continue;
        }

        // Вычисление и вывод значения функции
        try {
            double y = calculateY(x);
            if (isnan(y) {
                cout << "не определено\n";
            } else {
                cout << setw(10) << setprecision(6) << y << endl;
            }
        } catch (...) {
            cout << "ошибка вычисления\n";
        }
    }

    return 0;
}
