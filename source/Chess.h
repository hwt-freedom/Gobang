#pragma once
#include<iostream>

class Chess {
private:
	int colour;//������ɫ��Ϣ��0��1��
	int row, col;//����������Ϣ

public:
	void setChess(int colour, int row, int column);
	void inputChess(int colour);
	int getColour();
	int getRow();
	int getCol();

};