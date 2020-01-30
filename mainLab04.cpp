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
    const double gRatio = (1 + sqrt(5)) / 2; // "Золотое" число
    double x, XN, XK, DX; //x -аргумент функции; XN, XK - начальное и конечное значение для аргумента соответсвенно; DX - шаг
    double aa,bb,eps; //концы отрезка и точность
    double d1,d2, do1,do2; // Точки, делящие текущий отрезок в отношении золотого сечения

    cout << "Вычисления для функции: 1 – x + x3/6 – x5/120 –sin(x)" << endl;
    cout << "Введите начальное значение для аргумента: " << endl;
    cin >> XN;
    cout << "Введите конечное значение для аргумента: " << endl;
    cin >> XK;
    cout << "Введите шаг: "<< endl;
    cin >> DX;

    cout << "Аргумент" << setw(18) << "Значение" <<  endl; //форматирование заголовка таблицы
    for (double x = XN; x <= XK; x += DX) {
       cout << setw(10) << left << x;//манипулятор setw(int n) - задаем ширину столбца для аргумента
       cout.width(18);// cout.width - задаем ширину столбца для значения (член функции)
       cout << setprecision(10) << f_24(x) << endl;// задаем точность после запятой
    }
//Нахождение экстремумов функции
    cout << "----------------------------------" << endl;
/*    cout << "Вводим границу поиска [a, b] " << endl;
    cout<<"a = "<< endl;
    cin>>a;
    cout<<"b = "<< endl;
    cin>>b;*/
    cout<<"Введите точность eps = "<< endl;
    cin>>eps;

//Нахождение минимума функции
    //Шаг определяем по точности вычислений
    //DX = (b - a)*(eps/10);//Мин шаг точность/10
/*    aa = XN;
    bb = XK;
    double min = f_24(aa);
    //eps = fabs(a - b) / 100; //делим отрезок на 100 частей
    for (aa += eps; aa <= bb; aa += eps)
    {
        if (f_24(aa) < min)
            min = f_24(aa);
    }
    cout << "min = " << min << endl;*/

   // поиск корня
   int i=0;
        while (DX > 0.000001) {
            i = XN;
            while (i <= XK) {
                if (f_24(i) > 0) {
                    XN = i - DX;
                    break;
                }
                i += DX;
            }
            DX = DX / 10;
        }

    cout << "Корень функции = " << XN << endl;


    return 0;
    }




