#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//x - cos(x) = 0
//Величины XN, XK и DX

const double eps = 0.00000001; // погрешность
double x,y,a,b;
// расчетная функция
double f_3(double x){
    return x - cos(x);
}
int main() {
    cout << "Введите начальное значение для аргумента: ";
    cin >> a;
    cout << "Введите конечное значение для аргумента: ";
    cin >> b;
        for ( x= a; x <= b; x += eps) {
            y = f_3(x);
            //cout << "y = " << y << endl;
            if (fabs(y) <= eps) {
                cout << "Метод простых итераций. Корень = " << x << endl;
                getchar();
                exit(0);
            }
        }


    return 0;
}

