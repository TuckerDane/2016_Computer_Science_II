/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			02 October 2016
//
//	Description:	This is a file containing two functions. One function allows the user to input values into a matrix
//					The second funciton prints the values stored within the matrix.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>

int choice(std::string s, std::string entity, int c1, int c2, int c3, int c4);
int choice(std::string s, std::string entity, std::string c1, std::string c2, std::string c3, std::string c4);
int choice(std::string s, std::string entity, int c1, int c2, int c3, std::string c4);

int choiceValidation(int choice1, int choice2, int choice3, int choice4);
int choiceValidation(std::string choice1, std::string choice2, std::string choice3, std::string choice4);
int choiceValidation(int choice1, int choice2, int choice3, std::string choice4);

#endif