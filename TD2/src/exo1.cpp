#include <vector>
#include <algorithm>
#include <iostream>

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

bool is_sorted(std::vector<int> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}


void bubble_sort(std::vector<int> & vec){
    while(is_sorted(vec) == 0){
        for (int i = 0; i < vec.size(); i++)
        {
            if(i == vec.size()){
                vec[i] = vec[i];
            }
            else if (vec[i] > vec[i + 1])
            {
                int poubelle = vec[i + 1];
                vec[i + 1] = vec [i];
                vec[i] = poubelle;
            }
            
        }
        
    }
}

void selection_sort(std::vector<int> & vec){
    int debut = 0;
    while(is_sorted(vec) == 0){
        int min = vec[debut];
        int poubelle{};
        for (int i = debut; i < vec.size(); i++)
        {
            if (vec[i] < min)
            {
                min = vec[i];
                poubelle = vec[debut];
                vec[debut] = vec[i];
                vec[i] = poubelle;
            }
            
        }
        debut += 1;
    }

}



int main(){

    std::vector<int> vec = {3, 2, 6, 19, 1};
    bubble_sort (vec);
    std::cout << "Le tableau apres bubble_sort : " << std::endl;
    std::cout << vec << std::endl;
    

    std::vector<int> vec2 = {5, 8, 4, 9, 0, 1, 3};
    selection_sort(vec2);
    std::cout << "Le tableau apres selection_sort : " << std::endl;
    std::cout << vec2 << std::endl;

    

    return 0;
}