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
	this->fighterName = "Fighter";
	this->armor = 3;
	this->strength = 10;
	this->maxStrength = 50;
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
**	sets the maxStrength value of a creature
***************************************************************************************************/
void Creature::setMaxStrength(int m)
{
	this->maxStrength = m;
}

/***************************************************************************************************
**	sets the fighter name of the creature
***************************************************************************************************/
void Creature::setFighterName(string f)
{
	this->fighterName = f;
}

/***************************************************************************************************
**	returns the name of the creature
***************************************************************************************************/
string Creature::getName()
{
	return this->name;
}

/***************************************************************************************************
**	returns the name of the fighter
***************************************************************************************************/
string Creature::getFighterName()
{
	return this->fighterName;
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
**	returns the creature's  max strength value
***************************************************************************************************/
int Creature::getMaxStrength()
{
	return this->maxStrength;
}

/***************************************************************************************************
**	applies damage to a creature's strength points
***************************************************************************************************/
void Creature::applyDamage(int damage)
{
	damage = (damage - this->armor);													// subtract the creature's armor value from the damage taken

	if (damage <= 0)																	// if no actual damage is dealt
	{
		cout << this->getFighterName() << " takes no damage" << endl;							// display no damage dealt
	}
	else																				// else damage is dealt...
	{
		cout << this->getFighterName() << " takes " << damage << " damage" << endl;			// display the damage

		setStrength(getStrength() - damage);											// subtract the damage from strength

		if (getStrength() <= 0)															// ensures strength sets to 0 of the creature is dead
		{
			setStrength(0);
			cout << this->fighterName << " IS DEAD!" << endl;
		}
	}
}

/***************************************************************************************************
**	replenishes 50% damage, rounded down, to the creature
***************************************************************************************************/
void Creature::replenish()
{
	cout << this->getFighterName() << " strength replenished from " << this->getStrength() << " to ";
	this->setStrength(this->getStrength() + ((this->getMaxStrength() - this->getStrength()) / 2));
	cout << this->getStrength() << endl;
}