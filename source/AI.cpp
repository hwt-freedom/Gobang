#include"AI.h"

int AI::cumputeScore(ChessBoard &chessboard,Chess &currentChess) {

	if (!currentChess.getColour()) {//���������ɫΪ��ɫ
		if (referee.judgeForbidden(currentChess, chessboard)) {//���Υ�����ֹ��������µ�ǰλ�ã���Υ���򷵻ط�0ֵ��
			return 0;
		}
	}

	int ChessType;//����

	int Lian5Num = 0;
	int Huo4Num = 0;
	int DoubleChong4Num = 0;
	int HighChong4Num = 0;
	int LowChong4Num = 0;
	int Huo3Num = 0;
	int Tiao3Num = 0;
	int Mian3Num = 0;
	int Huo2Num = 0;
	int Tiao2Num = 0;
	int Mian2Num = 0;

	for (int direction = 0; direction < 4; direction++) {
		ChessType = rule.ChessTypeGet(chessboard, currentChess, direction);// ���ͻ�ú���
		switch (ChessType) {
		case Lian5:
			Lian5Num++;
			break;
		case Huo4:
			Huo4Num++;
			break;
		case DoubleChong4:
			DoubleChong4Num++;
			break;
		case HighChong4:
			HighChong4Num++;
			break;
		case LowChong4:
			LowChong4Num++;
			break;
		case Huo3:
			Huo3Num++;
			break;
		case Tiao3:
			Tiao3Num++;
			break;
		case Mian3:
			Mian3Num++;
			break;
		case Huo2:
			Huo2Num++;
			break;
		case Tiao2:
			Tiao2Num++;
			break;
		case Mian2:
			Mian2Num++;
			break;
		default:
			break;
		}
	}

	if (Lian5Num >= 1)
		return 10000;	//��5       10000��     Lian5Num >= 1
	if (Huo4Num >= 1 || DoubleChong4Num >= 1 || HighChong4Num + LowChong4Num >= 2 || 
		HighChong4Num + LowChong4Num + Huo3Num + Tiao3Num >=2)//��4+˫��4_1+˫��4_2+��4��3  5000��
		return 5000;   //Huo4Num >= 1  DoubleChong4Num >= 1
					   //HighChong4Num + LowChong4Num >= 2
					   //Chong4Num + Huo3Num + Tiao3Num>= 2
	if (Huo3Num >= 2)
		return  4500; //˫��3     4500��     Huo3Num >= 2
	if (Huo3Num + Tiao3Num >= 2)
		return 4000;  //˫��3     4400��     Huo3Num + Tiao3Num >= 2
	if (Tiao3Num >= 2)
		return 4000; //˫��3     3500��      Tiao3Num >= 2
	if (Huo3Num + Mian3Num >= 2)
		return 2500; //��3��3    2500��      Huo3Num + Mian3Num >= 2
	if (Tiao3Num + Huo3Num + Mian3Num >= 2)
		return 2000; //��3��3    2000��      Tiao3Num + Huo3Num + Mian3Num >= 2
	if (Tiao3Num + Mian3Num >= 2)
		return 1500; //��3��3    1500��      Tiao3Num + Mian3Num >= 2
	if (HighChong4Num >= 1)
		return 1000;  //��4       1000��     HighChong4Num >= 1 
	if (LowChong4Num >= 1)
		return 900;  //��4        900��      LowChong4Num >= 1 
	if (Huo3Num >= 1)
		return 800;   //��3       800��      Huo3Num >= 1
	if (Tiao3Num >= 1)
		return 700;   //��3       700��      Tiao3Num >= 1
	if (Huo2Num >= 2)
		return 550; //˫��2     4500��       Huo2Num >= 2
	if (Huo2Num + Tiao2Num >= 2)
		return 500;  //˫��2     4400��      Huo2Num + Tiao2Num >= 2
	if (Tiao2Num >= 2)
		return 450; //˫��2     3500��       Tiao2Num >= 2
	if (Huo2Num + Mian2Num >= 2)
		return 250; //��2��2    250��      Huo2Num + Mian2Num >= 2
	if (Tiao2Num + Huo2Num + Mian2Num >= 2)
		return 200; //��2��2    200��      Tiao2Num + Huo2Num + Mian2Num >= 2
	if (Tiao2Num + Mian2Num >= 2)
		return 150; //��2��2    150��      Tiao2Num + Mian2Num >= 2
	if (Mian3Num >= 1)
		return 100;  //��3       100��       Mian3Num >= 1
	if (Huo2Num >= 1)
		return 80;  //��2       80��         Huo2Num >= 1
	if (Tiao2Num >= 1)
		return 70;  //��2       70��         Tiao2Num >= 1
	if (Mian2Num >= 1)
		return 50;  //��2       50��         Mian2Num >= 1

	return 10;      //����      10��
}

