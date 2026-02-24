#include <vector>
#include <string>
#include <iostream>

#include "Node.h"

using namespace std;
class PriorityQueue {
public:
    vector<Node*> data;

    void push(Node* n);
    Node* pop();
    bool isEmpty();
    int size();
};