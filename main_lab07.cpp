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












/*#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int len = 81;
    char word[len],line[len];
    cout << " Input the word for search:  ";
    cin >> word;

    int l_word = strlen(word);
    ifstream fin("../text.txt",ios::in);
    if (!fin) {
        cout << "Error of file opening."<< endl;
        return 1; }
    //цикл чтения из файла
    while (fin.getline(line, len))
    {
        char *p = line;
        while( p = strstr(p, word)) {
            cout << "coincidence: " << p << endl;
            p += l_word;
            count++;
        }
    }

        cout << line << endl;


    return 0;
}*/

