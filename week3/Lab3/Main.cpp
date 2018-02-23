#include <iostream>
#include<ctime>
#include "Game.h"
#include "Die.h"
#include "LoadedDie.h"

int main()
{
	srand(time(NULL));

	/*
	Die die;
	LoadedDie loadedDie;
	LoadedDie somewhatLoaded(100, 4, 50);


	std::cout << std::endl << std::endl;
	std::cout << "Regular Die Rolls" << std::endl;
	std::cout << std::endl << die.roll();
	std::cout << std::endl << die.roll();
	std::cout << std::endl << die.roll();
	std::cout << std::endl << die.roll();
	std::cout << std::endl << die.roll();
	std::cout << std::endl << die.roll();
	std::cout << std::endl << die.roll();
	std::cout << std::endl << die.roll();
	std::cout << std::endl << die.roll();
	std::cout << std::endl << die.roll();
	std::cout << std::endl << die.roll();
	std::cout << std::endl << die.roll();
	std::cout << std::endl << std::endl;

	std::cout << "Loaded Die Rolls" << std::endl;
	std::cout << std::endl << loadedDie.roll();
	std::cout << std::endl << loadedDie.roll();
	std::cout << std::endl << loadedDie.roll();
	std::cout << std::endl << loadedDie.roll();
	std::cout << std::endl << loadedDie.roll();
	std::cout << std::endl << loadedDie.roll();
	std::cout << std::endl << loadedDie.roll();
	std::cout << std::endl << loadedDie.roll();
	std::cout << std::endl << loadedDie.roll();
	std::cout << std::endl << loadedDie.roll();
	std::cout << std::endl << loadedDie.roll();
	std::cout << std::endl << std::endl;

	std::cout << "Loaded 100-Sided Die Rolls" << std::endl;
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << somewhatLoaded.roll();
	std::cout << std::endl << std::endl;
	*/
	
	Game game1;

	game1.menu();
	
	while (game1.getRounds() > 0)
	{
		//std::cout << "Running round " << game1.getRounds() << std::endl;
		game1.runRound();
		game1.setRounds(game1.getRounds() - 1);
	}

	if (game1.getScore() > 0)
		std::cout << "Player 1 Wins!";
	else if (game1.getScore() < 0)
		std::cout << "Player 2 Wins!";
	else
		std::cout << "Its a tie!";

	std::cout << std::endl << std::endl;

	return 0;
}