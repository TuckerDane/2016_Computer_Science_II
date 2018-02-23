/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	A series of functions which test the code for the Assignment4 project
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "TestDriver.h"

#include <string>
using std::cout;
using std::endl;
using std::cin;

/***************************************************************************************************
**	prints the data members of a given creature
***************************************************************************************************/
void displayCreatureValues(Creature &creature)
{
	cout << "Name: " << creature.getName() << endl;
	cout << "Armor: " << creature.getArmor() << endl;
	cout << "Strength: " << creature.getStrength() << endl;
}

/***************************************************************************************************
**	creates a creature named creature, displays its values, and demonstrates its functions
***************************************************************************************************/
void testCreature(Creature &c)
{
	cout << "The " << c.getName() << " has the following values:" << endl << endl;
	displayCreatureValues(c);
	cout << endl;

	cout << c.getName() << " will demonstrate a series of 10 attacks:" << endl;

	for (int i = 0; i < 11; i++)
	{
		cout << c.getName() << " attacks and rolls a: " << c.attack() << endl;
	}
	cout << endl;

	cout << c.getName() << " will demonstrate a defense against 10 attacks:" << endl;
	for (int i = 0; i < 11; i++)
	{
		cout << c.getName() << " defends against " << i << " damage and returns " << c.defend(i) << endl;
	}
	cout << endl;

	cout << c.getName() << " will demonstrate applied damage against attacks until dead" << endl;
	bool dead = false;
	while (dead == false)
	{
		cout << c.getName() << "'s strength is " << c.getStrength() << endl;
		cout << c.getName() << " defends against " << 10 << " damage and applies it" << endl;
		c.applyDamage(c.defend(10));
		cout << c.getName() << "'s strength is now " << c.getStrength() << endl;
		if (c.getStrength() == 0)
		{
			dead = true;
			cout << endl << c.getName() << " IS NOW DEAD!!" << endl << endl;
		}
	}
}

/***************************************************************************************************
**	creates all of the creatures and tests them individually
***************************************************************************************************/
void testCreatures()
{
	Vampire Vamp;
	Barbarian Barb;
	BlueMen Blue;
	Medusa Med;
	HarryPotter Harry;

	testCreature(Vamp);
	testCreature(Barb);
	testCreature(Blue);
	testCreature(Med);
	testCreature(Harry);
}

/***************************************************************************************************
**	tests combat between two creatures
***************************************************************************************************/
void testCreatureCombat(Creature &creature1, Creature &creature2)
{
	cout << creature1.getName() << " and " << creature2.getName() << " engage in combat!" << endl << endl;

	displayCreatureValues(creature1);														// display creature values
	cout << endl;
	displayCreatureValues(creature2);
	cout << endl;

	while (creature1.getStrength() > 0 && creature2.getStrength() > 0)						// while neither creature is dead
	{
		cout << creature1.getName() << " attacks " << creature2.getName() << endl;			// creature1 attacks creature2
		creature2.applyDamage(creature2.defend(creature1.attack()));
		cout << endl << endl;

		if (creature2.getStrength() > 0)													// if neither creature2 is not now dead...
		{
			cout << creature2.getName() << " attacks " << creature1.getName() << endl;		// creature2 attacks creature1
			creature1.applyDamage(creature1.defend(creature2.attack()));
			cout << endl << endl;
		}
	}

	displayCreatureValues(creature1);														// display creature values
	cout << endl;
	displayCreatureValues(creature2);
	cout << endl;
}

/***************************************************************************************************
**	tests all combination of creatures against one another in combat
***************************************************************************************************/
void testAllCreatures()
{
	Vampire V;
	Barbarian B;
	BlueMen BM;
	Medusa M;
	HarryPotter H;

	Vampire V2;
	Barbarian B2;
	BlueMen BM2;
	Medusa M2;
	HarryPotter H2;

	Creature *creatures[5] = { &V, &B, &BM, &M, &H };
	Creature *creatures2[5] = { &V2, &B2, &BM2, &M2, &H2 };

	int choice1;
	int choice2;

	bool end = false;
	while (end == false)
	{
		cout << "Which creature would you like to see fight?" << endl << endl;

		cout << "1: Vampire" << endl;
		cout << "2: Barbarian" << endl;
		cout << "3: Blue Men" << endl;
		cout << "4: Medusa" << endl;
		cout << "5: Harry Potter" << endl;
		cout << "6: Leave Combat Mode" << endl << endl;

		cout << "Enter your choice: ";
		cin >> choice1;
		cout << endl;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid choice. Please try again" << endl << endl;
			continue;
		}

		if (choice1 > 0 && choice1 < 6)
		{
			cout << "Which creature would you like " << creatures[choice1 - 1]->getName() << " to fight against?" << endl;
			cout << "Enter your choice: ";
			cin >> choice2;
			cout << endl;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid choice. Please try again" << endl << endl;
				continue;
			}

			if (choice2 > 0 && choice2 < 6)
			{
				testCreatureCombat(*creatures[choice1 - 1], *creatures2[choice2 - 1]);		// test the creatures in combat against one another
				cout << "resetting creatures" << endl << endl;
				resetCreature(*creatures[choice1 - 1]);										// reset the creatures so the simulation can run again
				resetCreature(*creatures2[choice2 - 1]);
			}
			else if (choice2 == 6)
				end = true;
			else cout << "Invalid choice. Please try again." << endl << endl;

		}
		else if (choice1 == 6)
			end = true;
		else
			cout << "Invalid choice. Please try again." << endl << endl;
	}
}

/***************************************************************************************************
**	resets the values of a creature to its default
***************************************************************************************************/
void resetCreature(Creature &c)
{
	if (c.getName() == "Vampire")
	{
		c.setStrength(18);
	}
	else if (c.getName() == "Barbarian")
	{
		c.setStrength(12);
	}
	else if (c.getName() == "Blue Men")
	{
		c.setStrength(12);
	}
	else if (c.getName() == "Medusa")
	{
		c.setStrength(8);
	}
	else if (c.getName() == "Harry Potter")
	{
		c.setStrength(12);
		Creature *ptr = &c;
		dynamic_cast<HarryPotter*> (ptr)->setResurrected(false);
	}
}