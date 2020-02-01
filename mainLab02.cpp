#include <iostream>
#include <iomanip>
#include<cmath>
#include <ctime>
using namespace std;


int fact(int n) {

    if (n < 0)

        return 0;

    if (n == 0)

        return 1;

    else

        return n * fact(n - 1);

}

int main() {
    setlocale(LC_ALL, "RUS");

    cout << "x" << "  " << "Y(x)" << " " << "S(x)" << "  "  << "n" << endl;

    //float s, y,  k, d;
    // s - сумма Тейлора; d- факториал; k - значение предыдущего члена
    long double x,t,s,y,eps=0.000001;
    int  n;

    for (x = 0.0; x <= 1.0; x += 0.2) {
        n = 1; //порядковый номер в формуле
        s = x;
        t = 1.0;

        while (fabs(t) >= eps) {
            cout << "в цикле while fabs(t) = "<< fabs(t) << " x = " << x <<endl;
            t = pow(-1, n) * ((2 * pow(n, 2) + 1)/fact(2*n)) * (pow(x, 2 * n));//ряд Тейлора
            s += t;

            cout.precision(8);
            cout << "в цикле while смотим  n = "<< n << " и t = " << t << " и s =" << s <<endl;
            n += 1;
        }

        y = 1 - (pow(x, 2) / 2) * cos(x) - (x / 2) * sin(x);//вычисление функции

        cout.setf(ios::fixed);

        cout.precision(1);

        cout << x << " ";

        cout.setf(ios::fixed);

        cout.precision(6);

        cout << y << " " << s << " ";

        cout.setf(ios::fixed);

        cout.precision(0);

        cout << n << endl;

    }

    return 0;
}