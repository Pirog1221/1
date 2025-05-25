#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

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

int main() {
    setlocale(LC_ALL, "Russian");

    int n, m;
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