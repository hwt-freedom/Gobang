#pragma once

#include"Chess.h"
#include"ChessBoard.h"
#include"Referee.h"

class HumanPlayer{

private:

	Chess currentChess;//棋子类 棋子对象
	Referee referee;         //规则类 规则对象
	
	void Input();//输入函数
	Chess InputValidChess(int colour, ChessBoard &chessboard);

public:

	Chess InputChess(int colour, ChessBoard &chessboard);

};