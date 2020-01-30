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
void m_out(int* a, int size) {
   // cout << "Исходный массив: ";
    for (int i = 1; i <= size; i++)
        cout << a[i] << " ";
    cout << endl;
}
//Функция вывода массима в обратном порядке на печать
void m_turn_out(int* a, int size) {
    for (int i = 1; i <= size / 2; i++)
        swap(a[i], a[size - i + 1]); //Процедура swap производит обмен значений двух объектов, & - ссылка на указатель а
}

//Функция сортировки пузырьковым методом
void m_buble(int* a, int size) {
    int sravn = 0, perest = 0;
    for (int i = size; i >= 1; i--)
        for (int j = 0; j < i; j++) {
            sravn++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                perest++;
            }
        }
    cout << "Метод пузырька: ";
    for (int i = 1; i <= size; i++)
        cout << a[i] << " ";
    cout << "Сравнений: " << sravn << "; " << "Перестановок: " << "; " << perest << endl;
}
// Функция сортировки прямым выбором
void m_select(int* a, int size)
{
        int min, tmp, sravn = 0, perest = 0; // минимальный элемент и для обмена
        for (int i = 0; i < size - 1; i++)
        {
            min = i; // индекс текущего элемента
            // ищем минимальный элемент чтобы поместить на место i-ого
            for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
            {
                if (a[j] < a[min]) // если элемент меньше минимального,
                    min = j;       // запоминаем его индекс в min
                    sravn++;
            }
            tmp = a[i];      // меняем местами i-ый и минимальный элементы
            a[i] = a[min];
            a[min] = tmp;
            perest++;
        }
    cout << "Прямым выбором: ";
    for (int i = 1; i <= size; i++)
        cout << a[i] << " ";
    cout << "Сравнений: " << sravn << "; " << "Перестановок: " << perest << "; " << endl;
}

int main()
{
    setlocale(LC_ALL, "russian");
    srand(time(0));
    int r;
    int* m = new int[r]; //создаем указатель на массив целочисленного типа
    int* m_tmp = new int[r]; //сохраняем копию массива
    //int* arr2 = new int[n];

    cout << "Введите кол-во элементов массива: ";
    cin >> r;

    for (int i = 1; i <= r; i++)
        m[i] = rand() % 100;         //диапозон от  0 to 99
    m_tmp = m;

    //сортировка в прямом направлении 2-мя методами
    cout << "Исходный массив: ";
    m_out(m,r);//вывод массива на печать (случайный порядок)
    m_buble(m,r);//сортировка методом пузырька
    m_select(m,r);//сортировка выбором минимального значения
    cout << "----------------------------------------------------------------------"<< endl;

    //сортировка отсортированного массива – 2-мя методами
    cout << "Отсортированный массив: ";
/*    for (int i = 1; i <= r; i++)
        cout << m_tmp[i] << " ";
    cout << endl;*/
    m_out(m,r);//вывод массива на печать
    m_buble(m_tmp,r);//сортировка методом пузырька
    m_select(m_tmp,r);//сортировка выбором минимального значения
    cout << "----------------------------------------------------------------------"<< endl;

    //в обратную сторону– 2-мя методами
    cout << "Отсортированный массив в обратную сторону: ";
    m_turn_out(m,r);
    m_out(m,r);//вывод массива на печать (обратный порядок)
    m_buble(m,r);//сортировка методом пузырька
    m_select(m,r);//сортировка выбором минимального значения

}