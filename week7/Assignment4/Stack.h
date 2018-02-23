/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	A Stack Class for CS162 Assignment 4 that holds a stack of creatures
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "creature.h"

using std::cin;
using std::cout;
using std::endl;

//***********************************************************************************************
//	A Stack Class to hold Creature pointers
//**********************************************************************************************/
class Stack
{
protected:

	// declare a structure for each node in the stack
	struct  creatureNode
	{
		Creature *fighter;
		creatureNode *next;

		//	constructor for a new node
		creatureNode(Creature *c, creatureNode *n = NULL)
		{
			fighter = c;
			next = n;
		}
	};

	// points to the top of the stack
	creatureNode *top;

public:
	Stack();						// default constructor
	~Stack();						// destructor

	void push(Creature *c);			// takes a Creature pointer, creates a node, sets the value to the data part of the node, adjusts pointers
	Creature* pop();				// returns a Creature from the top of the stack, removes the top node, adjusts pointers
	bool empty();					// returns true if the stack is empty, returns false if it is not
	void displayStack();			// displays the fighters in the stack
};

#endif