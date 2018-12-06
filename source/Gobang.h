#pragma once
#include "ChessBoard.h"
#include "Chess.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Referee.h"
#include "Rule.h"
#include<iostream>

class Gobang {
private:
	int mode;//��Ϸģʽ��0����ģʽ��1�˻�ģʽ
	int order;//�˻�ģʽ����˳��

	int currentColour;//��ǰ������ɫ �����ʾ0�������ʾ1	
	int winner;//��ʤ�ߣ�1�����ʤ��2�����ʤ��3ƽ��

	ChessBoard chessboard;//������ ���̶���
	Chess currentChess;//������ ��ǰ���Ӷ���
	Referee referee;//������ ���ж���
	HumanPlayer humanPlayer;//��������� ������Ҷ���
	ComputerPlayer computerPlayer;//���������� �������Ҷ���

	void ChooseMode();//ѡ��ģʽ��0����ģʽ��1�˻�ģʽ
	void ChooseOrder();//�˻�ģʽѡ������˳��
	void playGobangMode1(HumanPlayer &humanPlayer, ComputerPlayer &computerPlayer, Chess &currentChess, ChessBoard &chessboard, Referee &referee, int order);//�˻�ģʽ
	void playGobangMode2(HumanPlayer &humanPlayer, Chess &currentChess, ChessBoard &chessboard, Referee &referee);//����ģʽ

public:

	Gobang();//���캯��
	void prepareGobang();//��Ϸ׼��
	void startGobang();//��Ϸ��ʼ
};
