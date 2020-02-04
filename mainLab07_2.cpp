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
            return i; // если символ найден вернуть индекс этого символа
    return -1; //если символа нет в массиве вернуть -1
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

    i = Amount_CWords();// получить количество кодовых слов в кодовом блокноте
    int* arr_tmp = new int[i]; //указатель на массив размерностью i (полученное количество слов из блокнота)
    arr_tmp = Read_CodePad();//заполнить массив словами из кодового блокнота
    char arr[255];
    int arr1[255];

    //заполнить
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

        fin.get(ch); //получаем символ из файла (потока)

        if (fin.eof()) //если конец файла прерываем цикл while
            break;

        cout << ch;
       // вызываем функцию find_char объявленную выше для поиска символа в масссиве
        if (find_char(arr, ch) == -1) { //если символ в массиве не найден заходим в цикл
            arr[k] = ch; //добавить символ в массив arr с индексом "к"
            arr1[k] = 1; //довавить 1 в массив arr1
            k++;
        }
        else {
            arr[find_char(arr, ch)] = ch; //функция find_char вернула индекс найденного символа и по этому индексу заносим символ "ch" в массив arr
            arr1[find_char(arr, ch)] += 1;//функция find_char вернула индекс найденного символа и по этому индексу суммируем +1 (при инициализации в массив заносили 1)
        }

        //Посимвольное кодирование и запись в новый файл
        //(int)ch - получаем код символа ch и суммируем его с кодом полученным из массива (код из кодовой таблицы)
        // и записываем в поток codeC(файлText_encryptC.txt") новый символ (со сдвигом символ)
        codeC << (char)((int)ch + arr_tmp[counter]);
        counter++;

    };

    //записываем в поток c_char файл ("out_char.txt") символ из исходного файла и его количество встречающееся в файле
    for (int i = 0; i < 255; i++) {
        if (arr[i] == '<') break;
        c_char << arr[i] << " - " << arr1[i] << endl;
    }

    fin.close();
    codeC.close();
    c_char.close();
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