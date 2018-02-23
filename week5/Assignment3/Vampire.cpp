/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			26 November 2016
//
//	Description:	The Vampire Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vampire.h"
#include "Die.h"
#include <string>

using std::cout;
using std::endl;
using std::cin;

/***************************************************************************************************
**	default constructor for vampire
***************************************************************************************************/
Vampire::Vampire()
{
	this->name = "Vampire";
	this->armor = 1;
	this->strength = 18;
}

/***************************************************************************************************
**	constructor for vampire
***************************************************************************************************/
Vampire::Vampire(int a, int s)
{
	this->armor = a;
	this->strength = s;
}

/***************************************************************************************************
**	destructor for vampire
***************************************************************************************************/
Vampire::~Vampire()
{

}

/***************************************************************************************************
**	returns the amount of damage inflicted
***************************************************************************************************/
int Vampire::attack()
{
	Die D12(12);
	return D12.roll();
}

/***************************************************************************************************
**	modifies attack damage given a vampire's defense roll, 50% chance the attack fails due to charm
***************************************************************************************************/
int Vampire::defend(int attack)
{
	cout << this->name << " defends against an attack of " << attack << endl;
	Die D6;
	if (D6.roll() > 3)					// roll the die, there is a 50% chance that...
	{
		return attack - D6.roll();		// the attack is successful and the Vampire rolls it's defense
	}
	else								// threre's also a 50% chance the attacker is charmed
	{
		cout << "CHARM SUCCEEDED" << endl;
		return 0;						// and no damage is inflicted whatsoever
	}	
}
