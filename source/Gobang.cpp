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
	//选择顺序
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
	std::cout << "*                Date: 2018 Dec                 *" << std::endl;
	std::cout << "*************************************************" << std::endl;
	ChooseMode();
	chessboard.print(mode);//打印棋盘信息
}

void Gobang::playGobangMode1(HumanPlayer    &humanPlayer,
							 ComputerPlayer &computerPlayer,
							 Chess			&currentChess,
							 ChessBoard     &chessboard,
							 Referee        &referee,
							 int order) 
{

	while (1) {

		currentColour = referee.setCurrentColour(currentChess.getColour());//设置当前棋子颜色，默认先返回黑色，即0

		if (order) {//0计算机先行，1玩家先行
			if(!currentColour)
				currentChess = humanPlayer.InputChess(currentColour, chessboard);//玩家先行 则当颜色为黑色0时，玩家输入
			else
				currentChess = computerPlayer.InputChess(currentColour, chessboard);
		}
		else {
			if(!currentColour)
				currentChess = computerPlayer.InputChess(currentColour, chessboard);//计算机先行 则当颜色为黑色0时，计算机输入
			else
				currentChess = humanPlayer.InputChess(currentColour, chessboard);
		}

		chessboard.addChessFlag(currentChess);//将当前得到的棋子添加到棋盘标志图中，以便显示
		chessboard.print(mode);//打印输入棋子后的棋盘信息
		chessboard.updateChessFlag();//显示完毕后将当前的flag更新，以便判断禁手和输赢

		winner = referee.judgeWinner(currentChess, chessboard);
		if (winner != 0)
			break;
	}
	referee.showWinner(winner);//显示输赢信息
	system("pause");
}


void Gobang::playGobangMode2(HumanPlayer &humanPlayer,
							 Chess       &currentChess,
							 ChessBoard  &chessboard,
							 Referee     &referee) 
{
	while (1) {	

		currentColour = referee.setCurrentColour(currentChess.getColour());//设置当前棋子颜色，默认先返回黑色，即0

		currentChess = humanPlayer.InputChess(currentColour, chessboard);//获得输入的棋子

		chessboard.addChessFlag(currentChess);//将当前得到的棋子添加到棋盘标志图中，以便显示
		chessboard.print(mode);//打印输入棋子后的棋盘信息
		chessboard.updateChessFlag();//显示完毕后将当前的flag更新，以便判断禁手和输赢

		winner = referee.judgeWinner(currentChess, chessboard);
		if (winner != 0)
			break;
	}
	referee.showWinner(winner);//显示输赢信息
	system("pause");
}

void Gobang::startGobang() {

	if (mode) {//人机模式为1
		ChooseOrder();//order为0计算机先行 为1玩家先行
		playGobangMode1(humanPlayer, computerPlayer, currentChess, chessboard, referee, order);
	}
	else {//人人模式为0
		playGobangMode2(humanPlayer, currentChess, chessboard, referee);
	}
}
