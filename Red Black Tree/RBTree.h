#ifndef _RBTREE_H_
#define _RBTREE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define RED 0
#define BLACK 1

typedef struct Node_t {
	Node_t(int c, int val) { 
		color = c;
		key = val;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
	int key;
	int color;
	struct Node_t* parent;
	struct Node_t* left;
	struct Node_t* right;
} Node;

class RBTree {
private:
	Node* root;
	Node* dummy;
	vector<Node*> *preorderTree;
	
private:
	Node* getGrandparent(Node* x);
	
	void rotateLeft(Node* x);
	void rotateRight(Node* x);
	
	void generatePreorder(Node* x);

	// Binary Tree removal methods
	void BTremove(Node* n);
	void BTremove(int data);

public:
	RBTree();
	~RBTree();
	
	// Operations
	Node* BTinsert(int color, int data); // Binary Tree insert (for initial nodes)
	Node* insert(int data);
	void remove();
	
	// Helper methods
	string printPreorder();
};

#endif

