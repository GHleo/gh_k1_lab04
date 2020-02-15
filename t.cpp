#include <iostream>

#include <fstream>

using namespace std;

int main()
{
    char ch;
    ifstream code ("../cod.txt");;
    code.seekg(0,ios::end); //устанавливает позицию чтения из потока в положение, определяемое значением параметра. ios::end	Смещение от конца
    int size=code.tellg();//tellg() определяет текущую позицию чтения из потока

    for (int j=1; j<=size; j++)
    { code.seekg(-j, ios::end);
        ch=code.get();
        cout <<ch;
    }

    code.close();
    return 0;
}

