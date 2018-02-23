/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			02 October 2016
//
//	Description:	This is a file containing two functions. One function allows the user to input values into a matrix
//					The second funciton prints the values stored within the matrix.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Menu.h"
#include <ctime>

// prompt user for # of items in an entity. Choices given are integers c1, c2, c3, c4
int choice(std::string s, std::string entity, int c1, int c2, int c3, int c4)
{
	int choice;
	bool end = false;

	std::cout << "Enter the " << s << " for the " << entity << std::endl << std::endl;
	return choiceValidation(c1, c2, c3, c4);
}

// prompt user for # of items in an entity. Choices given are strings c1, c2, c3, c4
int choice(std::string s, std::string entity, std::string c1, std::string c2, std::string c3, std::string c4)
{
	int choice;
	bool end = false;

	std::cout << "Enter the " << s << " for the " << entity << std::endl << std::endl;
	return choiceValidation(c1, c2, c3, c4);
}

// promt user for choices.
int choice(std::string s, std::string entity, int c1, int c2, int c3, std::string c4)
{
	int choice;
	bool end = false;

	std::cout << "Enter the " << s << " for the " << entity << std::endl << std::endl;
	return choiceValidation(c1, c2, c3, c4);
}

// validates the user's choices of ints
int choiceValidation(int choice1, int choice2, int choice3, int choice4)
{
	int choice;
	bool end = false;
	while (end == false)
	{
		std::cout << "1: " << choice1 << std::endl;
		std::cout << "2: " << choice2 << std::endl;
		std::cout << "3: " << choice3 << std::endl;
		std::cout << "4: " << choice4 << std::endl << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		std::cout << std::endl << std::endl;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid choice. Please try again" << std::endl << std::endl;
			continue;
		}

		if (choice == 1)
			return choice1;

		else if (choice == 2)
			return choice2;

		else if (choice == 3)
			return choice3;

		else if (choice == 4)
			return choice4;

		else
			std::cout << "Invalid choice. Please try again." << std::endl << std::endl;
	}
}

// validates the user's choices of strings
int choiceValidation(std::string choice1, std::string choice2, std::string choice3, std::string choice4)
{
	int choice;
	bool end = false;
	while (end == false)
	{
		std::cout << "1: " << choice1 << std::endl;
		std::cout << "2: " << choice2 << std::endl;
		std::cout << "3: " << choice3 << std::endl;
		std::cout << "4: " << choice4 << std::endl << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		std::cout << std::endl << std::endl;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid choice. Please try again" << std::endl << std::endl;
			continue;
		}

		if (choice == 1)
			return 1;

		else if (choice == 2)
			return 2;

		else if (choice == 3)
			return 3;

		else if (choice == 4)
			return 4;

		else
			std::cout << "Invalid choice. Please try again." << std::endl << std::endl;
	}
}

int choiceValidation(int choice1, int choice2, int choice3, std::string choice4)
{
	int choice;
	bool end = false;
	while (end == false)
	{
		std::cout << "1: " << choice1 << std::endl;
		std::cout << "2: " << choice2 << std::endl;
		std::cout << "3: " << choice3 << std::endl;
		std::cout << "4: " << choice4 << std::endl << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		std::cout << std::endl << std::endl;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid choice. Please try again" << std::endl << std::endl;
			continue;
		}

		if (choice == 1)
			return choice1;

		else if (choice == 2)
			return choice2;

		else if (choice == 3)
			return choice3;

		else if (choice == 4)
		{
			srand(time(NULL));
			return (rand() % choice3 + 1);
		}
		else
			std::cout << "Invalid choice. Please try again." << std::endl << std::endl;
	}
}