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

#include "Critter.h"

using std::cout;
using std::endl;
using std::cin;

/***************************************************************************************************
**	default constructor for critter
***************************************************************************************************/
Critter::Critter()
{
	rowPos = 0;
	colPos = 0;
	steps = 0;
	type = 'C';
	moved = 0;
}

/***************************************************************************************************
**	default constructor for critter
***************************************************************************************************/
Critter::Critter(char t)
{
	rowPos = 0;
	colPos = 0;
	steps = 0;
	type = t;
	moved = 0;
}

/***************************************************************************************************
**	constructor for critter
***************************************************************************************************/
Critter::Critter(int row, int col)
{
	rowPos = row;
	colPos = col;
	steps = 0;
	type = 'C';
	moved = 0;
}

/***************************************************************************************************
**	constructor for critter
***************************************************************************************************/
Critter::Critter(char t, int row, int col)
{
	rowPos = row;
	colPos = col;
	steps = 0;
	type = t;
	moved = 0;
}

/***************************************************************************************************
**	deconstructor for Critter
***************************************************************************************************/
Critter::~Critter()
{
}

/***************************************************************************************************
**	returns the row of the Critter
***************************************************************************************************/
int Critter::getRowPos()
{
	return rowPos;
}

/***************************************************************************************************
**	returns the column of the Critter
***************************************************************************************************/
int Critter::getColPos()
{
	return colPos;
}

/***************************************************************************************************
**	returns the number of steps the Critter has taken
***************************************************************************************************/
int Critter::getSteps()
{
	return steps;
}

/***************************************************************************************************
**	returns the type of the Critter
***************************************************************************************************/
char Critter::getType()
{
	return type;
}

/***************************************************************************************************
**	returns if the critter moved or not
***************************************************************************************************/
bool Critter::getMoved()
{
	return moved;
}

/***************************************************************************************************
**	sets the steps of the Critter
***************************************************************************************************/
void Critter::setSteps(int s)
{
	steps = s;
}

/***************************************************************************************************
**	sets the row of the Critter
***************************************************************************************************/
void Critter::setRowPos(int r)
{
	rowPos = r;
}

/***************************************************************************************************
**	sets the column of the Critter
***************************************************************************************************/
void Critter::setColPos(int c)
{
	colPos = c;
}

/***************************************************************************************************
**	sets moved to T/F
***************************************************************************************************/
void Critter::setMoved(bool b)
{
	moved = b;
}

/***************************************************************************************************
**	moves the Critter
***************************************************************************************************/
void Critter::move(char *surroundings)
{
	int openSpace = 0;									// initialize an integer to track the number of open spaces the Critter can move to

	for (int i = 0; i < 4; i++)							// iterate through surroundings and add 1 to openSpace for every empty space
	{
		if (surroundings[i] == 'E')
			openSpace++;
	}

	if (openSpace > 0)									// if there is at least one open space
	{
		bool m = false;

		while (m == false)								// while no movement has been made
		{
			int rdir = rand() % 4;						// pick a random direction from 0-3

			if (surroundings[rdir] == 'E')				// if the random direction corresponds to an empty space in the matrix
			{
				if (rdir == 0)							// and if the random direction is up (0)
				{
					this->setRowPos(getRowPos() - 1);	// move the critter's position up by one
					m = true;
				}
				else if (rdir == 1)						// else if the random direction is right (1)
				{
					this->setColPos(getColPos() + 1);	// move the critter's position right by one
					m = true;
				}
				else if (rdir == 2)						// else if the random direction is down (3)
				{
					this->setRowPos(getRowPos() + 1);	// move the critter's position down by one
					m = true;
				}
				else if (rdir == 3)						// else if the random direction is left (4)
				{
					this->setColPos(getColPos() - 1);	// move the critter's position left by one
					m = true;
				}
				else									// ERROR! - Cannot move for some reason
					cout << "Error! Cannot Move" << endl;

				steps++;								// add to the number of steps the critter has taken
				this->setMoved(true);					// changes moved to true
			}
		}
	}
	else												// else if there is no open space
	{
		steps++;										// add to the number of steps the critter has taken
		this->setMoved(false);							// changes moved to false
	}
		
	delete[] surroundings;								// delete the memory allocated for surroundings
}

/***************************************************************************************************
**	returns true if the critter has taken enough steps to breed
***************************************************************************************************/
Critter* Critter::breed(char *surroundings)
{
	if (this->getSteps() > 0 && this->getSteps() % 3 == 0)					// if the critter has survived at least three more steps
	{
		int openSpace = 0;													// initialize an integer to track the number of open spaces the Critter can breed into

		for (int i = 0; i < 4; i++)											// iterate through surroundings and add 1 to openSpace for every empty space
		{
			if (surroundings[i] == 'E')
				openSpace++;
		}

		if (openSpace > 0)													// if there is at least one open space
		{
			bool bred = false;

			while (bred == false)
			{
				int rdir = rand() % 4;											// pick a random direction from 0-3

				if (surroundings[rdir] == 'E')									// if the random direction corresponds to an empty space in the matrix
				{
					if (rdir == 0)												// and if the random direction is up (0)
					{
						return new Critter(this->getRowPos() - 1, this->getColPos());		// create a new Critter above the current critter
						bred = true;
					}
					else if (rdir == 1)											// else if the random direction is right (1)
					{
						return new Critter(this->getRowPos(), this->getColPos() + 1);		// create a new Critter to the right of the current critter
						bred = true;
					}
					else if (rdir == 2)											// else if the random direction is down (3)
					{
						return new Critter(this->getRowPos() + 1, this->getColPos());		// create a new Critter below the current critter
						bred = true;
					}
					else if (rdir == 3)											// else if the random direction is left (4)
					{
						return new Critter(this->getRowPos(), this->getColPos() - 1);		// create a new Critter to the left of the current critter
						bred = true;
					}
					//else														// ERROR! - Cannot breed for some reason
					//	cout << "Error! Cannot Breed!" << endl;
				}
			}
		}
		else																// else there are no open spaces
		{
			return NULL;													// return null
		}
	}
	else
	{
		return NULL;														// else its not time to breed
	}
}

/***************************************************************************************************
**	virtual function for starve()
***************************************************************************************************/
Critter* Critter::starve()
{
	return this;
}