#include "HuffTree.h"

using namespace std;



// Public
HuffTree::HuffTree() {
	root = nullptr;
}


void HuffTree::buildTreeFromQueue(PriorityQueue source) {
	while (!source.isEmpty()) {

		Node* n1 = source.pop();

		if (!source.isEmpty()) {
			Node* n2 = source.pop();
			Node* newNode = new Node('*', n1->freq + n2->freq);
			newNode->left = n1;
			newNode->right = n2;
			root = newNode;
			source.push(newNode);
		}
		else {
			root = n1;
		}
	}
}

Node* HuffTree::getRoot() {
	return root;
}

// Traverses and prints for testing purposes
void HuffTree::testPrint(Node* n, int depth) {
	for (int i = 0; i < depth; i++) {
		cout << "    ";
	}
	cout << "'" << n->ch << "' " << n->freq;
	if (n->left != nullptr) {
		cout << "(" << endl;
		
		testPrint(n->left, depth + 1);
		if (n->right != nullptr) {
			testPrint(n->right, depth + 1);
		}
		for (int i = 0; i < depth; i++) {
			cout << "    ";
		}
		cout << ")" << endl;
	}
	cout << endl;
}