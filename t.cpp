#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    const int len = 81;
    char word[len], line[len];
    int n = 0;
    string word2;
    string arr[8];
/*    cout << "Input the word for search: ";
    cin >>word;
    int l_word = strlen(word);
    cout << l_word<< endl;*/

    ifstream fin(("../cod.txt"), ios::in);

// извлекаем слова из потока в переменную String
    while (fin >> word2)
    {
        arr[n]=word2;
        cout<< word2 << '\n';
        n +=1;

    }
    cout << n << endl;
    for ( int i = n - 1; i >= 0; i-- )
        cout << arr[i] << endl;

    return 0;
}