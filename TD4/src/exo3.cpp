#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <random>
#include <cstdlib>
#include <numeric>


bool is_palindrome(std::string const& mot){
    auto fin {mot.cend()};
    auto fin2 {mot.crend()};
    auto debut {mot.begin()};
    auto debutreversed {mot.crbegin()};
    return std::equal(debut, fin, debutreversed);

    
}

//lambda : [](parametres) {instructions}

int somme_carres(std::vector<int> const &v)
{
    return std::accumulate(v.begin(), v.end(), 0, [](int a, int b){ return a + std::pow(b, 2); });
}

int produit_pairs(std::vector<int> const &v)
{
    return std::accumulate(v.begin(), v.end(), 1, [](int a, int b){ if (b % 2 == 0) return a * b; return a; });
}

int main(){

    const std::string &mot {"ressasser"};
    switch (is_palindrome(mot))
    {
    case true:
        std::cout << mot << " est un palindrome" << std::endl;
        break;
    
    case false:
        std::cout << mot << " n'est pas un palindrome" << std::endl;
        break;
    }
    
    std::vector<int> v{2, 3};
    std::cout << "La somme des carres est : " << somme_carres(v) << std::endl;
    std::cout << "Le produit des elements pairs est : " << produit_pairs(v) << std::endl;

    return 0;
}