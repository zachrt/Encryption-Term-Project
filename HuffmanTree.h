#pragma once
#include <string>
#include <unordered_map>
#include "Node.h"
#include "PriorityQueue.h"

using namespace std;

struct HashEntry {
    char key;
    std::string code;
    bool active = false;
};

class HashTable {
private:
    HashEntry table[256];
public:
    void insert(char c, std::string s) {
        int idx = (unsigned char)c;
        table[idx].key = c;
        table[idx].code = s;
        table[idx].active = true;
    }

    std::string get(char c) { return table[(unsigned char)c].code; }

    HashEntry* getTable() { 
        return table; 
    }
    
};

class HuffmanTree {
private:
    Node* root;
    HashTable codes;

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