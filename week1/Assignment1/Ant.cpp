/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			02 October 2016
//
//	Description:	This is a file contains the prototypes to two functions. One function allows the user to input values into a
//					matrix. The second funciton prints the values stored within the matrix.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Ant.h"
#include "Matrix.h"

/***************************************************************************************************
**	a default constructor for Ant
***************************************************************************************************/

Ant::Ant(int x, int y, int c)
{
	setXpos(x);
	setYpos(y);
	setCdir(c);
}

/***************************************************************************************************
**	a destructor for Ant
***************************************************************************************************/
Ant::~Ant()
{

}

/***************************************************************************************************
**	gets the column which the ant is occupying
***************************************************************************************************/
int Ant::getXpos()
{
	return xpos;
}

/***************************************************************************************************
**	gets the row which the ant is occupying
***************************************************************************************************/
int Ant::getYpos()
{
	return ypos;
}

/***************************************************************************************************
**	gets the cardinal direction which the ant is facing
***************************************************************************************************/
int Ant::getCdir()
{
	return cdir;
}

/***************************************************************************************************
**	sets what column the ant will occupy
***************************************************************************************************/
void Ant::setXpos(int x)
{
	xpos = x;
}

/***************************************************************************************************
**	sets what row the ant will occupy
***************************************************************************************************/
void Ant::setYpos(int y)
{
	ypos = y;
}

/***************************************************************************************************
**	sets the cardinal direction the ant will be facing
***************************************************************************************************/
void Ant::setCdir(int c)
{
	cdir = c;
}

/***************************************************************************************************
**	senses the value of the position in the matrix that the ant is occupying (true or false)
***************************************************************************************************/
bool Ant::senseSquare(bool s)
{
	return s;
}

/***************************************************************************************************
**	changes the x and y positions of the ant based on the ant's current cardinal direction
***************************************************************************************************/
void Ant::move(int mSizeY, int mSizeX)
{
	if (getCdir() == 1)									// cardinal direction is up
	{
		if (getYpos() == 0)								// if the ant is at the top edge of the matrix,
			setYpos(mSizeY - 1);						// move the ant to the bottom edge of the matrix
		else											// else
			setYpos(getYpos() - 1);						// move the y position of the ant up one
	}
	else if (getCdir() == 2)							// cardinal direction is right
	{
		if (getXpos() == (mSizeX - 1))					// if the ant is at the right edge of the matrix,
			setXpos(0);									// move the ant to the left edge of the matrix
		else											// else
			setXpos(getXpos() + 1);						// move the x position of the ant right one
	}
	else if (getCdir() == 3)							// cardinal direction is down
	{
		if (getYpos() == (mSizeY - 1))					// if the ant is at the bottom edge of the matrix,
			setYpos(0);									// move the ant to the top edge of the matrix
		else											// else
			setYpos(getYpos() + 1);						// move the y position of the ant down one
	}
	else // (getCdir() == 4)							// cardinal direction is left
	{
		if (getXpos() == 0)								// if the ant is at the left edge of the matrix,
			setXpos(mSizeX - 1);						// move the ant to the right edge of the matrix
		else											// else
			setXpos(getXpos() - 1);						// move the x position of the ant left one
	}
}

/***************************************************************************************************
**	turns the ant left or right based upon the the value of the square it is occupying 
***************************************************************************************************/
void Ant::turn(bool s)
{
	if (senseSquare(s) == false)						// if the position the ant currently occupies is black
	{
		cdir--;											// turn left
		if (cdir == 0)									// if the cardinal direction is 0, then it is 4
		{
			cdir = 4;
		}
	}
	else
	{
		cdir++;											// otherwise turn right
		if (cdir == 5)									// if the cardinal direction is 5, then its the same as 1
		{
			cdir = 1;
		}
	}
}

