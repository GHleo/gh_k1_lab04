#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
    char ch,i;
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
       // decod << int(ch) << endl;
        decod << ch << endl;
        s = ch;
        i = strlen(s);
    }
    while (!decod.eof())
    {
       //decod2 << decod.getline(s,N);
        cout << decod.get() << endl;
    }
    char W[80];
    while (!cod.eof())
    {
        cout << "xxxxx"<< endl;
        cod.getline(W,80);
        for (int i=strlen(W)-1;i>=0;i--)
            decod2 <<W[i]<<endl;

    }
    cod.close();
    decod.close();


    return 0;
}
