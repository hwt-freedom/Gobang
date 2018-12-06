#pragma once

#include"Chess.h"
#include<iostream>
#include<iomanip>

class ChessBoard {
private:

	static const int ROW = 15;//行
	static const int COL = 15;//列

	int chessBoardFlag[ROW][COL];//棋盘标志信息

	std::string gridsymbol1 = "┌┬┬┬┬┬┬┬┬┬┬┬┬┬┐";
	std::string gridsymbol2 = "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤";
	std::string gridsymbol3 = "└┴┴┴┴┴┴┴┴┴┴┴┴┴┘";//棋盘基本符号

	std::string grid[ROW];//棋盘显示信息

	std::string blacksymbol1 = "○";
	std::string blacksymbol2 = "△";
	std::string whitesymbol1 = "●";
	std::string whitesymbol2 = "▲";//棋子基本符号

	int flag;//棋子标志信息  0无棋子，1黑棋，2白棋，3黑棋下一步，4白棋下一步

public:
	ChessBoard() {

		for (int i = 0; i < ROW; i++) {
			switch (i)
			{
			case 0:
				grid[i] = gridsymbol1;
				break;
			case ROW - 1:
				grid[i] = gridsymbol3;
				break;
			default:
				grid[i] = gridsymbol2;
				break;
			}//棋盘显示信息初始化
		}

		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
				chessBoardFlag[i][j] = 0;//棋盘标志信息初始化

	}

	void print(int mode);//根据模式打印棋盘当前
	int isValid(Chess &currentChess);//判断输入的棋子是否合法
	void addChessFlag(Chess &currentChess);//为棋盘添加棋子
	void updateChessFlag();//更新棋盘信息
	int getFlag(int row, int col);
	int isFull(); //判断棋盘是否为满
	int isEmpty();//判断棋盘是否为空
	void setChessFlag(int state[15][15]);//用于测试输入特定棋谱
};