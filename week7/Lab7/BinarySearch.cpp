/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			08 December 2016
//
//	Description:	Completes step 4. Search for the target value using Binary Search for Lab 7 Assignment for CS162
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "BinarySearch.h"

/***************************************************************************************************
**	conducts a binary search of a file for a target and returns the position of the target
***************************************************************************************************/
int binarySearch(string fileName, char target)
{
	char nums[25];

	fstream fin(fileName, fstream::in);

	for (int i = 0; i < 25; i++)			// read the file into an array
	{
		fin >> nums[i];
	}

	int first = 0;
	int last = sizeof(nums) - 1;
	int middle;
	bool found = false;
	int position = -1;

	while (found == false && first <= last)
	{
		middle = (first + last) / 2;
		if (nums[middle] == target)
		{
			found = true;
			position = middle;
		}
		else if (nums[middle] > target)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}

	return position;
}

/***************************************************************************************************
**	runs binarySearch on a number of files for a target outputs the position(s) of the target
***************************************************************************************************/
void bSearchFiles(char target)
{
	cout << "Searching for the target value " << target << " using a BINARY SEARCH from page 623 in Starting Out With C++ Early Objects!!";
	cout << " Able to use binary search because the files are now sorted!" << endl << endl;

	bDisplaySearch("noTarget.txt", target, binarySearch("noTarget.txt", target));
	bDisplaySearch("beginning.txt", target, binarySearch("beginning.txt", target));
	bDisplaySearch("middle.txt", target, binarySearch("middle.txt", target));
	bDisplaySearch("theEnd.txt", target, binarySearch("theEnd.txt", target));
	cout << endl;
}

/***************************************************************************************************
**	displays the results of a search
***************************************************************************************************/
void bDisplaySearch(string fileName, char target, int actual)
{
	if (actual == -1)
	{
		cout << "There is no value " << target << " in " << fileName << endl;
	}
	else
	{
		cout << "The position of " << target << " in the file " << fileName << " is \t \t" << actual << endl;
	}
}