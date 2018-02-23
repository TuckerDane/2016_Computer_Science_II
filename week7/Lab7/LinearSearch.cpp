/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			08 December 2016
//
//	Description:	Completes step 2. Search for the target value (i.e. 0) for Lab 7 Assignment for CS162
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "LinearSearch.h"

/***************************************************************************************************
**	conducts a linear search of a file for a target and returns the position of the target
***************************************************************************************************/
int linearSearch(string fileName, int target)
{
	fstream fin(fileName, fstream::in);

	bool found = false;
	int index = 0;
	char position = -1;

	while (index < 25 && found == false)
	{
		char temp = -1;
		fin >> temp;

		if (temp == '0')
		{
			position = index;
			found = true;
		}

		index++;
	}

	return position+1;
}

/***************************************************************************************************
**	runs linearSearch on a number of files for a target outputs the position(s) of the target
***************************************************************************************************/
void lSearchFiles(int target)
{
	cout << "Searching for the target value " << target << " using a LINEAR SEARCH from page 596 in Starting Out With C++ Early Objects!!";
	cout << " Cannot use binary search yet because the lists are unsorted!" << endl << endl;

	displaySearch("noTarget.txt", target, linearSearch("noTarget.txt", target));
	displaySearch("beginning.txt", target, linearSearch("beginning.txt", target));
	displaySearch("middle.txt", target, linearSearch("middle.txt", target));
	displaySearch("theEnd.txt", target, linearSearch("theEnd.txt", target));
	cout << endl;
}

/***************************************************************************************************
**	displays the results of a search
***************************************************************************************************/
void displaySearch(string fileName, int target, int actual)
{
	if (actual == 0 || actual == -1)
	{
		cout << "There is no value " << target << " in " << fileName << endl;
	}
	else
	{
		cout << "The position of " << target << " in the file " << fileName << " is \t \t" << actual << endl;
	}
}