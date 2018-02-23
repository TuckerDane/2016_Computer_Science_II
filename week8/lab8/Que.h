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
	struct queNode
	{
		int value;
		queNode *next;
		queNode *previous;

		// constructor for a new node
		queNode(int v, queNode *n = NULL, queNode *p = NULL)
		{
			value = v;
			next = n;
			previous = p;
		}
	};

	// points to the front of the que
	queNode *front;

	// points to the back of the que
	queNode *back;

public:

	Que();					// default constructor
	~Que();					// destructor

	void addBack(int num);	// takes a value (num), sets the value at the back of the que to the num. if none exists, creates a new node
	int removeFront();		// returns an int from the front of the que, readjusts the value to -1, adjusts poiners
	bool empty();			// returns true if the stack is empty, returns false if it is not
	void displayQue();		// displays the que
	int getFront();			// displays the value of the front queNode

};

#endif