/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			08 December 2016
//
//	Description:	Lab 7 Assignment for CS162
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include "CreateDataFiles.h"
#include "LinearSearch.h"
#include "SortValues.h"
#include "BinarySearch.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	srand(time(NULL));
	
	cout << "CREATING FILES" << endl;							// 1. Create data files
	createFiles("noTarget.txt");	
	displayFiles();												// display contents

	cout << "CONDUCTING LINEAR SEARCH OF FILES" << endl;		// 2. Search for the target value (i.e. 0)
	lSearchFiles(0);		

	cout << "SORTING FILES" << endl;							// 3. Sort a set of values
	cout << "using a bubble sort function from page 606 of C++ Early Objects!" << endl;
	allSort();
	displayFiles();												// display contents
	
	cout << "CONDUCTING BINARY SEARCH OF FILES" << endl;		// 4. Search for the target value using Binary Search
	bSearchFiles('0');

	cout << endl;
	return 0;
}