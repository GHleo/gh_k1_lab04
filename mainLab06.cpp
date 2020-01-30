#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// определяем структуру для печати таблицы результатов (из методички)
struct I_print{	//данные для печати результатов интегрирования
    char* name;//название функции
    double i_sum;	//значение интегральной суммы
    double i_toch;	//точное значение интеграла
    int n;	//число разбиений области интегрирования при котором достигнута требуемая точность
};

// Функция для печати таблицы результатов (из методички)
void PrintTabl(I_print i_prn[],int k)
{
    const int m=4;//число столбцов таблицы
    int wn[m]={12,18,18,18};//ширина столбцов таблицы
    char *title[m]={"Function","Integral","IntSum","N "};
    int size[m];
    for(int i=0;i<m;i++)
        size[i]=strlen(title[i]);
//шапка таблицы
    cout<<char(124)<<setfill(char(61));
    for(int j=0;j<m-1;j++)
        cout<<setw(wn[j])<<char(124);
    cout<<setw(wn[m-1])<<char(124)<<endl;

    cout<<char(124);
    for(int j=0;j<m;j++)
        cout<<setw((wn[j]-size[j])/2)<<setfill(' ')<<' '<<title[j]
            <<setw((wn[j]-size[j])/2)<<char(124);
    cout<<endl;
    for(int i=0;i<k;i++)
    {//заполнение таблицы
        cout<<char(124)<<fixed;
        for(int j=0;j<m-1;j++)
            cout<<setfill(char(126))<<setw(wn[j])<<char(124);
        cout<<setw(wn[m-1])<<char(124)<<setfill(' ')<<endl;

        cout<<char(124)<<setw((wn[0]-strlen(i_prn[i].name))/2)<<' '<<i_prn[i].name
            <<setw((wn[0]-strlen(i_prn[i].name))/2)<<char(124);
        cout<<setw(wn[1]-1)<<setprecision(10)<<i_prn[i].i_toch<<char(124)
            <<setw(wn[2]-1)<<i_prn[i].i_sum<<setprecision(6)<<char(124)
            <<setw(wn[3]-1)<<i_prn[i].n<<char(124)<<endl;
    }
//низ таблицы
    cout<<char(126)<<setfill(char(126));
    for(int j=0;j<m-1;j++)
        cout<<setw(wn[j])<<char(126);
    cout<<setw(wn[m-1])<<char(126)<<setfill(' ')<<endl;
}

//определяем новый пользовательский тип, PF - указатель на функцию
typedef void (*PF)(int);

// Функция 1 (f1 = x)
double f_1(double x) {
    return x;
}

// Функция 2 (f2 = sin(22 * x))
double f_2(double x) {
    return sin(22 * x);
}

// Функция 3 (f3 = x^4)
double f_3(double x) {
    return pow(x,4);
}

// Функция 4 (f4 = arctg(x))
double f_4(double x) {
    return atan(x);
}

// Вычисление интеграла методом прямоугольников
double f_InRect(PF f, double a, double b, double eps, int& n) {
    n = 1;
    double s1, s2, dx = b - a, x = a + dx / 2.0;
    s1 = f(x) * dx;
    do {
        if (n > 1) s1 = s2;
        n *= 2;
        s2 = 0;
        x = a + dx / (2.0 * n);
        for (int i = 0; i < n; ++i) {
            s2 += f(x) * (dx / n);
            x = x + dx / n;
        }
    } while (fabs(s1 - s2) > eps);
    return s2;
}

int main()
{
 double a,b;
      I_print arr[4];

      // Ввод границ интервала
      cout << "Введите границы интервалов -> \n";
      cin >> a >> b;

      // Заполнение столбец Function
      arr[0].name = "x ";
      arr[1].name = "sin22x";
      arr[2].name = "x^4 ";
      arr[3].name = "arctgx";

      // Заполняем столбец Integral, задаем точное значение интеграла
      arr[0].i_toch = (b * b - a * a) / 2.0;
      arr[1].i_toch = (cos(a * 22.0) - cos(b * 22.0)) / 22.0;
      arr[2].i_toch = (b * b * b * b * b - a * a * a * a * a) / 5.0;
      arr[3].i_toch = b * atan(b) - a * atan(a) - (log(b * b + 1) - log(a * a + 1)) / 2.0;

    // Метод прямоугольников
    printf("Rectangle method, %.6f <= x <= %.6f\n", a, b);

    double eps[5] = { 1e-2, 1e-3, 1e-4, 1e-5, 1e-6 };
    for (int p = 0; p < 5; ++p) {
        cout << "Eps = " << eps[p] << endl;
        for (int i = 0; i < 4; ++i) {
            if (i == 0) arr[i].i_sum = IntRect(f_1, a, b, eps[p], arr[i].n);
            else if (i == 1) arr[i].i_sum = IntRect(f_2, a, b, eps[p], arr[i].n);
            else if (i == 2) arr[i].i_sum = IntRect(f_3, a, b, eps[p], arr[i].n);
            else  arr[i].i_sum = IntRect(f_4, a, b, eps[p], arr[i].n);
        }

      PrintTabl(arr, 4);

    return 0;
        };