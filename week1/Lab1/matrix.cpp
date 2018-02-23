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

#include "matrix.h"

/***************************************************************************************************
**	a function which takes a 2d matrix of integers, matrix[][], and an integer, mSize, as parameters
**	then allows the user to fill the matrix based on the number indicated by mSize. 
***************************************************************************************************/
void readMatrix(int* matrix[], int mSize)
{
	std::cout << "Fill the matrix with " << mSize*mSize << " integers: " << std::endl;
	
	for (int i = 0; i < mSize; i++)						// i indicates the row
	{
		for (int j = 0; j < mSize; j++)					// j indicates the column
		{
			std::cin >> matrix[i][j];					// user inputs the value at matrix[i][j]
		}
	}
}

/***************************************************************************************************
**	a function which takes a 2d matrix of integers, matrix[][], and an integer, mSize, as parameters
**	then prints the values stored in matrix[][]
***************************************************************************************************/
void printMatrix(int* matrix[], int mSize)
{
	std::cout << "The matrix of size " << mSize << "x" << mSize << " integers is:" << std::endl << std::endl;
	
	for (int i = 0; i < mSize; i++)							// i indicates the row
	{
		for (int j = 0; j < mSize; j++)						// j indicates the column
		{
			std::cout << "[" << matrix[i][j] << "] ";		// prints the value at matrix[i][j]
		} 
		std::cout << std::endl;
	}
}