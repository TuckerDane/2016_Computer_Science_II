/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	Lab 6 Linked List Assignment tests
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

//***********************************************************************************************
//	Function Definitions
//**********************************************************************************************/
void singleLinkedList();		//	Demonstrates a single linked list
void cSingleLinkedList();		//	Demonstrates a single linked list with a constructor
void traverseLinkedList();		//	Demonstrates traversing and printing out the values in a linked list

//***********************************************************************************************
//	A single linked-list structure with no constructor
//**********************************************************************************************/
struct ListNode
{
	int value;
	ListNode *next;
};

//***********************************************************************************************
//	A single linked-list structure with a constructor
//**********************************************************************************************/
struct cListNode
{
	int value;
	cListNode *next;

	// Constructor
	cListNode(int v, cListNode *n = NULL)
	{
		value = v;
		next = n;
	}
};

#endif