#include <vector>
#include <algorithm>
#include <iostream>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };
    bool is_leaf();
    void insert(int value);
    int height() const;
    void Node::delete_childs();
    void Node::display_infixe() const;
};

Node* create_node(int value);
