/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			02 October 2016
//
//	Description:	This file uses readMatrix() to prompt the user to enter 4 or 9 values into an array and then calculates
//					the determinant using determinant()
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "matrix.h"
#include "determinant.h"
#include <iostream>

int main()
{
	// size of the matrix
	int size = 0;																	

	// prompts user to give a size for the matrix
	std::cout << "Type '3' for a 3x3 matrix or '2' for a 2x2 matrix:  ";
	std::cin >> size;

	// forces the user to input a matrix size of 3x3 or 2x2
	while (size !=3 && size !=2)
	{
		std::cout << "Incorrect input! type '3' for a 3x3 matrix or '2' for a 2x2 matrix:  ";
		std::cin.clear();
		std::cin >> size;
	}

	// dynamic allocation of memory for a 2d array of size "size"
	int** mx = new int*[size];
	for (int i = 0; i < size; i++)
		mx[i] = new int[size];
	std::cout << std::endl;

	// prompt the user to fill the matrix with values
	readMatrix(mx, size);

	std::cout << std::endl;

	// print the matrix
	printMatrix(mx, size);

	// display the determinant of the matrix
	std::cout << "The Determinant is: " << determinant(mx, size) << std::endl << std::endl;

	//deallocating the dynamic 2d array
	for (int i = 0; i < size; i++)
		delete [] mx[i];

	delete[] mx;


	return 0;
}
