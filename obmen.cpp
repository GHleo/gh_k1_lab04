#include<cmath>
#include <iostream>
using namespace std;

const double epsilon = 0.00000001;
	double f(double x)
	{
		return x-cos(x);
	}

	int main()
	{
		double a, b, c;
		int k;
		cin >> a >> b;
		k = 0;
		while (b - a > epsilon) {
			k += 1;
			c = (a + b) / 2;
			if (f(b) * f(c) < 0)
				a = c;
			else
				b = c;
		}
		cout << (a + b) / 2 << endl;
		return 0;
	}
