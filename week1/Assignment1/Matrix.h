/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			02 October 2016
//
//	Description:	This is a file contains the prototypes to two functions. One function allows the user to input values into a
//					matrix. The second funciton prints the values stored within the matrix.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include "Ant.h"

class Matrix
{
private:
	int mSizeX;											// the size of the x axis
	int mSizeY;											// the size of the y axis
	bool** matrix;										// a dynamically allocated 2d matrix

public:
	Matrix(int sizeY, int sizeX);						// a constructor that initializes the values of "matrix[][]" to ' '
	~Matrix();											// a destructor for Matrix

	void setMatSize(int sY, int sX);					// sets the size of "matrix[][]" to "sX x sY"
	void setMatPos(bool position, int y, int x);		// sets the value of a position in "matrix[][]" at "x","y" to true(white - '#') or false(black - ' ')

	int	getMatSizeX();									// returns "mSizeX"
	int	getMatSizeY();									// returns "mSizeY"
	bool getMatPos(int y, int x);						// returns true or false for the position indicated
	void printMatrix(int antY, int antX);				// prints the matrix
};


#endif                                 