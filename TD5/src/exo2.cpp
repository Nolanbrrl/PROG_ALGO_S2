#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>



std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}


std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes){
    std::unordered_map<std::string, std::vector<float>> map_reparations_robots {};
    std::vector<std::string> noms_robots {};
    std::vector<float> prix_reparation {};

    for (int i = 0; i < robots_fixes.size(); i++)
    {
        
        if (map_reparations_robots.find(robots_fixes[i].first) != nullptr){
            map_reparations_robots.at(robots_fixes[i].first).push_back(robots_fixes[i].second);
        }
        else {
            
            map_reparations_robots.insert({robots_fixes[i].first, {robots_fixes[i].second}});
        }
    }
    return map_reparations_robots;
}

float somme_reparations(std::vector<float> v){
    float somme{0};
    for (int i = 0; i < v.size(); i++)
    {
        somme += v[i];
    }
    return somme;
}

std::ostream &operator<<(std::ostream &os, const std::vector<float> &vec)
{
    if (!vec.empty())
    {
        for (size_t i = 0; i < vec.size(); ++i)
        {
            os << "|" << vec[i];
        }
        os << "|";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::unordered_map<std::string, std::vector<float>> robots){
    for (std::pair p : robots)
    {
        os << "( " << p.first << " , " << p.second << " )" << std::endl;
    }
    return os;
}




int main(){
    std::vector<std::pair<std::string, float>> robots_fixes = get_robots_fix(100);
    std::unordered_map<std::string, std::vector<float>> map = robots_fixes_map(robots_fixes);
    for (std::pair p : map)
    {
        std::cout << p.first << " , " << somme_reparations(p.second) << std::endl;
    }
    
    return 0;
}