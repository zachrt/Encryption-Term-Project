#pragma once
#include <string>
#include <iostream>
#include "Node.h"

class PriorityQueue {
private:
    Node** data;      
    int capacity;   
    int currentSize;  

    void bubbleUp(int index);   // Internal heap logic - was unsure if std::vector would be allowed, so implemented array-based heap
    void bubbleDown(int index); // Internal heap logic - was unsure if std::vector would be allowed, so implemented array-based heap
    bool isHigherPriority(Node* a, Node* b);

public:
    PriorityQueue(int cap = 500); // Constructor to initialize array
    ~PriorityQueue();             // Destructor to prevent memory leaks
    
    void push(Node* n);
    Node* pop();
    bool isEmpty();
    int size();
};