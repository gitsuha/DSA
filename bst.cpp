#include "Header.h"

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int d, Node* l = NULL, Node* r = NULL) : data(d), left(l), right(r) {}
};

void inorder(const Node* root)
{

}

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
	n1->left = new Node(1);
	n2->left = new Node(4);
	n2->right = new Node(6, NULL, new Node(7));

	return 0;
}