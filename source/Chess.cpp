#include "Chess.h"

Chess::Chess() {//��ʼ��Ϊ1��ʹ���״ε���setCurrentColour�������صĲ���Ϊ0������ɫ
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
