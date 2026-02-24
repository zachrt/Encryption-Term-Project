#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

#include "Node.h"
#include "PriorityQueue.h"

using namespace std;

class FrequencyAnalysis {
private:
    string input;
    unordered_map<char,int> freqMap;     
    PriorityQueue pq;         
    vector<Node*> nodes;

public:
    FrequencyAnalysis();
    ~FrequencyAnalysis();

    void setInput(string& s);

    string& getInput();
    void buildFrequencyMap();

    unordered_map<char,int>& getFrequencyMap();

    void buildPriorityQueue();

    void run() {
        buildFrequencyMap();
        buildPriorityQueue();
    }

    void printResults();

    int  getFrequency(char c);
    int  uniqueCount();
    bool hasRun();
    PriorityQueue& getPQ();
};