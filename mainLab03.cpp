#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//x - cos(x) = 0
//Величины XN, XK и DX

// расчетная функция
double f_2(double x){
    return x - cos(x);
}
int main()
{
    double a,b,eps,x,dx;
    do
    {
        cout<<"Enter diapazone[a;b] of iterations\r\n";
        cout<<"a = ";cin>>a;
        cout<<"b = ";cin>>b;
        cout<<"Enter accuracy e ";cin>>eps;
        //Шаг определяем по точности вычислений
        //Погрешность f(x[i]) - f(x[i - 1]) < x[i] - x[i - 1] = h
        dx = (b - a)*(eps/10);//Мин шаг точность/10
        x = a;
        //Вычисления останавливаем когда добиваемся
        //требуемой точности вычислений eps < fabs(f(x))
        //или же достигаем конца промежутка
        while(eps < fabs(f_2(x)) && x <= b)
            x += dx;
        if(b < x)
            cout<<"[a;b] isn't contain roots\r\n";
        else
        {
            cout<<"root      : "<<x<<"\r\n";
            cout<<"acuracy e : "<<fabs(f_2(x))<<"\r\n";
        }
        cout<<"Press Y for new input\r\n";
    }
    while(toupper(getchar()) == 'Y');
    return 0;
}

