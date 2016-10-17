#pragma once

#include <iostream>

using namespace std;

template <typename T>
struct node {
	T value;
	node* left;
	node* right;
};


template <typename T>
class BinarySearchTreeTemplate
{
public:
	BinarySearchTreeTemplate();
	~BinarySearchTreeTemplate();


	//public-facing methods
	void insertType(T value);
	void printTree();
	void terminateTree();
	bool searchTree(T searchVal);



protected:
	//internal methods for modifying the tree
	void insertType(node<T>** tree, T value);
	void printTree(node<T>* tree);
	void terminateTree(node<T>* tree);
	bool searchTree(node<T>* tree, T searchVal);

	node<int>* root;
	
	T currentType;	//for checking input type is same as the Tree's current type
	

};




//.ccp file bits; the actual implementation

template <typename T>
BinarySearchTreeTemplate<T>::BinarySearchTreeTemplate() {
	root = nullptr;

}

template <typename T>
BinarySearchTreeTemplate<T>::~BinarySearchTreeTemplate() {
	terminateTree(root);

}


//public-facing methods, essentially just wrapper methods which mean root isn't exposed to external classes
template <typename T>
void BinarySearchTreeTemplate<T>::insertType(T value) {
	insertType(&root, value);
}

template <typename T>
void BinarySearchTreeTemplate<T>::printTree() {
	printTree(root);
}

template <typename T>
void BinarySearchTreeTemplate<T>::terminateTree() {
	terminateTree(root);
	root = nullptr;			//null the root node!
}

template <typename T>
bool BinarySearchTreeTemplate<T>::searchTree(T searchVal) {
	return searchTree(root, searchVal);
}




//internal methods for modifying the tree
template <typename T>
void BinarySearchTreeTemplate<T>::insertType(node<T>** tree, T value) {
	//if the node is empty, stick the number in there
	node<int>* treePtr = *tree; //for convenience

	if (treePtr == nullptr) {
		node<int>* newNode = new node<int>();
		*tree = newNode;

		newNode->value = value;
		newNode->left = nullptr;
		newNode->right = nullptr;
		return;
	}

	else { //else, check if it's higher or lower then go into that node
		if (treePtr->value == value) { //ignore duplicate entries
			return;
		}
		else if (treePtr->value > value) {
			insertType(&(treePtr->left), value);
		}
		else {
			insertType(&(treePtr->right), value);
		}
	}
}

template <typename T>
void BinarySearchTreeTemplate<T>::printTree(node<T>* tree) {
	//safety check if it's null
	if (tree == nullptr) {
		return;
	}

	//go as far left as possible
	if (tree->left != nullptr) {
		printTree(tree->left);
	}

	//then print out the node's value
	cout << tree->value << " ";

	//then go right if possible
	if (tree->right != nullptr) {
		printTree(tree->right);
	}

	return;
}

template <typename T>
void BinarySearchTreeTemplate<T>::terminateTree(node<T>* tree) {
	//safety check if it's null
	if (tree == nullptr) {
		return;
	}

	//go left if possible
	if (tree->left != nullptr) {
		terminateTree(tree->left);
	}
	//else go right if possible
	if (tree->right != nullptr) {
		terminateTree(tree->right);
	}

	//then delete the node itself
	delete tree;

	return;
}

template <typename T>
bool BinarySearchTreeTemplate<T>::searchTree(node<T>* tree, T searchVal) {
	//safety check if the root is null
	if (tree == nullptr) {
		return false;
	}

	//if it matches, we're done
	else if (tree->value == searchVal) {
		return true;
	}

	//else, check if the node exists and if the searched value is lower than the current node (if it is, go left)
	else if (
		tree->left != nullptr &&			//if left isn't null AND
		searchVal < tree->value &&			//if the searched for value is less than the current node's value AND
		searchTree(tree->left, searchVal)	//the search down the left-side node returns true theeeeen
		) {

		return true;						//we're in business, return true to the search above
	}

	//eeeelse, it has to be greater on the right side
	else if (tree->right != nullptr && searchTree(tree->right, searchVal)) {
		return true;
	}

	return false;
}


