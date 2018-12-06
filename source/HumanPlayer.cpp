#include"HumanPlayer.h"

void HumanPlayer::Input() {
	char alphabet;
	int number; //输入坐标信息

	std::cout << "请输入棋子坐标，如第H列8行,则输入H8即可(注意大写):";
	std::cin >> alphabet;
	std::cin >> number;
	while (!std::cin || !('A' <= alphabet && alphabet <= 'O') || !(1 <= number && number <= 15)) {
		std::cout << "输入不符合规范或超出棋盘尺寸，请重新输入" << std::endl;
		std::cout << "请输入棋子坐标，如第H列8行,则输入H8即可(注意大写):";
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cin >> alphabet;
		std::cin >> number;
	}

	int y = alphabet - 'A';
	int x = 15 - number;//获得输入棋子对应的横纵坐标

	currentChess.setPosition(x, y);
}

Chess HumanPlayer::InputValidChess(int colour, ChessBoard &chessboard) {

	while (1) {
		std::cout << std::endl;
		if (!colour)
			std::cout << "*******黑棋落子*******" << std::endl;
		else
			std::cout << "*******白棋落子*******" << std::endl;

		Input();

		if (chessboard.isValid(currentChess))//输入有效
			break;
	}

	currentChess.setColour(colour);//设置棋子颜色

	return currentChess;
}

Chess HumanPlayer::InputChess(int colour, ChessBoard &chessboard){

	while (1) {
		currentChess = InputValidChess(colour, chessboard);//获得输入的棋子
		if (!colour) {//如果为黑棋
			int forbiddenType = referee.judgeForbidden(currentChess, chessboard);
			if (forbiddenType) {//判断是否禁手，若是 （forbiddenType非零） 则重新输入
				referee.showForbidden(forbiddenType);
				continue;
			}
			else
				break;
		}
		else//如果为白棋则直接退出循环
			break;
	}

	return currentChess;
}
