#include "Chess.h"

Chess::Chess() {//初始化为1，使得首次调用setCurrentColour函数返回的参数为0，即黑色
	colour = 1;
}

void Chess::setPosition(int row, int col) {
	this->row = row;
	this->col = col;
}

void Chess::getPosition(int row, int col) {
	row = this->row;
	col = this->col;
}

void Chess::setColour(int colour) {
	this->colour = colour;
}

int Chess::getColour() {
	return this->colour;
}

int Chess::getRow() {
	return this->row;
}

int Chess::getCol() {
	return this->col;
}
