#pragma once
#include "Board.h"
#include <string>

class Game :public Board{
	int x;
	int y;
	int m;
	std::string i;
	std::string w;
	Board board;
public:
	Game(int x, int y, int m, std::string i, std::string w);

	int getX();
	int getY();
	int getM();
	std::string getI();
	std::string getW();
	void askForMove();
	void endGame();
	void Move(int x, int y);
	void StartGame();

};

Game Start(int argc, char* argv[]);

void TheGame(Game game);