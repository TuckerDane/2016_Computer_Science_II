/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			31 October 2016
//
//	Description:	The DoodleBug Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.h"

#define EMPTY	' '
#define ANT		'o'
#define DBUG	'+'

class DoodleBug : public Critter
{
private:
	int rowPos;								// a variable which stores the row the ant is on in the matrix
	int colPos;								// a variable which stores the column the ant is on in the matrix
	int steps;								// a variable which stores the number of steps the Critter has gone since its initializatio
	int feedCounter;						// a variable which stores the number of steps since the DoodleBug last ate
	char type;								// holds the type of critter
	bool moved;								// indicates wether or not the critter has moved already during this step

public:
	DoodleBug();							// default constructor for Critter
	DoodleBug(int row, int col);			// constructor for Critter initializing rowPos, colPos, steps = 0, and type = 'C'
	~DoodleBug();							// deconstructor for Critter

	int getFeedCounter();					// returns feedCounter
	void setFeedCounter(int f);				// sets the feedCounter

	void move(char *surroundings);			// moves the doodlebug
	DoodleBug* breed(char *surroundings);	// returns a pointer to a Critter if breeding occurs, otherwise returns NULL
	DoodleBug* starve();					// returns a pointer to NULL if the DoodleBug starves, returns the DoodleBug if it does not starve
};

#endif

