/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	A Que Class for CS162 Assignment 4 that holds a que of creatures
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Que.h"
#include <string>

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
	if (this->empty() == false)						// if the que is not empty				
	{
		creatureNode *backPtr = back;				// starts at the back of the que

		while (backPtr != front)					// while there is more than one node in the que
		{
			creatureNode *garbage = backPtr;		// trails backPtr for deletion of memory
			backPtr = backPtr->next;				// move on to the next node
			delete garbage->fighter;				// delete the creature stored in the node
			delete garbage;							// delete garbage trailing node
		}

		delete front->fighter;						// delete the last fighter in the circular que
		delete front;								// delete the last node in the circular que
	}
}

//***********************************************************************************************
//	push: takes a value (num), creates a node, sets the value to the data part of 
//	the node, adjusts pointers
//**********************************************************************************************/
void Que::push(Creature *c)
{
	if (this->empty() == true)						// if this is the first element to be put into the que
	{
		back = new creatureNode(c, front, front);	// point the back to this element, and point the previous/next to front so that it is circular
		front = back;								// AND point the front to this element
	}
	else											// otherwise the que is not empty
	{
		creatureNode *tempBack = back;				// create a temp ptr to adjust the old Back once a new node is created
		back = new creatureNode(c, back, front);	// create a new node and adjust the back pointer
		tempBack->previous = back;					// re-set the old back node's previous pointer from NULL to the new back
		front->next = back;							// set the next pointer after front to back so that it remains circular.
	}
}

//***********************************************************************************************
//	pop: returns an int from the front of the que, removes the front node, adjusts pointers
//**********************************************************************************************/
Creature* Que::pop()
{
	if (back != NULL)							// if the que is not empty
	{
		Creature *tempF = front->fighter;		// set a temp var that holds the value at the front of the que

		if (back == front)						// if there is only one node in the que
		{
			delete back;						// delete the node
			back = NULL;						// set back to NULL
			front = NULL;						// set front to NULL
			return tempF;						// return tempF
		}
		else									// else there is more than one node in the que
		{
			creatureNode *tempFront = front;	// set a temp var that points to the front of the que


			front = front->previous;			// set front to the new front of the que (previous)
			front->next = back;					// adjust pointer
			back->previous = front;				// adjust pointer

			delete tempFront;					// delete the node at the front of the que

			return tempF;						// returns the data that was in the front node
		}

	}
	else										// else throw an error
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

//***********************************************************************************************
//	empty: returns true if the stack is empty, returns false if it is not
//**********************************************************************************************/
void Que::rotate()
{
	if (back != front)
	{
		front = front->previous;
		back = back->previous;
	}
}

//***********************************************************************************************
//	displays the fighters in the que
//**********************************************************************************************/
void Que::displayQue()
{
	creatureNode *temp = front;
	int counter = 1;

	while (temp != back)
	{
		cout << "Fighter " << counter << " is: " << temp->fighter->getFighterName() << endl;
		temp = temp->previous;
		counter++;
	}

	cout << "Fighter " << counter << " is: " << temp->fighter->getFighterName() << endl;
}

//***********************************************************************************************
//	returns a pointer to the fighter at the front of the que
//**********************************************************************************************/
Creature* Que::getFront()
{
	if (this->front == NULL)
	{
		return NULL;
	}
	else
	{
		return this->front->fighter;
	}
}