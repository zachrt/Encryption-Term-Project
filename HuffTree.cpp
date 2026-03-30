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
	
	// Prevents issues if run with empty queue due to queue tests
	if (n == nullptr) {
		return;
	}

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
		cout << ")";
	}
	cout << endl;
}

void HuffTree::generateCodes(Node* n, string code) {
	if (n->left == nullptr && n->right == nullptr) {
		if (code == "") {
			code = "0";
		}
		n->code = code;

		// Testing
		cout << "'" << n->ch << "' --> " << code << endl;

	}
	else {
		generateCodes(n->left, code + "0");
		generateCodes(n->right, code + "1");
	}
}