#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

typedef double(*TPF)(double);

struct I_print {
	string name;
	double i_sum;
	double i_toch;
	int n;

};


// Печать таблицы
void PrintTabl(I_print i_prn[], int k)
{
	const int m = 4;
	int wn[m] = { 12,18,18,10 };
	string title[m] = { "Function" ,"Integral" ,"IntSum" ,"N " };
	int size[m];
	for (int i = 0; i < m; i++)
		size[i] = title[i].length();

	cout << char(218) << setfill(char(196));
	for (int j = 0; j < m - 1; j++)
		cout << setw(wn[j]) << char(194);
	cout << setw(wn[m - 1]) << char(191) << endl;
	cout << char(179);
	for (int j = 0; j < m; j++)
		cout << setw((wn[j] - size[j]) / 2) << setfill(' ') << ' ' << title[j]
		<< setw((wn[j] - size[j]) / 2) << char(179);
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		cout << char(195) << fixed;
		for (int j = 0; j < m - 1; j++)
			cout << setfill(char(196)) << setw(wn[j]) << char(197);
		cout << setw(wn[m - 1]) << char(180) << setfill(' ') << endl;
		cout << char(179) << setw((wn[0] - (i_prn[i].name).length()) / 2) << ' ' << i_prn[i].name
			<< setw((wn[0] - (i_prn[i].name).length()) / 2) << char(179);

		cout << setw(wn[1] - 1) << setprecision(10) << i_prn[i].i_toch << char(179)
			<< setw(wn[2] - 1) << i_prn[i].i_sum << setprecision(6) << char(179)
			<< setw(wn[3] - 1) << i_prn[i].n << char(179) << endl;
	}

	cout << char(192) << setfill(char(196));
	for (int j = 0; j < m - 1; j++)
		cout << setw(wn[j]) << char(193);
	cout << setw(wn[m - 1]) << char(217) << setfill(' ') << endl;
}

// Функция #1 (f1 = x)
double fx(double x) {
	return x;
}

// Функция #2 (f2 = sin(22 * x))
double fsin(double x) {
	return sin(22 * x);
}

// Функция #3 (f3 = x^4)
double fpow(double x) {
	return x * x * x * x;
}

// Функция #4 (f4 = arctg(x))
double farctg(double x) {
	return atan(x);
}

// Вычисление интеграла методом прямоугольников
double IntRect(TPF f, double a, double b, double eps, int& n) {
	n = 1;
	double s1, s2, dx = b - a, x = a + dx / 2.0;
	s1 = f(x) * dx;
	do {
		if (n > 1) s1 = s2;
		n *= 2;
		s2 = 0;
		x = a + dx / (2.0 * n);
		for (int i = 0; i < n; ++i) {
			s2 += f(x) * (dx / n);
			x = x + dx / n;
		}
	} while (fabs(s1 - s2) > eps);
	return s2;
}

// Вычисление интеграла методом трапеций
double IntTrap(TPF f, double a, double b, double eps, int& n) {
	n = 4;
	double s1 = (f(a) + f(b)) / 2.0, s2 = f((a + b) / 2.0);
	double s = 1, sn = 101;
	while (fabs(sn - s) > eps) {
		sn = s;
		double dx = (b - a) / n;
		for (int i = 0; i < n / 2; ++i) {
			s1 += f(a + (2 * i + 1) * dx);
		}
		s = dx * (s1 + s2);
		n *= 2;
	}
	return s;

}

//Основное тело программы 
void solve() {
	// Заполнение шапки таблицы
	I_print arr[4];
	arr[0].name = "x ";
	arr[1].name = "sin22x";
	arr[2].name = "x^4 ";
	arr[3].name = "arctgx";
	double a, b;

	// Ввод границ интервала
	cout << "Enter a and b values\n";
	cin >> a >> b;

	arr[0].i_toch = (b * b - a * a) / 2.0;
	arr[1].i_toch = (cos(a * 22.0) - cos(b * 22.0)) / 22.0;
	arr[2].i_toch = (b * b * b * b * b - a * a * a * a * a) / 5.0;
	arr[3].i_toch = b * atan(b) - a * atan(a) - (log(b * b + 1) - log(a * a + 1)) / 2.0;

	// Метод прямоугольников
	printf("Rectangle method, %.6f <= x <= %.6f\n", a, b);

	double eps[5] = { 1e-2, 1e-3, 1e-4, 1e-5, 1e-6 };
	for (int p = 0; p < 5; ++p) {
		cout << "Eps = " << eps[p] << endl;
		for (int i = 0; i < 4; ++i) {
			if (i == 0) arr[i].i_sum = IntRect(fx, a, b, eps[p], arr[i].n);
			else if (i == 1) arr[i].i_sum = IntRect(fsin, a, b, eps[p], arr[i].n);
			else if (i == 2) arr[i].i_sum = IntRect(fpow, a, b, eps[p], arr[i].n);
			else  arr[i].i_sum = IntRect(farctg, a, b, eps[p], arr[i].n);
		}
		PrintTabl(arr, 4);
		cout << endl;
	}


	// Метод трапеций
	printf("Trapezoidal method, %.6f <= x <= %.6f\n", a, b);

	for (int p = 0; p < 5; ++p) {
		cout << "Eps = " << eps[p] << endl;
		for (int i = 0; i < 4; ++i) {
			if (i == 0) arr[i].i_sum = IntTrap(fx, a, b, eps[p], arr[i].n);
			else if (i == 1) arr[i].i_sum = IntTrap(fsin, a, b, eps[p], arr[i].n);
			else if (i == 2) arr[i].i_sum = IntTrap(fpow, a, b, eps[p], arr[i].n);
			else  arr[i].i_sum = IntTrap(farctg, a, b, eps[p], arr[i].n);
		}
		PrintTabl(arr, 4);
		cout << endl;
	}
}

int main()
{
	solve();
	return 0;
}