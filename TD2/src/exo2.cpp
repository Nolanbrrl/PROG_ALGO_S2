#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "ScopedTimer.hpp"



template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& array)
{
    os << "[ ";
    for (size_t i=0; i<array.size()-1; i++)
    {
        os << array[i] << ", ";
    }
    os << array[array.size()-1] << "]";
    return os;
}

std::vector<float> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<float> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

bool is_sorted(std::vector<int> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}

void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right) {
    // On crée deux vecteurs temporaires pour stocker les copies des deux sous-parties à fusionner
    size_t const left_size { middle - left + 1 };
    size_t const right_size { right - middle };
    std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    // Deux index pour parcourir les deux sous-parties et remplir le vecteur original
    size_t left_index {0};
    size_t right_index {0};


    // Tant que nous avons pas parcouru tous les éléments d'au moins une des deux sous-parties
    while (left_index <= left_size - 1 && right_index <= right_size - 1) {
        // On compare les éléments des deux sous-parties et on place le plus petit dans le vecteur original
        // on met à jour les index pour parcourir les sous-parties en conséquence
        if (left_vec[left_index] <= right_vec[right_index]) {
            vec[left_index + right_index] = left_vec[left_index];
            left_index += 1;
        } else {
            vec[left_index + right_index] = right_vec[right_index];
            right_index += 1;
        }
        
    }

    // S'il reste des éléments dans une des deux sous-parties, on les place dans le vecteur original
    while (left_index <= left_size - 1) {
        vec[left_index + right_index] = left_vec[left_index];
        left_index += 1;
    }
    while (right_index <= right_size - 1) {
        vec[left_index + right_index] = right_vec[right_index];
            right_index += 1;
    }
}


void merge_sort(std::vector<float> & vec, size_t const left, size_t const right) {
    if (left >= right) {
        return;
    }
    size_t const middle = left + (right - left) / 2;

    merge_sort(vec, left, middle - 1);
    merge_sort(vec, middle + 1, right);
    merge_sort_merge(vec, left, middle, right);
    
    
    // 1. Choix de l'index au milieu de la partition
    // 2. Appels récursifs sur les deux sous-parties
    // 3. Fusion des deux sous-parties
}

// Même mécanisme que pour le tri rapide
void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

int dichotomie(std::vector<int> vec, int const& valeur){
    bool is_indice{false};
    int left{0};
    std::size_t right{vec.size() - 1}; 
    int middle{(left + static_cast<int>(right)) / 2};
    if (is_sorted(vec) == true)
    {
        while (left != right)
        {
            if (vec[middle] == valeur)
            {
                is_indice = true;
                return middle;
            }
            else if (vec[middle] < valeur)
            {
                left = middle + 1;
            }
            else if (vec[middle] > valeur)
            {
                right = middle - 1;
            }
            middle = (left + right) / 2;
        }
    }
    if (is_indice == false)
    {
        return -1;
    }
    
    else{
        std::cout << "Le tableau n'st pas trie" << std::endl;
        return -1; 
    }

}

void counting_sort(std::vector<int> & vec, int const max){
    std::vector<std::pair<int,int>> compteur_occurences_valeur{};
    std::vector<int> tableau_trie {};
    for (int i = 0; i <= max; i++)
    {
        int compteur {0};
        for (int j : vec)
        {
            if (j == i)
            {
                compteur++;
            }
            
        }
        
        compteur_occurences_valeur.push_back({i,compteur});

    }

    for (std::pair<int,int> p : compteur_occurences_valeur)
    {
        if (p.second > 0)
        {
            for (int i = 0; i < p.second; i++)
            {
                tableau_trie.push_back(p.first);
            }
            
        }
        
    }
    
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = tableau_trie[i];
    }
    
}

int main (){

    

    std::vector<float> vec2 = {5, 8, 4, 9, 0, 1, 3};
    merge_sort(vec2);
    std::cout << "Le tableau apres merge_sort : " << std::endl;
    std::cout << vec2 << std::endl;

    

    std::vector<int> tableau1 {1, 2, 2, 3, 4, 8, 12};
    std::vector<int> tableau2 {1, 2, 3, 3, 6, 14, 12, 15};
    std::vector<int> tableau3 {2, 2, 3, 4, 5, 8, 12, 15, 16};
    std::vector<int> tableau4 {5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<int> tableau5 {1, 2, 3, 4, 5, 6, 7, 8, 9};


    std::cout << "L'indice de la valeur cherchee 8 du tableau 1 est : " << dichotomie(tableau1, 8) << std::endl;
    std::cout << "L'indice de la valeur cherchee 15 du tableau 2 est : " << dichotomie(tableau2, 15) << std::endl;
    std::cout << "L'indice de la valeur cherchee 16 du tableau 3 est : " << dichotomie(tableau3, 16) << std::endl;
    std::cout << "L'indice de la valeur cherchee 6 du tableau 4 est : " << dichotomie(tableau4, 6) << std::endl;
    std::cout << "L'indice de la valeur cherchee 10 du tableau 5 est : " << dichotomie(tableau5, 10) << std::endl;

    std::vector<int> vec3 = {2, 8, 8, 9, 3, 1, 3};
    counting_sort(vec3, 9);
    std::cout << "Le tableau apres counting sort donne : " << std::endl;
    std::cout << vec3 << std::endl;

    {
        ScopedTimer timer("chrono sort basique");
        std::vector<float> array = generate_random_vector(100, 100);
        std::sort(array.begin(), array.end());
    }

    {
        ScopedTimer timer("chrono merge");
        std::vector<float> array2 = generate_random_vector(100, 100);
        merge_sort(array2);
    }
    
    // On remarque que les deux algorithmes ont un temps d'execution différent
    // L'ordre de grandeur joue sur le temps d'exécution
    // Avec plus de données, le récursif est nettement plus efficace

    return 0;
}

