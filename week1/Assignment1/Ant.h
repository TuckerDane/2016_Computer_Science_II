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

#ifndef ANT_HPP
#define ANT_HPP

#include <iostream>
#include "Matrix.h"

class Ant
{
private:
	int xpos;								// a variable which stores the row the ant is on in the matrix
	int ypos;								// a variable which stores the column the ant is on in the matrix
	int cdir;								// a variable which stores the cardinal direction which the ant is facing
											// (1=up, 2=right, 3=down, 4=left)
public:
	Ant(int x, int y, int c);				// default constructor for ant which takes its initial x, y positions and c direction
	~Ant();									// destructor for ant

	int getXpos();							// gets the column which the ant is occupying
	int getYpos();							// gets the row which the ant is occupying
	int getCdir();							// gets the cardinal direction which the ant is facing
	
	void setXpos(int x);					// sets what column the ant will occupy
	void setYpos(int y);					// sets what row the ant will occupy
	void setCdir(int c);					// sets the cardinal direction the ant will be facing

	bool senseSquare(bool s);				// returns the value of the position in the matrix that the ant is occupying (true or false)		
	void move(int mSizeY, int mSizeX);		// changes the x and y positions of the ant based on the ant's current cardinal direction
	void turn(bool s);						// turns the ant left or right based upon the the value of the square it is occupying 
};

#endif
