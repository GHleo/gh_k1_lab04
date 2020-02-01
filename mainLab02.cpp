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

    float s, y, t, k, d;
    // s - сумма Тейлора; d- факториал; k - значение предыдущего члена
    double x;
    int i = 0, n;
    for (x = 0.0; x <= 1.0; x += 0.2) {
        n = 0; //порядковый номер в формуле
        s = 0;
        k = 1.0;

        while (k >= 0.000001) {

            d = fact(2 * n);
            if (n != 0)
                k = (((pow(-1, n) * (2 * pow(n, 2) + 1) * (pow(x, 2 * n)))) / d) /
                    ((pow(-1, n - 1) * (2 * pow(n - 1, 2) + 1) * (pow(x, 2 * (n - 1)))) / d);

            else
              k = 1;
            t = ((pow(-1, n) * (2 * pow(n, 2) + 1) * (pow(x, 2 * n))) / d);//ряд Тейлора
            s += t;
            n++;
            cout << "в цикле while смотим  n = "<< n << " и k = " << k << endl;
        }

        y = (1 - pow(x, 2) / 2) * cos(x) - (x / 2) * sin(x);//вычисление функции

        cout.setf(ios::fixed);

        cout.precision(1);

        cout << x << " ";

        cout.setf(ios::fixed);

        cout.precision(6);

        cout << y << " " << s << " ";

        cout.setf(ios::fixed);

        cout.precision(0);

        cout << n << endl;

        i++;

    }

    return 0;
}