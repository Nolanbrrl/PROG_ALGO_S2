#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>
#include <stack>
#include <queue>
#include "utils.hpp"

int main(){
    std::vector<std::vector<int>> matrix {
        {0, 0, 7, 4, 0},
        {2, 0, 0, 0, 4},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0},
    };
    Graph::WeightedGraph graphe1 = adjency_list_from_adjency_matrix(matrix);

    Graph::WeightedGraph graphe2 {};
    for (int i = 0; i < matrix.size(); i++)
    {
        graphe2.add_vertex(i);
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j] > 0){
                graphe2.add_directed_edge(i,j, matrix[i][j]);
            }
        }   
    }
    
    bool resultat = graphe1 == graphe2;
    switch (resultat)
    {
    case 1:
        std::cout << "Les arbres sont egaux" << std::endl;
        break;
    
    case 0:
        std::cout << "Les arbres sont différents" << std::endl;
        break;
    }

    // graphe1.print_DFS(7);
    // graphe1.print_BFS(7);

    std::unordered_map<int, std::pair<float, int>> djikstra_map {};
    Graph::WeightedGraph graphe_djikstra {};
    graphe_djikstra.add_vertex(1);
    graphe_djikstra.add_vertex(9);
    graphe_djikstra.add_vertex(7);
    graphe_djikstra.add_vertex(4);
    graphe_djikstra.add_vertex(2);
    graphe_djikstra.add_directed_edge(1, 9, 1);
    graphe_djikstra.add_directed_edge(1, 7, 4);
    graphe_djikstra.add_directed_edge(9, 7, 1);
    graphe_djikstra.add_directed_edge(9, 4, 1);
    graphe_djikstra.add_directed_edge(9, 2, 5);
    graphe_djikstra.add_directed_edge(7, 2, 1);
    graphe_djikstra.add_directed_edge(4, 2, 3);
    graphe_djikstra.add_directed_edge(4, 1, 3);
    std::unordered_map<int, std::pair<float, int>> chemin{Graph::dijkstra(graphe_djikstra, 1, 2)};
    for (auto [vextex, pair] : chemin)
    {
        std::cout << "Du noeud 1 à : " << vextex << " : " << pair.first << " via " << pair.second << std::endl;
    }
    
    return 0;
}
