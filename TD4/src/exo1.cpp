#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <random>
#include <cstdlib>


int main(){
    std::vector<int> vec{};
    for (int i = 0; i < 100; i++)
    {
        int valeur_rand = rand() % 100;
        vec.push_back(valeur_rand);
    }

    std::vector<int>::iterator end_iterator { vec.end() };

    for (std::vector<int>::iterator begin_iterator { vec.begin() }; begin_iterator < end_iterator; begin_iterator++)
    {
        std::cout << *begin_iterator << std::endl;
    }
    
    int entree {};
    std::cout << "Veuillez entrer un nombre/chiffre entre 0 et 100" << std::endl;
    std::cin >> entree;

    auto it { std::find(vec.begin(), vec.end(), entree)};

    if (it != vec.end())
    {
       std::cout << entree << " est dans le tableau " << std::endl; 
    }
    else 
    {
        std::cout << entree << " n'est pas dans le tableau" << std::endl;
    }
    

    int entree2 {};
    std::cout << "Veuillez entrer un nombre/chiffre entre 0 et 100 pour chercher combien de fois il est dans le tableau" << std::endl;
    std::cin >> entree2;
    int compteur = std::count(vec.begin(), vec.end(), entree2);

    if (compteur != 0)
    {
        std::cout << entree2 << " est " << compteur << " fois dans le tableau" << std::endl;
    }
    else
    {
        std::cout << entree2 << " n'est pas dans le tableau" << std::endl;
    }
    
    std::sort(vec.begin(), vec.end());

    int somme_totale = std::accumulate(vec.begin(), vec.end(), vec[0]);

    std::cout << "La somme totale des elements du tableau est : " << somme_totale << std::endl;
    
    return 0;
}