/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			26 November 2016
//
//	Description:	The base class for various creatures
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
using std::string;

class Creature
{
protected:
	string name;

	int armor;
	int strength;

public:
	Creature();									// default constructor for Creature
	Creature(int a, int s);						// constructor for Creature
	~Creature();								// destructor for Creature

	void setArmor(int a);						// sets the armor value of a creature
	void setStrength(int s);					// sets the strength value of a creature

	string getName();							// returns the name of the creature
	int getArmor();								// returns the creature's armor value
	int getStrength();							// returns the creature's strength value

	virtual int attack();						// returns the amount of damage inflicted
	virtual int defend(int attack);				// modifies attack damage given a creature's defense roll
	virtual void applyDamage(int damage);		// applies damage to a creature's strength points
};

#endif