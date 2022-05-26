#include <iostream>
#include "Game.h"

int main(int argc, char* argv[])
{
	Game newGame = Start(argc,argv);
	newGame.StartGame();
}
