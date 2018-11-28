#pragma once
#include<iostream>

class Chess {
private:
	int colour;//棋子颜色信息，0黑1白
	int row, col;//棋子坐标信息

public:
	void setChess(int colour, int row, int column);
	void inputChess(int colour);
	int getColour();
	int getRow();
	int getCol();

};