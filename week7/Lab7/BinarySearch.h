/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			08 December 2016
//
//	Description:	Completes step 4. Search for the target value using Binary Search for Lab 7 Assignment for CS162
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP

#include <iostream>
#include <fstream>
#include <string>

using std::ofstream;
using std::ifstream;
using std::fstream;
using std::string;
using std::cout;
using std::endl;

int binarySearch(string fileName, char target);					//	conducts a binary search of a file for a target and returns the position of the target
void bSearchFiles(char target);									//	runs binarySearch on a number of files for a target outputs the position(s) of the target
void bDisplaySearch(string fileName, char target, int actual);	//	displays the results of a search

#endif