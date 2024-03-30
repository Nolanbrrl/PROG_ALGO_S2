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

void split_string(std::string const& str){
    std::vector<std::string> stock = {};
    std::string::const_iterator end_iterator { str.cend() };

    const auto it = std::find(str.cbegin(), str.cend(), ' ');
    while (it != end_iterator)
    {
        for (std::string::iterator debut = ; i < count; i++)
        {
            /* code */
        }
        
        it = std::find( it + 1, str.cend(), ' ');
        
    }

    
}

int main(){

    const std::string &phrase {"Jeangele ou Jean ?"};
    std::cout << "Le premier mot a : " << nbr_lettres_prem_mot(phrase) << " lettres " << std::endl;


    return 0;
}