/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			08 December 2016
//
//	Description:	Completes step 1. Create data files for Lab 7 Assignment for CS162
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "CreateDataFiles.h"

/***************************************************************************************************
**	a function which creates a file containing a random collection of 25 integers 1-9
***************************************************************************************************/
void createDataFile(string name)
{
	ofstream noTarget;					// begin a stream

	noTarget.open(name);				// open the "noTarget.txt" file

	for (int i = 0; i < 25; i++)		// for 25 iterations
	{
		int input = rand() % 9 + 1;		// pick a random number between 0 and 9
		noTarget << input;				// add the randomly selected number to noTarget
	}

	noTarget << "\n";					// add a newline character to noTarget
	noTarget.close();
}

/***************************************************************************************************
**	a function which copies and names a file
***************************************************************************************************/
void copyFile(string inF, string oF, int tLoc)
{
	ifstream inFile(inF);
	ofstream outFile(oF);

	outFile << inFile.rdbuf();

	outFile.seekp(tLoc);
	outFile << 0;
}

/***************************************************************************************************
**	a function which creates the necessary files for the CS162 Lab 7
***************************************************************************************************/
void createFiles(string fName)
{
	createDataFile(fName);
	copyFile(fName, "beginning.txt", 2);
	copyFile(fName, "middle.txt", 13);
	copyFile(fName, "theEnd.txt", 24);
}

/***************************************************************************************************
**	a function which displays the contents of a file
***************************************************************************************************/
void displayDataFile(string fName)
{
	cout << fName << "\t contains: \t";
	char temp;

	fstream fin(fName, fstream::in);

	for (int i = 0; i < 25; i++)			// read the chars into temp and display
	{
		fin >> temp;
		cout << temp;
	}

	cout << endl;
}

/***************************************************************************************************
**	displays the contents of all files
***************************************************************************************************/
void displayFiles()
{
	displayDataFile("noTarget.txt");
	displayDataFile("beginning.txt");
	displayDataFile("middle.txt");
	displayDataFile("theEnd.txt");
	cout << endl;
}

