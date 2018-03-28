/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 October 2016
//
//	Description:	A dynamically allocated matrix which holds the values "true"/"false" which can be printed as "#" or " "
//					respectively. Also prints "*" if an ant is in the position whether true or false/
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include "Critter.h"
#include "Ant.h"
#include "DoodleBug.h"

#define EMPTY	' '
#define ANT		'o'
#define DBUG	'+'

class Matrix
{
private:
	int mSizeRow;											// the size of the row
	int mSizeCol;											// the size of the column
	int openSlots;											// the current number of open positions in the matrix
	Critter*** matrix;										// a dynamically allocated 2d matrix of pointers to critters

public:
	Matrix();												// a constructor that initializes a 20x20 matrix with NULL values
	Matrix(int sizeRow, int sizeCol);						// a constructor that initializes an sizeRow x siezeCol matrix with NULL values
	~Matrix();												// a destructor for Matrix

	void setMatSize(int sRow, int sCol);					// sets the size of "matrix[][]" to "sRow x sCol"
	void setMatPos(Critter *c, int row, int col);			// sets the value of a position in "matrix[][]" at "row","col" to the address of a Critter
	void setOpenSlots(int s);								// sets the number of open slots in the matrix
	void addCritter(Critter *c);							// randomly sets the position of a new critter into an empty space in the matrix
	void addCritter(Critter *c, int row, int col);			// overloads addCritter to allow non-random placement

	int	getMatSizeRow();									// returns "mSizeRow"
	int	getMatSizeCol();									// returns "mSizeCol"
	int getOpenSlots();										// returns the number of open slots in the matrix
	Critter* getMatPos(int row, int col);					// returns a pointer to what is at the position stored in the matrix at x, y
	void setColor(char bug);									// changes the print color
	void printMatrix();										// prints the matrix
	char* around(Critter &c);								// returns the type of what is around Critter C
	void moveCritters();									// moves the critters assigned to the matrix
	void breedCritters();									// breeds the critters assigned to the matrix
	void starveDoodleBugs();								// starves the DoodleBugs assigned to the matrix
};


#endif                                 