#include "Header.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int ListLength(ListNode* A)
{
	int len = 1;
	ListNode* temp = A;
	while (temp->next)
	{
		len++;
		temp = temp->next;
	}
	return len;
}

ListNode* ReverseLinkList(ListNode* A)
{
	ListNode *curNode = A, *nxtNode;
	ListNode *first = NULL;

	// Until no more in list, insert current before first and advance.
	while (curNode != NULL) {
		// Need to save next node since we're changing the current.
		nxtNode = curNode->next;

		// Insert at start of new list.
		curNode->next = first;
		first = curNode;

		// Advance to next.
		curNode = nxtNode;
	}
	return first;
}

ListNode* MergeTwoLinkedLists(ListNode* A, ListNode* B)
{
	B = ReverseLinkList(B);
	ListNode* tmpA = A;
	ListNode* tmpB = B;
	ListNode* tmpANxt = NULL;
	ListNode* tmpBNxt = NULL;
	while (tmpA && tmpB)
	{
		tmpANxt = tmpA->next;
		tmpA->next = tmpB;

		tmpBNxt = tmpB->next;
		tmpB->next = tmpANxt;

		tmpA = tmpANxt;
		tmpB = tmpBNxt;
	}
	if (tmpB)
	{
		tmpA = A;
		while (tmpA)
		{
			if (tmpA->next == NULL)
			{
				tmpA->next = tmpB;
				break;
			}
			tmpA = tmpA->next;
		}
	}
	return A;
}

ListNode* reorderList(ListNode* A) {

	int len = ListLength(A);
	int halfLen = ceil(len / 2);
	ListNode* B = NULL;
	int i = 1;
	ListNode* temp = A;
	while (temp->next)
	{
		if (i == halfLen)
		{
			B = temp->next;
			temp->next = NULL;
			break;
		}
		temp = temp->next;
		i++;
	}

	return MergeTwoLinkedLists(A, B);
}

int main()
{
	// {1,2,3,4,5,6}
	ListNode* n7 = new ListNode(7);
	ListNode* n6 = new ListNode(6);
	n6->next = n7;
	ListNode* n5 = new ListNode(5);
	n5->next = n6;
	ListNode* n4 = new ListNode(4);
	n4->next = n5;
	ListNode* n3 = new ListNode(3);
	n3->next = n4;
	ListNode* n2 = new ListNode(2);
	n2->next = n3;
	ListNode* n1 = new ListNode(1);
	n1->next = n2;

	ListNode* reordered = reorderList(n1);

	return 0;
}