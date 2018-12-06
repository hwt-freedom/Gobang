#include "Referee.h"

int Referee::setCurrentColour(int lastColour) {//设置当前的棋子颜色，初始化输入的参数是1，使得返回的colour为0即黑色
	if (lastColour == 1)
		return 0;
	else
		return 1;
}

int Referee::judgeForbidden(Chess &currentChess, ChessBoard &chessboard) {

	//禁手规则：基于棋子类型判断 棋子类型判断需要另外构建函数，就在Rule类中实现即可
	//棋型判断函数实现思想
	//      1、首先获得四个方向的棋型（同一个方向需要获得9个棋子）
	//在判断棋子类型之前需要先基于当前棋子位置处理边界条件（以对手的颜色进行填充）
	//处理完边界条件之后就可以进行类型的判断
	//若满足棋子类型则该类型++
	//      2、最后根据返回的类型，判断该位置是否属于禁手位置

	int forbiddenType = 0;//禁手类型

	forbiddenType = rule.forbiddenTypeJudge(chessboard, currentChess);

	return forbiddenType;//如果禁手类型为0，则说明没有禁手，返回0

}

void Referee::showForbidden(int forbiddenType) {
	switch (forbiddenType) {
	case 1:
		std::cout << std::endl << "*********违反双活3禁手，请重新输入*******" << std::endl;
		break;
	case 2:
		std::cout << std::endl << "*********违反双4禁手，请重新输入*********" << std::endl;
		break;
	case 3:
		std::cout << std::endl << "*********违反长连禁手，请重新输入*********" << std::endl;
		break;
	default:
		break;
	}
}

int Referee::judgeWinner(Chess &currentChess, ChessBoard &chessboard) {//返回winner ：1黑棋获胜，2白棋获胜,3平局
	
		//思想：输入的棋盘是已经将当前的棋子标志减2的棋盘
	        //1、首先判断当前位置是否为禁手位置
				//若为禁手位置，则直接返回输赢结果
	            //否则则继续进行后续判断
			//2、再判断是否连成五子
	        //3、若未连成则再判断棋盘是否已满，若已满则返回平局结果即3            
				//否则返回0继续下棋

	int colour = currentChess.getColour();//0黑1白

	if (rule.isFive(chessboard, currentChess)) {//判断是否连成5子
		return colour == 0 ? 1 : 2;//若为0则返回1，若非0则返回2
	}

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