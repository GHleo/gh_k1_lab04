#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

void In_Cesar(int k) {
    ifstream fin("../text.txt");
    ofstream fout("../text_cesar.txt");

    char buff;
    int iter;

    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else {
        while (!fin.eof()) {
            buff = fin.get();
            if (buff == ' ')
                fout << ' ';
            if (buff == '\n')
                fout << '\n';

            if (buff >= 'A' && buff <= 'Z') {
                buff += (k % 26);
                if (buff > 'Z')
                    buff -= 26;
                fout << buff;
            }
            if (buff >= 'a' && buff <= 'z') {
                buff += (k % 26);
                if (buff > 'z')
                    buff -= 26;
                fout << buff;

            }
/*            if (buff >= 'А' && buff <= 'Я') {
                buff += (k % 33);
                if (buff > 'Я')
                    buff -= 33;
                fout << buff;
            }
            if (buff >= 'а' && buff <= 'я') {
                buff += (k % 33);
                if (buff > 'я')
                    buff -= 33;
                fout << buff;
            }*/
        }
    }
    fin.close();
    fout.close();
}
void Out_Cesar(int k) {
    ifstream fin("../text_cesar.txt");
    ofstream fout("../text_out.txt");

    char buff;
    int iter;

    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else {
        while (!fin.eof()) {
            buff = fin.get();
            if (buff == ' ')
                fout << ' ';
            if (buff == '\n')
                fout << '\n';

            if (buff >= 'A' && buff <= 'Z') {
                buff -= (k % 26);
                if (buff > 'Z')
                    buff += 26;
                fout << buff;
            }
            if (buff >= 'a' && buff <= 'z') {
                buff -= (k % 26);
                if (buff > 'z')
                    buff += 26;
                fout << buff;

            }
/*            if (buff >= 'А' && buff <= 'Я') {
                buff -= (k % 33);
                if (buff > 'Я')
                    buff += 33;
                fout << buff;
            }
            if (buff >= 'а' && buff <= 'я') {
                buff -= (k % 33);
                if (buff > 'я')
                    buff += 33;
                fout << buff;
            }*/
        }
    }
    fin.close();
    fout.close();
}

int main()
{
   // setlocale(LC_ALL, "ru");
    int k = 0;
    cout << "Сдвиг: ";
    cin >> k;

    if (k < 1)
        return 0;

    cout << "Шифровка Цезарь. " << '\n';
    In_Cesar(k);
    cout << "Дешифровка Цезарь." << '\n';
    Out_Cesar(k);

    return 0;
}


/*const int len = 81;
char word[len],line[len];//массив для слова и для строки
cout << " Input the word for search:  ";
cin >> word;
int l_word = strlen(word);//получаем длину слова
ifstream fin("../text.txt",ios::in);
if (!fin) {
cout << "Error of file opening."<< endl;
return 1; }
int count =0;
while (fin.getline(line, len)) {
char *p = line;
//strstr() возвращает указатель на первое вхождение в строку
while( p = strstr(p, word)) {
cout << "совпадение: " << p << endl;
p += l_word;
count++;
}
}
cout << count << endl;*/
