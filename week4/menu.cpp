#include "menu.h"
#include "reverseString.h"
#include "sumArray.h"
#include "triNumber.h"
#include <string>

/***************************************************************************************************
**	a menu function which allows the user to run different parts of the program
***************************************************************************************************/
void menu()
{
	int choice;
	bool end = false;
	while (end == false)
	{
		std::cout << "1: Reverse a String" << std::endl;
		std::cout << "2: Sum an Array" << std::endl;
		std::cout << "3: Calculate the Triangular Number for N" << std::endl;
		std::cout << "4: Quit" << std::endl << std::endl;
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
			std::string userInput;

			std::cout << "Enter a string: ";
			std::cin >> userInput;

			std::cout << "The reverse of your string is: ";
			reverseString(userInput);
			std::cout << std::endl;
		}
		else if (choice == 2)
		{
			int i = 0;										// indicates the number of integers in the array
			int *arr = new int[1];							// array to store integers entered by the user
			std::string numEntered;							// stores the user input


			std::cout << "Enter integers to sum, when you are done enter #" << std::endl;
			std::cin >> numEntered;							// user enters a number

			while (numEntered == "#")
			{
				std::cout << "Enter at least one number!! ";
				std::cin >> numEntered;
			}

			arr[0] = std::stoi(numEntered);					// sets the first value of arr to the number entered
			i++;											// iterates the counter

			std::cin >> numEntered;							// enter another number or a #

			while (numEntered != "#")						// while the user did not enter "#"
			{
				int *tempArray = new int[i+1];				// create a temporary array of integers that can hold one more integer than the current array

				for (int j = 0; j < i; j++)					// fill the temporary array with integers from the old array
				{
					tempArray[j] = arr[j];					
				}

				tempArray[i] = std::stoi(numEntered);		// fill the last slot of tempArray with the user's input converted to an integer

				delete[] arr;								// destroy arr to deallocate the memory it used to store integers
				

				arr = new int[i + 1];						// re-allocate memory for arr with the new size

				for (int j = 0; j < (i+1); j++)				// fill arr with the values stored in tempArray
				{
					arr[j] = tempArray[j];
				}

				delete[] tempArray;							// destroy the temporaryArray

				std::cin >> numEntered;						// enter a new number
				i++;										// iterate I so that the new number can be stored in the next block in array
			}

			std::cout << std::endl;
			std::cout << "The array sums to " << sumArray(arr, i) << std::endl << std::endl;

			delete[] arr;
		}
		else if (choice == 3)
		{
			int num;

			std::cout << "Enter an integer N: ";
			std::cin >> num;

			std::cout << "The triangular number for " << num << " is: " << triNum(num) << std::endl << std::endl;
		}
		else if (choice == 4)
		{
			end = true;
		}
		else
		{
			std::cout << "Invalid choice. Please try again." << std::endl << std::endl;
		}
	}

}