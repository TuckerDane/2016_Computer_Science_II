/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			26 November 2016
//
//	Description:	The Blue Men Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "BlueMen.h"
#include "Die.h"
#include <string>

using std::cout;
using std::endl;
using std::cin;

/***************************************************************************************************
**	default constructor for Blue Men
***************************************************************************************************/
BlueMen::BlueMen()
{
	this->name = "Blue Men";
	this->armor = 3;
	this->strength = 12;
}

/***************************************************************************************************
**	constructor for Blue Men
***************************************************************************************************/
BlueMen::BlueMen(int a, int s)
{
	this->armor = a;
	this->strength = s;
}

/***************************************************************************************************
**	destructor for Barbarian
***************************************************************************************************/
BlueMen::~BlueMen()
{

}

/***************************************************************************************************
**	returns the amount of damage inflicted
***************************************************************************************************/
int BlueMen::attack()
{
	Die D10(10);
	return (D10.roll() + D10.roll());
}

/***************************************************************************************************
**	modifies attack damage given a Blue Men's defense roll - number of die reduced based on strength
***************************************************************************************************/
int BlueMen::defend(int attack)
{
	cout << this->name << " defends against an attack of " << attack << endl;
	Die D6;

	if (this->getStrength() < 5)									// if the Blue Men's strengh is 4 or less
	{
		return attack - D6.roll();									// roll one die
	}
	else if(this->getStrength() < 9)								// else if the Blue Men's strength is 8 or less
	{
		return attack - (D6.roll() + D6.roll());					// roll two die
	}
	else															// else the Blue Men's strength is 12 or less
	{
		return attack - (D6.roll() + D6.roll() + D6.roll());		// roll three die
	}
}
