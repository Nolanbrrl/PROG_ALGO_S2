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
};

Node* create_node(int value);
