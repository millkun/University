#include <iostream>
#include <windows.h>
using namespace std;
int* Resize(int* a, int oldSize, int newSize) { //функция изменения размера массива
    int* tmp = new int[newSize];
    memset(tmp, 0, sizeof(int) * newSize);
    copy(a, a + min(oldSize, newSize), tmp);
    delete[] a;
    return tmp;
}
int main() {
    setlocale(LC_ALL, "rus");
    int input = 1, size = 1, rsize = 0, i; // Объявление переменных
    int* matrix = new int[size];// Создание массива
    while (input != 0) {
        cin >> input; // Ввод значения 
        rsize++; // Увеличиваем 
        if (matrix == nullptr) {
            cout << "Ошибка выделения памяти";
            delete[] matrix;
            input = 0;
        }
        matrix[rsize - 1] = input;
        if (size == rsize and input != 0) {
            matrix = Resize(matrix, size, size * 2); // Удвоение размера массива
            size *= 2;
            cout << "Память выделена. Новый размер массива: " << size << endl;
        }
    }
    cout << "Введенный массив:" << endl; //Вывод массива
    copy(matrix, matrix + size, ostream_iterator<int>(cout, " ")); // Копирование элементов из массива в вывод с пробелом-разделителем
    cout << endl;
    delete[] matrix; //освобождение памяти
    return 0;
}