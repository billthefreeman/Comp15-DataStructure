/*
 * BinarySearchTree.cpp
 */

#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	// TODO: Students write code here
	root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
	// walk tree in post-order traversal and delete
	post_order_delete(root);
}
/*
 * remove all nodes
 */
void BinarySearchTree::post_order_delete(Node *node) {
	// TODO: students write code here
	//  use a post-order traversal to remove all nodes
	if (node != NULL) {
		post_order_delete(node->left);
		post_order_delete(node->right);
		delete node;
	}
}
/* copy constructor
 */
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source) {
	// use pre-order traversal to copy the tree
	root = pre_order_copy(source.root);
}
/*assignment overload
 */
BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &source) {
	// TODO: Students write code here
	// check for self-assignment
	if (this == &source)
		return *this;
	// delete current tree if it exists
	else {
		post_order_delete(root);
		// use pre-order traversal to copy the tree
		root = pre_order_copy(source.root);// Not sure!
		// don't forget to "return *this"
		return *this;
	}
}
/*
 * copy details from the node to a new_node
 */
Node * BinarySearchTree::pre_order_copy(Node *node) {
	// TODO: Students write code here
	//  use a pre-order traversal to copy details from the
	// node to a new_node
	if (node == NULL)
		return NULL;
	Node *new_node = new Node();
	new_node->data = node->data;
	new_node->count = node->count;
	new_node->left = pre_order_copy(node->left);
	new_node->right = pre_order_copy(node->right);

	return new_node;
}
/*
 * find the leftest node's data
 */
int BinarySearchTree::find_min() {
	if (root == NULL)
		return INT_MIN;
	return find_min(root)->data;
}
/*
 * find the leftest node
 */
Node *BinarySearchTree::find_min(Node *node) {
	// TODO: Students write code here
	//recursive call the left subtree
	while (node->left != NULL)
		node = node->left;
	return node;
}
/*
 * find the rightest node's data
 */
int BinarySearchTree::find_max() {
	// TODO: Students write code here
	if (root == NULL)
		return INT_MAX;
	return find_max(root)->data;
}
/*
 * find the rightest node
 */
Node *BinarySearchTree::find_max(Node *node) {
	// TODO: Students write code here
	//recursive call the right subtree
	while (node->right != NULL)
		node = node->right;
	return node;
}

bool BinarySearchTree::contains(int value) {
	// TODO: Students write code here
	// quit if no tree
	if (root == NULL)
		return false;
	return contains(root, value);
}
/*
 * indicate if the value is in the tree
 */
bool BinarySearchTree::contains(Node *node, int value) {
	// TODO: Students write code here
	if (node == NULL)
		return false;
	if (value == node->data)
		return true;
	if (value < node->data)
		return contains(node->left, value);
	if (value > node->data)
		return contains(node->right, value);
	return false;
}

void BinarySearchTree::insert(int value) {
	insert(root, NULL, value);
}
/*inserts a node into the Binary Search Tree
 */
void BinarySearchTree::insert(Node *node, Node *parent, int value) {
	// TODO: Students write code here
	//base case
	if (node == NULL) {
		//create a new node, & initialize it
		node = new Node();
		node->data = value;
		node->count = 1;
		// insert at root
		if (parent == NULL)
			root = node;
		//set the parent's child to the new node
		else if (value < parent->data)
			parent->left = node;
		else
			parent->right = node;
		//recursive call right or left subtree
	} else if (value < node->data) {
		insert(node->left, node, value);
	} else if (value > node->data) {
		insert(node->right, node, value);
	} else
		// if duplicated simply add count
		node->count++;
}
bool BinarySearchTree::remove(int value) {
	return remove(root, NULL, value);
}
/*remove a node of a corresponding value from the Binary Search Tree
 */
