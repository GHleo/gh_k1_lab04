#include<cmath>
#include <iostream>
using namespace std;

const double eps = 0.00000001; // погрешность
	double f(double x)
	{
		return x-cos(x);
	}

/*	int main()
	{

	setlocale(LC_ALL, "russian");
	    double a, b, c;
		int k;
		a = 0;
		b = 10;
		k = 0;
		while (b - a > epsilon) {
			k += 1;
			
			c = (a + b) / 2;
			if (f(b) * f(c) < 0)
				a = c;
			else
				b = c;
		}
		cout << "x" <<"\t"<<"\t"<< setw(24) <<"кол-во итераций:"<< endl;
		cout << setprecision(8)<< setw(8) <<(a + b) / 2 <<"\t"<<"\t"<<k<< endl;
		return 0;
	}*/
int main() {
    setlocale(0, "");
    float a, b, e, x;
    int k = 0;
    cout << "1. y=3*cos(2*x+4)\n";
    cout << "Левая граница a=";
    cin >> a;
    cout << "Правая граница b=";
    cin >> b;
    cout << "Точность e=";
    cin >> e;
    x = (a + b) / 2;
    cout << "Корень уравнения:" << x;
    while (fabs(b - a) > e) {
        if (f(a) * f(x) <= 0) b = x;
        else a = x;
        x = (a + b) / 2;
        k++;
        cout << "\nТочность: " << fabs(b - a) << " Итерация №=" << k << " Корень уравнения: " << x;
    }
    cout << "\nКоличество итераций =" << k << "\nКорень уравнения: " << x;
    return 0;
}
// 1. делим отрезок пополам

