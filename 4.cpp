#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вычисления значения y
double calculateY(double x) {
    return 3 * x - 4 * log(x) - 5;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Ввод параметров табуляции
    double start, end, step;

    cout << "Табуляция функции y = 3x - 4ln(x) - 5\n";
    cout << "Введите начало интервала: ";
    cin >> start;
    cout << "Введите конец интервала: ";
    cin >> end;
    cout << "Введите шаг табуляции: ";
    cin >> step;

    // Проверка корректности ввода
    if (start > end) {
        cout << "Ошибка: начало интервала должно быть меньше конца!";
        return 1;
    }
    if (step <= 0) {
        cout << "Ошибка: шаг должен быть положительным!";
        return 1;
    }

    // Вывод заголовка таблицы
    cout << "\nРезультаты табуляции:\n";
    cout << "----------------------------\n";
    cout << "    x    |    y(x)\n";
    cout << "----------------------------\n";

    // Табуляция функции
    cout << fixed << setprecision(2);
    for (double x = start; x <= end + std::numeric_limits<double>::epsilon(); x += step) {
        cout << setw(8) << x << " | ";

        // Проверка области определения
        if (x <= std::numeric_limits<double>::epsilon()) {
            cout << "не определено (x ≤ 0)\n";
            continue;
        }

        // Вычисление и вывод значения функции
        double y = calculateY(x);
        cout << setw(10) << setprecision(6) << y << endl;
    }

    return 0;
}
