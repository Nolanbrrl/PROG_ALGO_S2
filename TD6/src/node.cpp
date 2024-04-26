#include <vector>
#include <algorithm>
#include <iostream>
#include <node.hpp>

Node* create_node(int value){

    Node* root { new Node {value, nullptr, nullptr}};

    return root;
    delete root;
}