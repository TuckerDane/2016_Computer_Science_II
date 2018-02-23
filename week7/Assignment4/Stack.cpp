/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	A Stack Class for CS162 Assignment 4 that holds a stack of creatures
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Stack.h"
#include <string>

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
	creatureNode *topPtr = top;				// starts at the top of the stack

	while (topPtr != NULL)					// while the stack is not empty
	{
		creatureNode *garbage = topPtr;		// trails topPtr for deletion of memory
		topPtr = topPtr->next;				// move on to the next node
		delete garbage->fighter;			// delete the creature stored in the node
		delete garbage;						// delete garbage trailing node
	}
}

//***********************************************************************************************
//	Stack push: takes a value (num), creates a node, sets the value to the data part of 
//	the node, adjusts pointers
//**********************************************************************************************/
void Stack::push(Creature *c)
{
	top = new creatureNode(c, top);
}

//***********************************************************************************************
//	Stack pop: returns an int from the top of the stack, removes the top node, adjusts poiners
//**********************************************************************************************/
Creature* Stack::pop()
{
	if (top != NULL)						// if the stack is not empty
	{
		creatureNode *temp = top;			// set a temp var that points to the top of the stack
		Creature *tempF = top->fighter;		// set a temp var that holds the value of the fighter at the top of the stack
		top = top->next;					// re-sets top to the next node in the stack
		delete temp;						// deletes the top node in the stack
		return tempF;						// returns the fighter that was in the top node
	}
	else									// else throw an error
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

//***********************************************************************************************
//	displays the fighters in the stack
//**********************************************************************************************/
void Stack::displayStack()
{
	creatureNode *temp = top;
	int counter = 1;

	while (temp != NULL)
	{
		cout << temp->fighter->getFighterName() << endl;
		temp = temp->next;
		counter++;
	}
}