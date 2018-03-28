/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			31 October 2016
//
//	Description:	The DoodleBug Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "DoodleBug.h"

using std::cout;
using std::endl;
using std::cin;

/***************************************************************************************************
**	default constructor for Ant
***************************************************************************************************/
DoodleBug::DoodleBug() : Critter(DBUG)
{
	feedCounter = 0;
}

/***************************************************************************************************
**	constructor for Ant
***************************************************************************************************/
DoodleBug::DoodleBug(int row, int col) : Critter(DBUG, row, col)
{
	feedCounter = 0;
}

/***************************************************************************************************
**	deconstructor for Ant
***************************************************************************************************/
DoodleBug::~DoodleBug()
{
}

/***************************************************************************************************
**	gets feedCounter for DoodleBug
***************************************************************************************************/
int DoodleBug::getFeedCounter()
{
	return feedCounter;
}

/***************************************************************************************************
**	gets feedCounter for DoodleBug
***************************************************************************************************/
void DoodleBug::setFeedCounter(int f)
{
	feedCounter = f;
}

/***************************************************************************************************
**	moves the DoodleBug
***************************************************************************************************/
void DoodleBug::move(char *surroundings)
{
	int openSpace = 0;									// initialize an integer to track the number of open spaces the Critter can move to
	int antSpace = 0;									// initialize an integer to track the number of bordering ants the DoodleBug can move to

	for (int i = 0; i < 4; i++)							// iterate through surroundings and
	{
		if (surroundings[i] == EMPTY)						// add 1 to open space for every open space available
			openSpace++;
		if (surroundings[i] == ANT)						// add 1 to antSpace for every bordering ant
			antSpace++;
	}

	if (antSpace > 0)									// if there is at least one bordering ant
	{
		bool m = false;

		while (m == false)								// while no movement has been made
		{
			int rdir = rand() % 4;						// pick a random direction from 0-3

			if (surroundings[rdir] == ANT)				// if the random direction corresponds to an Ant in the matrix
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
				else									// there is no ant, send error
				{
					cout << "Error, NO ANT" << endl;
				}

				this->setSteps(this->getSteps() +1);	// add to the number of steps the critter has taken
				this->setFeedCounter(0);				// reset feedCounter because the DoodleBug just ate
				this->setMoved(true);					// changes moved to true
			}
		}
	}
	else if (openSpace > 0)								// else there are no ants, and if there is at least one open space
	{
		bool m = false;

		while (m == false)								// while no movement has been made
		{
			int rdir = rand() % 4;						// pick a random direction from 0-3

			if (surroundings[rdir] == EMPTY)				// if the random direction corresponds to an Empty space in the matrix
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
				else									// there is no ope space, send error
				{
					cout << "Error, NO OPEN SPACE" << endl;
				}

				this->setSteps(this->getSteps() + 1);					// add to the number of steps the critter has taken
				this->setFeedCounter(this->getFeedCounter() + 1);		// add to the number of steps since the DoodleBug ate
				this->setMoved(true);									// changes moved to true
			}
		}
	}
	else													// else if there are no ants and no open spaces
	{
		this->setSteps(this->getSteps() + 1);				// add to the number of steps the critter has taken
		this->setFeedCounter(this->getFeedCounter() + 1);	// add to the number of steps since the DoodleBug ate
		this->setMoved(false);								// changes moved to false
	}

	delete[] surroundings;									// delete the memory allocated for surroundings
}

/***************************************************************************************************
**	returns true if the critter has taken enough steps to breed
***************************************************************************************************/
DoodleBug* DoodleBug::breed(char *surroundings)
{
	if (this->getSteps() > 0 && this->getSteps() % 8 == 0)					// if the critter has survived at least eight more steps
	{
		int openSpace = 0;													// initialize an integer to track the number of open spaces the Critter can breed into

		for (int i = 0; i < 4; i++)											// iterate through surroundings and add 1 to openSpace for every empty space
		{
			if (surroundings[i] == EMPTY)
				openSpace++;
		}

		if (openSpace > 0)													// if there is at least one open space
		{
			bool bred = false;

			while (bred == false)
			{
				int rdir = rand() % 4;															// pick a random direction from 0-3

				if (surroundings[rdir] == EMPTY)													// if the random direction corresponds to an empty space in the matrix
				{
					if (rdir == 0)																// and if the random direction is up (0)
					{
						return new DoodleBug(this->getRowPos() - 1, this->getColPos());			// create a new Critter above the current critter
						bred = true;
					}
					else if (rdir == 1)															// else if the random direction is right (1)
					{
						return new DoodleBug(this->getRowPos(), this->getColPos() + 1);			// create a new Critter to the right of the current critter
						bred = true;
					}
					else if (rdir == 2)															// else if the random direction is down (3)
					{
						return new DoodleBug(this->getRowPos() + 1, this->getColPos());			// create a new Critter below the current critter
						bred = true;
					}
					else if (rdir == 3)															// else if the random direction is left (4)
					{
						return new DoodleBug(this->getRowPos(), this->getColPos() - 1);			// create a new Critter to the left of the current critter
						bred = true;
					}
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

/***************************************************************************************************
**	starves the DoodleBug
***************************************************************************************************/
DoodleBug* DoodleBug::starve()
{
	if (this->getFeedCounter() >= 3)
	{
		return NULL;	// return null to take the place of the starved doodlebug
	}
	else
	{
		return this;	// return the doodlebug!
	}
}