#include "Header.h"

int count(ListNode* head) {
	int count = 0;
	ListNode* curr = head;
	while (curr) {
		curr = curr->next;
		count++;
	}
	return count;
}

ListNode* reverseKGroup(ListNode* head, int k) {

	int size = count(head);
	if (size == 0)
		return nullptr;
	if (size == 1 || size < k)
		return head;

	ListNode* curr = head;
	int i = 0;
	ListNode* prev = nullptr;
	ListNode* next = nullptr;
	ListNode* groupTail = nullptr;
	ListNode* newHead = nullptr;

	ListNode* prevGroupTail = NULL;
	while (curr) {
		if (size - i >= k) // have enough item to  make a group
		{
			int j = 0;
			while (curr && j < k) {
				if (j == 0)
					groupTail = curr;
				if (i == 0)
					prevGroupTail = groupTail;

				next = curr->next;
				curr->next = prev;

				prev = curr;
				curr = next;

				j++;
				i++;

				if (j == k)
					prevGroupTail->next = prev;
			}
			prevGroupTail = groupTail;
			if (i == k)
				newHead = prev;
		}
		else
		{
			if (groupTail)
				groupTail->next = curr;
			break;
		}
		if (i == size)
		{
			if (groupTail)
				groupTail->next = nullptr;
		}
	}
	return newHead;
}


int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	//head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	//head->next->next->next->next->next = new ListNode(6);
	//head->next->next->next->next->next->next = new ListNode(7);

	printLL(reverseKGroup(head, 3));
	//printLL(reverseKGroup(head, 3));

	return 0;
}