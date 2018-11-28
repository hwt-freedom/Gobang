#include "Chess.h"

void Chess::inputChess(int colour) {

	char alphabet;
	int number; //输入坐标信息

	std::cout << std::endl;
	if (!colour)
		std::cout << "*******黑棋落子*******" << std::endl;
	else
		std::cout << "*******白棋落子*******" << std::endl;

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

	setChess(colour, x, y);

}

void Chess::setChess(int colour, int row, int col) {
	this->colour = colour;
	this->row = row;
	this->col = col;
}

int Chess::getColour() {
	return this->colour;
}

int Chess::getRow() {
	return this->row;
}

int Chess::getCol() {
	return this->col;
}
