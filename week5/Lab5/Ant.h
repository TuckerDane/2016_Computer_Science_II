/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			31 October 2016
//
//	Description:	The Ant Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.h"

#define EMPTY	' '
#define ANT		'o'
#define DBUG	'+'

class Ant : public Critter
{
private:
	int rowPos;							// a variable which stores the row the ant is on in the matrix
	int colPos;							// a variable which stores the column the ant is on in the matrix
	int steps;							// a variable which stores the number of steps the Critter has gone since its initialization		
	char type;							// holds the type of critter
	bool moved;							// indicates wether or not the critter has moved already during this step

public:
	Ant();								// default constructor for Critter
	Ant(int row, int col);				// constructor for Critter initializing rowPos, colPos, steps = 0, and type = 'C'
	~Ant();								// deconstructor for Critter

	Ant* breed(char *surroundings);		// returns a pointer to a Critter if breeding occurs, otherwise returns NULL
};

#endif

