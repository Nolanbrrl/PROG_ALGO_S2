#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include "utils.hpp"

namespace Graph {
    bool WeightedGraphEdge::operator==(WeightedGraphEdge const& other) const {
        return to == other.to && weight == other.weight;
    }
    bool WeightedGraphEdge:: operator!=(WeightedGraphEdge const& other) const {
        return !(*this == other);
    }

    bool WeightedGraph::operator==(WeightedGraph const& other) const {
        return adjacency_list == other.adjacency_list;
    }

    bool WeightedGraph::operator!=(WeightedGraph const& other) const {
        return !(*this == other);
    }
}

void Graph::WeightedGraph::add_vertex(int const id){
    if(adjacency_list.find(id) != adjacency_list.end()){

    }
    else {
        adjacency_list.insert({id, {}});
    }
}

void Graph::WeightedGraph::add_directed_edge(int const from, int const to, float const weight){
    if (adjacency_list.find(from) != adjacency_list.end())
    {
        adjacency_list.at(from).push_back({to, weight});
    }
    else {
        add_vertex(from);
    } 
}

void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight){
    add_directed_edge(from, to, weight);
    add_directed_edge(to, from, weight);
}

Graph::WeightedGraph adjency_list_from_adjency_matrix(std::vector<std::vector<int>> adjency_matrix){
    Graph::WeightedGraph graph_final {};
    for (int i = 0; i < adjency_matrix.size(); i++)
    {
        graph_final.add_vertex(i);
        for (int j = 0; j < adjency_matrix.size(); j++)
        {
            if (adjency_matrix[i][j] > 0)
            {
                graph_final.add_directed_edge(i, j, adjency_matrix[i][j]);
            }
            
           
        }     
    }
    return graph_final;
}

void Graph::WeightedGraph::print_DFS(int const start) const{
    std::stack<int> pile {};
    std::vector<int> visite {};
    bool est_dans_la_pile {0};
    pile.push(start);
    visite.push_back(start);
    int emplacement_actuel {start};
    while (pile.empty() == 0)
    {
        for (int j = 0; j < visite.size(); j++)
        {
            if (visite[j] == emplacement_actuel)
            {
                est_dans_la_pile == 1;
            }
        }
        if (est_dans_la_pile == 0)
        {
            std::cout << " ( " << pile.top() << " ) puis " << std::endl;
            
        }
        pile.pop();
        for (int i = 0; i < adjacency_list.at(emplacement_actuel).size(); i++)
        {
            pile.push(adjacency_list.at(emplacement_actuel)[i].to);
            visite.push_back(adjacency_list.at(emplacement_actuel)[i].to);
        }
        emplacement_actuel = pile.top();
        est_dans_la_pile = {0};
        
    }
    

}

void Graph::WeightedGraph::print_BFS(int start) const
{
    std::queue<int> queue;
    std::vector<bool> visited(adjacency_list.size(), false);

    queue.push(start);
    visited[start] = true;

    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();

        std::cout << current << " ";

        for (auto const &edge : adjacency_list.at(current))
        {
            if (!visited[edge.to])
            {
                queue.push(edge.to);
                visited[edge.to] = true;
            }
        }
    }
    std::cout << std::endl;
}

std::unordered_map<int, std::pair<float, int>> Graph::dijkstra(const Graph::WeightedGraph &graph, const int &start, int end)
{
    // On crée un tableau associatif pour stocker les distances les plus courtes connues pour aller du sommet de départ à chaque sommet visité
    // La clé est l'identifiant du sommet et la valeur est un pair (distance, sommet précédent)
    std::unordered_map<int, std::pair<float, int>> distances{};

    // On crée une file de priorité pour stocker les sommets à visiter
    // la pair contient la distance pour aller jusqu'au sommet et l'identifiant du sommet

    // Ce type compliqué permet d'indiquer que l'on souhaite trier les éléments par ordre croissant (std::greater) et donc les éléments les plus petits seront au début de la file (top) (Min heap)
    std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int>>, std::greater<std::pair<float, int>>> to_visit{};

    // 1. On ajoute le sommet de départ à la liste des sommets à visiter avec une distance de 0 (on est déjà sur le sommet de départ)
    to_visit.push(std::make_pair(0, start));

    // Tant qu'il reste des sommets à visiter
    while (!to_visit.empty())
    {
        // 2. On récupère le sommet le plus proche du sommet de départ dans la liste de priorité to_visit
        auto [current, distance]{to_visit.top()};

        // 3.Si on atteins le point d'arrivé, on s'arrête
        if (current == end)
        {
            return distances;
        }

        // 3. On parcourt la liste des voisins (grâce à la liste d'adjacence) du noeud courant
        for (auto const &edge : graph.adjacency_list.at(current))
        {
            // 4. on regarde si le noeud existe dans le tableau associatif (si oui il a déjà été visité)
            auto find_node{distances.find(edge.to)};
            bool const visited{find_node != distances.end()};

            if (!visited)
            {
                // 5. Si le noeud n'a pas été visité, on l'ajoute au tableau associatif en calculant la distance pour aller jusqu'à ce noeud
                // la distance actuelle + le point de l'arrête)
                distances[edge.to] = {current, distance + edge.weight};

                // 6. On ajoute également le noeud de destination à la liste des noeud à visité (avec la distance également pour prioriser les noeuds les plus proches)
                to_visit.push(std::make_pair(distance + edge.weight, edge.to));
            }
            else
            {
                // 7. Si il a déjà été visité, On test si la distance dans le tableau associatif est plus grande
                // Si c'est le cas on à trouvé un plus court chemin, on met à jour le tableau associatif et on ajoute de nouveau le sommet de destination dans la liste à visité
                if ((distance + edge.weight) < find_node->second.first)
                {
                    distances[edge.to] = {current, distance + edge.weight};
                    to_visit.push(std::make_pair(distance + edge.weight, edge.to));
                }
            }
        }
    }

    return distances;
}