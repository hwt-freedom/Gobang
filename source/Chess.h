#pragma once

#include<iostream>

class Chess {
private:
	int colour;//棋子颜色信息，0黑1白
	int row, col;//棋子坐标信息

public:
	Chess();//构造函数

	void setPosition(int row, int col);
	void getPosition(int row, int col);
	void setColour(int colour);
	int getColour();
	int getRow();
	int getCol();

};