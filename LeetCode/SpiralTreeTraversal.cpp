#include "Header.h"

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int d) : val(d), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> vOuter;
	vector<int> vInner;

	if (!root)
		return vOuter;

	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	s1.push(root);
	while (!s1.empty())
	{
		TreeNode* n1 = s1.top();
		cerr << n1->val << " ";
		vInner.push_back(n1->val);
		if (n1->left)
			s2.push(n1->left);
		if (n1->right)
			s2.push(n1->right);
		s1.pop();
		if (s1.empty())
		{
			vOuter.push_back(vInner);
			vInner.clear();
			while (!s2.empty())
			{
				TreeNode* n2 = s2.top();
				cerr << n2->val << " ";
				vInner.push_back(n2->val);
				if (n2->right)
					s1.push(n2->right);
				if (n2->left)
					s1.push(n2->left);
				s2.pop();
				if (s2.empty())
				{
					vOuter.push_back(vInner);
					vInner.clear();
				}
			}
		}
	}
	return vOuter;
}

void InsertChildNode(TreeNode* root, TreeNode* nl, TreeNode* nr)
{
	root->left = nl;
	root->right = nr;
}

int main()
{
	TreeNode* root = new TreeNode(0);

	TreeNode* n1 = new TreeNode(2);
	TreeNode* n2 = new TreeNode(4);
	InsertChildNode(root, n1, n2);

	TreeNode* n3 = new TreeNode(1);
	InsertChildNode(n1, n3, nullptr);

	TreeNode* n4 = new TreeNode(3);
	TreeNode* n5 = new TreeNode(-1);
	InsertChildNode(n2, n4, n5);

	TreeNode* n6 = new TreeNode(5);
	TreeNode* n7 = new TreeNode(1);
	InsertChildNode(n3, n6, n7);

	TreeNode* n8 = new TreeNode(6);
	InsertChildNode(n4, nullptr, n8);

	TreeNode* n9 = new TreeNode(8);
	InsertChildNode(n5, nullptr, n9);

	printVectorOfVector(zigzagLevelOrder(root));
	return 0;
}