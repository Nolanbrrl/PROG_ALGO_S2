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
    return 0;
}