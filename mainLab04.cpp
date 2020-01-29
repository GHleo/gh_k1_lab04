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
    double a,b,eps; //концы отрезка и точность
    double d1,d2; // Точки, делящие текущий отрезок в отношении золотого сечения

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
       //cout << '\t';
       cout.width(18);// cout.width - задаем ширину столбца для значения (член функции)
       cout << setprecision(10) << f_24(x) << endl;// задаем точность после запятой
    }
//Нахождение экстремумов функции
    cout << "----------------------------------" << endl;
    cout << "Вводим границу поиска [a, b] " << endl;
    cout<<"a = "<< endl;
    cin>>a;
    cout<<"b = "<< endl;
    cin>>b;
    cout<<"Введите точность eps = "<< endl;
    cin>>eps;
//Нахождение минимума функции
    //Шаг определяем по точности вычислений
    DX = (b - a)*(eps/10);//Мин шаг точность/10
    double min = f_24(a);
    //eps = fabs(a - b) / 100; //делим отрезок на 100 частей
    for (a += eps; a <= b; a += eps)
    {
        if (f_24(a) < min)
            min = f_24(a);
    }
    cout << "min = " << min << endl;

//Нахождение максимума функции, метод золотого сечения
/*
    1. На первом шаге исходный отрезок делим двумя симметричными относительно его центра точками и находим значение в этих точках.
    2. После чего тот из концов отрезка, к которому среди двух вновь поставленных точек ближе оказалась та, значение в которой минимально, откидываем.
    3. На следующем шаге следует найти всего одну новую точку.
    4. Повторяем до тех пор, пока не будет достигнута заданная точность.*/

    while (fabs(b - a) > eps) {
        d1 = b - (b - a) / gRatio;
        d2 = a + (b - a) / gRatio;
        if (f_24(d1) <= f_24(d2)) // Условие для поиска максимума
            a = d1;
        else
            b = d2;
    } // Выполняем, пока не достигнем заданной точности
    //cout << "(" << (a + b) / 2 << ", " << f_24((a + b) / 2) << ")"<< endl;
    cout << "Максимум: " << f_24((a + b) / 2) << endl;

    //Корни
    //Вычисления останавливаем когда добиваемся
    //требуемой точности вычислений eps < fabs(f(x))
    //или же достигаем конца промежутка
    x = a;
    while(eps < fabs(f_24(x)) && x <= b)
        x += DX;
    if(b < x)
        cout<<"[a;b] Корней нет\r\n";
    else
    {
        cout<<"Корень      : "<<x<<"\r\n";
        cout<<"Точность e : "<<fabs(f_24(x))<<"\r\n";
    }
    cout<<"Нажмите Y для нового ввода\r\n";

    while(toupper(getchar()) == 'Y');

    return 0;
    }




