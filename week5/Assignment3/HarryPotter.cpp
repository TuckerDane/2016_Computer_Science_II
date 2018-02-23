/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			26 November 2016
//
//	Description:	The Harry Potter Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "HarryPotter.h"
#include "Die.h"
#include <string>

using std::cout;
using std::endl;
using std::cin;

/***************************************************************************************************
**	default constructor for HarryPotter
***************************************************************************************************/
HarryPotter::HarryPotter()
{
	this->resurrected = false;
	this->name = "Harry Potter";
	this->armor = 0;
	this->strength = 10;
}

/***************************************************************************************************
**	constructor for HarryPotter
***************************************************************************************************/
HarryPotter::HarryPotter(int a, int s)
{
	this->armor = a;
	this->strength = s;
}

/***************************************************************************************************
**	destructor for HarryPotter
***************************************************************************************************/
HarryPotter::~HarryPotter()
{

}

/***************************************************************************************************
**	resets the resurrection status of Harry Potter
***************************************************************************************************/
void HarryPotter::setResurrected(bool r)
{
	this->resurrected = r;
}

/***************************************************************************************************
**	resets the strength of Harry Potter to s and also sets resurrected to false
***************************************************************************************************/
void HarryPotter::setStrength(int s)
{
	this->strength = s;
}

/***************************************************************************************************
**	returns the amount of damage inflicted
***************************************************************************************************/
int HarryPotter::attack()
{
	Die D6(6);
	return (D6.roll() + D6.roll());
}

/***************************************************************************************************
**	modifies attack damage given a HarryPotter's defense roll
***************************************************************************************************/
int HarryPotter::defend(int attack)
{
	cout << this->name << " defends against an attack of " << attack << endl;
	Die D6;
	return attack - (D6.roll() + D6.roll());
}

/***************************************************************************************************
**	applies damage to a Harry Potter's strength points, allowing for resurrection
***************************************************************************************************/
void HarryPotter::applyDamage(int damage)
{
	damage = (damage - this->armor);													// subtract the creature's armor value from the damage taken

	if (damage <= 0)																	// if no actual damage is dealt
	{
		cout << this->getName() << " takes no damage" << endl;							// display no damage dealt
	}
	else																				// else damage is dealt...
	{
		cout << this->getName() << " takes " << damage << " damage" << endl;			// display the damage

		if (this->resurrected == true)													// if harry has been resurrected...
		{
			setStrength(getStrength() - damage);										// subtract the damage from strength

			if (getStrength() <= 0)														// ensures strength sets to 0 of the creature is dead
			{
				setStrength(0);
				cout << this->getName() << " IS DEAD" << endl;							// display death
			}
		}
		else																			// else harry has not been resurrected...
		{
			setStrength(getStrength() - damage);										// subtract the damage from strength

			if (getStrength() <= 0)														// if strength goes to or below 0, resurrect Harry Potter by...
			{
				setStrength(20);														// resetting strength to 20
				this->resurrected = true;												// and setting resurrected to true;
				cout << this->getName() << " IS RESURRECTED" << endl;
			}
		}
	}
}

