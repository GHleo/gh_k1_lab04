#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
    char ch;
    int p;
    const int N = 256;  //число символов в массивах
    char s[256], s2[256];
    string ss;

    ifstream cod; // for reading file
    fstream decod; // for writing file
    cod.open("../cod.txt");
    decod.open("../decod.txt");
   fstream decod2 ("../decod2.txt");
    while (!cod.eof())
    {
        cod.get(ch);
        decod << int(ch) << endl;
    }
    while (!decod.eof())
    {
       //decod2 << decod.getline(s,N);
        cout << decod.get() << endl;
    }
    cod.close();
    decod.close();


    return 0;
}
