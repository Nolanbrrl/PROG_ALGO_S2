#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <random>
#include <cstdlib>


int nbr_lettres_prem_mot (const std::string &phrase){
    int compteur {0};
    auto it = std::find(phrase.begin(), phrase.end(), ' ');
    compteur = std::distance(phrase.begin(), it );
    return compteur;
}

std::vector<std::string> split_string(std::string const& str){
    std::vector<std::string> stock = {};
    std::string::const_iterator end_iterator { str.cend() };

    auto it = std::find(str.cbegin(), str.cend(), ' ');
    std::string::const_iterator debut1 = str.cbegin();
    while (it != end_iterator)
    {
        std::string mot{debut1, it};
        stock.push_back(mot);
        
        debut1 = it + 1;
        it = std::find( it + 1, str.cend(), ' ');
        
    }
    std::string mot{debut1, it};
    stock.push_back(mot);
    return stock;
    
}

int main(){

    const std::string &phrase {"La synthese dimage c relou on a pas de cours ni de correction bouh"};
    std::cout << "Le premier mot a : " << nbr_lettres_prem_mot(phrase) << " lettres " << std::endl;
    std::vector<std::string> phrase_en_mots {split_string(phrase)};
    for (auto it : phrase_en_mots)
    {
        std::cout << it << ", ";
    }
    
    return 0;
}