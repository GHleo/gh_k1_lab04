#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//x - cos(x) = 0
//Величины XN, XK и DX

const double eps = 0.000001; // погрешность
double x,y,a,b;
int i,k;

// расчетная функция
double f_3(double x){return x - cos(x);}
double dfx(double x) { return 1+sin(x); } // производная функции
typedef double(*function)(double x); // задание типа function

double metN(function f_3, function dfx, double x0) {
    double x1 = x0 - f_3(x0) / dfx(x0); // первое приближение
    while (fabs(x1 - x0) > eps) { // пока не достигнута точность 0.000001
        k++;
        x0 = x1;
        x1 = x0 - f_3(x0) / dfx(x0); // последующие приближения
    }
    return x1;
}
double metSI(double beginV, double endV) {
	for (x = beginV; x <= endV; x += eps) {
		i += 1;
		y = f_3(x);
		if (fabs(y) <= eps) {
			cout << "Метод простых итераций. Корень = " << x << endl;
			cout << "ITER Метод простых итераций. Количество итераций = " << i << endl;
			getchar();
			exit(0);
		}
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	double XN;
	double XK = 0.8;
    i=0;


    cout << "Введите начальное значение для аргумента: ";
    cin >> a;
    cout << "Введите конечное значение для аргумента: ";
	cin >> b;
	XN = a;
	metSI(XN, XK);
	cout << "N Метод Ньютона. Корень = " << metN(f_3, dfx, 1) << endl;
	cout << "N Метод Ньютона. Количество итераций = " << k << endl;


			double a, b, c, e;
			a = 0;
			cin >> b;
			cin >> e;
			while (b - a > e) {
				c = (a + b) / 2;
				if (f(b) * f(c) < 0)
					a = c;
				else
					b = c;
			}
			cout << (a + b) / 2 << endl;


    return 0;
}
