/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	A Que Class for CS162 Assignment 4 that holds a que of creatures
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef QUE_H
#define QUE_H

#include <iostream>
#include "creature.h"
using std::cin;
using std::cout;
using std::endl;

//***********************************************************************************************
//	A Que Class
//**********************************************************************************************/
class Que
{
protected:

	// declare a structure for each node in the que
	struct creatureNode
	{
		Creature *fighter;
		creatureNode *next;
		creatureNode *previous;

		// constructor for a new node
		creatureNode(Creature *c, creatureNode *n = NULL, creatureNode *p = NULL)
		{
			fighter = c;
			next = n;
			previous = p;
		}
	};

	// points to the front of the que
	creatureNode *front;

	// points to the back of the que
	creatureNode *back;

public:

	Que();						// default constructor
	~Que();						// destructor

	void push(Creature *c);		// takes a value (num), creates a node, sets the value to the data part of the node, adjusts pointers
	Creature* pop();			// returns an int from the top of the stack, removes the top node, adjusts poiners
	bool empty();				// returns true if the stack is empty, returns false if it is not
	void rotate();				// moves the fighter at the front of the que to the back
	void displayQue();			// displays the fighters in the que
	Creature* getFront();		// returns a pointer to the creature at the front of the que
};

#endif