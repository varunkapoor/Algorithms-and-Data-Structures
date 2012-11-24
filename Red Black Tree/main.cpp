#include <iostream>
#include <fstream>
#include <string>

#include "RBTree.h"

using namespace std;

// Prototypes
bool RBread(string filename, RBTree* rbt, string* output);
bool RBwrite(string filename, string* contents);

// Reads in a valid RB tree from the provided input file (in preorder) and handles any insertions after the initial
// tree is setup. Text output is stored in the output string which will later be written by the RBwrite function
bool RBread(string filename, RBTree* rbt, string* output) {
	cout << "Reading input file " << filename << endl;
	
	ifstream fin(filename.c_str());
	if(!fin.is_open()) {
		cout << "Input file could not be opened!\n";
		return false;
	}
	
	// Read number of lines for initial values
	int lines = 0;
	fin >> lines;
	
	// Insert the inital BT tree nodes
	// Loop through each line inserting the properly colored node and value
	int color = 0;
	int value = 0;
	for(int i = 0; i < lines; i++) {
		fin >> color;
		fin >> value;
		rbt->BTinsert(color, value);
	}
	
	cout << "Initial RB tree" << endl;
	rbt->printPreorder();
	
	// Now read the number of lines of nodes to insert into the tree
	lines = 0;
	fin >> lines;
	
	// Insert the new values into the RB tree which will fix the tree automatically with rotations if necessary
	for(int i = 0; i < lines; i++) {
		fin >> value;
		rbt->insert(value);
		// Print to screen
		cout << "Insert: " << value << endl;
		output->append(rbt->printPreorder());
	}
	
	fin.close();
	return true;
}

// Write the output from the RBread operation to a specified output file
bool RBwrite(string filename, string* contents) {
	cout << "Writing output file " << filename << endl;
	
	ofstream fout;
	fout.open(filename.c_str(), ios::out);
	if(!fout.is_open()) {
		cout << "Output file could not be opened!" << endl;
		return false;
	}
	
	fout << contents->c_str();
	
	fout.close();
	return true;
}

int main(int argv, char** argc) {
	// Check for the input file argument
	if(argv != 2) {
		cout << "Invalid number of arguments." << endl;
		cout << "Usage: rbtree <input_file.txt>" << endl;
		return -1;
	}
	
	RBTree* rbt = new RBTree();
	string filename = argc[1];
	string contents;
	
	// Read from input file, which will setup the tree and perform the proper insertions
	if(!RBread(filename, rbt, &contents)) {
		cout << "RBread was unsuccessful, terminating program" << endl;
		delete rbt;
		return -1;
	}
	
	// Write the output of the RBread operation to the output file
	if(!RBwrite("output.txt", &contents)) {
		cout << "RBwrite was unsuccessful, terminating program" << endl;
		delete rbt;
		return -1;
	}
	
	return 0;
}
