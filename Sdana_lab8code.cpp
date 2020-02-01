#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
using namespace std;


// Вычисление факториалkа 
int fact(int n) {
	if (n == 0) return 1;
	if (n == 1) return 1;
	return n * fact(n - 1);
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

// Заполнение матрицы A
void InMatrA(double** a, int n, int x) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				a[i][j] = 1;
			if (i < j)
				a[i][j] = pow(x, i) / pow(fact(j), i);
			if (i > j)
				a[i][j] = pow(-x, i) / pow(fact(j), i);
		}
}

// Заполнение матрицы B
void InMatrB(double** b) {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			b[i][j] = i * 10 + j;
}

// Матрица A
void solveA() {
	system("mode con cols=5000");
	int n, x, YesNo;

	cout << "Введите n: ";
	cin >> n;
	cout << "Введите x: ";
	cin >> x;

	// Создание матрицы A
	double** A = new double* [n];
	for (int j = 0; j < n; j++)
		A[j] = new double[n];

	InMatrA(A, n, x);

	cout << "Использовать научный формат? (1 или 0): ";
	cin >> YesNo;
	if (YesNo == 0)
		cout << fixed << setprecision(8);
	outmatr(A, n, n, 15);
}

//Матрица B
void solveB() {

	// Создание матрицы B
	double** B = new double* [10];
	for (int j = 0; j < 10; j++)
		B[j] = new double[10];

	InMatrB(B);
	cout << endl;
	outmatr(B, 10, 10, 5);

	cout << B << "  " << B[0] << "  " << B[2] << endl;
	cout << B[0][0] << "  " << **B << "  " << *B[0] << endl;
	cout << *(*(B + 1)) << "  " << *B[1] << endl;
	cout << *(B[0] + 1) << "  " << *(*B + 1) << endl;
	cout << B[0][20] << "  " << *(B[0] + 20) << "  " << *B[2] << endl;

}

int main() {
	setlocale(LC_ALL, "russian");
	char AorB;
	cout << "C какой матрицей работать? (a / b): ";
	cin >> AorB;

	if ((AorB == 'B') || (AorB == 'b'))
		solveB();
	else
		solveA();

	system("pause");
	return 0;
}
