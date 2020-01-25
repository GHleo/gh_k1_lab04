#include <iostream>

int main()
{
    int age;
    double weight;
    char ch ='y';
    while(ch == 'y' or ch == 'Y') {
        std::cout << "Input age: ";
        std::cin >> age;
        std::cout << "Input weight: ";
        std::cin >> weight;
        std::cout << "Your age: " << age << "\t your weight: " << weight << std::endl;

        std::cout << "Продолжить работу? (y/n) ";
        std::cin >> ch;
        if(ch == 'n' or ch == 'N'){
            break;
        }
    }
    return 0;
}