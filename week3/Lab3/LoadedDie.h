#ifndef LOADEDDIE_H
#define LOADEDDIE_H

#include "Die.h"

class LoadedDie : public Die
{
private:
	int loadedSide;						// indicates what side of the die is loaded
	int loadPercent;					// indicates the percent loadedness of the loaded side of the die

public:
	LoadedDie();						// default constructor for LoadedDie
	LoadedDie(int s, int l, int p);		// constructor for LoadedDie setting sides = 6, loadedSide = 6, and loadPercent = 100

	void setLoadedSide(int l);			// sets the loaded side of the die
	void setLoadPercent(int p);			// sets the percent loadedness of the loaded side of the die
	
	int getLoadedSide();				// gets the loaded side of the die
	int getLoadPercent();				// gets the percent loadedness of the loaded side of the die

	int roll();							// rolls the loaded die
};

#endif
