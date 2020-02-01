#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
using namespace std;

// Заполнение матрицы A
void InMatrA(double** a, int N, int x) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (i == j)
                a[i][j] = 1;
            if (i < j)
                a[i][j] = pow(x, i) / pow(j, i);
            if (i > j)
                a[i][j] = pow(-x, i) / pow(j, i);
        }
}

// Функция распечатки матрицы A размеров N*M, ширина между столбцами w.
void outmatr(double** a, int n, int m, int w) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << setw(w) << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int n, x;

    cout << "Введите размерность N: ";
    cin >> n;
    cout << "Введите любое число x: ";
    cin >> x;

    // Создание матрицы A
    double** A = new double* [n];
    for (int j = 0; j < n; j++)
        A[j] = new double[n];

    InMatrA(A, n, x);

    outmatr(A, n, n, 15);


    return 0;
}

