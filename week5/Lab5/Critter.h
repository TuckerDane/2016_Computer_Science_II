/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 October 2016
//
//	Description:	The base class for various critters which tracks their position, number of steps, and allows move/breed
//					functionality
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <iostream>

#define EMPTY	' '
#define ANT		'o'
#define DBUG	'+'

class Critter
{
private:
	int rowPos;										// a variable which stores the row the ant is on in the matrix
	int colPos;										// a variable which stores the column the ant is on in the matrix
	int steps;										// a variable which stores the number of steps the Critter has gone since its initialization		
	char type;										// holds the type of critter
	bool moved;										// indicates wether or not the critter has moved already during this step

public:
	Critter();										// default constructor for Critter
	Critter(char t);								// constructor for inherited classes
	Critter(int row, int col);						// constructor for Critter initializing rowPos, colPos, steps = 0, and type = 'C'
	Critter(char t, int row, int col);				// constructor for inherited classes initializing rowPos, colPos, steps = 0, and type = t
	~Critter();										// deconstructor for Critter
	
	int getRowPos();								// returns the row of the Critter
	int getColPos();								// returns the column of the Critter
	int getSteps();									// returns the number of steps the Critter has taken
	char getType();									// returns the type of the Critter
	bool getMoved();								// returns if the critter moved or not

	void setSteps(int s);							// set steps of the Critter
	void setRowPos(int r);							// set rowPos of the Critter
	void setColPos(int c);							// set colPos of the Critter
	void setMoved(bool b);							// sets moved to T/F

	virtual void move(char *surroundings);			// steps++, change rowPos, change colPos
	virtual Critter* breed(char *surroundings);		// returns a pointer to a Critter if breeding occurs, otherwise returns NULL
	virtual Critter* starve();						// virtual function for starve()
};

#endif

