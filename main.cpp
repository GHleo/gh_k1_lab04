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
       cout << setw(18) << f_24(x) << endl;// << setw(18)<<endl;//манипулятор setw(int n) - задает ширину столбца для аргумента
       // cout << f_24(x) <<endl;

/*         cout << fixed;//количеству знаков после запятой перед precision
         cout.precision(13);
         cout <<f_24(x)<<endl;*/
    }

    return 0;
    }



