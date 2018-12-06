#include "ChessBoard.h"

void ChessBoard::print(int mode) {//�������ã���ӡ������Ϣ

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
		}//����flag�ı���ʾ��Ϣ

	system("cls");//����

	switch (mode) {
	case 0:
		std::cout << "***********C++��������Ϸ������ģʽ��**********" << std::endl;
		break;
	case 1:
		std::cout << "***********C++��������Ϸ���˻�ģʽ��**********" << std::endl;
		break;
	default://������
		break;
	}//��ʾ��ǰģʽ

	for (int i = 0; i < ROW; i++) {
		std::cout << std::setw(2) << 15 - i;//����к�
		for (int j = 0; j < COL; j++) {
			std::cout << grid[i].at(2 * j) << grid[i].at(2 * j + 1);
		}
		std::cout << std::endl;
	}
	
	std::cout << "   A B C D E F G H I J K L M N O" << std::endl;//����к�
	//��ʾ�µ����̼�������Ϣ
}

int ChessBoard::isValid(Chess &currentChess) {//�ж�����λ���Ƿ���Ч

	int row = currentChess.getRow();
	int col = currentChess.getCol();

	if (chessBoardFlag[row][col]) {
		std::cout << "��λ���������ӣ���ѡ������λ��\n";
		return 0;
	}
	else
		return 1;
}

void ChessBoard::addChessFlag(Chess &currentChess) {

	int row = currentChess.getRow();
	int col = currentChess.getCol();

	if (!currentChess.getColour()) {//����
		chessBoardFlag[row][col] = 3;
	}
	else {//����
		chessBoardFlag[row][col] = 4;
	}

}

void ChessBoard::updateChessFlag() {

	for (int i = 0; i < ROW; i++)//�����һ�����£��Ա���н��ֺ���Ӯ�ж�
		for (int j = 0; j < COL; j++) {
			if (chessBoardFlag[i][j] > 2)
				chessBoardFlag[i][j] -= 2;
		}
}

int ChessBoard::getFlag(int row, int col) {

	return this->chessBoardFlag[row][col];

}

int ChessBoard::isFull() {//�ж������Ƿ��������򷵻�1

	for(int i=0;i<ROW;i++)
		for (int j = 0; j < COL; j++) {
			if (chessBoardFlag[i][j] == 0)
				return 0;
		}
	return 1;
}

int ChessBoard::isEmpty() {//�ж������Ƿ�գ����򷵻�1

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