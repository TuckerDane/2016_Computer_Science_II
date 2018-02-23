/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			02 October 2016
//
//	Description:	This is a file contains the prototypes to two functions. One function allows the user to input values into a
//					matrix. The second funciton prints the values stored within the matrix.
//1
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef READMATRIX_HPP
#define READMATRIX_HPP

#include <iostream>

void readMatrix(int* matrix[], int mSize);		// prompts the user to fill the 2d array pointed to by matrix of size mSize
void printMatrix(int* matrix[], int mSize);		// prints the matrix

#endif                                 