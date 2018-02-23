/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	Lab 6 Linked List Assignment tests
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "LinkedList.h"

using std::cout;
using std::endl;

//***********************************************************************************************
//	Demonstrates a single linked list
//**********************************************************************************************/
void singleLinkedList()
{
	ListNode *head;

	// Create first node with 1
	head = new ListNode;											// allocate new node
	head->value = 1;												// store the value
	head->next = NULL;												// signify end of list

	// Create second node with 2
	ListNode *secondPtr = new ListNode;
	secondPtr->value = 2;
	secondPtr->next = NULL;											// second node is end of list
	head->next = secondPtr;											// first node points to second

																	// Print the list
	cout << "First item is " << head->value << endl;				// prints "First item is 1"
	cout << "Second item is " << head->next->value << endl;			// prints "Second item is 2"

	delete head->next;
	delete head;
}

//***********************************************************************************************
//	Demonstrates a single linked list with a constructor
//**********************************************************************************************/
void cSingleLinkedList()
{
	cListNode *head = new cListNode(4);								// create second node and set head to it
	head = new cListNode(3, head);									// create first node, point it to what head is pointing to, and re-point head to the new first node

	cout << "First item is " << head->value << endl;				// prints "First item is 3"
	cout << "Second item is " << head->next->value << endl;			// prints "Second item is 4"

	// garbage collection
	delete head->next;
	delete head;
}

//***********************************************************************************************
//	Demonstrates traversing and printing out the values in a linked list
//**********************************************************************************************/
void traverseLinkedList()
{
	cListNode *head = new cListNode(4);		// create a node (value 4) and set head to it
	head = new cListNode(3, head);			// create a new node (value 3) and set head to it
	head = new cListNode(2, head);			// create a new node (value 2) and set head to it
	head = new cListNode(1, head);			// create a new node (value 1) and set head to it

	cListNode *ptr = head;

	// should print: "1 2 3 4"
	while (ptr != NULL)						// while there is still a node to process
	{
		cout << ptr->value << " ";			// process node
		ptr = ptr->next;					// move to next node
	}
	
	//garbage collection
	ptr = NULL;
	delete head->next->next->next;
	delete head->next->next;
	delete head->next;
	delete head;
}