#pragma once

#include <iostream>

using namespace std;

struct node {
	int value;
	struct node* left;
	struct node* right;
};


class BinarySearchTree {
public:
	BinarySearchTree();
	~BinarySearchTree();

	//public-facing methods
	void insertInteger(int value);
	void printTree();
	void terminateTree();
	bool searchTree(int searchVal);

	void asdf(BinarySearchTree* someOtherTree);

private:
	//internal methods for modifying the tree
	void insertInteger(node** tree, int value);
	void printTree(node* tree);
	void terminateTree(node* tree);
	bool searchTree(node* tree, int searchVal);

	struct node* root;




};


