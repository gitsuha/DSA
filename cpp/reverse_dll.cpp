#include "Header.h"

struct DoublyLinkedListNode {
	int data;
	DoublyLinkedListNode* next;
	DoublyLinkedListNode* prev;
	DoublyLinkedListNode(int i) : data(i)
	{
		next = prev = NULL;
	}
};

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
	DoublyLinkedListNode* temp = head;
	while (temp->next)
	{
		DoublyLinkedListNode* nextTemp = temp->next;
		DoublyLinkedListNode* prevTemp = temp->prev;

		temp->prev = nextTemp;
		temp->next = prevTemp;

		temp = nextTemp;
	}

	DoublyLinkedListNode* nextTemp = temp->next;
	DoublyLinkedListNode* prevTemp = temp->prev;

	temp->prev = nextTemp;
	temp->next = prevTemp;

	return temp;
}

int main()
{
	DoublyLinkedListNode* n1 = new DoublyLinkedListNode(1);
	DoublyLinkedListNode* n2 = new DoublyLinkedListNode(2);
	DoublyLinkedListNode* n3 = new DoublyLinkedListNode(3);
	DoublyLinkedListNode* n4 = new DoublyLinkedListNode(4);

	n1->next = n2;

	n2->prev = n1; 
	n2->next = n3;

	n3->prev = n2;
	n3->next = n4;

	n4->prev = n3;

	DoublyLinkedListNode* revHead = reverse(n1);

	return 0;
}
