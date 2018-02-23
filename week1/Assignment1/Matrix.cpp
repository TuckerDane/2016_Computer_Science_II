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

#include "Matrix.h"

/***************************************************************************************************
**	a default constructor for Matrix
***************************************************************************************************/
Matrix::Matrix(int sizeY, int sizeX)
{														/* TEST
														std::cout << "Setting Default Matrix Size" << std::endl; */
	setMatSize(sizeY, sizeX);
														/* TEST
														std::cout << "Allocating memory for Matrix" << std::endl; */

	matrix = new bool*[getMatSizeY()];
	for (int i = 0; i < getMatSizeY(); i++)
		matrix[i] = new bool[getMatSizeX()];
														/* TEST		
														std::cout << "Setting Default Matrix Size rows: " << getMatSizeX() << " x columns: " << getMatSizeY() << " with t/f values:" << std::endl; */

	for (int i = 0; i < getMatSizeY(); i++)				// i indicates the column
	{
		for (int j = 0; j < getMatSizeX(); j++)			// j indicates the row
		{
			setMatPos(true, i, j);						// user inputs the value at matrix[i][j]
		}
	}
														/* // TEST
														std::cout << "Finished Setting Default Matrix" << std::endl;*/
}

/***************************************************************************************************
**	a destructor for Matrix
***************************************************************************************************/
Matrix::~Matrix()
{														/* TEST
														std::cout << "Destructing Matrix" << std::endl; */

	for (int i = 0; i < mSizeY; i++)					// destructs each column within matrix[]
	{
		delete[] matrix[i];								/* TEST
														std::cout << "Destroyed matrix y: " << i << std::endl; */

	}

	delete[] matrix;									// destructs matrix[]
														/* TEST
														std::cout << "Finished Destructing Matrix" << std::endl; */
}

/***************************************************************************************************
**	a function which sets the size of the matrix
***************************************************************************************************/
void Matrix::setMatSize(int sY, int sX)
{
	mSizeX = sX;
	mSizeY = sY;
}

/***************************************************************************************************
**	a function which sets the bool value for a particular position within the matrix
***************************************************************************************************/
void Matrix::setMatPos(bool position, int y, int x)
{
	matrix[y][x] = position;				/* TEST
											std::cout << "Setting matrix at position row" << x << " column " << y << std::endl; */
}

/***************************************************************************************************
**	a function which gets the size of the matrix
***************************************************************************************************/
int Matrix::getMatSizeX()
{
	return mSizeX;
}

/***************************************************************************************************
**	a function which gets the size of the matrix
***************************************************************************************************/
int Matrix::getMatSizeY()
{
	return mSizeY;
}

/***************************************************************************************************
**	a function which returns '#' for true and ' ' for false
***************************************************************************************************/
bool Matrix::getMatPos(int y, int x)
{
	return matrix[y][x];					// returns the value at matrix[y][x]
}

/***************************************************************************************************
**	a function which prints the 2d matrix and ant location
***************************************************************************************************/
void Matrix::printMatrix(int antY, int antX)
{
	for (int i = 0; i < getMatSizeY(); i++)							// i indicates the column
	{
		for (int j = 0; j < getMatSizeX(); j++)						// j indicates the row
		{
			std::cout << " ";
			if (i == antY && j == antX)
				std::cout << '*';
			else if (getMatPos(i, j) == false)							// prints the value at matrix[y][x]
				std::cout << ' ';										// ' ' for false(black)
			else // if (getMatPos(i, j) == true)						// '#' for true(white)
				std::cout << '#';
		}
		std::cout << std::endl;
	}
}