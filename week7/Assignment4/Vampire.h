/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			26 November 2016
//
//	Description:	The Vampire Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "creature.h"

class Vampire : public Creature
{

public:
	Vampire();							// default constructor for Vampire
	Vampire(int a, int s);				// constructor for Vampire
	~Vampire();							// destructor for Vampire

	int attack();						// returns the amount of damage inflicted
	int defend(int attack);				// modifies attack damage given a creature's defense roll
};

#endif