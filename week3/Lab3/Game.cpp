#include "Game.h"
#include "InputValidation.h"
#include <iostream>

/****************************************************************************************************************************
**	a default constructor for game setting a loaded die player and a regular player against one another for 10 rounds
****************************************************************************************************************************/
Game::Game()
{
	setPlayerDie(1, false, 6, 0, 0);			// initializes player 1's die to an unloaded six sided die
	setPlayerDie(2, true, 100, 10, 50);			// initializes player 2's die to a loaded 100 side die where the loaded side is 10 and it's percent is 50
	setRounds(10);								// initialize the number of rounds to 10
	setScore(0);								// initialize the starting score to 0
}

/****************************************************************************************************************************
**	sets the number of rounds the game is to be played
****************************************************************************************************************************/
void Game::setRounds(int r)
{
	rounds = r;
}

/****************************************************************************************************************************
**	sets the values for a player's die
****************************************************************************************************************************/
void Game::setPlayerDie(int player, bool loaded, int sides, int load, int percent)
{
	if (player == 1)										// if we are setting the value for player 1
	{
		if (loaded == false)								// and the die is not loaded
		{
			//std::cout << "Creating an unloaded die for player 1" << std::endl;
			LoadedDie player1die(sides, 0, 0);				// then create a die called player1die with the number of sides given
			die1 = player1die;								// and set die1 to player1die
		}
		else												// otherwise the die is loaded
		{
			//std::cout << "Creating a loaded die for player 1" << std::endl;
			LoadedDie player1die(sides, load, percent);		// so create a loadedDie called player1die with the number of sides, the load, and percent loadedness
			die1 = player1die;								// and set die2 to player1die
		}
	}
	else													// else we are setting player 2								
	{
		if (loaded == false)								// and the die is not loaded
		{
			//std::cout << "Creating an unloaded die for player 2" << std::endl;
			LoadedDie player2die(sides, 0, 0);				// then create a die called player2die with the number of sides given
			die2 = player2die;								// and set die1 to player2die
		}
		else												// otherwise the die is loaded
		{
			//std::cout << "Creating a loaded die for player 2" << std::endl;
			LoadedDie player2die(sides, load, percent);		// so create a loadedDie called player2die with the number of sides, the load, and percent loadedness
			die2 = player2die;								// and set die2 to player2die
		}
	}
}

/****************************************************************************************************************************
**	sets the score of the game
****************************************************************************************************************************/
void Game::setScore(int s)
{
	score = s;
}

/****************************************************************************************************************************
**	compares the rolls of player 1 and player 2's die and updates the score
****************************************************************************************************************************/
void Game::compareRolls(int d1Roll, int d2Roll)
{

	std::cout << "Die 1 roll is " << d1Roll << std::endl;
	std::cout << "Die 2 roll is " << d2Roll << std::endl;

	if (d1Roll > d2Roll)					// if the value of d1Roll is greater than d2Roll
	{
		std::cout << "Die 1 wins" << std::endl;
		setScore(getScore()+1);				// increase the score by 1. Positive scores mean that player 1 is winning
	}
	else if (d1Roll < d2Roll)				// otherwise if the value of d1Roll is less than d2Roll
	{
		std::cout << "Die 2 wins" << std::endl;
		setScore(getScore()-1);				// decrease the score by 1. Negative scores mean tha player 2 is winning
	}
											// else its a tie, do nothing

	std::cout << "Score is: " << getScore() << std::endl << std::endl;
}

/****************************************************************************************************************************
**	returns the number of rounds
****************************************************************************************************************************/
int Game::getRounds()
{
	return rounds;
}

/****************************************************************************************************************************
**	returns the value of score
****************************************************************************************************************************/
int Game::getScore()
{
	return score;
}

/****************************************************************************************************************************
**	iterates through one round of the game
****************************************************************************************************************************/
void Game::runRound()
{
	/*std::cout << "die 1 is :" << std::endl;
	std::cout << die1.getSides() << " sided, " << die1.getLoadedSide() << " is the loaded side, and " << die1.getLoadPercent() << " is its load percent" << std::endl << std::endl;

	std::cout << "die 2 is :" << std::endl;
	std::cout << die2.getSides() << " sided, " << die2.getLoadedSide() << " is the loaded side, and " << die2.getLoadPercent() << " is its load percent" << std::endl << std::endl;
	*/

	compareRolls(die1.roll(), die2.roll());
}

/****************************************************************************************************************************
**	a menu allowing the user to define the player's die and number of rounds
****************************************************************************************************************************/
void Game::menu()
{
	std::cout << "Hello and welcome to the Game!" << std::endl << std::endl;

	std::cout << "Let's set up the players! " << std::endl << std::endl;			// set up each player's die
	for (int player = 1; player <= 2; player++)													
	{
		bool loaded;
		int sides;
		int load = 0;
		int percent = 0;

		std::cout << "We will now set player " << player << "'s die" << std::endl; 
		std::cout << "Enter a number of sides between 4 and 20: ";
		std::cin >> sides;
		
		sides = boundsValidation(sides, 4, 20);

		std::cout << "Is the die loaded (1 for yes, 0 for no) ";
		std::cin >> loaded;

		loaded = boundsValidation(loaded, 0, 1);

		if (loaded == 1)
		{
			std::cout << "Okay, what side of the die is loaded? ";
			std::cin >> load;

			load = boundsValidation(load, 4, sides);

			std::cout << "What percent do you want the die to land on " << load << "? ";
			std::cin >> percent;

			percent = boundsValidation(percent, 0, 100);
		}
		else
			std::cout << "Okay, the die is not loaded" << std::endl;

		this->setPlayerDie(player, loaded, sides, load, percent);
		std::cout << std::endl;
	}

	int rds;																		// set the number of rounds
	std::cout << "How many rounds would you like the game to run for? ";
	std::cin >> rds;
	std::cout << std::endl;
	this->setRounds(rds);
}