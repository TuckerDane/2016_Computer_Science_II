#include "Die.h"
#include <iostream>

/***************************************************************************************************
**	default constructor for Die setting sides to 6
***************************************************************************************************/
Die::Die()
{
	setSides(6);
}

/***************************************************************************************************
**	a constructor for Die
***************************************************************************************************/
Die::Die(int s)
{
	setSides(s);
}

/***************************************************************************************************
**	a function which rolls the dice given a particular loaded side and loadedness
***************************************************************************************************/
int Die::roll()
{
	//std::cout << "rolling regular die" << std::endl;
	return (rand() % getSides() + 1);
}

/***************************************************************************************************
**	a function to set the number of sides of the die
***************************************************************************************************/
void Die::setSides(int s)
{
	sides = s;
}

/***************************************************************************************************
**	a function to get the number of sides of the die
***************************************************************************************************/
int Die::getSides()
{
	return sides;
}
