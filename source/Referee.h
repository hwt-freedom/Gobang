#pragma once
#include<iostream>
#include"Chess.h"
#include"ChessBoard.h"
#include"Rule.h"


class Referee {
private:

	int inputColour;//1表示当前为白棋输入，0表示当前为黑棋输入

	Rule rule;//规则类 规则对象
	ChessBoard chessboard;//棋盘类 棋盘对象

public:
	
	Referee();

	int setInputColour();
	int judgeWinner(int chessBoardFlagTmp[15][15],Chess currentChess);
	void showWinner(int winner);
	
};