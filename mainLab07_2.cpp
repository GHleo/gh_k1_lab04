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
    c_pad.seekg(0);//возвращает указатель в начало файла
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
        //Величина сдвига для каждой позиции в исходном тексте - сумма (по модулю 256) кодов символов слова кодового
        //блокнота, стоящего в блокноте на той же позиции.
        for (int j = 0; j < buff.length(); j++)//цикл по полученнуму слову
            shift += abs((int)buff[j]);//получаем код символ как десятечное число
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
   // c_char.close();
    delete []arr_tmp;
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

//Поиск кодирования символа
void Find_symbol(char CheckChar) {
    char ch; int i, counter = 1;
    bool isChar = false;
    i = Amount_CWords();// получаем количество слов в словаре
    int* arrcode = new int[i];//инициализация массива
    arrcode = Read_CodePad(); //получаем заполненный массив с сумами кодов слов для получения значения для сдвига

    //Посимвольное считывание исходного текста
    ifstream fin("../Text_codeC.txt");
    while (!fin.eof()) {
        if (counter > i)
            counter -= i;
        fin.get(ch); // получить символ из файла
        if (fin.eof())// для выхода из цикла while принудительно что бы не выполнился код ниже
            break;
        //Вывод кодов для символа
        if (ch == CheckChar) {
            //если найден символ в файле такой же как и введеный с клавиатуры то этот значение этого символа суммируем
            //со значением полеченное из массива соответствующей позиции кодового блокнота и полученный символ выводим
            //на печать
            cout << (char)((int)ch + arrcode[counter]) << " ";
            counter++;
        }
/*        else
            isChar = true;*/
    };
/*    if (isChar == true)
        cout << " true "; //"Нет такого символа в исходном тексте!" ;*/

    fin.close();
    delete []arrcode;
}

//Функция проверки информации о символе
void get_symbol() {
    char in_char, y_n = 'y';
       do {
        cout << "Введите символ для проверки: ";
        cin >> in_char;
        cout << endl << "Символ " << in_char << " кодируется следующими символами: " << endl;
           Find_symbol(in_char);// вызываем функцию поиска символа
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