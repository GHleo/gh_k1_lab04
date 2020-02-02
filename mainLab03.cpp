#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double eps;// = 0.000001; // погрешность
double x,y,a,b;
int n,h,con;

// расчетная функция
double f_3(double x){
    if (con == 1) return x - cos(x);
    if (con == 2) return x - 10 * cos(x);
}
// производная функции
double dfx(double x) { return 1+sin(x); }
typedef double(*func)(double x); // задание типа function

double metodN(func f_3, func dfx, double x0) {
    n=0;
    double x1 = x0 - f_3(x0) / dfx(x0); // первое приближение
    while (fabs(x1 - x0) > eps) { // пока не достигнута точность 0.000001
        n++;
        x0 = x1;
        x1 = x0 - f_3(x0) / dfx(x0); // последующие приближения
    }
    cout << "x1 = " << x1 << endl;
    return x1;
}
void metodSI(double a) {
    int i;
    for (x = a; x <= 1; x += eps) {
        i += 1;
        y = f_3(x);
        if (fabs(y) <= eps) {
            cout << "Метод простых итераций. Корень = " << x << endl;
            cout << "Метод простых итераций. Количество итераций = " << i << endl;
            getchar();
            exit(0);
        }
    }
}
// Половинное деление
double metodHalf(double a, double b) {
    double half;
    half = (a + b) * 0.5;
    while ((fabs(a - b) > eps) && (f_3(half) != 0))
    {
        if (f_3(a) * f_3(half) < 0)
            b = half;
        else
            a = half;
        half = (a + b) / 2;
        h++;
    }
    return half;
}
int main() {
    int i=0;
    cout << "1-е Уравнение x - cos(x) = 0" << endl;
    cout << "2-е Уравнение x - 10cos(x) = 0" << endl;
    cout << "Введите конечное значение для уравнения, для 1-го = 1, для 2-го = 2: "<< endl;
    cin >> con;
    cout << "Введите погрешность 0.000001 или 0.00000001: "<< endl;
    cin >> eps;
    cout << "Введите начальное значение для аргумента: ";
    cin >> a;
    cout << "Введите конечное значение для аргумента: ";
    cin >> b;
    cout << "----------------------------------------------------------------------"<< endl;
    // Метод Ньютона
    cout << "Метод Ньютона. Корень = " << metodN(f_3, dfx, 1)<< endl;
    cout << "Метод Ньютона. Количество итераций = " << n << endl;
    cout << "----------------------------------------------------------------------"<< endl;
    // Метод Ньютона
    cout << "Метод половинного деления. Корень = " << metodHalf(a,b) << endl;
    cout << "Метод половинного деления. Количество итераций = " << h << endl;
    cout << "----------------------------------------------------------------------"<< endl;
    metodSI(a); // Метод простых итераций

    return 0;
}

