#pragma once
#include "Block.h"
#include <vector>

class Board {

private:
	int x;
	int y;
	std::vector<Block> list;

public:
	Board(const Board& board);

	int getX();
	
	int getY();

	std::vector<Block> getList();

	void setX(int x);

	void setY(int y);

	void setList(std::vector<Block> list);

	void Update();

	void fillNumbers();

	void click(int x);

	Board();

	Board(int x, int y);

	Block findBlock(int x, int y);
};
