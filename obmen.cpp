#include <iostream>
#include <cmath>
#include <iostream>
using namespace std;

#define eps 0.000001
int k = 0;
double fx(double x) { return x-cos(x); } // вычисляемая функция
double dfx(double x) { return 1+sin(x); } // производная функции

typedef double(*function)(double x); // задание типа function

double solve(function fx, function dfx, double x0) {
    double x1 = x0 - fx(x0) / dfx(x0); // первое приближение
    while (fabs(x1 - x0) > eps) { // пока не достигнута точность 0.000001
        k++;
        x0 = x1;
        x1 = x0 - fx(x0) / dfx(x0); // последующие приближения
    }

    return x1;
}

int main() {
	printf("%f\n", solve(fx, dfx, 4)); // вывод на экран
	cout << k;
	return 0;
	

}




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






int main()
{
	setlocale(LC_ALL, "RUS");

	cout << "x" << " ";

	cout << "Y(x)" << " " << "S(x)" << " ";

	cout << "n" << endl;

	float s, y, t, k, d;

	double x;

	int i = 0, w;

	for (x = 0.0; x <= 1.0; x += 0.2) {

		w = 0; s = 0; k = 1.0;

		while (k >= 0.000001) {

			d = fact(2 * w );

			if (w != 0)
				
				 k = (((pow(-1, w ) * (2 * pow(w, 2) + 1) * (pow(x, 2 * w)))) / d) / ((pow(-1, w - 1) * (2 * pow(w-1, 2) + 1) * (pow(x, 2 * (w-1)))) / d);

			else

				k = 1;

			t = ((pow(-1, w ) * (2 * pow(w, 2) + 1) * (pow(x, 2 * w))) / d);

			s += t;

			w++;

		}

		y = (1-pow(x,2)/2)*cos(x)-(x/2)*sin(x);

		cout.setf(ios::fixed);

		cout.precision(1);

		cout << x << " ";

		cout.setf(ios::fixed);

		cout.precision(6);

		cout << y << " " << s << " ";

		cout.setf(ios::fixed);

		cout.precision(0);

		cout << w << endl;

		i++;

	}
