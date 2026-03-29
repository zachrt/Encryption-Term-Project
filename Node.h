#pragma once
#include <string>
using  namespace std;

class Node {
public:
    char ch;
    int freq;
    Node* left = nullptr;
    Node* right = nullptr;
    string code;

    Node(char c, int f);
};