#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//11. 3sin(x) + x4 * [1 + (x–2/x) / (x+2/x)] * sin (x) -1
//Величины XN, XK и DX

// расчетная функция
double f_11(double x){
    return 3*sin(x) + x*4 * abs(1 + (x - 2/x) / (x + 2/x)) * sin(x) - 1;
}

int main() {
    double x, XN, XK, DX; //x -аргумент функции; XN, XK - начальное и конечное значение для аргумента соответсвенно; DX - шаг
    cout << "Введите начальное значение для аргумента: ";
    cin >> XN;
    cout << "Введите конечное значение для аргумента: ";
    cin >> XK;
    cout << "Введите шаг: ";
    cin >> DX;
    for (double x = XN; x <= XK; x += DX) {
        cout << fixed;//количеству знаков после запятой перед precision
        cout.precision(6);
        cout << f_11(x) << endl;
    }
    return 0;
    }


/*    double a, b, h;
    cin >> a >> b>> h;
    for (double x = a; x <= b; x += h) {
        cout << fixed << setprecision(3) <<x<< " " << 3 * sin(x) << endl;
    }
    return 0;*/


