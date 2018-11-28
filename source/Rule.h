#pragma once
#include"Chess.h"

class Rule {
private:

	//�����жϵĻ�������
	static const int ChangLian = 1;   //����Ϊ1
	static const int Huo4 = 2;        //��4Ϊ2
	static const int Chong4 = 3;      //��4�����Ϊ3
	static const int TiaoChong4 = 4;  //��4���Ϊ4��ȡ��Ϊ����4
	static const int Huo3 = 5;        //��3Ϊ5
	static const int Tiao3 = 6;       //��3Ϊ6
	                                  //0������������

public:
	
	int isForbidden(int chessBoardFlagTmp[15][15], Chess currentChess);//�����ж�
	int fobiddenTypeJudge(int chessBoardFlagTmp[15][15], Chess currentChess);//���������ж�
	int ChessTypeGet(int chessBoardFlagTmp[15][15], Chess currentChess,int direction);//�������ͻ��
	void ChessArrange(int chessBoardFlagTmp[15][15], Chess currentChess, int direction, int ChessFlagTmp[9]);//��������������
	int ChessTypeJudge(int ChessTmp[9]);//�����ж�
	int isFive(int chessBoardFlagTmp[15][15],Chess currentChess);//���������ж�

};