#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = ";
    std::cout << f1;
    std::cout << "f2 = ";
    std::cout << f2;
    std::cout << std::endl;

    std::cout << "f1 + f2 = ";
    std:: cout << (f1+f2);

    std::cout << std::endl << "f1 - f2 = ";
    std::cout << (f1-f2);

    std::cout << std::endl << "f1 * f2 = ";
    std::cout << (f1*f2);

    std::cout << std::endl << "f1 / f2 = ";
    std::cout << (f1/f2);

    std::cout << std::endl << "f1 == f2 ";
    std::cout << (f1==f2)<< std::endl;

    std::cout << std::endl << "f1 != f2 = ";
    std::cout << (f1!=f2) << std::endl;

    std::cout << std::endl << "f1 += f2 = ";
    std::cout << (f1+=f2);

    f1  = { 3, 4 };

    std::cout << std::endl << "f1 -= f2 = ";
    std::cout << (f1-=f2);

    f1  = { 3, 4 };

    std::cout << std::endl << "f1 *= f2 = ";
    std::cout << (f1*=f2);

    f1  = { 3, 4 };

    std::cout << std::endl << "f1 /= f2 = ";
    std::cout << (f1/=f2);

    f1  = { 3, 4 };

    std::cout << std::endl << "f1 en flottant = ";
    std::cout << (f1.to_float());
    return 0;
}