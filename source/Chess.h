#pragma once

#include<iostream>

class Chess {
private:
	int colour;//������ɫ��Ϣ��0��1��
	int row, col;//����������Ϣ

public:
	Chess();//���캯��

	void setPosition(int row, int col);
	void getPosition(int row, int col);
	void setColour(int colour);
	int getColour();
	int getRow();
	int getCol();

};