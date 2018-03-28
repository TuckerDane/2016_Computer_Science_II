/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			28 October 2016
//
//	Description:	A dynamically allocated matrix which holds the values "true"/"false" which can be printed as "#" or " "
//					respectively. Also prints "*" if an ant is in the position whether true or false/
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Matrix.h"
#include "TestDriver.h"
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

/***************************************************************************************************
**	a default constructor for Matrix
***************************************************************************************************/
Matrix::Matrix()
{
	setMatSize(20, 20);										// create a matrix of size 20x20
	setOpenSlots(20*20);									// initializes openSlots to 400

	matrix = new Critter**[getMatSizeRow()];				// create an array (row sizeRow) of rows with pointers to critters
	for (int i = 0; i < getMatSizeRow(); i++)				// fill array with columns (sizeColumn) of pointers to critters
		matrix[i] = new Critter*[getMatSizeCol()];

															// fill matrix with NULL values
	for (int i = 0; i < getMatSizeRow(); i++)				// i indicates the row
	{
		for (int j = 0; j < getMatSizeCol(); j++)			// j indicates the column
		{
			setMatPos(NULL, i, j);							// the matrix position at [sizeRow][sizeColumn] is set to NULL
		}
	}
	
}

/***************************************************************************************************
**	a default constructor for Matrix
***************************************************************************************************/
Matrix::Matrix(int sizeRow, int sizeCol)
{								
	setMatSize(sizeRow, sizeCol);						// Set Default Matrix Size
	setOpenSlots(sizeRow*sizeCol);						// set the number of open slots in the matrix

														// Allocate memory for the Matrix
	matrix = new Critter**[getMatSizeRow()];			// create an array (row sizeRow) of rows with pointers to critters
	for (int i = 0; i < getMatSizeRow(); i++)			// fill array with columns (sizeColumn) of pointers to critters
		matrix[i] = new Critter*[getMatSizeCol()];
														
														// Fill Default Matrix with NULL values
	for (int i = 0; i < getMatSizeRow(); i++)			// i indicates the row
	{
		for (int j = 0; j < getMatSizeCol(); j++)		// j indicates the column
		{
			setMatPos(NULL, i, j);						// the matrix position at [sizeRow][sizeColumn] is set to NULL
		}
	}
}

/***************************************************************************************************
**	a destructor for Matrix
***************************************************************************************************/
Matrix::~Matrix()
{														

	for (int i = 0; i < mSizeRow; i++)					// destroys the values stored within the rows of matrix
	{
		for (int j = 0; j < mSizeCol; j++)				// destroys the values pointed to in each columnar position of a single row
		{
			if (matrix[i][j] == NULL)
			{
				delete matrix[i][j];					// destruction of the individual column value
			}
		}
		delete[] matrix[i];								// destruction of the row
	}
	delete matrix;										// destruction of the matrix itself
									
}

/***************************************************************************************************
**	a function which sets the size of the matrix
***************************************************************************************************/
void Matrix::setMatSize(int sRow, int sCol)
{
	mSizeRow = sRow;
	mSizeCol = sCol;
}

/***************************************************************************************************
**	a function which sets a position in the matrix to the address of a critter
***************************************************************************************************/
void Matrix::setMatPos(Critter *c, int row, int col)
{
	matrix[row][col] = c;
}

/***************************************************************************************************
**	a function which sets the number of open slots in the matrix
***************************************************************************************************/
void Matrix::setOpenSlots(int s)
{
	openSlots = s;
}

