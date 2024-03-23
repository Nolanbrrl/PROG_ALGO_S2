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
    std::cout << (f1.to_float()) << std:: endl;

    f1 = {1, 2};
    float d1 {static_cast<float>(f1)};
    std::cout << std::endl << "d1 le float de f1 ";
    std::cout << (d1);
    return 0;
}