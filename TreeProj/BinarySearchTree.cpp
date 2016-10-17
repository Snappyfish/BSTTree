#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
	terminateTree(root);
}


//public-facing methods, essentially just wrapper methods which mean root isn't exposed to external classes
void BinarySearchTree::insertInteger(int value) {
	insertInteger(&root, value);
}

void BinarySearchTree::printTree() {
	printTree(root);
}

void BinarySearchTree::terminateTree() {
	terminateTree(root);
	root = nullptr;			//null the root node!
}

bool BinarySearchTree::searchTree(int searchVal) {
	return searchTree(root, searchVal);
}

void BinarySearchTree::asdf(BinarySearchTree* someOtherTree) {
	someOtherTree->root->value++;
}


//internal methods for modifying the tree
void BinarySearchTree::insertInteger(struct node** tree, int value) {
	//if the node is empty, stick the number in there
	node* treePtr = *tree; //for convenience

	if (treePtr == nullptr) {
		node* newNode = new node();
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
			insertInteger(&(treePtr->left), value);
		}
		else {
			insertInteger(&(treePtr->right), value);
		}
	}
}


void BinarySearchTree::printTree(struct node* tree) {
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


void BinarySearchTree::terminateTree(struct node* tree) {
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


bool BinarySearchTree::searchTree(struct node* tree, int searchVal) {
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


