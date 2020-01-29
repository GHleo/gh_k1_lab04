/*#include &lt;time.h&gt; // time
#include &lt;stdlib.h&gt; // srand, rand
#include &lt;iostream&gt;*/
#include <iostream>
#include <ctime>
#include <stdio.h>

using namespace std;

double dRandom( int a, int b ) // вещественное из [a,b]
{
    return a + ( b - a ) * rand() / (double)RAND_MAX;
}

//функция вывода массима на печать
void m_out(int* a, int n) {
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}
//ункция вывода массима в обратном порядке на печать
void m_turn_out(int* a, int n) {
    for (int i = 1; i <= n / 2; i++)
        swap(a[i], a[n - i + 1]); //Процедура swap производит обмен значений двух объектов, & - ссылка на указатель а
}

void buble(int* a, int n) {
    int sravn = 0, perest = 0;
    for (int i = n; i >= 1; i--)
        for (int j = 0; j < i; j++) {
            sravn++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                perest++;
            }
        }
    cout << "Метод пузырьком: ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "Сравнений: " << sravn << "; " << "Перестановок: " << perest << endl;
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "russian");
    int r;
    int* m = new int[r]; //создаем указатель на массив целочисленного типа
    //int* arr2 = new int[n];

    cout << "Введите кол-во элементов массива: ";
    cin >> r;

    for (int i = 1; i <= r; i++)
        m[i] = rand() % 100;         //диапозон от  0 to 99
    //arr[r] = iRandom(1,9);

    m_out(m,r);//вывод массива на печать (случайный порядок)
    m_turn_out(m,r);
    m_out(m,r);//вывод массива на печать (обратный порядок)
    buble(m,r);

/*    const int n = 13; // количество элементов в массиве
    int a[n], i; // массив целых чисел
    srand( (unsigned int) time( NULL ) ); // начальное число-время
    rand( ); //сброс первого числа, чтобы не
// повторялось, пока srand не изменяется
    for( i = 0; i &lt; n; i++ ) // цикл инициализации массива
    { a[i] = iRandom( 1, 9 ); // целая случайная величина
        cout&lt;&lt;”a[“&lt;&lt;i&lt;&lt;”]=”&lt;&lt;a[i]&lt;&lt;endl;
    }*/
}