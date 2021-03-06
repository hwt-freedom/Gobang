#include "ChessBoard.h"

void ChessBoard::print(int mode) {//函数作用：打印棋盘信息

	for(int i=0;i<ROW;i++)
		for (int j = 0; j < COL; j++) {
			switch (chessBoardFlag[i][j]) {
			case 1:
				grid[i].at(2 * j) = blacksymbol1.at(0);
				grid[i].at(2 * j + 1) = blacksymbol1.at(1);
				break;
			case 2:
				grid[i].at(2 * j) = whitesymbol1.at(0);
				grid[i].at(2 * j + 1) = whitesymbol1.at(1);
				break;
			case 3:
				grid[i].at(2 * j) = blacksymbol2.at(0);
				grid[i].at(2 * j + 1) = blacksymbol2.at(1);
				break;
			case 4:
				grid[i].at(2 * j) = whitesymbol2.at(0);
				grid[i].at(2 * j + 1) = whitesymbol2.at(1);
				break;
			default:
				break;
			}
		}//根据flag改变显示信息

	system("cls");//清屏

	switch (mode) {
	case 0:
		std::cout << "***********C++五子棋游戏（人人模式）**********" << std::endl;
		break;
	case 1:
		std::cout << "***********C++五子棋游戏（人机模式）**********" << std::endl;
		break;
	default://差错控制
		break;
	}//显示当前模式

	for (int i = 0; i < ROW; i++) {
		std::cout << std::setw(2) << 15 - i;//输出行号
		for (int j = 0; j < COL; j++) {
			std::cout << grid[i].at(2 * j) << grid[i].at(2 * j + 1);
		}
		std::cout << std::endl;
	}
	
	std::cout << "   A B C D E F G H I J K L M N O" << std::endl;//输出列号
	//显示新的棋盘及棋子信息
}

int ChessBoard::isValid(Chess &currentChess) {//判断落子位置是否有效

	int row = currentChess.getRow();
	int col = currentChess.getCol();

	if (chessBoardFlag[row][col]) {
		std::cout << "该位置已有棋子，请选择其他位置\n";
		return 0;
	}
	else
		return 1;
}

void ChessBoard::addChessFlag(Chess &currentChess) {

	int row = currentChess.getRow();
	int col = currentChess.getCol();

	if (!currentChess.getColour()) {//黑棋
		chessBoardFlag[row][col] = 3;
	}
	else {//白棋
		chessBoardFlag[row][col] = 4;
	}

}

void ChessBoard::updateChessFlag() {

	for (int i = 0; i < ROW; i++)//将最后一步更新，以便进行禁手和输赢判断
		for (int j = 0; j < COL; j++) {
			if (chessBoardFlag[i][j] > 2)
				chessBoardFlag[i][j] -= 2;
		}
}

int ChessBoard::getFlag(int row, int col) {

	return this->chessBoardFlag[row][col];

}

int ChessBoard::isFull() {//判断棋盘是否满，满则返回1

	for(int i=0;i<ROW;i++)
		for (int j = 0; j < COL; j++) {
			if (chessBoardFlag[i][j] == 0)
				return 0;
		}
	return 1;
}

int ChessBoard::isEmpty() {//判断棋盘是否空，空则返回1

	for (int i = 0; i<ROW; i++)
		for (int j = 0; j < COL; j++) {
			if (chessBoardFlag[i][j] != 0)
				return 0;
		}
	return 1;
}

void ChessBoard::setChessFlag(int state[15][15]) {

	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			chessBoardFlag[i][j] = state[i][j];

}