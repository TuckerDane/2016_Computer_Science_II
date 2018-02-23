/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			08 December 2016
//
//	Description:	Completes step 2. Search for the target value (i.e. 0) for Lab 7 Assignment for CS162
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef LINEARSEARCH_HPP
#define LINEARSEARCH_HPP

#include <iostream>
#include <fstream>
#include <string>

using std::ofstream;
using std::ifstream;
using std::fstream;
using std::string;
using std::cout;
using std::endl;

int linearSearch(string fileName, int target);					//	conducts a linear search of a file for a target and returns the position of the target
void lSearchFiles(int target);									//	runs linearSearch on a number of files for a target outputs the position(s) of the target
void displaySearch(string fileName, int target, int actual);	//	displays the results of a search

#endif