/***************************************************************************************************
**	a function which randomly sets a Critter into an open location in the matrix
***************************************************************************************************/
void Matrix::addCritter(Critter *c)
{
	if (getOpenSlots() <= 0)															// if there are no open slots, nothing is added
	{
		cout << endl << "No open slots, critter cannot be added" << endl << endl;		// an error is thrown
	}
	else																				// but if there are open slots, set the critter in a random position
	{	
		int tempRowPos = (rand() % this->getMatSizeRow());							// select a random row
		int tempColPos = (rand() % this->getMatSizeCol());							// select a random column

		if (this->getMatPos(tempRowPos, tempColPos) != NULL)						// if the matrix position at tempRowPos/tempColPos contains a critter
		{
			//*******************************************************************************************
			//	Go through every row from tempRowPos-mSizeRow find an open slot
			//********************************************************************************************/
			for (int i = tempRowPos; i < this->getMatSizeRow(); i++)				// go through every next element tempRowPos-mSizeRow
			{
				//*******************************************************************************************
				//	Go through every column from tempColPos-mSizeCol to find an open slot
				//********************************************************************************************/
				for (int j = tempColPos; j < this->getMatSizeCol(); j++)			// go through every next element from tempColPos-mSizeCol
				{
					if (this->getMatPos(i, j) == NULL)								// if an empty slot is found
					{
						tempRowPos = i;												// set tempRowPos to the row
						tempColPos = j;												// set tempColPos to the column
						goto stop;													// goto the stop
					}
				}

				//*******************************************************************************************
				//	Go through every column from 0-tempColPos to find an open slot
				//********************************************************************************************/
				for (int j = 0; j < tempColPos; j++)								// go through every next column in the row from 0-mSizeCol
				{
					if (this->getMatPos(i, j) == NULL)								// if an empty slot is found
					{
						tempRowPos = i;												// set tempRowPos to the row
						tempColPos = j;												// set tempColPos to the column
						goto stop;													// goto the stop
					}
				}
			}

			//*******************************************************************************************
			//	Go through every row from 0-tempRowPos find an open slot
			//********************************************************************************************/
			for (int i = 0; i < tempRowPos; i++)									// go through every next element 0-tempRowPos
			{
				//*******************************************************************************************
				//	Go through every column from tempColPos-mSizeCol to find an open slot
				//********************************************************************************************/
				for (int j = tempColPos; j < this->getMatSizeCol(); j++)			// go through every next element from tempColPos-mSizeCol
				{
					if (this->getMatPos(i, j) == NULL)								// if an empty slot is found
					{
						tempRowPos = i;												// set tempRowPos to the row
						tempColPos = j;												// set tempColPos to the column
						goto stop;													// goto the stop
					}
				}

				//*******************************************************************************************
				//	Go through every column from 0-tempColPos to find an open slot
				//********************************************************************************************/
				for (int j = 0; j < tempColPos; j++)								// go through every next column in the row from 0-mSizeCol
				{
					if (this->getMatPos(i, j) == NULL)								// if an empty slot is found
					{
						tempRowPos = i;												// set tempRowPos to the row
						tempColPos = j;												// set tempColPos to the column
						goto stop;													// goto the stop
					}
				}
			}
		}

	stop:
		c->setRowPos(tempRowPos);													// set the row position of the critter
		c->setColPos(tempColPos);													// set the column position of the critter
		setMatPos(c, c->getRowPos(), c->getColPos());								// update the matrix with the critter's row/column position
		setOpenSlots(getOpenSlots() - 1);
	}
}

