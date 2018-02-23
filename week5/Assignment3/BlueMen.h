/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			26 November 2016
//
//	Description:	The Blue Men Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "creature.h"

class BlueMen : public Creature
{

public:
	BlueMen();								// default constructor for Barbarian
	BlueMen(int a, int s);					// constructor for Barbarian
	~BlueMen();								// destructor for Barbarian

	int attack();							// returns the amount of damage inflicted
	int defend(int attack);					// modifies attack damage given a creature's defense roll
};

#endif