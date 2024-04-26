#include <vector>
#include <algorithm>
#include <iostream>
#include <node.hpp>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };
    bool is_leaf();
};

Node* create_node(int value);