#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

std::ostream& operator<<(std::ostream& os, Fraction f1){
    return os << f1.numerator << " / " << f1.denominator << std::endl;
}

Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}



Fraction operator-(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}

bool operator==(Fraction const& f1, Fraction const& f2){
    simplify(f1);
    simplify(f2);
    if(f1.numerator == f2.numerator && f1.denominator == f2.denominator){
        return true;
    }
    else {
        return false;
    }
}

bool operator!=(Fraction const& f1, Fraction const& f2){
    simplify(f1);
    simplify(f2);
    if(f1 == f2) {
        return false;
    }
    else {
        return true;
    }
}

bool operator< (const Fraction &f1, const Fraction &f2){
    simplify(f1);
    simplify(f2);
    return ((float)(f1.numerator / f1.denominator) < (float)(f2.numerator / f2.denominator));
}

bool operator> (const Fraction &f1, const Fraction &f2){
    simplify(f1);
    simplify(f2);
    if(f1 < f2){
        return false;
    }
    else if (f1 == f2){
        return false;
    }
    else {
        return true;
    }
}

bool operator <= (const Fraction &f1, const Fraction &f2){
    simplify(f1);
    simplify(f2);
    if(f1 < f2){
        return true;
    }
    else if (f1 == f2){
        return true;
    }
    else {
        return false;
    }
}

bool operator >= (const Fraction &f1, const Fraction &f2){
    simplify(f1);
    simplify(f2);
    if(f1 > f2){
        return true;
    }
    else if (f1 == f2){
        return true;
    }
    else {
        return false;
    }
}

Fraction operator+=(Fraction &f1, Fraction const& f2) {
    f1.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f1.denominator = f1.denominator * f2.denominator;
    return simplify(f1);
}

Fraction operator-=(Fraction &f1, Fraction const& f2) {
    f1.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    f1.denominator = f1.denominator * f2.denominator;
    return simplify(f1);
}

Fraction operator*=(Fraction &f1, Fraction const& f2) {
    f1.numerator = f1.numerator * f2.numerator;
    f1.denominator = f1.denominator * f2.denominator;
    return simplify(f1);
}

Fraction operator/=(Fraction &f1, Fraction const& f2) {
    f1.numerator = f1.numerator * f2.denominator;
    f1.denominator = f1.denominator * f2.numerator;
    return simplify(f1);
}

float Fraction::to_float(){
    return (static_cast<float>(numerator) / static_cast<float>(denominator));
}

Fraction::operator float(){
    return to_float();
};