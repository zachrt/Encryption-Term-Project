#include "PriorityQueue.h"

// Helper function to handle both primary priority (frequency) and tie-breaking (character)
bool isHigherPriority(Node* a, Node* b) {
    if (a->freq != b->freq) {
        return a->freq < b->freq;
    }
    // Tie-breaker: sort by character value if frequencies are identical
    return a->ch < b->ch;
}

void PriorityQueue::push(Node* n) {
    data.push_back(n);

    // Start sifting up from the newly added element at the end
    int i = data.size() - 1;

    while (i > 0) {
        // Standard 0-indexed min-heap parent formula
        int parent = (i - 1) / 2;
        
        if (isHigherPriority(data[i], data[parent])) {
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
    // Replace the root with the last element
    data[0] = data.back(); 
    data.pop_back();

    int i = 0;
    
    // Sift down
    while (true) {
        int left  = 2 * i + 1;
        int right = 2 * i + 2;
        int lowest = i;

        if (left < data.size() && isHigherPriority(data[left], data[lowest]))
            lowest = left;
        if (right < data.size() && isHigherPriority(data[right], data[lowest]))
            lowest = right;

        if (lowest != i) {
            Node* temp = data[lowest];
            data[lowest] = data[i];
            data[i] = temp;
            i = lowest;
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