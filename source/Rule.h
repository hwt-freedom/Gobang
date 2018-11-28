#pragma once
#include"Chess.h"

class Rule {
private:

	//禁手判断的基本棋型
	static const int ChangLian = 1;   //长连为1
	static const int Huo4 = 2;        //活4为2
	static const int Chong4 = 3;      //冲4不间断为3
	static const int TiaoChong4 = 4;  //冲4间断为4，取名为跳冲4
	static const int Huo3 = 5;        //活3为5
	static const int Tiao3 = 6;       //跳3为6
	                                  //0代表其他棋型

public:
	
	int isForbidden(int chessBoardFlagTmp[15][15], Chess currentChess);//禁手判断
	int fobiddenTypeJudge(int chessBoardFlagTmp[15][15], Chess currentChess);//禁手类型判断
	int ChessTypeGet(int chessBoardFlagTmp[15][15], Chess currentChess,int direction);//棋子类型获得
	void ChessArrange(int chessBoardFlagTmp[15][15], Chess currentChess, int direction, int ChessFlagTmp[9]);//单方向棋子整理
	int ChessTypeJudge(int ChessTmp[9]);//棋型判断
	int isFive(int chessBoardFlagTmp[15][15],Chess currentChess);//连成五子判断

};