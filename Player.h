#pragma once
#include <string>

class Player {
	std::string name;
	int win;
	int lose;
public:
	Player(std::string name, int win, int lose) {
		this->name = name;
		this->win = win;
		this->lose = lose;
	}
	std::string getName() {
		return name;
	}
	int getWin() {
		return win;
	}
	int getLose() {
		return lose;
	}
	void addWin() {
		win = win + 1;
	}
	void addLose() {
		lose = lose + 1;
	}
};