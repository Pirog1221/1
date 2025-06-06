#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

/**
 * @brief Функция для безопасного ввода числа
 * @param prompt Приглашение для ввода
 * @return Введенное число
 * @note Завершает программу при некорректном вводе
 */
double getValidInput(const string& prompt) {
    double value = 0.0;  // Явная инициализация
    cout << prompt;
    
    if (!(cin >> value)) {
        cerr << "Ошибка ввода! Программа завершена.\n";
        exit(EXIT_FAILURE);
    }
    
    return value;
}

/**
 * @brief Вычисляет значение функции y = 3x - 4ln(x) - 5
 * @param x Аргумент функции
 * @return Значение функции
 * @note Для x ≤ 0 возвращает NAN
 */
double calculateY(double x) {
    if (x <= 0) return NAN;
    return 3 * x - 4 * log(x) - 5;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Табуляция функции y = 3x - 4ln(x) - 5\n";

    // Ввод параметров
    double start = getValidInput("Введите начало интервала: ");
    double end = getValidInput("Введите конец интервала: ");
    double step = getValidInput("Введите шаг табуляции: ");

    // Проверка корректности введенных значений
    if (start > end) {
        cerr << "Ошибка: начало интервала должно быть меньше или равно концу!\n";
        return EXIT_FAILURE;
    }
    if (step <= 0) {
        cerr << "Ошибка: шаг должен быть положительным!\n";
        return EXIT_FAILURE;
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
        
        double y = calculateY(x);
        if (isnan(y)) {
            cout << "не определено (x ≤ 0)\n";
        } else {
            cout << setw(10) << setprecision(6) << y << endl;
        }
    }

    return EXIT_SUCCESS;
}
