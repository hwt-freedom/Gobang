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
	//ѡ��˳��
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
	std::cout << "*                Date: 2018 Dec                 *" << std::endl;
	std::cout << "*************************************************" << std::endl;
	ChooseMode();
	chessboard.print(mode);//��ӡ������Ϣ
}

void Gobang::playGobangMode1(HumanPlayer    &humanPlayer,
							 ComputerPlayer &computerPlayer,
							 Chess			&currentChess,
							 ChessBoard     &chessboard,
							 Referee        &referee,
							 int order) 
{

	while (1) {

		currentColour = referee.setCurrentColour(currentChess.getColour());//���õ�ǰ������ɫ��Ĭ���ȷ��غ�ɫ����0

		if (order) {//0��������У�1�������
			if(!currentColour)
				currentChess = humanPlayer.InputChess(currentColour, chessboard);//������� ����ɫΪ��ɫ0ʱ���������
			else
				currentChess = computerPlayer.InputChess(currentColour, chessboard);
		}
		else {
			if(!currentColour)
				currentChess = computerPlayer.InputChess(currentColour, chessboard);//��������� ����ɫΪ��ɫ0ʱ�����������
			else
				currentChess = humanPlayer.InputChess(currentColour, chessboard);
		}

		chessboard.addChessFlag(currentChess);//����ǰ�õ���������ӵ����̱�־ͼ�У��Ա���ʾ
		chessboard.print(mode);//��ӡ�������Ӻ��������Ϣ
		chessboard.updateChessFlag();//��ʾ��Ϻ󽫵�ǰ��flag���£��Ա��жϽ��ֺ���Ӯ

		winner = referee.judgeWinner(currentChess, chessboard);
		if (winner != 0)
			break;
	}
	referee.showWinner(winner);//��ʾ��Ӯ��Ϣ
	system("pause");
}


void Gobang::playGobangMode2(HumanPlayer &humanPlayer,
							 Chess       &currentChess,
							 ChessBoard  &chessboard,
							 Referee     &referee) 
{
	while (1) {	

		currentColour = referee.setCurrentColour(currentChess.getColour());//���õ�ǰ������ɫ��Ĭ���ȷ��غ�ɫ����0

		currentChess = humanPlayer.InputChess(currentColour, chessboard);//������������

		chessboard.addChessFlag(currentChess);//����ǰ�õ���������ӵ����̱�־ͼ�У��Ա���ʾ
		chessboard.print(mode);//��ӡ�������Ӻ��������Ϣ
		chessboard.updateChessFlag();//��ʾ��Ϻ󽫵�ǰ��flag���£��Ա��жϽ��ֺ���Ӯ

		winner = referee.judgeWinner(currentChess, chessboard);
		if (winner != 0)
			break;
	}
	referee.showWinner(winner);//��ʾ��Ӯ��Ϣ
	system("pause");
}

void Gobang::startGobang() {

	if (mode) {//�˻�ģʽΪ1
		ChooseOrder();//orderΪ0��������� Ϊ1�������
		playGobangMode1(humanPlayer, computerPlayer, currentChess, chessboard, referee, order);
	}
	else {//����ģʽΪ0
		playGobangMode2(humanPlayer, currentChess, chessboard, referee);
	}
}
