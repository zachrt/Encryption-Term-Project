#pragma once
#include <string>
#include <unordered_map>
#include "Node.h"
#include "PriorityQueue.h"

using namespace std;

class HuffmanTree {
private:
    Node* root;
    unordered_map<char, string> codes;

    void generateCodes(Node* node, string code);
    void deleteTree(Node* node);
    string serializeTree(Node* node);
    Node* deserializeTree(const string& data, int& index);
    string toBinary(const string& bits);
    string fromBinary(const string& binary);

public:
    HuffmanTree();
    ~HuffmanTree();

    void build(PriorityQueue& pq);
    string compress(const string& input);
    string decompress(const string& compressed);
    void printCodes();
};