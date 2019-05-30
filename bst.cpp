#include <assert.h>
#include <limits>
#include <iostream>
#include <random>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <iterator>
#include <thread>
#include <stack>
#include <numeric>
#include <queue>
#include <unordered_set>

using namespace std;

#pragma warning(disable  : 4996)

template <class T>
void printVector(vector<T> v)
{
	for (T& i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int d, Node* l = NULL, Node* r = NULL) : data(d), left(l), right(r) {}
};

vector<int> sorted;
void inorder(const Node* n)
{
	if (n != NULL)
	{
		inorder(n->left);
		cout << n->data;
		sorted.push_back(n->data);
		inorder(n->right);
	}
}

int height(const Node* n)
{
	if (n == NULL)
		return -1;
	int leftHeight = height(n->left);
	int rightHeight = height(n->right);
	return max(leftHeight, rightHeight) + 1;
}

void insertNode(Node*& root, int key)
{
	if (root == nullptr)
		root = new Node(key);
	else if (key < root->data)
		insertNode(root->left, key);
	else
		insertNode(root->right, key);
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

	//Node* root = new Node(3, new Node(2), new Node(5));
	//Node* n1 = root->left;
	//Node* n2 = root->right;
	//n1->left = new Node(1);
	//n2->left = new Node(4);
	//n2->right = new Node(6, NULL, new Node(7));

	Node* root = NULL;
	vector<int> v = { 3, 5, 2, 1, 4, 6, 7 };
	for (int k : v)
		insertNode(root, k);

	inorder(root);
	cout << endl;
	cout << height(root);
	cout << endl;
	//cout << checkBST(root);
	cout << endl;

	system("pause");
	return 0;
}