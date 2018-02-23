/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			26 November 2016
//
//	Description:	Assignment 3 for CS162
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include <string>

#include "TestDriver.h"
#include "creature.h"
#include "Vampire.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"
#include "Die.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	srand(time(NULL));

	testAllCreatures();

	return 0;
}