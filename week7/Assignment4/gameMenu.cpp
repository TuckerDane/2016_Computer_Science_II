/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	Lab 6 Linked List Assignment Menu, also contains a couple of test functions
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gameMenu.h"
#include "Stack.h"
#include "Que.h"
#include "InputValidation.h"

#include <limits>
#include <string>

//***********************************************************************************************
//	an algorithm that runs the interface for the Assignment 4 game
//**********************************************************************************************/
void gameMenu()
{
	Que team1;
	Que team2;
	Stack losers;

	int team1Score = 0;
	int team2Score = 0;

	int t1Fighters = 0;
	int t2Fighters = 0;
	int numFighters = 0;

	cout << "How many fighters (between 1 and 10) will be on a team? ";
	cin >> numFighters;
	cout << endl;

	numFighters = boundsValidation(numFighters, 1, 10);

	int choice;
	bool end = false;
	while (end == false)
	{
		cout << "1: Enter Fighters for Team 1" << endl;
		cout << "2: Enter Fighters for Team 2" << endl;
		cout << "3: Display Team 1 Fighters" << endl;
		cout << "4: Display Team 2 Fighters" << endl;
		cout << "5: Display Losers" << endl;
		cout << "6: Battle" << endl;
		cout << "7: Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid choice. Please try again" << std::endl << std::endl;
			continue;
		}

		// adds a creature to team 1
		if (choice == 1)
		{
			while (t1Fighters < numFighters)
			{
				team1.push(inputCreature());
				t1Fighters++;
			}

			if (team1.empty() == true)
			{
				cout << "NO TEAM ONE FIGHTERS" << endl << endl;
			}
			else
			{
				cout << "TEAM ONE FIGHTERS: " << endl;
				team1.displayQue();
				cout << endl;
			}
		}
		// adds a creature to team 2
		else if (choice == 2)
		{
			while (t2Fighters < numFighters)
			{
				team2.push(inputCreature());
				t2Fighters++;
			}

			if (team2.empty() == true)
			{
				cout << "NO TEAM TWO FIGHTERS" << endl << endl;
			}
			else
			{
				cout << "TEAM TWO FIGHTERS: " << endl;
				team2.displayQue();
				cout << endl;
			}
		}
		// displays team 1 fighters
		else if (choice == 3)
		{
			if (team1.empty() == true)
			{
				cout << "NO TEAM ONE FIGHTERS" << endl << endl;
			}
			else
			{
				cout << "TEAM ONE FIGHTERS: " << endl;
				team1.displayQue();
				cout << endl;
			}
		}
		// displays team 2 fighters
		else if (choice == 4)
		{
			if (team2.empty() == true)
			{
				cout << "NO TEAM TWO FIGHTERS" << endl <<  endl;
			}
			else
			{
				cout << "TEAM TWO FIGHTERS: " << endl;
				team2.displayQue();
				cout << endl;
			}
		}
		// displays losing fighters
		else if (choice == 5)
		{
			if (losers.empty() == true)
			{
				cout << "NO LOSERS" << endl << endl;
			}
			else
			{
				cout << "LOSING FIGHTERS: " << endl;
				losers.displayStack();
				cout << endl;
			}
		}
		// initiates battle
		else if (choice == 6)
		{
			// if neither team has the specified number of fighters, no fight can start
			if (t1Fighters != numFighters || t2Fighters != numFighters)
			{
				cout << "Both teams must have " << numFighters << " to initiate a battle!!" << endl << endl;
			}
			// otherwise the teams do have the specified number of fighters and the battle commences
			else
			{
				int roundCounter = 0;
				while (team1.getFront() != NULL && team2.getFront() != NULL)				// while at least one team still has creatures in their que
				{
					roundCounter++;
					cout << "ROUND " << roundCounter<< "!!!" << endl;						// display the round of combat
					if (creatureCombat(team1.getFront(), team2.getFront()) == true)			// if team1's creature wins
					{
						team1.rotate();														// rotate team1's creature to the back of the line
						losers.push(team2.pop());											// push the team2 loser onto the loser's stack
						team1Score++;														// add 1 to team 1's score
					}
					else																	// otherwise team2's creature wins
					{
						team2.rotate();														// rotate team2's creature to the back of the line
						losers.push(team1.pop());											// push the team1 loser onto the loser's stack
						team2Score++;														// add 1 to team 2's score
					}
				}
				if (team1.getFront() == NULL)
				{
					cout << endl;
					cout << "-----------------------------------" << endl;
					cout << "   TEAM 2 WINS BY ELIMINATION" << endl;
					cout << "-----------------------------------" << endl;
				}
				else
				{
					cout << endl;
					cout << "-----------------------------------" << endl;
					cout << "   TEAM 1 WINS BY ELIMINATION" << endl;
					cout << "-----------------------------------" << endl;
				}

				cout << "   KOs: " << endl;
				cout << "   Team 1 knocked out " << team1Score << " fighters" << endl;
				cout << "   Team 2 knocked out " << team2Score << " fighters" << endl;
				cout << "-----------------------------------" << endl << endl;
			}
		}
		// quit
		else if (choice == 7)
		{
			end = true;
		}
		// error
		else
		{
			std::cout << "Invalid choice. Please try again." << std::endl << std::endl;
		}
	}
}

/***************************************************************************************************
**	begins combat between two creatures - returns "true" if team 1's fighter wins
***************************************************************************************************/
bool creatureCombat(Creature *creature1, Creature *creature2)
{
	cout << endl << creature1->getName() << " " << creature1->getFighterName() << " and " << creature2->getName() << " " << creature2->getFighterName() << " ENGAGE IN COMBAT!" << endl << endl;

	while (creature1->getStrength() > 0 && creature2->getStrength() > 0)										// while neither creature is dead
	{
		cout << creature1->getFighterName() << " attacks " << creature2->getFighterName() << endl;			// creature1 attacks creature2
		creature2->applyDamage(creature2->defend(creature1->attack()));
		cout << endl << endl;

		if (creature2->getStrength() > 0)																	// if neither creature2 is not now dead...
		{
			cout << creature2->getFighterName() << " attacks " << creature1->getFighterName() << endl;		// creature2 attacks creature1
			creature1->applyDamage(creature1->defend(creature2->attack()));
			cout << endl << endl;
		}
	}

	if (resolveCombat(creature1, creature2) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/***************************************************************************************************
**	resolves combat between two creatures - returns "true" if team 1's fighter wins
***************************************************************************************************/
bool resolveCombat(Creature *c1, Creature *c2)
{
	if (c1->getStrength() <= 0)
	{
		cout << c1->getFighterName() << " lost! " << c1->getFighterName() << " goes to the loser's pile!" << endl;
		cout << c2->getFighterName() << " won with " << c2->getStrength() << " strength remaining!" << endl;
		c2->replenish();

		return false;
	}
	else //(c2->getStrength() <= 0)
	{
		cout << c2->getFighterName() << " lost! " << c2->getFighterName() << " goes to the loser's pile!" << endl;
		cout << c1->getFighterName() << " won with " << c1->getStrength() << " strength remaining!" << endl;
		c1->replenish();

		return true;
	}
}