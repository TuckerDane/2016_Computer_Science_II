/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			26 November 2016
//
//	Description:	The Harry Potter Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "creature.h"

class HarryPotter : public Creature
{
private:
	bool resurrected;

public:
	HarryPotter();								// default constructor for Medusa
	HarryPotter(int a, int s);					// constructor for Medusa
	~HarryPotter();								// destructor for Medusa

	void setResurrected(bool r);				// resets the resurrection status of Harry Potter
	void setStrength(int s);					// resets the strength of Harry Potter to s and also sets resurrected to false

	int attack();								// returns the amount of damage inflicted
	int defend(int attack);						// modifies attack damage given a creature's defense roll
	void applyDamage(int damage);				// applies damage to a Harry Potter's strength points, allowing for resurrection
};

#endif