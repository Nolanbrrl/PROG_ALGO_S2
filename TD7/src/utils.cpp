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
    int emplacement_actuel {start};
    while (pile.empty() == 0)
    {
        std::cout << " ( " << pile.top() << " ) puis " << std::endl;
        pile.pop();
        for (int i = 0; i < adjacency_list.at(emplacement_actuel).size(); i++)
        {
            pile.push(adjacency_list.at(emplacement_actuel)[i].to);
        }
        emplacement_actuel = pile.top();
        
    }
    

}

void Graph::WeightedGraph::print_BFS(int const start) const{

}