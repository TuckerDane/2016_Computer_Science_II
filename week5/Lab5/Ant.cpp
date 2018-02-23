/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			31 October 2016
//
//	Description:	The Ant Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Ant.h"

using std::cout;
using std::endl;
using std::cin;

/***************************************************************************************************
**	default constructor for Ant
***************************************************************************************************/
Ant::Ant() : Critter('O')
{
}

/***************************************************************************************************
**	constructor for Ant
***************************************************************************************************/
Ant::Ant(int row, int col) : Critter('O', row, col)
{
}

/***************************************************************************************************
**	deconstructor for Ant
***************************************************************************************************/
Ant::~Ant()
{
}

/***************************************************************************************************
**	returns true if the critter has taken enough steps to breed
***************************************************************************************************/
Ant* Ant::breed(char *surroundings)
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
						return new Ant(this->getRowPos() - 1, this->getColPos());			// create a new Critter above the current critter
						bred = true;
					}
					else if (rdir == 1)														// else if the random direction is right (1)
					{
						return new Ant(this->getRowPos(), this->getColPos() + 1);			// create a new Critter to the right of the current critter
						bred = true;
					}
					else if (rdir == 2)														// else if the random direction is down (3)
					{
						return new Ant(this->getRowPos() + 1, this->getColPos());			// create a new Critter below the current critter
						bred = true;
					}
					else if (rdir == 3)														// else if the random direction is left (4)
					{
						return new Ant(this->getRowPos(), this->getColPos() - 1);			// create a new Critter to the left of the current critter
						bred = true;
					}
					else														// ERROR! - Cannot breed for some reason
						cout << "Error! Cannot Breed!" << endl;
				}
			}
		}
		else																	// else there are no open spaces
		{
			return NULL;														// return null
		}
	}
	else
	{
		return NULL;															// else its not time to breed
	}
}