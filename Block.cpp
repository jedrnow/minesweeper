#include <iostream>
#include "Block.h"




int Block::getX() {
	return this->x;
}

int Block::getY() {
	return this->y;
}

bool Block::gethasBomb() {
	return this->hasBomb;
}

int Block::getNumber() {
	return this->number;
}

bool Block::getClicked() {
	return this->clicked;
}

void Block::sethasBomb(bool x) {
	this->hasBomb = x;
}

void Block::setNumber(int number) {
	this->number = number;
}

void Block::setClicked(bool x) {
	this->clicked = x;
}

Block::Block() {
	this->x = 0;
	this->y = 0;
	this->hasBomb = false;
}


Block::Block(int x, int y, bool bomb) {
	this->x = x;
	this->y = y;
	this->hasBomb = bomb;
}

Block::Block(const Block& block) {
	this->x = block.x;
	this->y = block.y;
	this->hasBomb = block.hasBomb;
}

void Block::Show() {
/*	if (this->hasBomb == true) {
		std::cout << "[#]";
	}
	else */if (this->clicked == false) {
		std::cout << "[ ]";
	}
	else {
		std::cout << "[" << this->number << "]";
	}
}