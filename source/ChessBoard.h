#pragma once

#include"Chess.h"
#include<iostream>
#include<iomanip>

class ChessBoard {
private:

	static const int ROW = 15;//��
	static const int COL = 15;//��

	int chessBoardFlag[ROW][COL];//���̱�־��Ϣ

	std::string gridsymbol1 = "���ЩЩЩЩЩЩЩЩЩЩЩЩЩ�";
	std::string gridsymbol2 = "�����������������";
	std::string gridsymbol3 = "���ةةةةةةةةةةةةة�";//���̻�������

	std::string grid[ROW];//������ʾ��Ϣ

	std::string blacksymbol1 = "��";
	std::string blacksymbol2 = "��";
	std::string whitesymbol1 = "��";
	std::string whitesymbol2 = "��";//���ӻ�������

	int flag;//���ӱ�־��Ϣ  0�����ӣ�1���壬2���壬3������һ����4������һ��

public:
	ChessBoard() {

		for (int i = 0; i < ROW; i++) {
			switch (i)
			{
			case 0:
				grid[i] = gridsymbol1;
				break;
			case ROW - 1:
				grid[i] = gridsymbol3;
				break;
			default:
				grid[i] = gridsymbol2;
				break;
			}//������ʾ��Ϣ��ʼ��
		}

		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COL; j++)
				chessBoardFlag[i][j] = 0;//���̱�־��Ϣ��ʼ��

	}

	void print(int mode);//����ģʽ��ӡ���̵�ǰ
	int isCorrect(Chess currentChess);//�ж�����������Ƿ�Ϸ�
	int isFull();
	void updateBoard(Chess currentChess);
	void getChessBoardFlag(int chessBoardFlagTmp[ROW][COL]);
	void setChessBoardFlag(int chessBoardFlagTmp[ROW][COL]);
};