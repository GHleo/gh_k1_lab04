#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

// Функция для вычисления факториала
int factorial(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

// Функция для заполнение матрицы A размером N*N
void MatrA_fill(double** a, int N, int x) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (i == j)
                a[i][j] = 1;
            if (i < j)//для элементов лежащих выше главной диагонали
                a[i][j] = pow(x, i) / pow(factorial(j), i);
            if (i > j)//для элементов лежащих ниже главной диагонали
                a[i][j] = pow(-x, i) / pow(factorial(j), i);
        }
}

// Функция для заполнение матрицы B
void MatrB_fill(double** b) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            b[i][j] = i * 10 + j;
}

// Функция распечатки матрицы размером N*M
void Matr_print(double** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout <<setw(12) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n, x;
    char inAB;
    cout << "Введите размерность N: ";
    cin >> n;
    cout << "Введите любое число x: ";
    cin >> x;
    cout << endl;

    cout << "Введите название матрицы - А или B (латиницей): ";
    cin >> inAB;
    // Создание матрицы A
    if ((inAB == 'A') || (inAB == 'a')) {

        //Вспомогательный массив указателей на строки
        double **A = new double *[n];
        for (int j = 0; j < n; j++)
            A[j] = new double[n];

        MatrA_fill(A, n, x);
        Matr_print(A, n, n);
    }
    // Создание матрицы В
    if ((inAB == 'B') || (inAB == 'b')) {
        //Вспомогательный массив указателей на строки
        double** B = new double* [10];
        for (int j = 0; j < 10; j++)
            B[j] = new double[10];

        MatrB_fill(B);
        cout << endl;
        Matr_print(B, 10, 10);

        cout << B << "  " << B[0] << "  " << B[2] << endl;
        cout << B[0][0] << "  " << **B << "  " << *B[0] << endl;
        cout << *(*(B + 1)) << "  " << *B[1] << endl;
        cout << *(B[0] + 1) << "  " << *(*B + 1) << endl;
        cout << B[0][20] << "  " << *(B[0] + 20) << "  " << *B[2] << endl;

    }

    return 0;
}

