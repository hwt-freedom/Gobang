#include"AI.h"

int AI::cumputeScore(ChessBoard &chessboard,Chess &currentChess) {

	if (!currentChess.getColour()) {//如果棋子颜色为黑色
		if (referee.judgeForbidden(currentChess, chessboard)) {//如果违反禁手规则，则不能下当前位置（若违反则返回非0值）
			return 0;
		}
	}

	int ChessType;//棋型

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
		ChessType = rule.ChessTypeGet(chessboard, currentChess, direction);// 棋型获得函数
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
		return 10000;	//连5       10000分     Lian5Num >= 1
	if (Huo4Num >= 1 || DoubleChong4Num >= 1 || HighChong4Num + LowChong4Num >= 2 || 
		HighChong4Num + LowChong4Num + Huo3Num + Tiao3Num >=2)//活4+双冲4_1+双冲4_2+冲4活3  5000分
		return 5000;   //Huo4Num >= 1  DoubleChong4Num >= 1
					   //HighChong4Num + LowChong4Num >= 2
					   //Chong4Num + Huo3Num + Tiao3Num>= 2
	if (Huo3Num >= 2)
		return  4500; //双活3     4500分     Huo3Num >= 2
	if (Huo3Num + Tiao3Num >= 2)
		return 4000;  //双活3     4400分     Huo3Num + Tiao3Num >= 2
	if (Tiao3Num >= 2)
		return 4000; //双活3     3500分      Tiao3Num >= 2
	if (Huo3Num + Mian3Num >= 2)
		return 2500; //活3眠3    2500分      Huo3Num + Mian3Num >= 2
	if (Tiao3Num + Huo3Num + Mian3Num >= 2)
		return 2000; //活3眠3    2000分      Tiao3Num + Huo3Num + Mian3Num >= 2
	if (Tiao3Num + Mian3Num >= 2)
		return 1500; //活3眠3    1500分      Tiao3Num + Mian3Num >= 2
	if (HighChong4Num >= 1)
		return 1000;  //冲4       1000分     HighChong4Num >= 1 
	if (LowChong4Num >= 1)
		return 900;  //冲4        900分      LowChong4Num >= 1 
	if (Huo3Num >= 1)
		return 800;   //活3       800分      Huo3Num >= 1
	if (Tiao3Num >= 1)
		return 700;   //跳3       700分      Tiao3Num >= 1
	if (Huo2Num >= 2)
		return 550; //双活2     4500分       Huo2Num >= 2
	if (Huo2Num + Tiao2Num >= 2)
		return 500;  //双活2     4400分      Huo2Num + Tiao2Num >= 2
	if (Tiao2Num >= 2)
		return 450; //双活2     3500分       Tiao2Num >= 2
	if (Huo2Num + Mian2Num >= 2)
		return 250; //活2眠2    250分      Huo2Num + Mian2Num >= 2
	if (Tiao2Num + Huo2Num + Mian2Num >= 2)
		return 200; //活2眠2    200分      Tiao2Num + Huo2Num + Mian2Num >= 2
	if (Tiao2Num + Mian2Num >= 2)
		return 150; //活2眠2    150分      Tiao2Num + Mian2Num >= 2
	if (Mian3Num >= 1)
		return 100;  //眠3       100分       Mian3Num >= 1
	if (Huo2Num >= 1)
		return 80;  //活2       80分         Huo2Num >= 1
	if (Tiao2Num >= 1)
		return 70;  //跳2       70分         Tiao2Num >= 1
	if (Mian2Num >= 1)
		return 50;  //眠2       50分         Mian2Num >= 1

	return 10;      //其他      10分
}

void AI::computePosition(int currentScore[15][15], int opponentScore[15][15]) {//计算位置坐标值

	int currentMax = 0;
	int opponentMax = 0;
	for (int i = 0; i<15; i++)//获得两个分数矩阵各自的最大值
		for (int j = 0; j < 15; j++) {
			if (currentScore[i][j] > currentMax)
				currentMax = currentScore[i][j];
			if (opponentScore[i][j] > opponentMax)
				opponentMax = opponentScore[i][j];
		}


	Position position = { 0, 0 };
	std::vector<Position> currentPosition;
	std::vector<Position> opponentPosition;

	if (currentMax >= opponentMax) {//如果我方的最大分值大于对方

		for(int i = 0; i < 15; i++)
			for(int j = 0; j < 15; j++)
				if (currentScore[i][j] == currentMax) {
					position.row = i;
					position.col = j;
					currentPosition.push_back(position);
				}//先将分值最大的所有位置保存

		int tmp = 0;
		for (unsigned int i = 0; i < currentPosition.size(); i++) {
			if (opponentScore[currentPosition[i].row][currentPosition[i].col] >= tmp) {
				tmp = opponentScore[currentPosition[i].row][currentPosition[i].col];
				position = currentPosition[i];
			}		
		}//再从我方所有分值最大的位置中，挑选出对方分值最大的位置
	}
	else {//如果我方的最大分值小于对方

		for (int i = 0; i < 15; i++)
			for (int j = 0; j < 15; j++)
				if (opponentScore[i][j] == opponentMax) {
					position.row = i;
					position.col = j;
					opponentPosition.push_back(position);
				}//先将分值最大的所有位置保存

		int tmp = 0;
		for (unsigned int i = 0; i < opponentPosition.size(); i++) {
			if (currentScore[opponentPosition[i].row][opponentPosition[i].col] >= tmp) {
				tmp = currentScore[opponentPosition[i].row][opponentPosition[i].col];
				position = opponentPosition[i];
			}
		}//再从对方所有分值最大的位置中，挑选出我方分值最大的位置
	}

	currentChess.setPosition(position.row, position.col);
}

Chess AI::computeChess(int colour, ChessBoard &chessboard) {

	Chess currentChessTmp;
	Chess opponentChessTmp;//当前棋子和对手棋子临时变量
	if (!colour) {//如果colour为黑色0
		currentChessTmp.setColour(0);
		opponentChessTmp.setColour(1);
	}
	else {
		currentChessTmp.setColour(1);
		opponentChessTmp.setColour(0);
	}

	int currentScore[15][15] = { 0 };
	int opponentScore[15][15] = { 0 };//分数矩阵初始化

	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++) {
			if (chessboard.getFlag(i, j) != 0)//如果当前位置有棋子，跳过计算分数步骤
				continue;
			currentChessTmp.setPosition(i, j);
			opponentChessTmp.setPosition(i, j);
			currentScore[i][j] = cumputeScore(chessboard, currentChessTmp);
			opponentScore[i][j] = cumputeScore(chessboard, opponentChessTmp);
		}

	currentChess.setColour(colour);//根据参数colour设置返回棋子的颜色
	computePosition(currentScore, opponentScore);//设置返回棋子的位置

	return currentChess;
}
