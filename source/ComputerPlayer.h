#pragma once

#include"Chess.h"
#include"ChessBoard.h"
#include"AI.h"

class ComputerPlayer {

private:

	AI ai;//�˹�������  �˹����ܶ���
	Chess currentChess;//������ ���Ӷ���

public:

	Chess InputChess(int colour, ChessBoard &chessboard);

};