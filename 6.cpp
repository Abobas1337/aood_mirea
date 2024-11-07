#include <iostream>
#include <climits>

using namespace std;


void in(int*& arr, int& n);
void out(int* arr, int n);
int lastnegativ(int* arr, int n);
void removelastbm(int*& arr, int& n);



void in(int*& arr, int& n) {
    cout << "Введите количество элементов (n <= 100): ";
    cin >> n;

    if (n > 100 or n <= 0) 
    {
        cout << "Неверное количество элементов." << endl;
        return 1;
    }

    arr = new int[n];
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> arr[i];
    }
}


void out(int* arr, int n) 
{
    if (n == 0) {
        cout << "Массив пуст." << endl;
        return;
    }

    cout << "Массив: ";
    for (int i = 0; i < n; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int lastnegativ(int* arr, int n) 
{
    int lastNegativeIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            lastNegativeIndex = i;
        }
    }
    return lastNegativeIndex;
}


void removelastbm(int*& arr, int& n) 
{
    int maxElement = INT_MIN;
    for (int i = 0; i < n; ++i) 
    {
        if (arr[i] > maxElement) 
        {
            maxElement = arr[i];
        }
    }

    int newSize = n;
    for (int i = 0; i < n; ++i) 
    {
        if (arr[i] == maxElement and i > 0) 
        {
            newSize--;
        }
    }

    int* newArr = new int[newSize];
    int j = 0;
    for (int i = 0; i < n; ++i) 
    {
        if (i > 0 and arr[i] == maxElement) 
        {
            continue;
        }
        newArr[j++] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    n = newSize;
}

int main() 
{

    int* arr = nullptr;
    int n = 0;
    int choice;

    do 
    {
        cout << "1. Ввод массива" << endl;
        cout << "2. Вывод массива" << endl;
        cout << "3. Поиск номера последнего отрицательного элемента" << endl;
        cout << "4. Удаление числа перед каждым максимальным числом" << endl;
        cout << "5. Завершение работы" << endl;
        cout << "Выберите пункт меню: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                in
            (arr, n);
                break;
            case 2:
                out(arr, n);
                break;
            case 3:
                cout << "Номер последнего отрицательного элемента: " << lastnegativ(arr, n) << endl;
                break;
            case 4:
                removelastbm(arr, n);
                break;
            case 5:
                cout << "Завершение работы программы." << endl;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }; while (choice != 5);

    delete[] arr;
    return 0;
}
