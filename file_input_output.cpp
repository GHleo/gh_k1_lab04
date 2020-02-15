#include<fstream>
#include <iostream>
using namespace std;

int main()
{
	char ch;
	int p, n;
	int ar[100];
    char S1[256];
    ifstream cod; // for reading file
	ofstream decod; // for writing file
	cod.open("../cod.txt");
    decod.open("../decod.txt");
	while (!cod.eof())
	{
        cod.get(ch);
        p = int(ch);
        decod << p << endl;
        cin >> S1;
       // decod << ch << " - " << p << endl;
       cout << ch;
	}
    std::cout << endl << "Текст для шифрования: " << endl;
    cod.close();
    decod.close();
	return 0;
}