bool BinarySearchTree::remove(Node *node, Node *parent, int value) {
	// TODO: Students write code here
	// (cannot be a lazy removal)
	//if there's no node
	if (node == NULL)
		return false;
	//if we find the node we are looking for
	if (node->data == value) {
		//if the node count more than 1 time, decrement the count
		if (node->count > 1) {
			node->count--;
			return true;
		} else {//if the node has no children,just delete the root
			if (node->left == NULL && node->right == NULL) {
				delete node;
				//then, point the parent to NULL
				//according to the position of the parent
				if (parent == NULL) {
					root = NULL;
					return true;
				}
				if (parent->left == node) {
					parent->left = NULL;
					return true;
				} else {
					parent->right = NULL;
					return true;
				}
			}//if the node has 2 children
			if (node->left != NULL && node->right != NULL) {
				//traverse the lefts subtree of the right node
				Node *temp = node->right;
				parent = node;
				while (temp->left != NULL) {
					parent = temp;
					temp = temp->left;
				}
				//copy the most left of the node's right's data
				// to the node
				node->data = temp->data;
				//note that if that node has more than 1 count
				//copy the count as well
				node->count = temp->count;
				// then set that node's count to 1
				// so that it will definitely be deleted
				temp->count = 1;
				return remove(temp, parent, temp->data);
			}// when the node has only 1 child

			//if the the node is the root
			if (node == root) {
				//set temp node to the existing child
				// right child of left child
				// depending on which one is not NULL
				Node *temp = root->left == NULL ? root->right
						: root->left;
				//bypass the node;
				delete root;
				root = temp;
				return true;
			}
			//set temp node to the existing child
			Node *temp = node->left == NULL ? node->right
					: node->left;
			//bypass the node;
			//when child is in the left subtree
			if (node == parent->left) {
				delete node;
				parent->left = temp;
				return true;
			}//bypass the node;
			//when child is in the right subtree
			if (node == parent->right) {
				delete node;
				parent->right = temp;
				return true;
			}
		}
	}
	//when value is smaller, go to & recursively call the left subtree
	if (value < node->data)
		return remove(node->left, node, value);
	//when value is bigger, go to & recursively call the right subtree
	if (node->data < value)
		return remove(node->right, node, value);
	return false;
}

int BinarySearchTree::tree_height() {
	return tree_height(root);
}
/*
 * find the height of a tree
 */
int BinarySearchTree::tree_height(Node *node) {
	// TODO: Students write code here
	if (node == NULL)
		return -1;
	//get the height of left and right subtree
	int Hleft = tree_height(node->left);
	int Hright = tree_height(node->right);
	//increment the bigger one of the left or right height
	if (Hleft > Hright)
		return 1 + Hleft;
	else
		return 1 + Hright;
}

// returns the total number of nodes
int BinarySearchTree::node_count() {
	return node_count(root);
}
/*
 * find the total number of nodes
 */
int BinarySearchTree::node_count(Node *node) {
	// TODO: Students write code here
	//base case: count=0 if no node
	if (node == NULL)
		return 0;
	//add 1 to the sum of the count of the right and left subtree
	return 1 + node_count(node->left) + node_count(node->right);
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() {
	return count_total(root);
}
/*
 * find the sum of all the values in a tree
 */
int BinarySearchTree::count_total(Node *node) {
	// TODO: Students write code here:
	//base case: sum=0 if no node
	if (node == NULL)
		return 0;
	//multiply count with data, then add to the old sum
	return node->count * node->data + count_total(node->left)
			+ count_total(node->right);
}

/*
 * use the printPretty helper to make the tree look nice
 */
void BinarySearchTree::print_tree() {
	printPretty(root, 1, 0, std::cout);
}
/*
 * find the parent node of a node
 */
Node *BinarySearchTree::find_parent(Node *node, Node *child) {
	if (node == NULL)
		return NULL;
	// if either the left or right is equal to the child,
	// we have found the parent
	if (node->left == child || node->right == child) {
		return node;
	}
	// Use the binary search tree invariant to walk the tree
	if (child->data > node->data) {
		return find_parent(node->right, child);
	} else {
		return find_parent(node->left, child);
	}
}
