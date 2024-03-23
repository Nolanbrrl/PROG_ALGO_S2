#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator{0};
    unsigned int denominator{1};

    float to_float();
    operator float();
};

Fraction operator+(const Fraction &f1, const Fraction &f2);
Fraction operator-(const Fraction &f1, const Fraction &f2);
Fraction operator*(const Fraction &f1, const Fraction &f2);
Fraction operator/(const Fraction &f1, const Fraction &f2);

std::ostream& operator<<(std::ostream& os, Fraction f1);

bool operator== (const Fraction &f1, const Fraction &f2);

bool operator!= (const Fraction &f1, const Fraction &f2);

bool operator< (const Fraction &f1, const Fraction &f2);
bool operator> (const Fraction &f1, const Fraction &f2);
bool operator<= (const Fraction &f1, const Fraction &f2);
bool operator>= (const Fraction &f1, const Fraction &f2);


//Je garde les + - * / et les += -= *= /= pour avoir toute la progression de l'exercice en trace
Fraction operator+=(Fraction &f1, const Fraction &f2);
Fraction operator-=(Fraction &f1, const Fraction &f2);
Fraction operator*=(Fraction &f1, const Fraction &f2);
Fraction operator/=(Fraction &f1, const Fraction &f2);

float operatorfloat(Fraction &f1);