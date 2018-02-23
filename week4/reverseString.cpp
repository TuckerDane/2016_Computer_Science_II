#include "reverseString.h"

/***************************************************************************************************
**	// a function which takes a string reverses it using recursion
***************************************************************************************************/
void reverseString(std::string s)
{
	std::string str = s;
	int stringLength = str.length();

	if (stringLength == 1)									// base case - if we've printed every element until there is only one left
	{
		std::cout << str << "\n";							// print the first element in the string!
	}
	else													// otherwise, swap the first/last elements of whatever has been passed to the swap funciton
	{
		std::cout << str[stringLength - 1];					// print the last character of the string
		reverseString(str.substr(0, stringLength - 1));		// call reverseString on the substring of s from the first to the second to last element
	}
}