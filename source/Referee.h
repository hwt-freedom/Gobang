#pragma once
#include<iostream>
#include"Chess.h"
#include"ChessBoard.h"
#include"Rule.h"


class Referee {
private:

	Rule rule;//������ �������

public:

	int setCurrentColour(int lastColour);
	int judgeForbidden(Chess &currentChess, ChessBoard &chessboard);
	void showForbidden(int forbiddenType);
	int judgeWinner(Chess &currentChess, ChessBoard &chessboard);
	void showWinner(int winner);

};