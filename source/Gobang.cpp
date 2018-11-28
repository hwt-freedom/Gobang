#include "Gobang.h"

Gobang::Gobang() {
	winner = 0;
}

void Gobang::ChooseMode() {
	//ѡ��ģʽ
	std::cout << "��ѡ������ģʽ��0����ģʽ��1�˻�ģʽ����";
	std::cin >> mode;

	while (1) {
		while (!std::cin || !(0 <= mode && mode <= 1)) {
			std::cout << "������������������" << std::endl;
			std::cout << "��ѡ������ģʽ��0����ģʽ��1�˻�ģʽ����";
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cin >> mode;
		}
		if (mode == 0 || mode == 1)
			break;
	}

}

void Gobang::ChooseOrder() {
	std::cout << std::endl << "******��ѡ������˳��0��������У�1������У�*******��";
	std::cin >> order;

	while (1) {
		while (!std::cin || !(0 <= order && order <= 1)) {
			std::cout << "������������������" << std::endl;
			std::cout << "��ѡ������˳��0��������У�1������У���";
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
	std::cout << "*                 C++��������Ϸ                 *" << std::endl;
	std::cout << "*    Author��huangwentao18@mails.ucas.ac.cn     *" << std::endl;
	std::cout << "*                Date:2018.12.12                *" << std::endl;
	std::cout << "*************************************************" << std::endl;
	ChooseMode();
	chessboard.print(mode);//��ӡ������Ϣ
}



int Gobang::GobangInput(Chess &currentChess, ChessBoard &chessboard, int colour) {


	return 1;
}

void Gobang::playGobangMode1(Chess &currentChess, ChessBoard &chessboard, Referee referee) {//�˻�ģʽ

	int chessBoardFlagTmp[15][15] = { 0 };//���̱�־��ʱ����

}

void Gobang::playGobangMode2(Chess &currentChess,ChessBoard &chessboard,Referee referee) {//����ģʽ

	int chessBoardFlagTmp[15][15] = { 0 };//���̱�־��ʱ����
	
	while (1) {

		 int colour = referee.setInputColour();//���õ�ǰ������ɫ��Ĭ���ȷ��غ�ɫ����0
		 while (1) {
			 //��ʱ��ʼ ����15��
//			 if (GobangInput(currentChess, chessboard, colour)) {//���������������
				 //��ʱ������
//			 }
			currentChess.inputChess(colour);//��������
			if (chessboard.isCorrect(currentChess)) {//����ǰλ��������
				//��ʱ�� ֹͣ
				chessboard.updateBoard(currentChess);//������Ϣ���£�����һ���ģ����̶����У�����2��ֵ��2������ǰ������ӵ����̱�־ͼ��
				chessboard.print(mode);//��ӡ�������Ӻ��������Ϣ
				break;
			}
		 }
		 chessboard.getChessBoardFlag(chessBoardFlagTmp);//����Tmpֵ������Ϊ��֮��������ݣ�

		 winner = referee.judgeWinner(chessBoardFlagTmp,currentChess);//����winner ��0�������壬1�����ʤ��2�����ʤ��3ƽ��
		 //��ʱ����ȥ�Ĳ��������̱�־��ʱ������ֵ������ʱ���������¼��������
		 if (winner != 0) {
			referee.showWinner(winner);
			break;
		 }	 
	}	
}

void Gobang::startGobang() {
	if (mode) {//�˻�ģʽΪ1
		ChooseOrder();//orderΪ0��������� Ϊ0�������
		playGobangMode1(currentChess, chessboard, referee);
	}
	else {//����ģʽΪ0
		playGobangMode2(currentChess, chessboard, referee);
	}
}
