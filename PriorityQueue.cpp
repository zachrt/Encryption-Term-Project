#include "PriorityQueue.h"

void PriorityQueue::push(Node* n) {
    data.push_back(n);

    int i = data.size() - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (data[parent]->freq < data[i]->freq) {
            Node* temp = data[parent];
            data[parent] = data[i];
            data[i] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

Node* PriorityQueue::pop() {
    if (data.empty()) return nullptr;

    Node* top = data[0];
    data[0] = data[data.size() - 1];
    data.pop_back();

    int i = 0;
    while (true) {
        int left  = 2 * i + 1;
        int right = 2 * i + 2;
        int biggest = i;

        if (left < data.size() && data[left]->freq > data[biggest]->freq)
            biggest = left;
        if (right < data.size() && data[right]->freq > data[biggest]->freq)
            biggest = right;

        if (biggest != i) {
            Node* temp = data[biggest];
            data[biggest] = data[i];
            data[i] = temp;
            i = biggest;
        } else {
            break;
        }
    }

    return top;
}

bool PriorityQueue::isEmpty() {
    return data.empty();
}

int PriorityQueue::size() {
    return data.size();
}
