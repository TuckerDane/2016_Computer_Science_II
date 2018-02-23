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
//	Que default constructor
//**********************************************************************************************/
Que::Que()
{
	back = NULL;
	front = back;
}

//***********************************************************************************************
//	Stack destructor
//**********************************************************************************************/
Que::~Que()
{
	queNode *backPtr = back;		// starts at the back of the que

	while (backPtr->value != -1)	// while the que is not empty
	{
		queNode *garbage = backPtr;	// trails backPtr for deletion of memory
		backPtr = backPtr->next;	// move on to the next node
		delete garbage;				// delete garbage trailing node
	}
}

//***********************************************************************************************
//	addBack: takes a value (num), creates a node, sets the value to the data part of 
//	the node, adjusts pointers
//**********************************************************************************************/
void Que::addBack(int num)
{
	if (this->empty() == true)						// if this is the initial member of the que
	{
		back = new queNode(num, back, back);		// point the back to this element, and point the previous/next to front so that it is circular								
													// AND point the front to this element
		back->next = back;
		back->previous = back;
		front = back;
	}
	else if (back == front && back->value == -1)	// if there is only one queNode and it is empty
	{
		back->value = num;							// set the queNode
	}
	else if (back == front && back->value > 0)		// if there is only one queNode and it is not empty
	{
		back = new queNode(num, back, front);		// set the queNode
		back->next->previous = back;
	}
	else if (back->value == -1)						// if the que has open space
	{
		queNode *temp = back;						// make a temp que to find the furthest front open space

		while (temp->next->value < 0)				// move to the furthest forward open space
		{
			temp = temp->next;
		}

		temp->value = num;							// set the value in that open space to num
	}
	else											// otherwise the que is full
	{
		queNode *tempBack = back;					// create a temp ptr to adjust the old Back once a new node is created
		back = new queNode(num, back, front);		// create a new node and adjust the back pointer
		tempBack->previous = back;					// re-set the old back node's previous pointer from NULL to the new back
		front->next = back;							// set the next pointer after front to back so that it remains circular
	}
}

//***********************************************************************************************
//	pop: returns an int from the front of the que, removes the front node, adjusts pointers
//**********************************************************************************************/
int Que::removeFront()
{
	if (back->value != -1)				// if the que is not empty
	{
		int tempVal = front->value;		// set a temp var that holds the value at the front of the que

		queNode *tempFront = front;		// set a temp var that points to the front of the que
		
		front = front->previous;		// set front to the new front of the que (previous)
		front->next->value = -1;		// adjust node

		return tempVal;					// returns the data that was in the front node
	}
	else								// else the que is empty, cannot remove
	{
		cout << "ERROR, cannot removeFront, que is empty" << endl;
		return -1;
	}
}

//***********************************************************************************************
//	empty: returns true if the que is initially empty, returns false if it is not
//**********************************************************************************************/
bool Que::empty()
{
	if (back == NULL)
		return true;
	else
		return false;
}

//***********************************************************************************************
//	displays the values in the que
//**********************************************************************************************/
void Que::displayQue()
{
	queNode *temp = front;
	int counter = 1;

	while (temp != back)
	{
		cout << "Value " << counter << " is: " << temp->value << endl;
		temp = temp->previous;
		counter++;
	}

	cout << "Value " << counter << " is: " << temp->value << endl;
}

//***********************************************************************************************
//	displays the values in the front of the que
//**********************************************************************************************/
int Que::getFront()
{
	return front->value;
}