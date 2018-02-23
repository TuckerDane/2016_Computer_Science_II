/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			08 December 2016
//
//	Description:	Completes step 3. Sort a set of values for Lab 7 Assignment for CS162
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "SortValues.h"

/***************************************************************************************************
**	sorts numbers in a file so that they are in ascending order
***************************************************************************************************/
void bubbleSort(string fileName)
{
	char nums[25];

	fstream fin(fileName, fstream::in);

	for (int i = 0; i < 25; i++)			// read the file into an array
	{	
		fin >> nums[i];
	}

	bool swap;								// variable that tells if a swap has been made
	do
	{
		swap = false;						// swap is false
		for (int i = 0; i < 24; i++)		// iterate through array
		{
			if (nums[i] > nums[i + 1])		// if a num is greater than the next num in the list
			{
				int temp = nums[i];			// swap the nums
				nums[i] = nums[i + 1];
				nums[i + 1] = temp;
				swap = true;				// set swap to true
			}
		}
	} while (swap == true);					// continue to do this while swap is true

	ofstream outFile(fileName);

	for (int i = 0; i < 25; i++)
	{
		outFile.seekp(i);
		outFile << nums[i];
	}
}

/***************************************************************************************************
**	sorts all of the files
***************************************************************************************************/
void allSort()
{
	bubbleSort("noTarget.txt");
	bubbleSort("beginning.txt");
	bubbleSort("middle.txt");
	bubbleSort("theEnd.txt");
}