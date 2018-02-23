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
#include "Stack.h"
#include "Que.h"

void linkedListTest();				// runs the various linked list tests that I made while learning about stacks/ques/nodes
void stackTest();					// runs the stack test to verify that the stack works properly
void queTest();						// runs the que test to verify that the que works properly

void menu();						// an algorithm that runs the interface for Lab6
void qPushOrPop();					// gets the user to use push or pop on a que and calls inputVale for push if it is selected
void sPushOrPop();					// gets the user to use push or pop on a stack and calls inputVale for push if it is selected
int inputValue();					// retreivs an integer from the user, validates it, and returns
int inputValidation(int uinput);	// validates the user's input is an integer

#endif