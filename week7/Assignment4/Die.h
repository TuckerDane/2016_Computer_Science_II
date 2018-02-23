/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			26 November 2016
//
//	Description:	A simple die class that allows the user to define the number of sides and can roll a random number from 1-n
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DIE_H
#define DIE_H

class Die
{
private:
	int sides;							// the number of sides on the die

public:
	Die();								// default constructor for die setting sides to 6
	Die(int s);							// constructer setting the number of sides to s

	int roll();							// rolls the dice. If "load" is given to a particular number, that side of the dice is "loaded" to roll at a higher percent indicated by percent
	void setSides(int s);				// sets the number of sides on the dice
	int getSides();						// gets the number of sides of the dice
};

#endif