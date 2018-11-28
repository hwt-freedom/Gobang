#pragma once
#include<iostream>
#include"Chess.h"
#include"ChessBoard.h"
#include"Rule.h"


class Referee {
private:

	int inputColour;//1��ʾ��ǰΪ�������룬0��ʾ��ǰΪ��������

	Rule rule;//������ �������
	ChessBoard chessboard;//������ ���̶���

public:
	
	Referee();

	int setInputColour();
	int judgeWinner(int chessBoardFlagTmp[15][15],Chess currentChess);
	void showWinner(int winner);
	
};