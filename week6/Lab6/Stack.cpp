/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	A Stack Class for CS162 Assignment 6
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Stack.h"

//***********************************************************************************************
//	Stack default constructor
//**********************************************************************************************/
Stack::Stack()
{
	top = NULL;
}

//***********************************************************************************************
//	Stack destructor
//**********************************************************************************************/
Stack::~Stack()
{
	node *topPtr = top;				// starts at the top of the stack

	while (topPtr != NULL)			// while the stack is not empty
	{
		node *garbage = topPtr;		// trails topPtr for deletion of memory
		topPtr = topPtr->next;		// move on to the next node
		delete garbage;				// delete garbage trailing node
	}
}

//***********************************************************************************************
//	Stack push: takes a value (num), creates a node, sets the value to the data part of 
//	the node, adjusts pointers
//**********************************************************************************************/
void Stack::push(int num)
{
	top = new node(num, top);
}

//***********************************************************************************************
//	Stack pop: returns an int from the top of the stack, removes the top node, adjusts poiners
//**********************************************************************************************/
int Stack::pop()
{
	if (top != NULL)				// if the stack is not empty
	{
		node *temp = top;			// set a temp var that points to the top of the stack
		int tempVal = top->value;	// set a temp var that holds the value at the top of the stack
		top = top->next;			// re-sets top to the next node in the stack
		delete temp;				// deletes the top node in the stack
		return tempVal;				// returns the data that was in the top node
	}
	else							// else throw an error
	{
		cout << "ERROR, cannot pop, stack is empty" << endl;
		return NULL;
	}
}

//***********************************************************************************************
//	Stack empty: returns true if the stack is empty, returns false if it is not
//**********************************************************************************************/
bool Stack::empty()
{
	if (top == NULL)
		return true;
	else
		return false;
}