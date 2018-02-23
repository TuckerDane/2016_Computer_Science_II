/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			October 2016
//
//	Description:	Input Validation functions that handle int/doubles to ensure that they are within certain numberic bounds
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

#include <iostream>
#include <string>
#include <sstream>

int inputValidation(int uinput);
int boundsValidation(int userInput, int min, int max);

double inputValidation(double uinput);
double boundsValidation(double userInput, double min, double max);

#endif