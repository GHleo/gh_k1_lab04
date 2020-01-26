https://yadi.sk/d/Uit3aQdNC_eeDA
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;

double eps;
int SI, NM, HD, A;


// Функция f(x)
double FX(double x)
{
    return(x - A * cos(x));
}

// Производная f'(x)
double DFX(double x)
{
    return(1 + A * sin(x));
}

// Простая итерация
double SimpleIt(double x, double eps) {
    double x0;
    do {
        x0 = x;
        x = A * cos(x0);
/*        cout << "x0 " << x0 << endl;
        cout << "x " << x << endl;*/
        SI++;
    } while (abs(x - x0) > eps && SI < 100000);
    return x;
}

// Половинное деление
double HalfDiv(double startpt, double endpt) {

    double halfpt;
    halfpt = (startpt + endpt) * 0.5;
    while ((fabs(endpt - startpt) > eps) && (FX(halfpt) != 0))
    {
        if (FX(startpt) * FX(halfpt) < 0)
            endpt = halfpt;
        else
            startpt = halfpt;
        halfpt = (startpt + endpt) / 2;
        HD++;
    }
    return halfpt;
}

// Метод Ньютона
double NewtonMet(double x0) {
    double x1 = x0 - FX(x0) / DFX(x0);
    while (abs(x1 - x0) > eps) {
        x0 = x1;
        x1 = x1 - FX(x1) / DFX(x1);
        NM++;
    }
    return x1;
}

void slove(double Leftpt, double Rightpt, double x) {
    cout << "Простая итерация";
    cout << setw(17) << "Метод Ньютона";
    cout << setw(25) << "Половинное деление" << endl;
    cout << SimpleIt(x, eps);
    cout << setw(20) << NewtonMet(x);
    cout << setw(20) << HalfDiv(Leftpt, Rightpt) << endl << endl;
    cout << "Количество шагов, методом " << endl;
    cout << "Простой итерации: " << SI << endl;
    cout << "Ньютона: " << NM << endl;
    cout << "Половинного деления: " << HD << endl;
}

int main()
{
    setlocale(LC_ALL, "russian");

    double Leftpt, Rightpt, x = 0;

    cout << "Укажите точность вычислений: ";
    cin >> eps;
    cout << "Введите границы интервала на Ox: " << endl;
    cin >> Leftpt >> Rightpt;

    for (int j = 0; j < 70; j++) cout << "_";
    cout << endl << "Для функции: x - cos(x) = 0" << endl << endl;
    A = 1;
    slove(Leftpt, Rightpt, x);

    for (int j = 0; j < 70; j++) cout << "_";
    cout << endl << endl << "Для функции: x - 10 * cos(x) = 0" << endl << endl;
    A = 10;
    slove(Leftpt, Rightpt, x);

    for (int j = 0; j < 70; j++) cout << "_";
    cout << endl << endl;

    system("pause");
    return 0;
}

