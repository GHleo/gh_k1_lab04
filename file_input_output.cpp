#include<string>
#include<fstream>
#include <iostream>
using namespace std;

int main()
{
	char ch;
	int p = 0,i=0;
	int mas[256];
	for (int i = 0; i < 256; i++)
		mas[i] = 0;


	fstream decod;

    ifstream cod ("../cod.txt");
    decod.open("../decod.txt");
    fstream decod2 ("../decod2.txt");
    while (cod.get(ch))
		{
			p = int(ch);
			mas[i] = p;
			decod << p << endl;
		i+=1;
		}

	for (int i = 0; i < 256; i++)

	{
		if (mas[i] > 0)
		{
			decod2 << char(mas[i]);
		}
 	}

    char W[80];

    while(!cod.eof())
    {
        cout << "xxxxx";
        cod.getline(W,80);
        for (int i=strlen(W)-1;i>=0;i--)
            cout<<W[i]<<endl;

    }

    cod.close();
    decod.close();
    decod2.close();
	return 0;
}



