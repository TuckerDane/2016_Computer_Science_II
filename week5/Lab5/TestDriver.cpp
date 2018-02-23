/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 October 2016
//
//	Description:	A series of functions which test the code for the Lab5 project
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "TestDriver.h"
#include "InputValidation.h"

using std::cout;
using std::endl;
using std::cin;

/***************************************************************************************************
**	prints the data members of a given critter
***************************************************************************************************/
void displayCritterValues(Critter &critter)
{
	cout << endl;
	cout << "Row: " << critter.getRowPos() << endl;
	cout << "Column: " << critter.getColPos() << endl;
	cout << "Steps: " << critter.getSteps() << endl;
	cout << "Type: " << critter.getType() << endl;
	cout << "Moved: ";

	if (critter.getMoved() == true)
		cout << "True" << endl;
	else
		cout << "False" << endl;
}

/***************************************************************************************************
**	prints what is around a critter inside of a given matrix
***************************************************************************************************/
void displayAroundCritter(Matrix &m, Critter &critter)
{
	for (int i = 0; i < 4; i++)							// print out if the space(s) up/down/left/right are open to move into
	{
		if (i == 0)
			cout << "UP:\t";
		else if (i == 1)
			cout << "RIGHT:\t";
		else if (i == 2)
			cout << "DOWN:\t";
		else	// (i == 3)
			cout << "LEFT:\t";

		cout << m.around(critter)[i] << endl;
	}
	cout << endl;
}

/***************************************************************************************************
**	tests the printMatrix() funciton of Matrix
***************************************************************************************************/
void testPrintMatrix()
{
	Matrix m;
	m.printMatrix();
	m.printMatrix();
}

/***************************************************************************************************
**	tests the addCritter() function of Matrix
***************************************************************************************************/
void testAddCritter()
{
	Critter critter1;
	Critter critter2;
	Critter critter3;
	Critter critter4;
	Critter critter5;

	Matrix matrix1(1, 1);
	Matrix matrix2(2, 2);
	Matrix matrix3(2, 3);

	cout << "printing matrix 1" << endl << endl;
	matrix1.printMatrix();
	cout << endl;

	cout << "adding critters to matrix 1" << endl;
	matrix1.addCritter(&critter1);
	cout << endl;
	
	cout << "printing matrix 1" << endl << endl;
	matrix1.printMatrix();
	cout << endl;

	cout << "Critter 1's values are: " << endl;
	displayCritterValues(critter1);

	cout << "adding critters to matrix 1" << endl;
	matrix1.addCritter(&critter1);
	cout << endl;

	cout << "printing matrix 2" << endl << endl;
	matrix2.printMatrix();
	cout << endl;

	cout << "adding critters to matrix 2" << endl;
	matrix2.addCritter(&critter2);
	matrix2.addCritter(&critter3);
	matrix2.addCritter(&critter4);
	matrix2.addCritter(&critter5);
	matrix2.addCritter(&critter1);
	cout << endl;

	cout << "printing matrix 2 again" << endl;
	matrix2.printMatrix();
	cout << endl;

	cout << "Critter 2's values are " << endl;
	displayCritterValues(critter2);
	cout << endl;

	cout << "Critter 3's values are " << endl;
	displayCritterValues(critter3);
	cout << endl;

	cout << "Criter 4's values are " << endl;
	displayCritterValues(critter4);
	cout << endl;

	cout << "Criter 5's values are " << endl;
	displayCritterValues(critter5);
	cout << endl;

	cout << "Criter 1's values are " << endl;
	displayCritterValues(critter1);
	cout << endl;


	cout << endl;

}

/***************************************************************************************************
**	tests the around() funciton of Matrix
***************************************************************************************************/
void testMatrixAround()
{
	Matrix m;
	Critter critter1;
	Critter critter2;
	Critter critter3;

	m.addCritter(&critter1, 0, 0);
	m.addCritter(&critter2, 1, 0);
	m.addCritter(&critter3, 19, 19);

	m.printMatrix();
	cout << endl;

	// top left limits
	cout << "This is what is around Critter 1" << endl;
	displayAroundCritter(m, critter1);

	// added to be able to sense other critters
	cout << "This is what is around Critter 2" << endl;
	displayAroundCritter(m, critter2);

	// bottom right limits
	cout << "This is what is around Critter 3" << endl;
	displayAroundCritter(m, critter3);
}

