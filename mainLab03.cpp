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

double solve(function f_3, function dfx, double x0) {
    double x1 = x0 - f_3(x0) / dfx(x0); // первое приближение
    int k;
    while (fabs(x1 - x0) > eps) { // пока не достигнута точность 0.000001
        k++;
        x0 = x1;
        x1 = x0 - f_3(x0) / dfx(x0); // последующие приближения
    }
}
int main() {
    i=0;
    int iter;
    double root;
    cout << "Введите начальное значение для аргумента: ";
    cin >> a;
    cout << "Введите конечное значение для аргумента: ";
    cin >> b;
        for ( x= a; x <= b; x += eps) {
            i += 1;
            y = f_3(x);
            if (fabs(y) <= eps) {
                cout << "Метод простых итераций. Корень = " << x << endl;
                cout << "Метод простых итераций. Количество итераций = " << i << endl;
                getchar();
                exit(0);
            }
        }


   // printf("%f\n", solve(f_3, dfx, 1)); // вывод на экран
    cout << "Метод Ньютона. Корень = " << solve(f_3, dfx, 1)<< endl;
    cout << "Метод Ньютона. Количество итераций = " << k << endl;

/*    x = a;
    while(eps < fabs(f_3(x)) && x <= b)
        cout << fabs(f_3(x));
        x += 0.1;
    if(b < x)
        cout<<"[a;b] Корней нет\r\n";
    else
    {
        cout<<"Корень      : "<<x<<"\r\n";
        cout<<"Точность e : "<<fabs(f_3(x))<<"\r\n";
    }
    cout<<"Нажмите Y для нового ввода\r\n";*/


    return 0;
}

