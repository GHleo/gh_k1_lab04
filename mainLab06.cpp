#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//определяем новый пользовательский тип, PF - указатель на функцию
typedef void (*PF)(int);

// Функция 1 (f1 = x)
double f_x(double x) {
    return x;
}

// Функция 2 (f2 = sin(22 * x))
double f_sin(double x) {
    return sin(22 * x);
}

// Функция 3 (f3 = x^4)
double f_pow(double x) {
    return pow(x,4);
}

// Функция 4 (f4 = arctg(x))
double f_arctg(double x) {
    return atan(x);
}
