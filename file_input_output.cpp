#include<string>
#include<fstream>
#include <iostream>
using namespace std;

int main()
{
	char ch;
	int p = 0;
	int mas[256];
	for (int i = 0; i < 256; i++)
		mas[i] = 0;


	;
	ifstream cod;
	ofstream decod2;
	fstream decod;
	
	decod2.open("C:/Users/den/source/repos/ConsoleApplication12/decod2.txt");
	cod.open("C:/Users/den/source/repos/ConsoleApplication12/cod.txt");
	decod.open("C:/Users/den/source/repos/ConsoleApplication12/decod.txt",fstream::in | fstream::out);
		while (cod.get(ch))
		{
			cout << ch << endl;
			p = int(ch);
			mas[p] = p;
			decod << p << endl;
			
			

		}
	
	cod.close();
    decod.close();
	for (int i = 0; i < 256; i++)

	{
		if (mas[i] > 0)
		{
			decod2 << char(mas[i]);
		}
 	}
	return 0;
}



