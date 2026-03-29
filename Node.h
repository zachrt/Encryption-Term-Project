#pragma once

using  namespace std;

class Node {
public:
    char ch;
    int freq;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(char c, int f);
};