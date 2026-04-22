#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int cap) : capacity(cap), currentSize(0) {
    data = new Node*[capacity]; // Manual memory allocation
}

PriorityQueue::~PriorityQueue() {
    delete[] data; // Clean up the raw array
}

bool PriorityQueue::isHigherPriority(Node* a, Node* b) {
    if (a->freq != b->freq) return a->freq < b->freq;
    return a->ch < b->ch;
}

void PriorityQueue::push(Node* n) {
    if (currentSize == capacity) return; // Basic overflow protection
    data[currentSize] = n;
    bubbleUp(currentSize);
    currentSize++;
}

void PriorityQueue::bubbleUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (isHigherPriority(data[i], data[parent])) {
            Node* temp = data[parent];
            data[parent] = data[i];
            data[i] = temp;
            i = parent;
        } else break;
    }
}

Node* PriorityQueue::pop() {
    if (currentSize == 0) return nullptr;
    Node* top = data[0];
    data[0] = data[currentSize - 1]; // Move last to root
    currentSize--;
    bubbleDown(0);
    return top;
}

void PriorityQueue::bubbleDown(int i) {
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int lowest = i;
        if (left < currentSize && isHigherPriority(data[left], data[lowest])) lowest = left;
        if (right < currentSize && isHigherPriority(data[right], data[lowest])) lowest = right;
        if (lowest != i) {
            Node* temp = data[lowest];
            data[lowest] = data[i];
            data[i] = temp;
            i = lowest;
        } else break;
    }
}

bool PriorityQueue::isEmpty() { return currentSize == 0; }
int PriorityQueue::size() { return currentSize; }