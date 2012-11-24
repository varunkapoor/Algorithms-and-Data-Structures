#include "RBTree.h"

RBTree::RBTree() {
	dummy = new Node(BLACK, 0);
	dummy->parent = NULL;
	dummy->left = NULL;
	dummy->right = NULL;
	root = dummy;
	
	preorderTree = new vector<Node*>();
}

RBTree::~RBTree() {
	Node* a;
	while(preorderTree->size() > 0) {
		a = preorderTree->back();
		delete a;
		preorderTree->pop_back(); // Delete the last element
	}
	delete preorderTree;
	delete dummy;
}

// Binary Tree insertion
// Used to setup the initial state of the tree
Node* RBTree::BTinsert(int color, int data) {
	Node* n = new Node(color, data);
	n->parent = dummy;
	n->left = dummy;
	n->right = dummy;
	
	// Find the correct place to put the new Node n
	Node* y = dummy; // Current Parent
	Node* x = root; // Starting Node
	while(x != dummy) {
		y = x;
		// If the new node's key is less than the current Node's key, traverse the left side
		if(n->key < x->key) {
			x = x->left;
		} else { // Otherwise, go to the right
			x = x->right;
		}
	}
	
	// Parent is the last Node traversed that wasn't a dummy node
	n->parent = y;
	
	if(y == dummy) { // List was empty to begin with
		root = n;
	} else if(n->key < y->key) { // New node's key is less than parent (y), n becomes left child
		y->left = n;
	} else {
		y->right = n;
	}
	
	return n;
}

// Insert a new Node into the existing RB tree
Node* RBTree::insert(int data) {
	// Insert as if ordinary Binary Search Tree as a RED node
	Node* n = BTinsert(RED, data);
	
	// Now fix the tree as RB properties may be violated
	Node* gp;
	Node* y;
	while(n->parent->color == RED) {
		gp = getGrandparent(n);
		if(n->parent == gp->left) {
			y = gp->right;
			if(y->color == RED) { // Case 1: Uncle is Red
				n->parent->color = BLACK;
				y->color = BLACK;
				gp->color = RED;
				n = gp;
			} else {
				// Case 2: Uncle is Black, n is a right child of a left child
				// Stretch out into a straight line (transforms into case 3)
				if(n == n->parent->right) {
					n = n->parent;
					rotateLeft(n);
				}
				// Case 3: Uncle is Black, n is a left child of a left child
				n->parent->color = BLACK;
				gp->color = RED;
				rotateRight(gp);
			}
		} else { // When n->parent == gp->right
			// Same as above except swap 'left' and 'right'. Symmetric
			y = gp->left;
			if(y->color == RED) { // Case 4
				n->parent->color = BLACK;
				y->color = BLACK;
				gp->color = RED;
				n = gp;
			} else {
				// Case 5
				if(n == n->parent->left) {
					n = n->parent;
					rotateRight(n);
				}
				// Case 6
				n->parent->color = BLACK;
				gp->color = RED;
				rotateLeft(gp);
			}
		}
	}
	
	// Make sure the root is always black
	root->color = BLACK;
	
	return n;
}

// Private helper function to obtain the grandparent of a Node. Returns NULL if a grandparent doesn't exist
Node* RBTree::getGrandparent(Node* x) {
	/*if(x != dummy && x->parent != dummy && x->parent->parent != dummy) {
		return x->parent->parent;
	}
	return NULL;*/
	return x->parent->parent;
}

// Rotate left operation for maintiaing RB property
void RBTree::rotateLeft(Node* x) {
	if(x->right == dummy)
		return;
	
	Node* y = x->right; // y becomes x's right subtree
	x->right = y->left; // y's left subtree becomes x's right subtree
	if(y->left != dummy)
		y->left->parent = x;
	
	y->parent = x->parent; // Set y's parent to x's parent (x's parent will be fixed last)
	
	if(x->parent == dummy) {
		root = y;
	} else if(x == x->parent->left) {
		x->parent->left = y;
	} else {
		x->parent->right = y;
	}
	
	y->left = x; // x becomes y's left subtree
	x->parent = y; // y becomes x's parent
}

// Rotate right operation for maintiaing RB property (opposite of rotateLeft)
void RBTree::rotateRight(Node* x) {
	if(x->left == dummy)
		return;
	
	Node* y = x->left; // y is x's left subtree
	x->left = y->right; // x's left subtree now becomes y's subtree
	if(y->right != dummy)
		y->right->parent = x;
	
	y->parent = x->parent;
	
	if(x->parent == dummy) { // if x is at the root, y becomes the new root
		root = y;
	} else if(x == x->parent->right) {
		x->parent->right = y;
	} else {
		x->parent->left = y;
	}
	
	y->right = x;
	x->parent = y;
}

///
// Helper Methods

// Generate a preorder vector from the current tree
void RBTree::generatePreorder(Node* x) {
	if(x == NULL || x == dummy)
		return;
		
	preorderTree->push_back(x);
	generatePreorder(x->left);
	generatePreorder(x->right);
}

// Regenerate the preorderTree and print all the Nodes in preorder
// Format: COLOR KEY
string RBTree::printPreorder() {
	preorderTree->clear();
	generatePreorder(root);
	
	stringstream output;
	int s = preorderTree->size();
	Node* x;
	
	// Print number of nodes in the tree onto the screen
	cout << "(" << s << " nodes)" << endl;
	
	// Loop through all nodes in the tree and print their color and key
	for(int i = 0; i < s; i++) {
		x = preorderTree->at(i);
		cout << x->color << " " << x->key << endl;
		output << x->color << " " << x->key << endl;
	}
	if(s > 0) {
		cout << endl;
		output << endl;
	}
	
	return output.str();
}


