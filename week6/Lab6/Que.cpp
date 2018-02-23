/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	A Que Class for CS162 Assignment 6
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Que.h"

//***********************************************************************************************
//	Stack default constructor
//**********************************************************************************************/
Que::Que()
{
	front = NULL;
	back = NULL;
}

//***********************************************************************************************
//	Stack destructor
//**********************************************************************************************/
Que::~Que()
{
	node *backPtr = back;			// starts at the back of the que

	while (backPtr != NULL)			// while the que is not empty
	{
		node *garbage = backPtr;	// trails backPtr for deletion of memory
		backPtr = backPtr->next;	// move on to the next node
		delete garbage;				// delete garbage trailing node
	}
}

//***********************************************************************************************
//	push: takes a value (num), creates a node, sets the value to the data part of 
//	the node, adjusts pointers
//**********************************************************************************************/
void Que::push(int num)
{
	if (this->empty() == true)			// if this is the first element to be put into the que
	{
		back = new node(num);			// point the back to this element
		front = back;					// AND point the front to this element
	}
	else								// otherwise the que is not empty
	{
		node *tempBack = back;			// create a temp ptr to adjust the old Back once a new node is created
		back = new node(num, back);		// create a new node and adjust the back pointer
		tempBack->previous = back;		// re-set the old back node's previous pointer from NULL to the new back
	}

}

//***********************************************************************************************
//	pop: returns an int from the front of the que, removes the front node, adjusts pointers
//**********************************************************************************************/
int Que::pop()
{
	if (back != NULL)						// if the que is not empty
	{
		int tempVal = front->value;			// set a temp var that holds the value at the front of the que

		if (back == front)					// if there is only one node in the que
		{
			delete back;					// delete the node
			back = NULL;					// set back to NULL
			front = NULL;					// set front to NULL
			return tempVal;					// return tempVal
		}
		else								// else there is more than one node in the que
		{
			node *tempFront = front;		// set a temp var that points to the front of the que


			front = front->previous;		// set front to the new front of the que (previous)
			front->next = NULL;				// adjust pointer

			delete tempFront;				// delete the node at the front of the que

			return tempVal;					// returns the data that was in the front node
		}

	}
	else									// else throw an error
	{
		cout << "ERROR, cannot pop, que is empty" << endl;
		return NULL;
	}
}

//***********************************************************************************************
//	empty: returns true if the stack is empty, returns false if it is not
//**********************************************************************************************/
bool Que::empty()
{
	if (back == NULL)
		return true;
	else
		return false;
}