/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	A series of functions which test the code for the Assignment3 project
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TESTDRIVER_HPP
#define TESTDRIVER_HPP

#include "creature.h"
#include "Vampire.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"
#include "Die.h"

void displayCreatureValues(Creature &creature);								// prints the data members of a given creature
void testCreature(Creature &c);												// creates a creature, displays its values, and demonstrates its functions
void testCreatures();														// creates all of the creatures and tests them individually
void testCreatureCombat(Creature &creature1, Creature &creature2);			// tests two creatures against one another in combat
void testAllCreatures();													// tests all combination of creatures against one another in combat
void resetCreature(Creature &c);											// resets the values of a creature to its default

#endif