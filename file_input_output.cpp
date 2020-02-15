#include<fstream>
#include <iostream>
using namespace std;

int main()
{
	char ch;
	int p, n;
	int ar[100];
	ifstream cod;
	ofstream decod;
	cod.open("C:/Users/den/source/repos/ConsoleApplication12/cod");
	while (cod.get(ch))
	{
		p = int(ch);
		ar[p] = p;


	}
	decod.open("C:/Users/den/source/repos/ConsoleApplication12/decod");
	for (int i = 0; i < 100; i++)
	{
		if (ar[p] > 0)
			decod << ar[p];
	}

	return 0;
}