/***************************************************************************************************
**	tests the move() funciton of Critter
***************************************************************************************************/
void testCritterMove()
{
	Matrix m;											// create matrix
	Critter critter1;									// create a critter

	m.addCritter(&critter1, 0, 0);						// add critter to matrix at 0, 0
	m.printMatrix();									// print the matrix, critter should be displayed in top left corner of 20x20 matrix

	displayCritterValues(critter1);						// should display critter at row = 0, col = 0, type = C, steps = 0, moved = false (0)

	critter1.move(m.around(critter1));					// move the critter based upon its current surroundings in matrix 1

	displayCritterValues(critter1);						// should indicate that the critter has moved down one or right one, and steps ++

	m.printMatrix();									// no update to matrix should be shown because the matrix has not been updated
}

/***************************************************************************************************
**	tests the moveCritters() function of Matrix
***************************************************************************************************/
void testMatrixMoveCritters()
{
	Matrix m;											// create matrix
	Critter critter1;									// create a critter
	Critter critter2;
	Critter critter3;
	Critter critter4;
	Critter critter5;
	Critter critter6;

	m.addCritter(&critter1, 0, 0);						// add critter to matrix at 0, 0
	m.addCritter(&critter2, 0, 19);
	m.addCritter(&critter3, 19, 0);
	m.addCritter(&critter4, 19, 19);
	m.addCritter(&critter5, 0, 1);
	m.addCritter(&critter6, 1, 0);

	m.printMatrix();									// print the matrix, critter should be displayed in top left corner of 20x20 matrix

	displayCritterValues(critter1);						// should display critter at row = 0, col = 0, type = C, steps = 0, moved = false (0)
	displayCritterValues(critter2);
	displayCritterValues(critter3);
	displayCritterValues(critter4);
	displayCritterValues(critter5);
	displayCritterValues(critter6);

	m.moveCritters();									// should move the critters around in the matrix
	m.moveCritters();
	m.moveCritters();

	m.printMatrix();									// update to matrix should be shown because the matrix has 6been updated

	displayCritterValues(critter1);						// should display critter at row = 0, col = 0, type = C, steps = 0, moved = false (0)
	displayCritterValues(critter2);
	displayCritterValues(critter3);
	displayCritterValues(critter4);
	displayCritterValues(critter5);
	displayCritterValues(critter6);

}

/***************************************************************************************************
**	tests the move() funciton of Critter
***************************************************************************************************/
void testCritterBreed()
{
	Matrix m(1,2);												// create matrix
	Critter critter1;											// create a critter
	critter1.setSteps(3);

	m.addCritter(&critter1, 0, 0);								// add critter to matrix at 0, 0
	m.printMatrix();											// print the matrix, critter should be displayed in top left corner of 20x20 matrix

	displayCritterValues(critter1);								// should display critter at row = 0, col = 0, type = C, steps = 0, moved = false (0)

	Critter *c = new Critter;

	c = critter1.breed(m.around(critter1));						// breed the critter based upon its current surroundings in the matrix
	cout << c->getRowPos() << endl;								// output should be "0"
	cout << c->getColPos() << endl;								// output should be "1"
	
	delete c;
}

/***************************************************************************************************
**	tests the breedCritters() function of Matrix
***************************************************************************************************/
void testMatrixBreedCritters(int rounds)
{
	Matrix m(3,3);								// create matrix

	Ant *ant1 = new Ant;
	Ant *ant2 = new Ant;
	Ant *ant3 = new Ant;
	DoodleBug* doodlebug4 = new DoodleBug;
	DoodleBug* doodlebug5 = new DoodleBug;
	DoodleBug* doodlebug6 = new DoodleBug;


	m.addCritter(ant1, 0, 0);						// add critter to matrix at 0, 0
	m.addCritter(ant2, 2, 2);
	m.addCritter(ant3, 0, 2);
	m.addCritter(doodlebug4, 1, 0);
	m.addCritter(doodlebug5, 1, 2);
	m.addCritter(doodlebug6, 1, 1);

	m.printMatrix();								// print the matrix, critter should be displayed in top left corner of 20x20 matrix
	cout << endl;

	for (int i = 0; i < rounds; i++)
	{
		cout << "-------------------" << endl;
		m.moveCritters();
		m.printMatrix();
		cout << endl;
		m.breedCritters();
		m.starveDoodleBugs();
		m.printMatrix();
		cout << endl;
	}
}

