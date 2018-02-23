/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 November 2016
//
//	Description:	Lab 6 Linked List Assignment Menu, also contains a couple of test functions
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Menu.h"
#include "Stack.h"
#include "Que.h"

#include <limits>
#include <string>

//***********************************************************************************************
//	an algorithm that runs the interface for Lab6
//**********************************************************************************************/
void menu()
{
	int choice;
	bool end = false;
	while (end == false)
	{
		cout << "1: Work with a Stack" << endl;
		cout << "2: Work with a Que" << endl;
		cout << "3: Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << std::endl;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid choice. Please try again" << std::endl << std::endl;
			continue;
		}

		if (choice == 1)
		{
			sPushOrPop();
		}
		else if (choice == 2)
		{
			qPushOrPop();
		}
		else if (choice == 3)
		{
			end = true;
		}
		else
		{
			std::cout << "Invalid choice. Please try again." << std::endl << std::endl;
		}
	}
}

//***********************************************************************************************
//	gets the user to use push or pop on a que and calls inputVale for push if it is selected
//**********************************************************************************************/
void qPushOrPop()
{
	Que q;

	cout << "Working with a que. The que is currently empty." << endl << endl;

	int choice;
	bool end = false;
	while (end == false)
	{
		std::cout << "1: Push" << std::endl;
		std::cout << "2: Pop" << std::endl;
		std::cout << "3: Return to Stack or Que" << std::endl << endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		std::cout << std::endl;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid choice. Please try again" << std::endl << std::endl;
			continue;
		}

		if (choice == 1)
		{
			q.push(inputCreature());
		}
		else if (choice == 2)
		{
			if (q.empty() == true)
			{
				cout << "Cannot pop; the que is empty!!" << endl << endl;
			}
			else
			{
				q.displayQue();
				int rotations;
				cout << "how many rotations? ";
				cin >> rotations;
				cout << endl;

				for (int i = 0; i < rotations; i++)
				{
					q.rotate();
				}

				cout << "Popped off : " << q.pop()->getFighterName() << endl << endl;
			}
		}
		else if (choice == 3)
		{
			end = true;
		}
		else
		{
			std::cout << "Invalid choice. Please try again." << std::endl << std::endl;
		}
	}
}

//***********************************************************************************************
//	gets the user to use push or pop on a stack and calls inputVale for push if it is selected
//**********************************************************************************************/
void sPushOrPop()
{
	Stack s;

	cout << "Working with a stack. The stack is currently empty." << endl << endl;

	int choice;
	bool end = false;
	while (end == false)
	{
		std::cout << "1: Push" << std::endl;
		std::cout << "2: Pop" << std::endl;
		std::cout << "3: Return to Stack or Que" << std::endl << endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		std::cout << std::endl;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid choice. Please try again" << std::endl << std::endl;
			continue;
		}

		if (choice == 1)
		{
			s.push(inputCreature());
		}
		else if (choice == 2)
		{
			if (s.empty() == true)
			{
				cout << "Cannot pop; the stack is empty!!" << endl << endl;
			}
			else
			{
				cout << "Popped off : " << s.pop()->getFighterName() << endl << endl;
			}
		}
		else if (choice == 3)
		{
			end = true;
		}
		else
		{
			std::cout << "Invalid choice. Please try again." << std::endl << std::endl;
		}
	}
}

//***********************************************************************************************
//	has the user choose a creature and its name
//**********************************************************************************************/
Creature* inputCreature()
{
	cout << "Coose a creature type to add to your fighter list: " << endl;
	
	int choice;
	bool end = false;
	while (end == false)
	{
		std::cout << "1: Vampire" << std::endl;
		std::cout << "2: Barbarian" << std::endl;
		std::cout << "3: Blue Men" << std::endl;
		std::cout << "4: Medusa" << std::endl;
		std::cout << "5: Harry Potter" << std::endl << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid choice. Please try again" << std::endl << std::endl;
			continue;
		}

		if (choice == 1)
		{
			Creature *tempF = new Vampire;		// creates a new creature of the selected type
			return nameFighter(tempF);			// returns a pointer to the named fighter
		}
		else if (choice == 2)
		{
			Creature *tempF = new Barbarian;	// creates a new creature of the selected type
			return nameFighter(tempF);			// returns a pointer to the named fighter
		}
		else if (choice == 3)
		{
			Creature *tempF = new BlueMen;		// creates a new creature of the selected type
			return nameFighter(tempF);			// returns a pointer to the named fighter
		}
		else if (choice == 4)
		{
			Creature *tempF = new Medusa;		// creates a new creature of the selected type
			return nameFighter(tempF);			// returns a pointer to the named fighter
		}
		else if (choice == 5)
		{
			Creature *tempF = new HarryPotter;	// creates a new creature of the selected type
			return nameFighter(tempF);			// returns a pointer to the named fighter
		}
		else
		{
			std::cout << "Invalid choice. Please try again." << std::endl << std::endl;
		}
	}
}

/***************************************************************************************************
**	names a fighter
***************************************************************************************************/
Creature* nameFighter(Creature *c)
{
	string fighterName;															// holds the user-defined name of the fighter

	cout << "What do you want your " << c->getName() << "'s name to be? ";
	cin >> fighterName;															// user inputs name of fighter
	cout << endl;

	c->setFighterName(fighterName);											// sets the fighter name to user input
	return c;
}

//***********************************************************************************************
//	runs the stack test to verify that the stack works properly
//**********************************************************************************************/
void stackTest()
{
	cout << "Demonstration of a Stack of creatures using a singly-linked list: " << endl;
	cout << "Adding Vampire, Barbarian, Blue Men, Medusa, Harry Potter to stack, in order" << endl << endl;

	cout << "..." << endl << endl;

	Stack s;

	s.push(new Vampire);
	s.push(new Barbarian);
	s.push(new BlueMen);
	s.push(new Medusa);
	s.push(new HarryPotter);


	cout << "..." << endl << endl;
	cout << "Stack complete" << endl << endl;

	cout << "Now displaying stack, in reverse order as elements are popped off of the top: " << endl << endl;

	while (s.empty() == false)
	{
		cout << s.pop()->getName() << endl;	// Harry Potter, Medusa, Blue Men, Barbarian, Vampire
	}
	cout << endl;
}

//***********************************************************************************************
//	runs the que test to verify that the que works properly
//**********************************************************************************************/
void queTest()
{
	cout << "Demonstration of a Que using a doubly-linked list: " << endl;
	cout << "Adding Vampire, Barbarian, Blue Men, Medusa, Harry Potter to stack, in order" << endl << endl;

	cout << "..." << endl << endl;

	Que q;
	q.push(new Vampire);
	q.push(new Barbarian);
	q.push(new BlueMen);
	q.push(new Medusa);
	q.push(new HarryPotter);

	cout << "..." << endl << endl;
	cout << "Que complete" << endl << endl;

	cout << "Now displaying que, in order as elements are popped off of the front: " << endl << endl;

	while (q.empty() == false)
	{
		cout << q.pop()->getName() << endl;	// Vampire, Barbarian, Blue Men, Medusa, Harry Potter
	}
	cout << endl;
}
