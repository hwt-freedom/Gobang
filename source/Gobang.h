#pragma once
#include "ChessBoard.h"
#include "Chess.h"
#include "Rule.h"
#include "Referee.h"
#include<iostream>

class Gobang {
private:
	int mode;//��Ϸģʽ��0����ģʽ��1�˻�ģʽ
	int order;//�˻�ģʽ����˳��
	
	int winner;//��ʤ�ߣ�1�����ʤ��2�����ʤ��3ƽ��

	ChessBoard chessboard;//������ ���̶���
	Chess currentChess;//������ ��ǰ���Ӷ���
	Referee referee;//������ ���ж���

	//Rule �����࣬�������ֹ��������ӹ���
	//Referee �����࣬�����жϵ�ǰ����λ���Ƿ�Ϸ�
	//Timer ��ʱ����
	//AI �˹������࣬�������Ұ���AI��

	void ChooseMode();//ѡ��ģʽ��0����ģʽ��1�˻�ģʽ
	void ChooseOrder();//�˻�ģʽѡ������˳��
	int GobangInput(Chess &currentChess, ChessBoard &chessboard, int colour);//���뺯�� ����1����������ȷ
	void playGobangMode1(Chess &currentChess, ChessBoard &chessboard, Referee referee);//�˻�ģʽ
	void playGobangMode2(Chess &currentChess, ChessBoard &chessboard, Referee referee);//����ģʽ

public:

	Gobang();//���캯��
	void prepareGobang();//��Ϸ׼��
	void startGobang();//��Ϸ��ʼ
};