void AI::computePosition(int currentScore[15][15], int opponentScore[15][15]) {//����λ������ֵ

	int currentMax = 0;
	int opponentMax = 0;
	for (int i = 0; i<15; i++)//�����������������Ե����ֵ
		for (int j = 0; j < 15; j++) {
			if (currentScore[i][j] > currentMax)
				currentMax = currentScore[i][j];
			if (opponentScore[i][j] > opponentMax)
				opponentMax = opponentScore[i][j];
		}


	Position position = { 0, 0 };
	std::vector<Position> currentPosition;
	std::vector<Position> opponentPosition;

	if (currentMax >= opponentMax) {//����ҷ�������ֵ���ڶԷ�

		for(int i = 0; i < 15; i++)
			for(int j = 0; j < 15; j++)
				if (currentScore[i][j] == currentMax) {
					position.row = i;
					position.col = j;
					currentPosition.push_back(position);
				}//�Ƚ���ֵ��������λ�ñ���

		int tmp = 0;
		for (unsigned int i = 0; i < currentPosition.size(); i++) {
			if (opponentScore[currentPosition[i].row][currentPosition[i].col] >= tmp) {
				tmp = opponentScore[currentPosition[i].row][currentPosition[i].col];
				position = currentPosition[i];
			}		
		}//�ٴ��ҷ����з�ֵ����λ���У���ѡ���Է���ֵ����λ��
	}
	else {//����ҷ�������ֵС�ڶԷ�

		for (int i = 0; i < 15; i++)
			for (int j = 0; j < 15; j++)
				if (opponentScore[i][j] == opponentMax) {
					position.row = i;
					position.col = j;
					opponentPosition.push_back(position);
				}//�Ƚ���ֵ��������λ�ñ���

		int tmp = 0;
		for (unsigned int i = 0; i < opponentPosition.size(); i++) {
			if (currentScore[opponentPosition[i].row][opponentPosition[i].col] >= tmp) {
				tmp = currentScore[opponentPosition[i].row][opponentPosition[i].col];
				position = opponentPosition[i];
			}
		}//�ٴӶԷ����з�ֵ����λ���У���ѡ���ҷ���ֵ����λ��
	}

	currentChess.setPosition(position.row, position.col);
}

Chess AI::computeChess(int colour, ChessBoard &chessboard) {

	Chess currentChessTmp;
	Chess opponentChessTmp;//��ǰ���ӺͶ���������ʱ����
	if (!colour) {//���colourΪ��ɫ0
		currentChessTmp.setColour(0);
		opponentChessTmp.setColour(1);
	}
	else {
		currentChessTmp.setColour(1);
		opponentChessTmp.setColour(0);
	}

	int currentScore[15][15] = { 0 };
	int opponentScore[15][15] = { 0 };//���������ʼ��

	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++) {
			if (chessboard.getFlag(i, j) != 0)//�����ǰλ�������ӣ����������������
				continue;
			currentChessTmp.setPosition(i, j);
			opponentChessTmp.setPosition(i, j);
			currentScore[i][j] = cumputeScore(chessboard, currentChessTmp);
			opponentScore[i][j] = cumputeScore(chessboard, opponentChessTmp);
		}

	currentChess.setColour(colour);//���ݲ���colour���÷������ӵ���ɫ
	computePosition(currentScore, opponentScore);//���÷������ӵ�λ��

	return currentChess;
}
