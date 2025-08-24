#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;
/**
 * @brief Создает двумерный динамический массив целых чисел
 * @param n Количество строк в массиве
 * @param m Количество столбцов в массиве
 * @return Указатель на созданный двумерный массив
 * @note Память выделяется в куче, необходимо освобождение с помощью freeArray()
 * @warning Все элементы массива инициализируются нулями
 */
int** createArray(int n, int m)

/**
 * @brief Заполняет массив случайными целыми числами в диапазоне [0, 99]
 * @param arr Указатель на двумерный массив для заполнения
 * @param n Количество строк в массиве
 * @param m Количество столбцов в массиве
 * @note Использует текущее время как seed для генератора случайных чисел
 * @warning Вызывает srand(time(0)), что влияет на все последующие вызовы rand()
 */
void fillRandom(int** arr, int n, int m)

/**
 * @brief Заполняет массив значениями, введенными пользователем с клавиатуры
 * @param arr Указатель на двумерный массив для заполнения
 * @param n Количество строк в массиве
 * @param m Количество столбцов в массиве
 * @note Запрашивает ввод для каждого элемента массива
 * @note Обрабатывает ошибки ввода, требуя корректные целые числа
 * @warning В случае ошибки ввода очищает флаги и буфер cin
 */
void fillManual(int** arr, int n, int m)

/**
 * @brief Выводит содержимое массива в табличном формате
 * @param arr Указатель на двумерный массив для вывода
 * @param n Количество строк в массиве
 * @param m Количество столбцов в массиве
 * @note Элементы выводятся через табуляцию, каждая строка с новой линии
 * @note Форматирование сохраняет выравнивание столбцов
 */
void printArray(int** arr, int n, int m)

/**
 * @brief Заменяет максимальный элемент в каждой строке массива на ноль
 * @param arr Указатель на двумерный массив для модификации
 * @param n Количество строк в массиве
 * @param m Количество столбцов в массиве
 * @note Для каждой строки находит максимальный элемент и устанавливает его в 0
 * @note Если в строке несколько максимальных элементов, заменяется первый из них
 * @note Использует линейный поиск максимального элемента
 */
void replaceMaxWithZero(int** arr, int n, int m) 

/**
 * @brief Вставляет строки из нулей перед строками, где первый элемент делится на 3
 * @param arr Указатель на двумерный массив для модификации
 * @param n Ссылка на количество строк в массиве (изменяется при вставке)
 * @param m Количество столбцов в массиве
 * @return Указатель на новый массив с добавленными строками
 * @note Выделяет новую память под массив с дополнительными строками
 * @note Освобождает память старого массива
 * @note Обновляет значение n до нового количества строк
 * @warning Старый массив освобождается, нельзя использовать после вызова функции
 */
int** insertZeroRows(int** arr, int& n, int m)

int main() {
    setlocale(LC_ALL, "Russian");
// Функция для создания массива
int** createArray(int n, int m) {
    int** arr = new int*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m]();
    }
    return arr;

// Функция для заполнения массива случайными числами
void fillRandom(int** arr, int n, int m) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand() % 100;
        }
    }
}

// Функция для заполнения массива с клавиатуры
void fillManual(int** arr, int n, int m) {
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
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
void printArray(int** arr, int n, int m) {
    cout << "Массив:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Функция для замены максимального элемента каждой строки нулем
void replaceMaxWithZero(int** arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        int max_index = 0;
        for (int j = 1; j < m; ++j) {
            if (arr[i][j] > arr[i][max_index]) {
                max_index = j;
            }
        }
        arr[i][max_index] = 0;
    }
}


// Функция для вставки строк из нулей перед строками, где первый элемент делится на 3
int** insertZeroRows(int** arr, int& n, int m) {
    int new_rows_count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i][0] % 3 == 0) {
            new_rows_count++;
        }
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
