/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			02 October 2016
//
//	Description:	This is a file contains the prototypes to two functions. One function allows the user to input values into a
//					matrix. The second funciton prints the values stored within the matrix.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include<ctime>
#include "Matrix.h"
#include "Ant.h"
#include "Menu.h"

int main()
{
	int sX = choice("rows", "matrix", 10, 20, 30, 40);
	int sY = choice("columns", "matrix", 10, 20, 30, 40);

	Matrix sandbox(sY, sX);
					
				  // (               X START LOCATION                         ),(                     Y START LOCATION                         ),(CARDINAL DIRECTION)
	              //( choice           , entity, c1, c2      , c3         ,x4),        (choice           , entity, c1, c2      , c3         ,x4),        ( choice             , entity, c1, c2, c3, c4)
	Ant jerry((choice("x start location", "ant", 1, (sX / 2), sX, "random")-1), (choice("y start location", "ant", 1, (sY / 2), sY, "random")-1), choice("cardinal direction", "ant", "up", "right", "down", "left"));

	int steps = choice("steps", "ant", 5, 100, 300, 1000);
																														/* TEST
																														sandbox.printMatrix(jerry.getYpos(), jerry.getXpos());*/

	// Runs the number of steps indicated
	for (int i = 1; i <= steps; i++)
	{
		std::cout << "STEP " << i << std::endl << std::endl;															// indicates the step

		sandbox.printMatrix(jerry.getYpos(), jerry.getXpos());															// prints the matrix with jerry the ant's location included
																														
																														// TEST
																														/*std::cout << "Jerry is on a " << sandbox.getMatPos(jerry.getYpos(), jerry.getXpos()) << " color square" << std::endl;
																														std::cout << "Jerry is facing in the " << jerry.getCdir() << " direction" << std::endl << std::endl;

																														std::cout << "Flipping the tile to a new color" << std::endl;*/
		sandbox.setMatPos(!sandbox.getMatPos(jerry.getYpos(), jerry.getXpos()), jerry.getYpos(), jerry.getXpos());		// updates sandbox by flipping the black tile white or white tile black

																														// TEST
																														/*std::cout << "Jerry is on a " << sandbox.getMatPos(jerry.getYpos(), jerry.getXpos()) << " color square" << std::endl;
																														std::cout << "Jerry is facing in the " << jerry.getCdir() << " direction" << std::endl << std::endl;

																														std::cout << "Jerry is moving from X:" << jerry.getXpos() << ", Y:" << jerry.getYpos() << " to ";*/
		jerry.move(sY, sX);																								// moves jerry's location

																														// TEST
																														/*std::cout << "X:" << jerry.getXpos() << ", Y:" << jerry.getYpos();

																														std::cout << "Jerry is facing in the " << jerry.getCdir() << " direction" << std::endl << std::endl;
																														std::cout << "Jerry is turning now" << std::endl;*/
		jerry.turn(sandbox.getMatPos(jerry.getYpos(), jerry.getXpos()));												// gives jerry a new cardinal direction based upon the color of the new tile

																														// TEST
																														/*std::cout << "Jerry is on a " << sandbox.getMatPos(jerry.getYpos(), jerry.getXpos()) << " color square" << std::endl;
																														std::cout << "Jerry is facing in the " << jerry.getCdir() << " direction" << std::endl << std::endl;*/

		std::cout << std::endl << std::endl;
	}
	return 0;
}