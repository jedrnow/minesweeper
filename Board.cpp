#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include "Board.h"
#include "Block.h"

Board::Board(const Board& board) {
	this->x = board.x;
	this->y = board.y;
	this->list = board.list;
}

int Board::getX() {
	return this->x;
}

int Board::getY() {
	return this->y;
}

std::vector<Block> Board::getList() {
	return this->list;
}

void Board::setX(int x) {
	this->x = x;
}

void Board::setY(int y) {
	this->y = y;
}

void Board::setList(std::vector<Block> list) {
	this->list = list;
}

Board::Board() {
	this->x = 0;
	this->y = 0;
}

void Board::click(int x) {
	for (int i = 0; i < this->list.size(); i++) {
		if (i == x) {
			list[i].setClicked(true);
		}
	}
}

void Board::fillNumbers() {
	for (int i = 0; i < this->list.size(); i++) {
		int counter = 0;
		if (i != 0) {
			if (i - this->x -1 >= 0) {
				if (list[i - this->x - 1].gethasBomb() == true) {
					counter++;
				}
			}
			if (i - this->x >= 0) {
				if (list[i - this->x].gethasBomb() == true) {
					counter++;
				}
			}
			if (i + this->x < this->list.size()) {
				if (list[i + this->x].gethasBomb() == true) {
					counter++;
				}
			}
			if (i + this->x + 1 < this->list.size()) {
				if (list[i + this->x + 1].gethasBomb() == true) {
					counter++;
				}
			}
			if (list[i - 1].gethasBomb() == true) {
				counter++;
			}
			if (i + 1 != this->list.size()) {
				if (list[i + 1].gethasBomb() == true) {
					counter++;
				}
			}
		}
		list[i].setNumber(counter);
	}
}

void Board::Update() {
	system("cls");
	std::cout << "  ";
	for (int i = 0; i < x; i++) {
		if (i + 1 < 10) {
			std::cout << " " << i + 1 << " ";
		}
		else {
			std::cout << " " << i + 1;
		}
	}
	int j = 0;
	for (int i = 0; i < this->list.size(); i++) {
		if (i == 0 || i % this->x == 0) {
			if (j + 1 < 10) {
				std::cout << std::endl << j + 1 << " ";
			}
			else {
				std::cout << std::endl << j + 1;
			}
			j++;
		}
		list[i].Show();
	}
	std::cout << std::endl;
}

Board::Board(int x, int y) {
	this->x = x;
	this->y = y;

	srand(time(NULL));
	int bomb;
	std::cout << "  ";
	for (int i = 0; i < x; i++) {
		if (i + 1 < 10) {
			std::cout << " "<< i + 1 << " ";
		}
		else {
			std::cout << " " << i + 1;
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < y; i++) {
		if (i + 1 < 10) {
			std::cout << i + 1 << " ";
		}
		else {
			std::cout << i + 1;
		}
		for (int j = 0; j < x; j++) {
			bomb = rand() % 100;
			if (bomb < 30) {
				Block t(i, j, true);
				t.Show();
				this->list.push_back(t);
			}
			else {
				Block t(i, j, false);
				t.Show();
				this->list.push_back(t);
			}
		}
		std::cout << "\n";
	}
	fillNumbers();
	Update();
}

Block Board::findBlock(int x, int y) {
	for (int i = 0; i < this->list.size(); i++) {
		if (list[i].getX() == x && list[i].getY() == y) {
			return list[i];
		}
	}
}
