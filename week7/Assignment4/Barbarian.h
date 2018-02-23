/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			26 November 2016
//
//	Description:	The Barbarian Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "creature.h"

class Barbarian : public Creature
{

public:
	Barbarian();							// default constructor for Barbarian
	Barbarian(int a, int s);				// constructor for Barbarian
	~Barbarian();							// destructor for Barbarian

	int attack();							// returns the amount of damage inflicted
	int defend(int attack);					// modifies attack damage given a creature's defense roll
};

#endif