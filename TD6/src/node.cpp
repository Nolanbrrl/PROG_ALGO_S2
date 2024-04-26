#include <vector>
#include <algorithm>
#include <iostream>
#include "node.hpp"

Node* create_node(int value){

    Node* noeud { new Node {value, nullptr, nullptr}};
    delete noeud;
    return noeud;

}

bool Node::is_leaf(){
    if (Node::left == nullptr && Node::right == nullptr)
    {
        return true;
    }
    return false;
    
}

void Node::insert(int value){
    if (value < Node::value)
    {
        Node::left = create_node(value);
    }
    else if (value > Node::value)
    {
        Node::right = create_node(value);
    }
    else{

    }
}

int Node::height() const{
    int taille_gauche{};
    int taille_droite{};
    if (Node::left != nullptr)
    {
        taille_gauche = (1 + Node::left->height());
    }
    if (Node::right != nullptr)
    {
        taille_droite = (1 + Node::right->height());
    }
    if (taille_gauche > taille_droite)
    {
        return taille_gauche;
    }
    else
    {
        return taille_droite;
    }
    
}