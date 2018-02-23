#ifndef GAME_H
#define GAME_H

#include "Die.h"
#include "LoadedDie.h"

class Game
{
private:
	int rounds;																					// indicatese the number of rounds of the game
	int score;																					// indicates the current score

	LoadedDie die1;																				// player 1's die
	LoadedDie die2;																				// player 2's die

public:
	Game();																						// a default constructor for game setting a loaded die player and a regular player against one another for 10 rounds

	void setRounds(int r);																		// sets the number of rounds the game is to be played
	void setPlayerDie(int player, bool loaded, int sides, int load, int percent);				// sets the values for a player's die
	void setScore(int s);																		// sets the game's score
	void compareRolls(int d1Roll, int d2Roll);													// compares the rolls of player 1 and player 2's die and updates the score
	
	int getRounds();																			// gets the number of rounds
	int getScore();																				// returns the value of score
	void runRound();																			// iterates through one round of the game
	void menu();																				// a menu allowing the user to define the player's die and number of rounds
};

#endif