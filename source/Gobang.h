#pragma once
#include "ChessBoard.h"
#include "Chess.h"
#include "Rule.h"
#include "Referee.h"
#include<iostream>

class Gobang {
private:
	int mode;//游戏模式：0人人模式，1人机模式
	int order;//人机模式下棋顺序
	
	int winner;//获胜者：1黑棋获胜，2白棋获胜，3平局

	ChessBoard chessboard;//棋盘类 棋盘对象
	Chess currentChess;//棋子类 当前棋子对象
	Referee referee;//裁判类 裁判对象

	//Rule 规则类，包含禁手规则，五连子规则
	//Referee 裁判类，包含判断当前棋子位置是否合法
	//Timer 计时器类
	//AI 人工智能类，计算机玩家包含AI类

	void ChooseMode();//选择模式，0人人模式，1人机模式
	void ChooseOrder();//人机模式选择下棋顺序
	int GobangInput(Chess &currentChess, ChessBoard &chessboard, int colour);//输入函数 返回1代表输入正确
	void playGobangMode1(Chess &currentChess, ChessBoard &chessboard, Referee referee);//人机模式
	void playGobangMode2(Chess &currentChess, ChessBoard &chessboard, Referee referee);//人人模式

public:

	Gobang();//构造函数
	void prepareGobang();//游戏准备
	void startGobang();//游戏开始
};
