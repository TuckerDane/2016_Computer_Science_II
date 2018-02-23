/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			08 December 2016
//
//	Description:	Completes step 3. Sort a set of values for Lab 7 Assignment for CS162
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SORTVALUES_HPP
#define SORTVALUES_HPP

#include <iostream>
#include <fstream>
#include <string>

using std::ofstream;
using std::ifstream;
using std::fstream;
using std::string;


void bubbleSort(string fileName);	// sorts numbers in a file so that they are in ascending order
void allSort();						// sorts all of the files

#endif