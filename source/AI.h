#pragma once
#include"Rule.h"
#include"Referee.h"
#include"Chess.h"
#include<vector>
#include<iostream>

struct Position {
	int row;
	int col;
};

class AI {

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

	//��ֹ���
	    //��Ϊ������ɫΪ��ɫ�������ж��Ƿ�Ϊ����
	     //��5       10000��     Lian5Num >= 1

	     //��4       5000��      Huo4Num >= 1
	     //˫��4_1   5000��      DoubleChong4Num >= 1
	     //˫��4_2   5000��      Chong4Num >= 2
	     //��4��3    5000��      Chong4Num + Huo3Num + Tiao3Num>= 2

	     //˫��3     4500��       Huo3Num >= 2
		 //˫��3     4000��       Huo3Num + Tiao3Num >= 2
	     //˫��3     3500��       Tiao3Num >= 2         //���ȿ�����ͨ��3

	     //��3��3    2500��       Huo3Num + Mian3 >= 2
	     //��3��3    2000��       Tiao3Num + Huo3Num + Mian3 >= 2
		 //��3��3    1500��       Tiao3Num + Mian3 >= 2 //���ȿ�����ͨ��3

	     //��4       1000��       Chong4Num >= 1

	     //��3       800��        Huo3Num >= 1

	     //��3       700��        Tiao3Num >= 1

	     //˫��2     550��        Huo2Num >= 2
	     //˫��2     500��        Huo2Num + Tiao2Num >= 2
	     //˫��2     450��        Tiao2Num >= 2        //���ȿ�����ͨ��2

         //��2��2    250��        Huo2Num + Mian2Num >= 2
	     //��2��2    200��        Huo2Num + Tiao2Num + Mian2Num >= 2
	     //��2��2    150��        Tiao2Num + Mian2Num >= 2
	     
		 //��3       100��        Mian3 >= 1
	     //��2       80��         Huo2Num >= 1
	     //��2       70��         Tiao2Num >= 1
	     //��2       50��         Mian2Num >= 1
	     //����      10��

	Rule rule;
	Referee referee;//�����жϽ���
	Chess currentChess;

	int cumputeScore(ChessBoard &chessboard, Chess &currentChess);
	void computePosition(int currentScore[15][15], int opponentScore[15][15]);

public:

	Chess computeChess(int colour, ChessBoard &chessboard);

};