/***************************************************************************************************
**	Base Assignment (no extra credit)
***************************************************************************************************/
void baseAssignment()
{
	Matrix m(20, 20);							// create a 20x20 matrix

	for (int i = 0; i < 100; i++)				// fill the matrix with 100 ants
	{
		m.addCritter(new Ant);
	}
	for (int i = 0; i < 5; i++)					// fill the matrix with 5 doodlebugs
	{
		m.addCritter(new DoodleBug);
	}

	bool finished = false;
	int timeSteps;

	while (finished == false)
	{
		cout << "How many time steps do you want to run? " << endl;
		cin >> timeSteps;

		for (int i = 0; i < timeSteps; i++)
		{
			cout << "Time Step " << i + 1 << endl << endl;
			m.moveCritters();
			m.breedCritters();
			m.starveDoodleBugs();
			m.printMatrix();
			cout << endl;
		}

		cout << "Are you done? (1 for yes, 0 for no) ";
		cin >> finished;
	}
}

/***************************************************************************************************
**	Extra Credit Assignment
***************************************************************************************************/
void extraCreditAssignment()
{
	cout << "THIS ASSIGNMENT INCLUDES EXTRA CREDIT" << endl << endl;

	int rows;		// used to provide input for number of rows in the matrix
	int columns;	// used to provide input for number of columns in the matrix
	int numAnts;	// used to provide input for number of ants in the matrix
	int numDBugs;	// used to provide input for number of doodlebugs in the matrix

	cout << "How many rows do you want in your matrix? ";
	cin >> rows;

	rows = boundsValidation(rows, 1, 1000);									// ensure matrix has between 1-1000 rows

	cout << "How many columns do you want in your matrix? ";
	cin >> columns;

	columns = boundsValidation(columns, 1, 1000);							// ensure matrix has between 1-1000 columns

		cout << "How many ants do you want in your matrix? ";				// promtuser for number of ants
		cin >> numAnts;														// input number of ants

		numAnts = boundsValidation(numAnts, 0, rows*columns);				// ensure that numAnts is at least 0 and no more than the number of possible slots in the matrix

		cout << "How many doodlebugs do you want in your matrix? ";			// prompt user for number of doodlebugs
		cin >> numDBugs;													// input number of doodlebugs

		numDBugs = boundsValidation(numDBugs, 0, (rows*columns - numAnts));	// ensure that numDBugs is at least 0 and no more than the number of available slots left in the matrix
		cout << endl;

	Matrix m(rows, columns);							// create a rowsxcolumns matrix

	for (int i = 0; i < numAnts; i++)					// fill the matrix with numAnts ants
	{
		m.addCritter(new Ant);
	}
	for (int i = 0; i < numDBugs; i++)					// fill the matrix with numDBugs doodlebugs
	{
		m.addCritter(new DoodleBug);
	}

	int finished = 0;
	int timeSteps;
	int counter = 0;

	cout << "Starting Positions of Critters before any timesteps" << endl << endl;
	m.printMatrix();
	cout << endl;

	while (finished != 1)
	{
		cout << "How many ";
		if (counter > 0)
			cout << "more ";
		cout << "time steps do you want to run? ";
		cin >> timeSteps;

		timeSteps = boundsValidation(timeSteps, 0, 1000);
		cout << endl;

		for (int i = 0; i < timeSteps; i++)
		{
			cout << "Time Step " << counter + 1 << endl << endl;
			m.moveCritters();
			m.breedCritters();
			m.starveDoodleBugs();
			m.printMatrix();
			counter++;
			cout << endl;
		}

		cout << "Are you done? (1 for yes, 0 for no) ";
		cin >> finished;

		finished = boundsValidation(finished, 0, 1);
	}
}