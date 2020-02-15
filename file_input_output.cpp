#include<string>
#include<fstream>
#include <iostream>
using namespace std;

int main()
{
	char ch;
	int p = 0,i=0, n=0;
	int mas[256];
	string word;
    string arr[256];
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
//--------------- Считавание с конца посимвольно -----------------------
    cod.seekg(0,ios::end); //устанавливает позицию чтения из потока в положение, определяемое значением параметра. ios::end	Смещение от конца
    int size=cod.tellg();//tellg() определяет текущую позицию чтения из потока

    for (int j=1; j<=size; j++)
    { cod.seekg(-j, ios::end);
        ch=cod.get();
        cout << ch;
    }
//--------------- Считавание с конца по словам -----------------------
// извлекаем слова из потока в переменную String
    while (cod >> word)
    {
        arr[n]=word;
        cout<< word << '\n';
        n +=1;

    }
    for ( int j = n - 1; j >= 0; j-- )
        cout << arr[j] << endl;


    cod.close();
    decod.close();
    decod2.close();
	return 0;
}



