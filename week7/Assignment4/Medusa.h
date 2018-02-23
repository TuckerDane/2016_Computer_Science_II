/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			26 November 2016
//
//	Description:	The Medusa Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "creature.h"

class Medusa : public Creature
{
public:
	Medusa();								// default constructor for Medusa
	Medusa(int a, int s);					// constructor for Medusa
	~Medusa();								// destructor for Medusa

	int attack();							// returns the amount of damage inflicted
	int defend(int attack);					// modifies attack damage given a creature's defense roll
};

#endif