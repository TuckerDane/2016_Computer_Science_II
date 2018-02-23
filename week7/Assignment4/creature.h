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
	string fighterName;

	int armor;
	int strength;
	int maxStrength;

public:
	Creature();									// default constructor for Creature
	Creature(int a, int s);						// constructor for Creature
	~Creature();								// destructor for Creature

	virtual void setArmor(int a);				// sets the armor value of a creature
	virtual void setStrength(int s);			// sets the strength value of a creature
	virtual void setMaxStrength(int m);			// sets the maxStrength value of a creature
	virtual void setFighterName(string f);		// sets the fighter name of the creature

	virtual string getName();					// returns the name of the creature
	virtual string getFighterName();			// returns the name of the fighter
	virtual int getArmor();						// returns the creature's armor value
	virtual int getStrength();					// returns the creature's strength value
	virtual int getMaxStrength();				// returns the creature's maxStrength value

	virtual int attack() = 0;					// returns the amount of damage inflicted
	virtual int defend(int attack) = 0;			// modifies attack damage given a creature's defense roll
	virtual void applyDamage(int damage);		// applies damage to a creature's strength points
	virtual void replenish();					// replenishes 50% damage, rounded down, to the creature
};

#endif