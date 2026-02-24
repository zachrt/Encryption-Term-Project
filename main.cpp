#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cassert>

#include "Node.h"
#include "PriorityQueue.h"

using namespace std;

unordered_map<char, int> getFrequencies(string input) {
    unordered_map<char, int> freqMap;

    for (int i = 0; i < input.length(); i++) {
        freqMap[input[i]]++;
    }

    return freqMap;
}

int main() {

    string input;
    cout << "Enter a string: ";
    
    getline(cin, input);

    if (input.empty()) {
        cout << endl << "You didn't enter anything!" << endl;

        return 0;
    }

    unordered_map<char, int> freqMap = getFrequencies(input);

    PriorityQueue pq;

    for (auto x : freqMap) {
        Node* n = new Node(x.first, x.second);
        pq.push(n);
    }

    cout << "\nCharacter Frequencies (highest to lowest):" << endl;
    cout << "-------------------------------------------" << endl;

    while (!pq.isEmpty()) {
        Node* n = pq.pop();
        cout << "'" << n->ch << "' --> " << n->freq << endl;
        delete n;
    }

    return 0;
}
