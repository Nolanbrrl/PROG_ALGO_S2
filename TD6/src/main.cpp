#include <vector>
#include <algorithm>
#include <iostream>
#include "node.hpp"

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

int main(){
    Node* racine = create_node(0);
    std::cout << racine->is_leaf() << std::endl;
    racine->insert(12);
    std::cout << racine->right->value << std::endl;

    racine->right->insert(5);
    std::cout << "L'arbre fait " << racine->height() << " de taille" <<  std::endl;
    
    std::cout << "Les noeuds de l'arbre dans l'ordre infixe donnent : " << std::endl;
    racine->display_infixe();
    std::cout << std::endl;

    //EXO2
    Node *arbre{create_node(5)};
    arbre->insert(3);
    arbre->insert(7);
    arbre->insert(2);
    arbre->insert(4);
    arbre->insert(6);
    arbre->insert(8);
    arbre->insert(1);
    arbre->insert(9);
    arbre->insert(0);

    std::cout << "Les noeuds de l'arbre dans l'ordre infixe donnent : " << std::endl;
    arbre->display_infixe();
    std::cout << std::endl;

    std::cout<< "La valeur max de l'arbre est : " << std::endl;
    std::cout << arbre->max() << std::endl;

    std::cout<< "La valeur min de l'arbre est : " << std::endl;
    std::cout << arbre->min() << std::endl;

    std::cout << "La somme des valeurs de l'arbre est : " << arbre->somme() << std::endl;

    std::cout << "La hauteur de l'arbre : " << arbre->height() << " apres la racine" << std::endl;
    return 0;
}