/***************************************************************************************************
**	a function which overloads addCritter to allow non-random placement
***************************************************************************************************/
void Matrix::addCritter(Critter *c, int row, int col)
{
	if (getOpenSlots() <= 0)															// if there are no open slots, nothing is added
	{
		cout << endl << "No open slots, critter cannot be added" << endl << endl;		// an error is thrown
	}
	else																				// but if there are open slots, set the critter in a random position
	{
		int tempRowPos = (row);														// set tempRowPos to the passed in row
		int tempColPos = (col);														// set tempColPos to the passed in col

		if (this->getMatPos(tempRowPos, tempColPos) != NULL)						// if the matrix position at tempRowPos/tempColPos contains a critter
		{
			//*******************************************************************************************
			//	Go through every row from tempRowPos-mSizeRow find an open slot
			//********************************************************************************************/
			for (int i = tempRowPos; i < this->getMatSizeRow(); i++)				// go through every next element tempRowPos-mSizeRow
			{
				//*******************************************************************************************
				//	Go through every column from tempColPos-mSizeCol to find an open slot
				//********************************************************************************************/
				for (int j = tempColPos; j < this->getMatSizeCol(); j++)			// go through every next element from tempColPos-mSizeCol
				{
					if (this->getMatPos(i, j) == NULL)								// if an empty slot is found
					{
						tempRowPos = i;												// set tempRowPos to the row
						tempColPos = j;												// set tempColPos to the column
						goto stop;													// goto the stop
					}
				}

				//*******************************************************************************************
				//	Go through every column from 0-tempColPos to find an open slot
				//********************************************************************************************/
				for (int j = 0; j < tempColPos; j++)								// go through every next column in the row from 0-mSizeCol
				{
					if (this->getMatPos(i, j) == NULL)								// if an empty slot is found
					{
						tempRowPos = i;												// set tempRowPos to the row
						tempColPos = j;												// set tempColPos to the column
						goto stop;													// goto the stop
					}
				}
			}

			//*******************************************************************************************
			//	Go through every row from 0-tempRowPos find an open slot
			//********************************************************************************************/
			for (int i = 0; i < tempRowPos; i++)									// go through every next element 0-tempRowPos
			{
				//*******************************************************************************************
				//	Go through every column from tempColPos-mSizeCol to find an open slot
				//********************************************************************************************/
				for (int j = tempColPos; j < this->getMatSizeCol(); j++)			// go through every next element from tempColPos-mSizeCol
				{
					if (this->getMatPos(i, j) == NULL)								// if an empty slot is found
					{
						tempRowPos = i;												// set tempRowPos to the row
						tempColPos = j;												// set tempColPos to the column
						goto stop;													// goto the stop
					}
				}

				//*******************************************************************************************
				//	Go through every column from 0-tempColPos to find an open slot
				//********************************************************************************************/
				for (int j = 0; j < tempColPos; j++)								// go through every next column in the row from 0-mSizeCol
				{
					if (this->getMatPos(i, j) == NULL)								// if an empty slot is found
					{
						tempRowPos = i;												// set tempRowPos to the row
						tempColPos = j;												// set tempColPos to the column
						goto stop;													// goto the stop
					}
				}
			}
		}

	stop:
		c->setRowPos(tempRowPos);													// set the row position of the critter
		c->setColPos(tempColPos);													// set the column position of the critter
		setMatPos(c, c->getRowPos(), c->getColPos());								// update the matrix with the critter's row/column position
		setOpenSlots(getOpenSlots() - 1);
	}
}

/***************************************************************************************************
**	a function which gets the size of the matrix
***************************************************************************************************/
int Matrix::getMatSizeRow()
{
	return mSizeRow;
}

/***************************************************************************************************
**	a function which gets the size of the matrix
***************************************************************************************************/
int Matrix::getMatSizeCol()
{
	return mSizeCol;
}

/***************************************************************************************************
**	a function which returns the number of open slots in the matrix
***************************************************************************************************/
int Matrix::getOpenSlots()
{
	return openSlots;
}

/***************************************************************************************************
**	returns a pointer to what is at the position stored in the matrix at x, y
***************************************************************************************************/
Critter* Matrix::getMatPos(int row, int col)
{
	if (matrix[row][col] == NULL)
	{
		return NULL;
	}
	else
	return matrix[row][col];		// return a pointer to the critter at row, col
}

/***************************************************************************************************
**	set the color of the space on screen
***************************************************************************************************/
void Matrix::setColor(char bug)
{
	if (bug == ANT)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);	// ANTS are BLUE
	}
	else if (bug == DBUG)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);	// DOODLEBUGS are YELLOW
	}
	// else no bug, no change
}

