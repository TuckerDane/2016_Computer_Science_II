/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			October 2016
//
//	Description:	Input Validation functions that handle int/doubles to ensure that they are within certain numberic bounds
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "InputValidation.h"
#include <iostream>
#include <limits>

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

/***************************************************************************************************
**	validates the user's input is within specified bounds
***************************************************************************************************/
int boundsValidation(int userInput, int min, int max)
{
	bool validated = false;									// the userInput value has not yet been validated, therefore "validated" is set to false

	userInput = inputValidation(userInput);				// validate that userInput is an integer

	while (validated == false)								// while the userInput value is not validated
	{
		if (userInput < min)								// if the userInput is less than the minimum value allowed
		{
			std::cout << "Input too low! Re-enter: ";		// throw an error that the number is too low
			std::cin >> userInput;							// user inputs new userInput
			userInput = inputValidation(userInput);		// userInput is validated as an integer
		}
		if (userInput > max)
		{
			std::cout << "Input too high! Re-enter: ";		// throw an error that the number is too low
			std::cin >> userInput;							// user inputs new userInput
			userInput = inputValidation(userInput);		// userInput is validated as an integer
		}
		if (max >= userInput && userInput >= min)			// if userInput is within the correct bounds
		{
			validated = true;								// consider the integer validated
		}
	}

	return userInput;										// return the userInput;
}

/***************************************************************************************************
**	validates the user's input is an integer
***************************************************************************************************/
double inputValidation(double uinput)
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

/***************************************************************************************************
**	validates the user's input is within specified bounds
***************************************************************************************************/
double boundsValidation(double userInput, double min, double max)
{
	bool validated = false;									// the userInput value has not yet been validated, therefore "validated" is set to false

	userInput = inputValidation(userInput);				// validate that userInput is an integer

	while (validated == false)								// while the userInput value is not validated
	{
		if (userInput < min)								// if the userInput is less than the minimum value allowed
		{
			std::cout << "Input too low! Re-enter: ";		// throw an error that the number is too low
			std::cin >> userInput;							// user inputs new userInput
			userInput = inputValidation(userInput);		// userInput is validated as an integer
		}
		if (userInput > max)
		{
			std::cout << "Input too high! Re-enter: ";		// throw an error that the number is too low
			std::cin >> userInput;							// user inputs new userInput
			userInput = inputValidation(userInput);		// userInput is validated as an integer
		}
		if (max >= userInput && userInput >= min)			// if userInput is within the correct bounds
		{
			validated = true;								// consider the integer validated
		}
	}

	return userInput;										// return the userInput;
}