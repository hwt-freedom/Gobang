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

void ChessBoard::updateBoard(Chess currentChess) {

	for (int i = 0; i < ROW; i++)//�����һ������
		for (int j = 0; j < COL; j++) {
			if (chessBoardFlag[i][j] > 2)
				chessBoardFlag[i][j] -= 2;
		}

	int row = currentChess.getRow();
	int col = currentChess.getCol();
	if (!currentChess.getColour()) {//����
		chessBoardFlag[row][col] = 3;
	}
	else {//����
		chessBoardFlag[row][col] = 4;
	}

}

int ChessBoard::isCorrect(Chess currentChess) {//�ж�����λ���Ƿ���ȷ
	int row = currentChess.getRow();
	int col = currentChess.getCol();

	if (chessBoardFlag[row][col]) {
		std::cout << "��λ���������ӣ���ѡ������λ��\n";
		return 0;
	}
	else
		return 1;
}

int ChessBoard::isFull() {//�ж������Ƿ��������򷵻�1-----��δ��֤�������Ƿ���ȷ��������

	for(int i=0;i<ROW;i++)
		for (int j = 0; j < COL; j++) {
			if (chessBoardFlag[i][j] == 0)
				return 0;
		}
	return 1;
}

void ChessBoard::getChessBoardFlag(int chessBoardFlagTmp[ROW][COL]) {
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			chessBoardFlagTmp[i][j] = this->chessBoardFlag[i][j];
}

void ChessBoard::setChessBoardFlag(int chessBoardFlagTmp[ROW][COL]) {
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			this->chessBoardFlag[i][j] = chessBoardFlagTmp[i][j];
}