#pragma once

class Block{
private:
	int x;
	int y;
	bool hasBomb;
	int number = 0;
	bool clicked = false;

public:
	int getX();

	int getY();

	bool gethasBomb();

	int getNumber();

	bool getClicked();

	void sethasBomb(bool x);

	void setNumber(int number);

	void setClicked(bool x);

	Block();

	Block(int x, int y, bool bomb);

	Block(const Block& block);

	void Show();
};