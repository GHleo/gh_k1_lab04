#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
    int nrow, ncol;
    cout << " Введите количество строк и столбцов :";
    cin >> nrow >> ncol;
    int **a = new int *[nrow];	// 1
    for(int i = 0; i < nrow; i++)	// 2
        a[i] = new int [ncol];	 // 3
    return 0;
}

