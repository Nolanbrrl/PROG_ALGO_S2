#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };
    bool is_leaf() const;
    void insert(int value);
    int height() const;
    void delete_childs();
    void display_infixe() const;
    std::vector<Node const *> prefixe() const;
    std::vector<Node const *> postfixe() const;
    int max();
    int min();
    int somme();
};

Node* create_node(int value);
Node *&most_left(Node *&node);
bool remove(Node*& node, int value);
void delete_tree(Node* node);