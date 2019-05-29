#include "Header.h"

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int d, Node* l = NULL, Node* r = NULL) : data(d), left(l), right(r) {}
};


int main()
{
	// 3 5 2 1 4 6 7
	//       3
	//	    / \
	//	   2   5
	//	  /   / \
	//	 1   4   6
	//	          \
	//	           7

	Node* root = new Node(3, new Node(2), new Node(5));
	Node* n1 = root->left;
	Node* n2 = root->right;


	return 0;
}