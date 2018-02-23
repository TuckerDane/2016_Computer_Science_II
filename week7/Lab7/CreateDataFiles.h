/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			08 December 2016
//
//	Description:	Completes step 1. Create data files for Lab 7 Assignment for CS162
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CREATEDATA_HPP
#define CREATEDATA_HPP

#include <iostream>
#include <string>
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::string;
using std::cout;
using std::endl;

void createDataFile(string name);					// a function which creates a file containing a random collection of 25 integers 1-9
void copyFile(string inF, string oF, int tLoc);		// a function which copies and names a file with the target (0) location at the beginning, middle, and end.
void createFiles(string fName);						// a function which creates the necessary files for the CS162 Lab 7
void displayDataFile(string fName);					// a function which displays the contents of a file
void displayFiles();								// displays the contents of all files

#endif

