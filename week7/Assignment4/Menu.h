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

#include "Stack.h"
#include "Que.h"
#include "Vampire.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"

void stackTest();					// runs the stack test to verify that the stack works properly
void queTest();						// runs the que test to verify that the que works properly

void menu();						// an algorithm that runs the interface for Lab6
void qPushOrPop();					// gets the user to use push or pop on a que and calls inputCreature for push if it is selected
void sPushOrPop();					// gets the user to use push or pop on a stack and calls inputCreature for push if it is selected
Creature* inputCreature();			// has the user choose a creature and its name
Creature* nameFighter(Creature *c);	// names a fighter

#endif