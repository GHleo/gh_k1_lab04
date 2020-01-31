#include <fstream>
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
}

