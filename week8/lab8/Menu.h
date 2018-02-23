/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	Lab 6 Linked List Assignment Menu, also contains a couple of test functions
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MENU_H
#define MENU_H

#include "LinkedList.h"
#include "Que.h"

void linkedListTest();				// runs the various linked list tests that I made while learning about stacks/ques/nodes
void queTest();						// runs the que test to verify that the que works properly

void menu();						// an algorithm that runs the interface for Lab6
int inputValue();					// retreivs an integer from the user, validates it, and returns
int inputValidation(int uinput);	// validates the user's input is an integer

#endif