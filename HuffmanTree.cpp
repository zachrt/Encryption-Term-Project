#include "HuffmanTree.h"
#include <iostream>

HuffmanTree::HuffmanTree() : root(nullptr) {}

HuffmanTree::~HuffmanTree() {
    deleteTree(root);
}

void HuffmanTree::deleteTree(Node* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void HuffmanTree::build(PriorityQueue& pq) {
    while (pq.size() > 1) {
        Node* left  = pq.pop();
        Node* right = pq.pop();
        Node* merged = new Node(left->freq + right->freq, left, right);
        pq.push(merged);
    }

    root = pq.pop();

    generateCodes(root, "");
}

void HuffmanTree::generateCodes(Node* node, string code) {
    if (!node) return;

    if (!node->left && !node->right) {
        codes[node->ch] = code.empty() ? "0" : code;
        return;
    }

    generateCodes(node->left,  code + "0");
    generateCodes(node->right, code + "1");
}

void HuffmanTree::printCodes() {
    for (auto& pair : codes)
        cout << "'" << pair.first << "' --> " << pair.second << "\n";
}

string HuffmanTree::toBinary(const string& bits) {
    string binary = "";

    int padding = (8 - (bits.size() % 8)) % 8;
    string padded = bits + string(padding, '0');

    // Store padding amount in first byte
    binary += (char)padding;

    for (int i = 0; i < (int)padded.size(); i += 8) {
        char byte = 0;
        for (int b = 0; b < 8; b++)
            if (padded[i + b] == '1')
                byte |= (1 << (7 - b));
        binary += byte;
    }

    return binary;
}

string HuffmanTree::fromBinary(const string& binary) {
    int padding = (unsigned char)binary[0];
    string bits = "";
    
    for (int i = 1; i < (int)binary.size(); i++) {
        unsigned char byte = binary[i];
        for (int b = 7; b >= 0; b--)
            bits += ((byte >> b) & 1) ? '1' : '0';
    }

    if (padding > 0)
        bits = bits.substr(0, bits.size() - padding);

    return bits;
}

string HuffmanTree::serializeTree(Node* node) {
    if (!node) return "";

    if (!node->left && !node->right)
        return "L" + string(1, node->ch);

    return "I" + serializeTree(node->left) + serializeTree(node->right);
}

Node* HuffmanTree::deserializeTree(const string& data, int& i) {
    if (i >= (int)data.size()) return nullptr;

    if (data[i] == 'L') {
        i++;
        return new Node(data[i++], 0);
    }

    i++; // skip 'I'

    Node* left  = deserializeTree(data, i);
    Node* right = deserializeTree(data, i);

    return new Node(0, left, right);
}

string HuffmanTree::compress(const string& input) {
    string treeData = serializeTree(root);
    string result = "";

    int treeSize = treeData.size();
    

    result += (char)((treeSize >> 24) & 0xFF);
    result += (char)((treeSize >> 16) & 0xFF);
    result += (char)((treeSize >> 8)  & 0xFF);
    result += (char)((treeSize)       & 0xFF);
    result += treeData;

    char currentByte = 0;
    int bitCount = 0;

    for (char c : input) {
        const string& code = codes.at(c);
        for (char bit : code) {
            if (bit == '1')
                currentByte |= (1 << (7 - bitCount));
            bitCount++;

            if (bitCount == 8) {
                result += currentByte;
                currentByte = 0;
                bitCount = 0;
            }
        }
    }

    char padding = (bitCount > 0) ? (8 - bitCount) : 0;
    result += padding; 

    if (bitCount > 0)
        result += currentByte;

    return result;
}

string HuffmanTree::decompress(const string& compressed) {
    int treeSize = ((unsigned char)compressed[0] << 24) |
                   ((unsigned char)compressed[1] << 16) |
                   ((unsigned char)compressed[2] << 8)  |
                   ((unsigned char)compressed[3]);

    string treeData = compressed.substr(4, treeSize);

    int index = 0;

    root = deserializeTree(treeData, index);
    
    generateCodes(root, "");

    string data = compressed.substr(4 + treeSize);

    int padding = (unsigned char)data[data.size() - 2];

    string result = "";
    Node* curr = root;

    for (int i = 0; i < (int)data.size() - 2; i++) {
        unsigned char byte = data[i];
        for (int b = 7; b >= 0; b--) {
            curr = ((byte >> b) & 1) ? curr->right : curr->left;
            if (!curr->left && !curr->right) {
                result += curr->ch;
                curr = root;
            }
        }
    }

    unsigned char lastByte = data[data.size() - 1];
    for (int b = 7; b >= (int)padding; b--) {
        curr = ((lastByte >> b) & 1) ? curr->right : curr->left;
        if (!curr->left && !curr->right) {
            result += curr->ch;
            curr = root;
        }
    }

    return result;
}