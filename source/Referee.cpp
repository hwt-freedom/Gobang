#include "Referee.h"


Referee::Referee() {
	inputColour = 1;//初始化
}

int Referee::setInputColour() {
	if (inputColour)
		inputColour = 0;
	else
		inputColour = 1;
	return inputColour;
}

int Referee::judgeWinner(int chessBoardFlagTmp[15][15],Chess currentChess) {//返回winner ：1黑棋获胜，2白棋获胜,3平局
	
		//思想：首先将当前的棋子标志减2
	        //1、首先判断当前位置是否为禁手位置
				//若为禁手位置，则直接返回输赢结果
	            //否则则继续进行后续判断
			//2、再判断是否连成五子，
	            //若未连成则再判断棋盘是否已满，若已满则返回平局结果即3
	            //否则返回0继续下棋

	int colour = currentChess.getColour();//0黑1白

	int currentRow = currentChess.getRow();
	int currentCol = currentChess.getCol();
	chessBoardFlagTmp[currentRow][currentCol] -= 2;//将临时变量值减去2，目前所有位置的值都不超过2

	if (!colour) {//如果当前落子为黑棋
		if (rule.isForbidden(chessBoardFlagTmp, currentChess))//若违反禁手规则
			return 2;//返回白棋胜利的标志
	}

	if (rule.isFive(chessBoardFlagTmp, currentChess)) {//判断是否连成5子
		return colour == 0 ? 1 : 2;//若为0则返回1，若非0则返回2
	}

	chessboard.setChessBoardFlag(chessBoardFlagTmp);//获得当前状态信息
	if (chessboard.isFull()) {//若棋盘已满
		return 3;
	}

	return 0;//返回0则继续下棋
}

void Referee::showWinner(int winner) {
	switch (winner)
	{
	case 1:
		std::cout << std::endl << "*******黑棋获胜*******" << std::endl;
		break;
	case 2:
		std::cout << std::endl << "*******白棋获胜*******" << std::endl;
		break;
	case 3:
		std::cout << std::endl << "*******平局*******" << std::endl;
		break;
	default:
		break;
	}
}