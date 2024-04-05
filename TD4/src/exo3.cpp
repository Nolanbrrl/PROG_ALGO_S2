#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <random>
#include <cstdlib>


bool is_palindrome(std::string const& mot){
    auto fin {mot.cend()};
    auto fin2 {mot.crend()};
    auto debut {mot.begin()};
    auto debutreversed {mot.crbegin()};
    return std::equal(debut, fin, debutreversed);

    
}



int main(){

    const std::string &mot {"ressasser"};
    switch (is_palindrome(mot))
    {
    case true:
        std::cout << mot << " est un palindrome";
        break;
    
    case false:
        std::cout << mot << " n'est pas un palindrome";
        break;
    }
    
    return 0;
}