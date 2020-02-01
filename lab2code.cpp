#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;


//факториал
int fact(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return n * (fact(n - 1));
}

void num3() {
	int n;
	double s, k;
	cout << "x        Y(x)     S(x)     N\n";
	for (double x = 0; x <= 1; x += 0.2) {
		n = 1;
		s = x;
		k = 1;
		while (abs(k) > 0.000000001) {
			k = pow((-1), n) * ((pow(x, 2 * n + 1)) / (fact(2 * n + 1)));
			s += k;
			n += 1;
		}
		cout << fixed;
		cout.precision(6);
		cout << x << " " << sin(x) << " " << s << " " << n - 1 << "\n";
	}
}



int main() {
	setlocale(LC_ALL, "russian");
	num3();
	return 0;
}



