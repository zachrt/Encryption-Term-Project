#include <vector>
#include <string>
#include <iostream>
#include "Node.h"
#include "PriorityQueue.h"

using namespace std;

class HuffTree {
	private:
		Node* root;
	public:
		HuffTree();

		void buildTreeFromQueue(PriorityQueue source);
		
		Node* getRoot();

		void testPrint(Node* n, int depth);

		
};