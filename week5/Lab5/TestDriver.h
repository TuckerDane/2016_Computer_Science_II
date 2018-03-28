/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 October 2016
//
//	Description:	A series of functions which test the code for the Lab5 project
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TESTDRIVER_HPP
#define TESTDRIVER_HPP

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#include "Matrix.h"
#include "Critter.h"
#include "Ant.h"

void cls();													// windows h function to replace screen with nulls

void displayCritterValues(Critter &critter);				// prints the data members of a given critter
void displayAroundCritter(Matrix &m, Critter &critter);		// prints what is around a critter inside of a given matrix

void testPrintMatrix();										// tests the printMatrix() funciton of Matrix
void testAddCritter();										// tests the addCritter() function of Matrix
void testMatrixAround();									// tests the around() funciton of Matrix
void testCritterMove();										// tests the move() function of Critter
void testCritterBreed();									// tests teh breed() function of Critter
void testMatrixMoveCritters();								// tests the moveCritters() function of Matrix
void testMatrixBreedCritters(int rounds);					// tests teh breedCritters() function of Matrix

void baseAssignment();										// base assignment (no extra credit)
void extraCreditAssignment();								// extra credit assignment
#endif