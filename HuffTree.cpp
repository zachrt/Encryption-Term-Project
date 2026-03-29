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

void HuffTree::testPrint(Node* n) {
	cout << n->ch << " " << n->freq;
	if (n->left != nullptr) {
		cout << " (";
		testPrint(n->left);
		if (n->right != nullptr) {
			cout << ", ";
			testPrint(n->right);
		}
		cout << ") ";
	}
}