/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			01 December 2016
//
//	Description:	Assignment 4 for CS162
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
#include "Menu.h"
#include "gameMenu.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	srand(time(NULL));

	cout << "Welcome to the BATTLE ARENA. Its time for players to select their creatures to FIGHT!" << endl << endl;
	gameMenu();

	return 0;
}