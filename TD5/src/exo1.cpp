#include <vector>
#include <algorithm>
#include <iostream>

size_t folding_string_hash(std::string const& chaine, size_t max){
    size_t hash {0};

    for (auto &character : chaine)
    {
        hash += static_cast<size_t>(character) % max;
    }
    return hash;
}

size_t folding_string_ordered_hash(std::string const& chaine, size_t max){
    size_t hash {0};
    size_t pos {1};
    for (auto &character : chaine)
    {
        hash += (static_cast<size_t>(character)* pos) % max;
        pos +=1;
    }
    return hash;
}

size_t polynomial_rolling_hash(const std::string& chaine, size_t prem, size_t max){
    size_t hash {0};
    size_t power = prem;
    for (size_t i = 0; i < chaine.size() - 1; i++)
    {
        hash += (chaine[i] * power) % max;
        power *= prem;
    }
    return hash;
}

int main(){

    std::string chaine {"Noot NOOT nooooooooooooooooot"};
    std::cout << "Le code de la chaine 1 : " << folding_string_hash(chaine, 127 * chaine.size()) << std::endl;
    
    std::string chaine2 {"abc"};
    std::string chaine3 {"cba"};
    std::cout << "Le code de la chaine 2 : " << folding_string_ordered_hash(chaine2, 127 * chaine2.size()) << std::endl;
    std::cout << "Le code de la chaine 3 : " << folding_string_ordered_hash(chaine3, 127 * chaine3.size()) << std::endl;
   

    std::string chaine4 {"abc"};
    std::cout << "Le code de la chaine 4 : " << polynomial_rolling_hash(chaine4, 3, 127 * chaine3.size()) << std::endl;
   
    return 0;
}