#include "Gobang.h"

Gobang::Gobang() {
	winner = 0;
}

void Gobang::ChooseMode() {
	//选择模式
	std::cout << "请选择下棋模式（0人人模式、1人机模式）：";
	std::cin >> mode;

	while (1) {
		while (!std::cin || !(0 <= mode && mode <= 1)) {
			std::cout << "输入有误，请重新输入" << std::endl;
			std::cout << "请选择下棋模式（0人人模式、1人机模式）：";
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cin >> mode;
		}
		if (mode == 0 || mode == 1)
			break;
	}

}

void Gobang::ChooseOrder() {
	std::cout << std::endl << "******请选择下棋顺序（0计算机先行，1玩家先行）*******：";
	std::cin >> order;

	while (1) {
		while (!std::cin || !(0 <= order && order <= 1)) {
			std::cout << "输入有误，请重新输入" << std::endl;
			std::cout << "请选择下棋顺序（0计算机先行，1玩家先行）：";
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cin >> order;
		}
		if (order == 0 || order == 1)
			break;
	}
}

void Gobang::prepareGobang() {
	std::cout << "*************************************************" << std::endl;
	std::cout << "*                 C++五子棋游戏                 *" << std::endl;
	std::cout << "*    Author：huangwentao18@mails.ucas.ac.cn     *" << std::endl;
	std::cout << "*                Date:2018.12.12                *" << std::endl;
	std::cout << "*************************************************" << std::endl;
	ChooseMode();
	chessboard.print(mode);//打印棋盘信息
}



int Gobang::GobangInput(Chess &currentChess, ChessBoard &chessboard, int colour) {


	return 1;
}

void Gobang::playGobangMode1(Chess &currentChess, ChessBoard &chessboard, Referee referee) {//人机模式

	int chessBoardFlagTmp[15][15] = { 0 };//棋盘标志临时变量

}

void Gobang::playGobangMode2(Chess &currentChess,ChessBoard &chessboard,Referee referee) {//人人模式

	int chessBoardFlagTmp[15][15] = { 0 };//棋盘标志临时变量
	
	while (1) {

		 int colour = referee.setInputColour();//设置当前棋子颜色，默认先返回黑色，即0
		 while (1) {
			 //计时开始 倒数15秒
//			 if (GobangInput(currentChess, chessboard, colour)) {//如果棋子输入无误
				 //计时器重置
//			 }
			currentChess.inputChess(colour);//棋子输入
			if (chessboard.isCorrect(currentChess)) {//若当前位置无棋子
				//计时器 停止
				chessboard.updateBoard(currentChess);//棋盘信息更新，将上一步的（棋盘对象中）大于2的值减2，将当前棋子添加到棋盘标志图中
				chessboard.print(mode);//打印输入棋子后的棋盘信息
				break;
			}
		 }
		 chessboard.getChessBoardFlag(chessBoardFlagTmp);//更新Tmp值，其作为类之间参数传递，

		 winner = referee.judgeWinner(chessBoardFlagTmp,currentChess);//返回winner ：0继续下棋，1黑棋获胜，2白棋获胜，3平局
		 //此时传进去的参数是棋盘标志临时变量的值，且临时变量包含新加入的棋子
		 if (winner != 0) {
			referee.showWinner(winner);
			break;
		 }	 
	}	
}

void Gobang::startGobang() {
	if (mode) {//人机模式为1
		ChooseOrder();//order为0计算机先行 为0玩家先行
		playGobangMode1(currentChess, chessboard, referee);
	}
	else {//人人模式为0
		playGobangMode2(currentChess, chessboard, referee);
	}
}
