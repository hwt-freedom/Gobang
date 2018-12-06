#pragma once
#include"Rule.h"
#include"Referee.h"
#include"Chess.h"
#include<vector>
#include<iostream>

struct Position {
	int row;
	int col;
};

class AI {

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

	//打分规则
	    //若为棋子颜色为黑色，首先判断是否为禁手
	     //连5       10000分     Lian5Num >= 1

	     //活4       5000分      Huo4Num >= 1
	     //双冲4_1   5000分      DoubleChong4Num >= 1
	     //双冲4_2   5000分      Chong4Num >= 2
	     //冲4活3    5000分      Chong4Num + Huo3Num + Tiao3Num>= 2

	     //双活3     4500分       Huo3Num >= 2
		 //双活3     4000分       Huo3Num + Tiao3Num >= 2
	     //双活3     3500分       Tiao3Num >= 2         //优先考虑普通活3

	     //活3眠3    2500分       Huo3Num + Mian3 >= 2
	     //活3眠3    2000分       Tiao3Num + Huo3Num + Mian3 >= 2
		 //活3眠3    1500分       Tiao3Num + Mian3 >= 2 //优先考虑普通活3

	     //冲4       1000分       Chong4Num >= 1

	     //活3       800分        Huo3Num >= 1

	     //跳3       700分        Tiao3Num >= 1

	     //双活2     550分        Huo2Num >= 2
	     //双活2     500分        Huo2Num + Tiao2Num >= 2
	     //双活2     450分        Tiao2Num >= 2        //优先考虑普通活2

         //活2眠2    250分        Huo2Num + Mian2Num >= 2
	     //活2眠2    200分        Huo2Num + Tiao2Num + Mian2Num >= 2
	     //活2眠2    150分        Tiao2Num + Mian2Num >= 2
	     
		 //眠3       100分        Mian3 >= 1
	     //活2       80分         Huo2Num >= 1
	     //跳2       70分         Tiao2Num >= 1
	     //眠2       50分         Mian2Num >= 1
	     //其他      10分

	Rule rule;
	Referee referee;//用于判断禁手
	Chess currentChess;

	int cumputeScore(ChessBoard &chessboard, Chess &currentChess);
	void computePosition(int currentScore[15][15], int opponentScore[15][15]);

public:

	Chess computeChess(int colour, ChessBoard &chessboard);

};