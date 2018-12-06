#pragma once

#include"Chess.h"
#include"ChessBoard.h"
#include"AI.h"

class ComputerPlayer {

private:

	AI ai;//人工智能类  人工智能对象
	Chess currentChess;//棋子类 棋子对象

public:

	Chess InputChess(int colour, ChessBoard &chessboard);

};