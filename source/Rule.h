#pragma once

#include"Chess.h"
#include"ChessBoard.h"

class Rule {
private:

	//��������
	static const int ChangLian = 1;		//����Ϊ1
	static const int Lian5 = 2;			//��5Ϊ2
	static const int Huo4 = 3;			//��4Ϊ3
	static const int DoubleChong4 = 4;  //��4 ͬһ�����ϵ�˫��4Ϊ 4
	static const int HighChong4 = 5;	//��4 �����Ϊ5
	static const int LowChong4 = 6;		//��4 ���Ϊ6
	static const int Huo3 = 7;			//��3Ϊ7
	static const int Tiao3 = 8;			//��3Ϊ8
	static const int Mian3 = 9;			//��3Ϊ9
	static const int Huo2 = 10;			//��2Ϊ10
	static const int Tiao2 = 11;		//��2Ϊ11
	static const int Mian2 = 12;		//��2Ϊ12
										//0��������в������

public:
	
	int forbiddenTypeJudge(ChessBoard &chessboard, Chess &currentChess);//���������ж�
	int ChessTypeGet(ChessBoard &chessboard, Chess &currentChess,int direction);//�������ͻ��
	void ChessArrange(ChessBoard &chessboard, Chess &currentChess, int direction, int ChessFlagTmp[9]);//��������������
	int ChessTypeJudge(int ChessTmp[9]);//�����ж�
	int isFive(ChessBoard &chessboard,Chess &currentChess);//���������ж�

};