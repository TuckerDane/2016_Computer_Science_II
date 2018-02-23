#include "LoadedDie.h"
#include <iostream>

/***************************************************************************************************
**	default constructor for LoadedDie setting sides = 6, loadedSide = 6, and loadPercent = 100
***************************************************************************************************/
LoadedDie::LoadedDie()
{
	setSides(6);
	setLoadedSide(6);
	setLoadPercent(100);
}

/***************************************************************************************************
**	a constructor for LoadedDie
***************************************************************************************************/
LoadedDie::LoadedDie(int s, int l, int p)
{
	setSides(s);
	setLoadedSide(l);
	setLoadPercent(p);
}

/***************************************************************************************************
**	sets the side of the dice which is loaded
***************************************************************************************************/
void LoadedDie::setLoadedSide(int l)
{
	loadedSide = l;
}

/***************************************************************************************************
**	sets the percentage the loaded side will be landed on
***************************************************************************************************/
void LoadedDie::setLoadPercent(int p)
{
	loadPercent = p;
}

/***************************************************************************************************
**	returns loadedSide
***************************************************************************************************/
int LoadedDie::getLoadedSide()
{
	return loadedSide;
}

/***************************************************************************************************
**	returns loadPercent
***************************************************************************************************/
int LoadedDie::getLoadPercent()
{
	return loadPercent;
}

/***************************************************************************************************
**	rolls the loaded die
***************************************************************************************************/
int LoadedDie::roll()
{
	if (rand() % 100 + 1 <= getLoadPercent())			// if the loaded side gets landed on, return it
	{
		//std::cout << "Rolling Loaded Die" << std::endl;
		return getLoadedSide();
	}
	else												// else randomly return another number that is not loadedSide
	{
		int temp = 0;									// use a temp variable to compare to the number rolled in order to eliminate rolling the loadedSide already accounted for
		while (temp == 0 || temp == getLoadedSide())
		{
			temp = Die::roll();
		}

		return temp;
	}
}