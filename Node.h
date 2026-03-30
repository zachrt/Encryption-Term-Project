#pragma once
#include <string>
using  namespace std;

class Node {
public:
    char ch;
    int freq;
    Node* left;
    Node* right;

    // Leaf node (your existing constructor + child pointers)
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}

    // Internal node (for merging two nodes during tree building)
    Node(int f, Node* l, Node* r) : ch('\0'), freq(f), left(l), right(r) {}
};