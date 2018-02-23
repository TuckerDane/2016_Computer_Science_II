/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			26 November 2016
//
//	Description:	The base class for various creatures
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "creature.h"
#include "Die.h"
#include <string>

using std::cout;
using std::endl;
using std::cin;

/***************************************************************************************************
**	default constructor for creature
***************************************************************************************************/
Creature::Creature()
{
	this->name = "Creature";
	this->armor = 3;
	this->strength = 10;
}

/***************************************************************************************************
**	constructor for creature
***************************************************************************************************/
Creature::Creature(int a, int s)
{
	this->armor = a;
	this->strength = s;
}

/***************************************************************************************************
**	destructor for creature
***************************************************************************************************/
Creature::~Creature()
{

}

/***************************************************************************************************
**	sets the armor value of a creature
***************************************************************************************************/
void Creature::setArmor(int a)
{
	this->armor = a;
}

/***************************************************************************************************
**	sets the strength value of a creature
***************************************************************************************************/
void Creature::setStrength(int s)
{
	this->strength = s;
}

/***************************************************************************************************
**	returns the name of the creature
***************************************************************************************************/
string Creature::getName()
{
	return this->name;
}

/***************************************************************************************************
**	returns the creature's armor value
***************************************************************************************************/
int Creature::getArmor()
{
	return this->armor;
}

/***************************************************************************************************
**	returns the creature's strength value
***************************************************************************************************/
int Creature::getStrength()
{
	return this->strength;
}

/***************************************************************************************************
**	returns the amount of damage inflicted (default creature rolls a D6)
***************************************************************************************************/
int Creature::attack()
{
	Die D6(6);
	return D6.roll();
}

/***************************************************************************************************
**	modifies attack damage given a creature's defense roll (default creature rolls a D6)
***************************************************************************************************/
int Creature::defend(int attack)
{
	cout << this->name << " defends against an attack of " << attack << endl;
	Die D6;
	return attack - D6.roll();
}

/***************************************************************************************************
**	applies damage to a creature's strength points
***************************************************************************************************/
void Creature::applyDamage(int damage)
{
	damage = (damage - this->armor);													// subtract the creature's armor value from the damage taken

	if (damage <= 0)																	// if no actual damage is dealt
	{
		cout << this->getName() << " takes no damage" << endl;							// display no damage dealt
	}
	else																				// else damage is dealt...
	{
		cout << this->getName() << " takes " << damage << " damage" << endl;			// display the damage

		setStrength(getStrength() - damage);											// subtract the damage from strength

		if (getStrength() <= 0)															// ensures strength sets to 0 of the creature is dead
		{
			setStrength(0);
			cout << this->name << " IS DEAD!" << endl;
		}
	}
}