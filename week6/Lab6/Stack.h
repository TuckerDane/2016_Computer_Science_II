/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	A Stack Class for CS162 Assignment 6
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef STACK_H
#define STACK_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//***********************************************************************************************
//	A Stack Class
//**********************************************************************************************/
class Stack
{
protected:

	// declare a structure for each node in the stack
	struct node
	{
		int value;
		node *next;

		//	constructor for a new node
		node(int v, node *n = NULL)
		{
			value = v;
			next = n;
		}
	};

	// points to the top of the stack
	node *top;

public:

	Stack();				// default constructor
	~Stack();				// destructor

	void push(int num);		// takes a value (num), creates a node, sets the value to the data part of the node, adjusts pointers
	int pop();				// returns an int from the top of the stack, removes the top node, adjusts poiners
	bool empty();			// returns true if the stack is empty, returns false if it is not

};

#endif