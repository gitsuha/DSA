#include <iostream>
#include <string>

using namespace std;

 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	// This one have number overflow issue
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *tmpNode = l1;
		int n1 = 0, n2 = 0, i = 0;
		while (tmpNode != NULL)
		{
			n1 += tmpNode->val*pow(10, i);
			tmpNode = tmpNode->next;
			i++;
		}
		cout << n1 << endl;
		tmpNode = l2; i = 0;
		while (tmpNode != NULL)
		{
			n2 += tmpNode->val*pow(10, i);
			tmpNode = tmpNode->next;
			i++;
		}
		cout << n2 << endl;
		int n = n1 + n2;
		string s = to_string(n);
		cout << s << endl;
		ListNode* head = new ListNode(0);
		tmpNode = head;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			int val = s.at(i) - '0';
			if (i == s.length() - 1)
				tmpNode->
				val = val;
			else
			{
				ListNode* node = new ListNode(val);
				tmpNode->next = node;
				tmpNode = node;
			}
		}
		return head;
	}

	// Optimal solution
	ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
		ListNode* tmp1 = l1;
		ListNode* tmp2 = l2;
		int carryOver = 0;
		ListNode* head = new ListNode(0);
		ListNode* tmp = NULL;
		bool bHead = true;
		while (tmp1 != NULL || tmp2 != NULL)
		{
			int val1 = 0, val2 = 0;
			if (tmp1) {
				val1 = tmp1->val;
				tmp1 = tmp1->next;
			}
			if (tmp2) {
				val2 = tmp2->val;
				tmp2 = tmp2->next;
			}			

			int val = val1 + val2 + carryOver;
			bool bCarr = false;
			if (val > 9) {
				val -= 10;
				bCarr = true;
			}
			ListNode* node = new ListNode(val);
			if (bCarr)
				carryOver = 1;
			else
				carryOver = 0;

			if (bHead) {
				head = node;
				bHead = false;
				tmp = node;
			}
			else
			{
				tmp->next = node;
				tmp = node;
			}			
		}
		if (carryOver == 1)
		{
			ListNode* node = new ListNode(carryOver);
			tmp->next = node;
		}
		return head;
	}
};

int main()
{
	ListNode* l1 = new ListNode(1);
	//ListNode* l11 = new ListNode(4);
	//l1->next = l11;
	//ListNode* l12 = new ListNode(3);
	//l11->next = l12;

	ListNode* l2 = new ListNode(9);
	ListNode* l21 = new ListNode(9);
	l2->next = l21;
	//ListNode* l22 = new ListNode(4);
	//l21->next = l22;

	Solution s;
	ListNode* L = s.addTwoNumbers2(l1, l2);

	return 0;
}