/***************************************************************************************************
**	a function which prints the 2d matrix and ant location
***************************************************************************************************/
void Matrix::printMatrix()
{
	for (int i = 0; i < getMatSizeRow(); i++)				// i indicates the row
	{
		for (int j = 0; j < getMatSizeCol(); j++)			// j indicates the column
		{
			cout << " ";
			if (getMatPos(i, j) == NULL)					// Print out that the cell is empty
			{
				cout << EMPTY;
			}
			else // critter
			{
				setColor(this->matrix[i][j]->getType());						// set the color to be printed for the critter
				cout << this->matrix[i][j]->getType();							// Print out the type of the critter in the cell
			}
		}
		cout << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// set color back to white
}

/***************************************************************************************************
**	returns the type of what is around Critter C
***************************************************************************************************/
char* Matrix::around(Critter &c)
{
	char* direction = new char[4];													// create a new pointer to an array

	// Check the position above and set to direction[0]
	if ((c.getRowPos() - 1) < 0)													// if the position above is the border
		direction[0] = 'B';															// set direction[0] to 'B' for Border
	else if (getMatPos(c.getRowPos() - 1, c.getColPos()) == NULL)					// else if the position above is NULL
		direction[0] = EMPTY;														// set direction[0] to 'E' for Empty
	else																			// else the position above contains a critter
		direction[0] = getMatPos(c.getRowPos() - 1, c.getColPos())->getType();		// set direction[0] to the critter type

	// Check the position to the right and set to direction[1]
	if ((c.getColPos() + 1) > getMatSizeCol() - 1)										// if the position to the right is the border
		direction[1] = 'B';															// set direction[1] to 'B' for Border
	else if (getMatPos(c.getRowPos(), c.getColPos() + 1) == NULL)					// else if the position to the right is NULL
		direction[1] = EMPTY;															// set direction[1] to 'E' for Empty
	else																			// else the position to the right contains a critter
		direction[1] = getMatPos(c.getRowPos(), c.getColPos() + 1)->getType();		// set direction[1] to the critter type

	// Check the position below and set to direction[2]
	if ((c.getRowPos() + 1) > getMatSizeRow() - 1)									// if the position below is the border
		direction[2] = 'B';															// set direction[2] to 'B' for Border
	else if (getMatPos(c.getRowPos() + 1, c.getColPos()) == NULL)					// else if the position below is NULL
		direction[2] = EMPTY;															// set direction[2] to 'E' for Empty
	else																			// else the position below contains a critter
		direction[2] = getMatPos(c.getRowPos() + 1, c.getColPos())->getType();		// set direction[2] to the critter type

	// Check the position to the left and set to direction[3]
	if ((c.getColPos() - 1) < 0)													// if the position to the left is the border
		direction[3] = 'B';															// set direction[3] to 'B' for Border
	else if (getMatPos(c.getRowPos(), c.getColPos() - 1) == NULL)					// else if the position to the left is NULL
		direction[3] = EMPTY;															// set direction[3] to 'E' for Empty
	else																			// else the position to the left contains a critter
		direction[3] = getMatPos(c.getRowPos(), c.getColPos() - 1)->getType();		// set direction[3] to the critter type

	return direction;
}

/***************************************************************************************************
**	moves the critters assigned to the matrix
***************************************************************************************************/
void Matrix::moveCritters()
{
	// iterate through matrix, move doodleBugs, update matrix
	for (int i = 0; i < this->getMatSizeRow(); i++)																		// for each row position
	{		
		for (int j = 0; j < this->getMatSizeCol(); j++)																	// and each column position
		{
			if (getMatPos(i, j) != NULL)																				// if the matrix position is not empty (ie has a critter)
			{
				if (getMatPos(i, j)->getType() == DBUG)																	// and if the critter is a doodleBug
				{
					if (getMatPos(i, j)->getMoved() == false)															// and if the critter at the matrix position has not already moved during this step
					{
						getMatPos(i, j)->move(this->around(*getMatPos(i, j)));											// move the critter at i, j based off of what is around its current position

						if (i != getMatPos(i, j)->getRowPos() || j != getMatPos(i, j)->getColPos())						// if the critter changes positions
						{
							delete getMatPos(getMatPos(i, j)->getRowPos(), getMatPos(i, j)->getColPos());				// delete whatever is currently pointed to at the new critter position
							setMatPos(getMatPos(i, j), getMatPos(i, j)->getRowPos(), getMatPos(i, j)->getColPos());		// set matrix pointer at the new position of the Critter to point to the Critter's address
							setMatPos(NULL, i, j);																		// then set the old position of the Critter to NULL to empty it
						}
					}
				}
			}
		}
	}

	// iterate through matrix, move Ants, update matrix
	for (int i = 0; i < this->getMatSizeRow(); i++)																		// for each row position
	{
		for (int j = 0; j < this->getMatSizeCol(); j++)																	// and each column position
		{
			if (getMatPos(i, j) != NULL)																				// if the matrix position is not empty (ie has a critter)
			{
				if (getMatPos(i, j)->getType() == ANT)																	// and if the critter is a doodleBug
				{
					if (getMatPos(i, j)->getMoved() == false)															// and if the critter at the matrix position has not already moved during this step
					{
						getMatPos(i, j)->move(this->around(*getMatPos(i, j)));											// move the critter at i, j based off of what is around its current position

						if (i != getMatPos(i, j)->getRowPos() || j != getMatPos(i, j)->getColPos())						// if the critter changes positions
						{
							delete getMatPos(getMatPos(i, j)->getRowPos(), getMatPos(i, j)->getColPos());				// delete whatever is currently pointed to at the new critter position
							setMatPos(getMatPos(i, j), getMatPos(i, j)->getRowPos(), getMatPos(i, j)->getColPos());		// set matrix pointer at the new position of the Critter to point to the Critter's address
							setMatPos(NULL, i, j);																		// then set the old position of the Critter to NULL to empty it
						}
					}
				}
			}
		}
	}

	// re-set moved for each critter to false
	for (int i = 0; i < this->getMatSizeRow(); i++)			// for each row position
	{
		for (int j = 0; j < this->getMatSizeCol(); j++)		// and each column position
		{
			if (getMatPos(i, j) != NULL)					// if the matrix position is not empty (ie has a critter)										
			{
				getMatPos(i, j)->setMoved(false);			// re-set the critter at position i, j to false
			}
		}
	}
}

/***************************************************************************************************
**	breeds the critters assigned to the matrix
***************************************************************************************************/
void Matrix::breedCritters()
{
	// iterate through matrix, breed critters, and update matrix
	for (int i = 0; i < this->getMatSizeRow(); i++)												// for each row position
	{
		for (int j = 0; j < this->getMatSizeCol(); j++)											// and each column position
		{
			if (getMatPos(i, j) != NULL)														// if the matrix position is not empty (ie has a critter)
			{
				Critter *tempCrit = new Critter;												// create a temporary pointer to a Critter							
				tempCrit = getMatPos(i, j)->breed(this->around(*getMatPos(i, j)));				// breed the critter at i, j and set tempCrit to it

				if (tempCrit != NULL)															// if breeding was successful
				{
					this->setMatPos(tempCrit, tempCrit->getRowPos(), tempCrit->getColPos());	// add the new critter to the matrix
					openSlots--;
				}
				else
				{
					delete tempCrit;															// if tempCrit is Null, delete tempCrit's allocated space
				}
			}
		}
	}
}

/***************************************************************************************************
**	starves the DoodleBugs assigned to the matrix
***************************************************************************************************/
void Matrix::starveDoodleBugs()
{
	// iterate through matrix, starve DoodleBugs, and update matrix
	for (int i = 0; i < this->getMatSizeRow(); i++)												// for each row position
	{
		for (int j = 0; j < this->getMatSizeCol(); j++)											// and each column position
		{
			if (getMatPos(i, j) != NULL)														// if the matrix position is not empty (ie has a critter)
			{
				if (getMatPos(i, j)->getType() == DBUG)											// and if the matrix position contains a DoodleBug
				{	
					Critter* tempD = new Critter;												// create a temporary null critter
					tempD = this->getMatPos(i, j);												// set the temporary doodleBug to the address pointed to in the matrix at i, j

					this->setMatPos(this->getMatPos(i,j)->starve(), i, j);						// starve the critter at i, j and set tempCrit to its return (NULL if starved)

					if (this->getMatPos(i, j) == NULL)
					{
						delete tempD;															// if the critter starved, delete the data pointed to by tempD
					}
				}
			}
		}
	}
}
