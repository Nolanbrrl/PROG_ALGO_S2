#include <vector>
#include <algorithm>
#include <iostream>
#include "node.hpp"

Node* create_node(int value){

    Node* noeud { new Node {value, nullptr, nullptr}};
    return noeud;

}

bool Node::is_leaf() const{
    if (Node::left == nullptr && Node::right == nullptr)
    {
        return true;
    }
    return false;
    
}

void Node::insert(int value)
{
    if (value < this->value)
    {
        if (this->left != nullptr)
            this->left->insert(value);
        else
            this->left = create_node(value);
    }
    else
    {
        if (this->right != nullptr)
            this->right->insert(value);
        else
            this->right = create_node(value);
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

void Node::delete_childs(){
    if (left)
    {
        left->delete_childs();
        this->left = nullptr;
    }
    if (right)
    {
        right->delete_childs();
        this->right = nullptr;
    }
}

void Node::display_infixe() const
{
    if (this->left != nullptr)
    {
        this->left->display_infixe();
    }

    std::cout << this->value << " | ";
    
    if (this->right != nullptr)
    {
        this->right->display_infixe();
    }
}

std::vector<Node const *> Node::prefixe() const
{
    std::vector<Node const *> nodes;
    nodes.push_back(this);
    if (!(this->is_leaf()))
    {
        if (this->left != nullptr)
        {
            auto left_nodes{this->left->prefixe()};
            nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
        }

        if (this->right != nullptr)
        {
            auto right_nodes{this->right->prefixe()};
            nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
        }
    }
    return nodes;
}

std::vector<Node const *> Node::postfixe() const
{
    std::vector<Node const *> nodes;
    if (!(this->is_leaf()))
    {
        if (this->left != nullptr)
        {
            auto left_nodes{this->left->postfixe()};
            nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
        }

        if (this->right != nullptr)
        {
            auto right_nodes{this->right->postfixe()};
            nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
        }
    }
    nodes.push_back(this);
    return nodes;
}

Node *&most_left(Node *&node)
{
    if (node->left != nullptr)
    {
        return most_left(node->left);
    }
    return node;
}

bool remove(Node *&node, int value)
{

    if (node->value > value)
    {
        remove(node->left, value);
    }

    else if (node->value < value)
    {
        remove(node->right, value);
    }
    else
    {
        if (node->is_leaf()) // feuille
        {
            delete node;
            node = nullptr;
            return true;
        }
        else if (node->left != nullptr && node->right == nullptr) //fils à gauche
        {
            Node *tmp = node->left;
            delete node;
            node = tmp;
        }
        else if (node->right != nullptr && node->left == nullptr) //fils à droite
        {
            Node *tmp = node->right;
            delete node;
            node = tmp;
        }
        else //le reste donc deux fils
        {
            Node *less = most_left(node->right); 
            node->value = less->value;
            remove(node->right, less->value);
        }
        return true;
    }
    return false;
}

void delete_tree(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    delete_tree(node->left);
    delete_tree(node->right);

    if (node->left != nullptr)
    {
        delete node->left;
        node->left = nullptr;
    }
    if (node->right != nullptr)
    {
        delete node->right;
        node->right = nullptr;
    }
}

int Node::max()
{
     std::vector<Node const *> getNodes{this->prefixe()};
    int maximum{getNodes[0]->value};
    for (int i{0}; i < getNodes.size(); i++){
        if (maximum <= getNodes[i]->value){
            maximum = getNodes[i]->value;
        }
    }
    return maximum;
}

int Node::min()
{
    std::vector<Node const *> getNodes{this->postfixe()};
    int minimum{getNodes[0]->value};
    for (int i{0}; i < getNodes.size(); i++)
    {
        if (minimum >= getNodes[i]->value){
            minimum = getNodes[i]->value;
        }
    }
    return minimum;

}

int Node::somme()
{
    std::vector<Node const *> getNodes{this->postfixe()};
    int somme{0};
    for (int i{0}; i < getNodes.size(); i++)
    {
        somme += getNodes[i]->value;
    }
    return somme;
}