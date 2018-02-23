#include <iostream>

#include "menu.h"

int main()
{
	// reverseString Testing
	/*
	std::string userInput;

	std::cout << "Enter a string: ";
	std::cin >> userInput;

	std::cout << "The reverse of your string is: ";
	reverseString(userInput);
	*/

	// sumArray Testing
	/*
	int arr[5] = { 1, 2, 3, 4, 5 };		// array has the sum 15
	std::cout << "Array size is: " << sizeof(arr)/4 << std::endl;
	std::cout << "Array at size - 1 is:" << arr[sizeof(arr)/4 - 1] << std::endl;
	std::cout << "The array sums to " << sumArray(arr, sizeof(arr)/4) << std::endl;
	*/

	// triNumber Testing
	/*
	std::cout << "The triangular number for 1 is: " << triNum(-1) << std::endl;	// 0
	std::cout << "The triangular number for 1 is: " << triNum(0) << std::endl;	// 0
	std::cout << "The triangular number for 1 is: " << triNum(1) << std::endl;	// 1
	std::cout << "The triangular number for 1 is: " << triNum(2) << std::endl;	// 3
	std::cout << "The triangular number for 1 is: " << triNum(3) << std::endl;	// 6
	std::cout << "The triangular number for 1 is: " << triNum(4) << std::endl;	// 10
	std::cout << "The triangular number for 1 is: " << triNum(5) << std::endl;	// 15
	std::cout << "The triangular number for 1 is: " << triNum(6) << std::endl;	// 21
	std::cout << "The triangular number for 1 is: " << triNum(7) << std::endl;	// 28
	*/

	menu();
	
	return 0;
}