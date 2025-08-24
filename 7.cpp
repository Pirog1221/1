#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;
/**
 * @brief Создает двумерный массив (вектор векторов) заданного размера
 * @param n Количество строк в массиве
 * @param m Количество столбцов в массиве
 * @return Двумерный вектор целых чисел размером n x m
 * @note Все элементы массива инициализируются нулями
 */
vector<vector<int>> createArray(int n, int m)

/**
 * @brief Заполняет массив случайными целыми числами в диапазоне [0, 99]
 * @param arr Ссылка на двумерный вектор для заполнения
 * @note Использует текущее время как seed для генератора случайных чисел
 * @warning Вызывает srand(time(0)), что влияет на все последующие вызовы rand()
 */
void fillRandom(vector<vector<int>>& arr) 

/**
 * @brief Заполняет массив значениями, введенными пользователем с клавиатуры
 * @param arr Ссылка на двумерный вектор для заполнения
 * @note Запрашивает ввод для каждого элемента массива
 * @note Обрабатывает ошибки ввода, требуя корректные целые числа
 * @warning В случае ошибки ввода очищает флаги и буфер cin
 */
void fillManual(vector<vector<int>>& arr) 

/**
 * @brief Выводит содержимое массива в табличном формате
 * @param arr Константная ссылка на двумерный вектор для вывода
 * @note Элементы выводятся через табуляцию, каждая строка с новой линии
 * @note Форматирование сохраняет выравнивание столбцов
 */
void printArray(const vector<vector<int>>& arr) 

/**
 * @brief Заменяет максимальный элемент в каждой строке массива на ноль
 * @param arr Ссылка на двумерный вектор для модификации
 * @note Для каждой строки находит максимальный элемент и устанавливает его в 0
 * @note Если в строке несколько максимальных элементов, заменяется первый из них
 * @uses algorithm::max_element для поиска максимального элемента
 */
void replaceMaxWithZero(vector<vector<int>>& arr) 

/**
 * @brief Вставляет строки из нулей перед строками, где первый элемент делится на 3
 * @param arr Ссылка на двумерный вектор для модификации
 * @note Создает новый массив, вставляя перед подходящими строками строки нулей
 * @note Проверяет, что строка не пустая перед проверкой первого элемента
 * @note Размер вставляемой строки нулей соответствует размеру исходной строки
 * @return Модифицированный массив с добавленными строками нулей
 */
void insertZeroRows(vector<vector<int>>& arr) 

int main() {
    setlocale(LC_ALL, "Russian");
// Функция для создания массива
vector<vector<int>> createArray(int n, int m) {
    return vector<vector<int>>(n, vector<int>(m));
}

// Функция для заполнения массива случайными числами
void fillRandom(vector<vector<int>>& arr) {
    srand(time(0));
    for (auto& row : arr) {
        for (auto& elem : row) {
            elem = rand() % 100; // числа от 0 до 99
        }
    }
}

// Функция для заполнения массива с клавиатуры
void fillManual(vector<vector<int>>& arr) {
    cout << "Введите элементы массива:\n";
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = 0; j < arr[i].size(); ++j) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            while (!(cin >> arr[i][j])) {
                cout << "Ошибка! Введите целое число: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
}

// Функция для вывода массива
void printArray(const vector<vector<int>>& arr) {
    cout << "Массив:\n";
    for (const auto& row : arr) {
        for (const auto& elem : row) {
            cout << elem << "\t";
        }
        cout << "\n";
    }
}

// Функция для замены максимального элемента каждой строки нулем
void replaceMaxWithZero(vector<vector<int>>& arr) {
    for (auto& row : arr) {
        auto max_it = max_element(row.begin(), row.end());
        *max_it = 0;
    }
}

// Функция для вставки строк из нулей перед строками, где первый элемент делится на 3
void insertZeroRows(vector<vector<int>>& arr) {
    vector<vector<int>> newArr;
    for (const auto& row : arr) {
        if (!row.empty() && row[0] % 3 == 0) {
            newArr.push_back(vector<int>(row.size(), 0));
        }
        newArr.push_back(row);
    }
    arr = newArr;
}
    int n=0, m=0;
    cout << "Введите размеры массива (n m): ";
    cin >> n >> m;

    auto arr = createArray(n, m);

    char choice;
    cout << "Выберите способ заполнения (r - случайные, m - вручную): ";
    cin >> choice;

    if (choice == 'r') {
        fillRandom(arr);
    } else if (choice == 'm') {
        fillManual(arr);
    } else {
        cout << "Неверный выбор. Используются случайные числа.\n";
        fillRandom(arr);
    }

    printArray(arr);

    // Задание 1
    replaceMaxWithZero(arr);
    cout << "\nПосле замены максимальных элементов нулями:\n";
    printArray(arr);

    // Задание 2
    insertZeroRows(arr);
    cout << "\nПосле вставки строк из нулей:\n";
    printArray(arr);

    return 0;
}
