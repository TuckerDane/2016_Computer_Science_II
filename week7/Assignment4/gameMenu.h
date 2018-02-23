/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	Lab 6 Linked List Assignment Menu, also contains a couple of test functions
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "Menu.h"
#include "Stack.h"
#include "Que.h"
#include "Vampire.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"

void gameMenu();													// an algorithm that runs the interface for the Assignment 4 game
bool creatureCombat(Creature *creature1, Creature *creature2);		// begins combat between two creatures - returns "true" if team 1's fighter wins
bool resolveCombat(Creature *c1, Creature *c2);						// resolves combat between two creatures - returns "true" if team 1's fighter wins

#endif