#pragma once

#include"Chess.h"
#include"ChessBoard.h"
#include"Referee.h"

class HumanPlayer{

private:

	Chess currentChess;//������ ���Ӷ���
	Referee referee;         //������ �������
	
	void Input();//���뺯��
	Chess InputValidChess(int colour, ChessBoard &chessboard);

public:

	Chess InputChess(int colour, ChessBoard &chessboard);

};