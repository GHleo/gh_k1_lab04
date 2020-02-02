#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

//Функция посчета слов в кодовом блокноте
int Amount_CWords() {
    string buf;
    int i = 0;
    ifstream c_pad("../Code_pad.txt");
    while (!c_pad.eof()) {
        c_pad >> buf;
        i++;
    }
    c_pad.seekg(0);
    c_pad.close();
    return i;
}

//  Функция поиска символа в массиве
int find_char(char* m, char ch) {
    for (int i = 0; i < 255; i++)
        if (ch == m[i])
            return i;
    return -1;
}
// Функция для считывания кодового блокнота
int* Read_CodePad() {
    ifstream fin("../Code_pad.txt");
    string buff;
    int shift, n;
    n = Amount_CWords();
    int* arr = new int[n];

    for (int i = 0; !fin.eof(); i++) {
        shift = 0;
        fin >> buff;
        for (int j = 0; j < buff.length(); j++)
            shift += abs((int)buff[j]);
        arr[i] = shift;
    }

    fin.close();
    return arr;
}

// Функция кодирование методом Цезаря
void Text_codeC() {
    char ch; int i, counter = 0, k = 0;

    i = Amount_CWords();
    int* arr_tmp = new int[i];
    arr_tmp = Read_CodePad();
    char arr[255];
    int arr1[255];

    for (int i = 0; i < 255; i++) {
        arr[i] = '<';
        arr1[i] = 0;
    }

    //Посимвольное считывание исходного текста
    ifstream fin("../Text_codeC.txt");
    ofstream codeC("../Text_encryptC.txt");
    ofstream c_char("../out_char.txt");

    while (!fin.eof()) {
        if (counter > i)
            counter -= i;

        fin.get(ch);

        if (fin.eof())
            break;

        cout << ch;
        if (find_char(arr, ch) == -1) {
            arr[k] = ch;
            arr1[k] = 1;
            k++;
        }
        else {
            arr[find_char(arr, ch)] = ch;
            arr1[find_char(arr, ch)] += 1;
        }

        //Посимвольное кодирование и запись в новый файл
        codeC << (char)((int)ch + arr_tmp[counter]);
        counter++;

    };

    for (int i = 0; i < 255; i++) {
        if (arr[i] == '<') break;
        c_char << arr[i] << " - " << arr1[i] << endl;
    }

    fin.close();
    codeC.close();
    c_char.close();
    delete []arr_tmp;
}

//Поиск кодирования символа
void Find_symbol(char CheckChar) {
    char ch; int i, counter = 1;

    i = Amount_CWords();
    int* arrcode = new int[i];
    arrcode = Read_CodePad();

    //Посимвольное считывание исходного текста
    ifstream fin("../TextRus.txt");

    while (!fin.eof()) {
        if (counter > i)
            counter -= i;

        fin.get(ch);

        if (fin.eof())
            break;

        //Вывод кодов для символа
        if (ch == CheckChar) {
            cout << (char)((int)ch + arrcode[counter]) << " ";
            counter++;
        }

    };

    fin.close();
    delete []arrcode;
}

//Чтение закодированного текста из файла
void Read_CodeText() {
    ifstream fin("../Text_encryptC.txt");
    char ch;
    while (!fin.eof()) {
        fin.get(ch);
        cout << ch;
    }
    fin.close();
    cout << endl;
}

// Функци для декодирование текста
void Decryption() {
    int n, counter = 0;
    char ch;
    n = Amount_CWords();
    int* arr = new int[n];
    arr = Read_CodePad();
    ifstream fin("../Text_encryptC.txt");
    while (!fin.eof()) {
        if (counter > n) counter -= n;
        fin.get(ch);
        if (fin.eof()) break;
        cout << char((int)(ch)-arr[counter]);
        counter++;
    }
    delete []arr;
}

//Функция проверки информации о символе
void get_symbol() {
    char in_char, y_n = 'y';
       do {
        cout << "Введите символ для проверки: ";
        cin >> in_char;
        cout << endl << "Символ " << in_char << " кодируется следующими символами: " << endl;
           Find_symbol(in_char);

        cout << endl << endl << "Проверить символ еще символ? (y or n): ";
        cin >> y_n;
       }
       while (y_n == 'y' || y_n == 'Y');
}

int main()
{
   // system("chcp 1251");
   // вывод результатов по запрашиваемого символа
    get_symbol();
    cout << endl << "Количество слов в словаре: ";
    cout << Amount_CWords() << endl;
    cout << endl << "Текст для шифрования: " << endl;
    Text_codeC();
    cout << endl << endl << "Закодированный текст методом Цезаря: " << endl;
    Read_CodeText();
    cout << endl << endl << "Текст после декодирования: " << endl;
    Decryption();


    //system("pause");
    return 0;
}