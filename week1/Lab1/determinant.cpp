/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			02 October 2016
//
//	Description:	This is a file which contains a function that finds the determinant of a 2x2 or 3x3 matrix
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "determinant.h"

/***************************************************************************************************
**	a function which takes a 2d matrix of integers, m[][], and an integer, s, as parameters
**	then computes the determinant of the matrix based on whether it is a 2x2 or 3x3 matrix
***************************************************************************************************/
int determinant(int* m[], int s)
{
	if (s == 2)
	{
		return m[0][0]*m[1][1] - m[1][0]*m[0][1];
	}
	else if (s == 3)
	{

		return	 ( m[0][0] * m[1][1] * m[2][2] ) + ( m[0][1] * m[1][2] * m[2][0] ) + ( m[0][2] * m[1][0] * m[2][1] ) 
			   - ( m[2][0] * m[1][1] * m[0][2] ) - ( m[2][1] * m[1][2] * m[0][0] ) - ( m[2][2] * m[1][0] * m[0][1] );
	}
	else
	{
		std::cout << "The matrix size must be 2x2 or 3x3!" << std::endl;
		return 0;
	}
}