/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	A Que Class for CS162 Assignment 6
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef QUE_H
#define QUE_H

#include <iostream>
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
	struct node
	{
		int value;
		node *next;
		node *previous;

		// constructor for a new node
		node(int v, node *n = NULL, node *p = NULL)
		{
			value = v;
			next = n;
			previous = p;
		}
	};

	// points to the front of the que
	node *front;

	// points to the back of the que
	node *back;

public:

	Que();					// default constructor
	~Que();					// destructor

	void push(int num);		// takes a value (num), creates a node, sets the value to the data part of the node, adjusts pointers
	int pop();				// returns an int from the top of the stack, removes the top node, adjusts poiners
	bool empty();			// returns true if the stack is empty, returns false if it is not

};

#endif