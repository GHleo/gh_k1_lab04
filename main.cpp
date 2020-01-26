#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//24. 1 – x + x3/6 – x5/120 –sin(x)
//Величины XN, XK и DX

// расчетная функция
double f_24(double x){
    return 1 - x + x*3/6 - x*5/120 - sin(x);
}

int main() {
    double x, XN, XK, DX; //x -аргумент функции; XN, XK - начальное и конечное значение для аргумента соответсвенно; DX - шаг
    double a,b; //концы отрезка
    cout << "Введите начальное значение для аргумента: ";
    cin >> XN;
    cout << "Введите конечное значение для аргумента: ";
    cin >> XK;
    cout << "Введите шаг: ";
    cin >> DX;
    //cout << "Аргумент" << setw(10) << "Значение"<< setw(15) << endl;
    for (double x = XN; x <= XK; x += DX) {

       cout  << setw(10) << x;//манипулятор setw(int n) - задает ширину столбца для аргумента
       //cout << '\t';
       cout.width(18);// cout.width - member function
       cout << setprecision(10) << f_24(x) << endl;// << setw(18) - задает ширину столбца для значения
    }

    cout << "Вводим границу поиска [a, b]" << endl;
    cin >> a >> b;
    double min = f_24(a);
    double eps = fabs(a - b) / 100; //

    for (a += eps; a <= b; a += eps)
    {
        if (f_24(a) < min)
            min = f_24(a);
    }

    cout << "min = " << min;
    return 0;
    }



