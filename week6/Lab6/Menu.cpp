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
#include "LinkedList.h"
#include "Stack.h"
#include "Que.h"

#include <limits>

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
			q.push(inputValue());
		}
		else if (choice == 2)
		{
			if (q.empty() == true)
			{
				cout << "Cannot pop; the que is empty!!" << endl << endl;
			}
			else
			{
				cout << "Popped off : " << q.pop() << endl << endl;
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
			s.push(inputValue());
		}
		else if (choice == 2)
		{
			if (s.empty() == true)
			{
				cout << "Cannot pop; the stack is empty!!" << endl << endl;
			}
			else
			{
				cout << "Popped off : " << s.pop() << endl << endl;
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
//	retreivs an integer from the user, validates it, and returns
//**********************************************************************************************/
int inputValue()
{
	int push;

	cout << "Enter an integer to push: ";
	cin >> push;

	push = inputValidation(push);
	return push;
}

/***************************************************************************************************
**	validates the user's input is an integer
***************************************************************************************************/
int inputValidation(int uinput)
{
	while (std::cin.fail())																// while uinput is not considered valid
	{
		if (std::cin.fail())															// if uinput is not a valid integer, throw an error and have the user enter a new uinput
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Incorrect input, re-enter " << std::endl;
			std::cin >> uinput;
		}
		if (!std::cin.fail())															// if uinput is a valid integer, break out of the while loop
		{
			break;
		}
	}

	return uinput;																		// the uinput must be an integer, return uinput
}

//***********************************************************************************************
//	runs the various linked list tests that I made while learning about stacks/ques/nodes
//**********************************************************************************************/
void linkedListTest()
{
	cout << "Demonstration of single linked list: " << endl;
	singleLinkedList();
	cout << endl << endl;

	cout << "Demonstration of single linked list with constructor: " << endl;
	cSingleLinkedList();
	cout << endl << endl;

	cout << "Demonstration of the traversal and processing of a linked list: " << endl;
	traverseLinkedList();
	cout << endl << endl;
}

//***********************************************************************************************
//	runs the stack test to verify that the stack works properly
//**********************************************************************************************/
void stackTest()
{
	cout << "Demonstration of a Stack using a singly-linked list: " << endl;
	cout << "Adding 1, 2, 3, 4, 5, 6, and 7 to stack, in order" << endl << endl;

	cout << "..." << endl << endl;

	Stack s;
	for (int i = 0; i < 7; i++)
	{
		s.push(i + 1);
	}

	cout << "..." << endl << endl;
	cout << "Stack complete" << endl << endl;

	cout << "Now displaying stack, in reverse order as elements are popped off of the top: " << endl << endl;

	for (int i = 0; i < 8; i++)
	{
		if (s.empty() == false)
			cout << "The number " << i + 1 << " item off is: " << s.pop() << endl;
		else
			cout << "The stack is empty" << endl << endl;
	}
}

//***********************************************************************************************
//	runs the que test to verify that the que works properly
//**********************************************************************************************/
void queTest()
{
	cout << "Demonstration of a Que using a doubly-linked list: " << endl;
	cout << "Adding 1, 2, 3, 4, 5, 6, and 7 to que, in order" << endl << endl;

	cout << "..." << endl << endl;

	Que q;
	for (int i = 0; i < 7; i++)
	{
		q.push(i + 1);
	}

	cout << "..." << endl << endl;
	cout << "Que complete" << endl << endl;

	cout << "Now displaying que, in order as elements are popped off of the front: " << endl << endl;

	for (int i = 0; i < 8; i++)
	{
		if (q.empty() == false)
			cout << "The number " << i + 1 << " item off is: " << q.pop() << endl;
		else
			cout << "The que is empty" << endl << endl;
	}
}
