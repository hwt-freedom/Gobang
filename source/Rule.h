#pragma once

#include"Chess.h"
#include"ChessBoard.h"

class Rule {
private:

	//基本棋型
	static const int ChangLian = 1;		//长连为1
	static const int Lian5 = 2;			//连5为2
	static const int Huo4 = 3;			//活4为3
	static const int DoubleChong4 = 4;  //冲4 同一方向上的双冲4为 4
	static const int HighChong4 = 5;	//冲4 不间断为5
	static const int LowChong4 = 6;		//冲4 间断为6
	static const int Huo3 = 7;			//活3为7
	static const int Tiao3 = 8;			//跳3为8
	static const int Mian3 = 9;			//眠3为9
	static const int Huo2 = 10;			//活2为10
	static const int Tiao2 = 11;		//跳2为11
	static const int Mian2 = 12;		//眠2为12
										//0代表无威胁的棋型

public:
	
	int forbiddenTypeJudge(ChessBoard &chessboard, Chess &currentChess);//禁手类型判断
	int ChessTypeGet(ChessBoard &chessboard, Chess &currentChess,int direction);//棋子类型获得
	void ChessArrange(ChessBoard &chessboard, Chess &currentChess, int direction, int ChessFlagTmp[9]);//单方向棋子整理
	int ChessTypeJudge(int ChessTmp[9]);//棋型判断
	int isFive(ChessBoard &chessboard,Chess &currentChess);//连成五子判断

};