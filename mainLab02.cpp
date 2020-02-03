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
/*
	cout << "x" << "    " << "Y(x)" << "       " << "S(x)" << "  " << "n" << endl;

	//float s, y,  k, d;
	// s - сумма Тейлора; d- факториал; k - значение предыдущего члена
	double ii, x, t, s, y, eps = 0.000001;
	int  n;

	for (x = 0.0; x <= 1.0; x += 0.2) {
		n = 1; //порядковый номер в формуле
		s = x;
		t = 1.0;

		while (abs(t) > eps) {
			// cout << "в цикле while fabs(t) = "<< fabs(t) << " x = " << x <<endl;
			t = pow(-1, n) * ((2 * pow(n, 2) + 1) / (2 * fact(n))) * (pow(x, 2 * n));//ряд Тейлора
			s += t;

			cout.precision(8);
			//cout << "в цикле while смотим  n = "<< n << " и t = " << t << " и s =" << s <<endl;
			n += 1;
		}

		y = (1 - (pow(x, 2) / 2) * cos(x)) - ((x / 2) * sin(x));//вычисление функции
/*        cout << "cos(x) = "<< cos(x)  <<endl;
		ii = (pow(x, 2) / 2);
		cout << "(pow(x, 2) / 2) = "<< ii << endl;
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
	
	
	
	
	*/
	
	
	
	
	/*
	
	double n,y,i;
	cout << "введите кол-во илементов  " ;
	cin >> n;
	y = 0;
	i = 2;
	for (n; n > 0; n--)
	{
		y = y + pow(2 * n, 1. / i);
		i += 2;
	}
	cout <<"y = "<< y <<endl;
	
	*/
	
	
	
	
	
	
	
	
	
	
	
	/*
	
	int m, n, i,sum;
	sum = 0;
	i = 0;
	cout << "введите n и m" << endl;
	cin >>  n>>m;
	while (n > 0)
	{
		if ((i % 5 == 0) && ((i % m) != 0))
		{
			sum += i;
			n--;
		}
		i++;



	}
	cout << "сумма членов до n = "<<sum;
	
	
	
	
	*/



/*

	float a, s, k;

	s = 1;


	cout << "введите значение а "<<endl;
	cin >> a;
	if (a >= 0)
	{
		for (int i = 2; i <= 8; i += 2)
		{
			s = s * pow(i, 2);
		}

		cout << fixed << setprecision(1) << s - a << endl;

	}
	else
	{

		for (int i = 3; i <= 9; i += 3)
		{
			s = s * (i - 2);
		}
		cout << s << endl;
	}
	*/
	return 0;
}
