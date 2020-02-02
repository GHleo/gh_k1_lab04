#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//24. 1 – x + x3/6 – x5/120 –sin(x)
//Величины XN, XK и DX

// расчетная функция
double f_24(double x){
    return 1 - x + pow(x,3)/6 - pow(x,5)/120 - sin(x);
}
// Половинное деление
double metodHalf(double a, double b, double eps) {
    double half;
    int h;
    half = (a + b) * 0.5;
    while ((fabs(a - b) > eps) && (f_24(half) != 0))
    {
        if (f_24(a) * f_24(half) < 0)
            b = half;
        else
            a = half;
        half = (a + b) / 2;
        h++;
    }
    return half;
}

int main() {
    double x, XN, XK, DX, eps; //x -аргумент функции; XN, XK - начальное и конечное значение для аргумента соответсвенно; DX - шаг

    cout << "Вычисления для функции: 1 – x + x3/6 – x5/120 –sin(x)" << endl;
    cout << "Введите начальное значение для аргумента: " << endl;
    cin >> XN;
    cout << "Введите конечное значение для аргумента: " << endl;
    cin >> XK;
    cout << "Введите шаг: "<< endl;
    cin >> DX;

    cout << "Аргумент" << setw(18) << "Значение" <<  endl; //форматирование заголовка таблицы
    for (double x = XN; x <= XK; x += DX) {
       cout << setw(10) << left << x;//манипулятор setw(int n) - задаем ширину столбца для аргумента
       cout.width(18);// cout.width - задаем ширину столбца для значения (член функции)
       cout << setprecision(10) << f_24(x) << endl;// задаем точность после запятой
    }
    cout << "----------------------------------" << endl;
    cout<<"Введите точность eps = "<< endl;
    cin>>eps;

    cout << "Корень функции = " << metodHalf(XN, XK,eps) << endl;

    return 0;
    }




