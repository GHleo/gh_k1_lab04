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

//Нахождение максимума функции, метод золотого сечения
/*
    1. На первом шаге исходный отрезок делим двумя симметричными относительно его центра точками и находим значение в этих точках.
    2. После чего тот из концов отрезка, к которому среди двух вновь поставленных точек ближе оказалась та, значение в которой минимально, откидываем.
    3. На следующем шаге следует найти всего одну новую точку.
    4. Повторяем до тех пор, пока не будет достигнута заданная точность.*/
cout<<"XN = "<< XN<< endl;
cout<<"XK = "<< XK<< endl;
while (fabs(XK - XN) > eps)
{
d1 = XK - (XK - XN) / gRatio;
d2 = XN + (XK - XN) / gRatio;
if (f_24(d1) <= f_24(d2)) // Условие для поиска максимума
XN = d1;
else
XK = d2;
};

// Выполняем, пока не достигнем заданной точности
//cout << "(" << (a + b) / 2 << ", " << f_24((a + b) / 2) << ")"<< endl;

#include <bits/stdc++.h>
//http://www.cyberforum.ru/cpp-beginners/thread2343192.html
using namespace std;
#define NUM_READ_LINES 4
//Кол-во слов в кодовом блокноте
int AmountCodeWords() {
    string buffer;
    int n = 0;
    ifstream code_pad("../text.txt");
    while (!code_pad.eof()) {
        code_pad >> buffer;
        n++;
    }
    code_pad.seekg(0);
    code_pad.close();
    return n;
}

/*
char charEncode(char c, int k) {
    char a, b;
    if (isupper(c)) {
        if (int(c) + k > 90) {
            a = k + int(c) - 26;
            b = char(a);
        } else {
            b = char(c + k);
        }
    } else if (islower(c)) {
        if (int(c) + k > 122) {
            a = k + int(c) - 26;
            b = char(a);
        } else {
            b = char(c + k);
        }
    }
    return b;
}
*/

string wordEncode(string s, int k) {
    string b;
    for (int i = 0; s[i]; i++) {
        if (!(isalpha(s[i]))) {
            b += s[i];
        } else {
            b += charEncode(s[i], k);
        }
    }
    return b;
}

//Считывание кодового блокнота
/*int* ReadCodePad() {
    ifstream file("../text.txt");
    string buffer;
    int shift, n;
    n = AmountCodeWords();
    int* arr = new int[n];

    for (int i = 0; !file.eof(); i++) {
        shift = 0;
        file >> buffer;
        for (int j = 0; j < buffer.length(); j++)
            shift += abs((int)buffer[j]);
        arr[i] = shift;
        cout << arr[i];
    }

    file.close();
    return arr;
}*/


int main() {
    ReadCodePad();
    ifstream fin("../text.txt", ios::in);
    ofstream fout("../encoded.txt", ios::in);
    int shift;
    string s, str;
    cout << "What's the shift length?\n";
    cout << "shift = ";
    cin >> shift;
    while (getline(fin, s)) {
        str = wordEncode(s, shift);
        fout << str << "\n";
    }
    cout << "Text has been encoded!\n";


    cout << endl << "Количество слов в словаре: ";
    cout << AmountCodeWords() << endl;

    char thearray[NUM_READ_LINES][100];
    int counter = 0;
    // Open our file
    locale::global( locale( "" ) );
    ifstream inFile("../text.txt",ifstream::in);
    // If we can read/write great

    if (inFile.good()) {
        // Read throuthe file and load into array
        while (!inFile.eof() && (counter < NUM_READ_LINES)) {

            inFile.getline(thearray[counter],100);

            counter++;

        }

        // Loop through the array which we just put together

        for (int i = 0; i < counter; i++) {

            cout << thearray[i] << endl;

        }
    }
    inFile.close();

    fin.close();
    fout.close();

    return 0;
}

