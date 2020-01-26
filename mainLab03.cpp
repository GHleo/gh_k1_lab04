#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//x - cos(x) = 0
//Величины XN, XK и DX

const double eps = 0.00000001; // погрешность
double x,y,a,b;
// расчетная функция
double f_3(double x){
    return x - cos(x);
}
int main() {

   // Простая итерация    Хj+1 = Xj - f(Xj).
/*    int n=0;
    x=-5;
//double x=-2.0,y,b,eps=0.000001;
    do {
        y=f_3(x);
        b=fabs(x-y);
        x=y;
        n++;
    }while (b>=eps && n<100);
    cout<<"Root x ="<<x<<"\n";
    cout<<"Iterations n= "<<n<<"\n";
    getchar();
    return 0;*/

        for ( x= 0.7; x <= 1; x += eps) {
            y = f_3(x);
            //cout << "y = " << y << endl;
            if (fabs(y) <= eps) {
                cout << "x = " << x << endl;
                getchar();
                exit(0);
            }
        }


    return 0;
}

