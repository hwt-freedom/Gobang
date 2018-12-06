#pragma once
#include "ChessBoard.h"
#include "Chess.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Referee.h"
#include "Rule.h"
#include<iostream>

class Gobang {
private:
	int mode;//游戏模式：0人人模式，1人机模式
	int order;//人机模式下棋顺序

	int currentColour;//当前棋子颜色 黑棋表示0，白棋表示1	
	int winner;//获胜者：1黑棋获胜，2白棋获胜，3平局

	ChessBoard chessboard;//棋盘类 棋盘对象
	Chess currentChess;//棋子类 当前棋子对象
	Referee referee;//裁判类 裁判对象
	HumanPlayer humanPlayer;//人类玩家类 人类玩家对象
	ComputerPlayer computerPlayer;//计算机玩家类 计算机玩家对象

	void ChooseMode();//选择模式，0人人模式，1人机模式
	void ChooseOrder();//人机模式选择下棋顺序
	void playGobangMode1(HumanPlayer &humanPlayer, ComputerPlayer &computerPlayer, Chess &currentChess, ChessBoard &chessboard, Referee &referee, int order);//人机模式
	void playGobangMode2(HumanPlayer &humanPlayer, Chess &currentChess, ChessBoard &chessboard, Referee &referee);//人人模式

public:

	Gobang();//构造函数
	void prepareGobang();//游戏准备
	void startGobang();//游戏开始
};
