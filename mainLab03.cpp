#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//x - cos(x) = 0
//Величины XN, XK и DX

const double eps = 0.00000001; // погрешность
double x,y,a,b;
int i;
// расчетная функция
double f_3(double x){
    return x - cos(x);
}
int main() {
    i=0;
    cout << "Введите начальное значение для аргумента: ";
    cin >> a;
    cout << "Введите конечное значение для аргумента: ";
    cin >> b;
        for ( x= a; x <= b; x += 0.001) {
            i += 1;
            y = f_3(x);
            if (fabs(y) <= eps) {
                cout << "Метод простых итераций. Корень = " << x << endl;
                cout << "Метод простых итераций. Количество итераций = " << i << endl;
                getchar();
                exit(0);
            }
        }



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

