#include "Referee.h"


Referee::Referee() {
	inputColour = 1;//��ʼ��
}

int Referee::setInputColour() {
	if (inputColour)
		inputColour = 0;
	else
		inputColour = 1;
	return inputColour;
}

int Referee::judgeWinner(int chessBoardFlagTmp[15][15],Chess currentChess) {//����winner ��1�����ʤ��2�����ʤ,3ƽ��
	
		//˼�룺���Ƚ���ǰ�����ӱ�־��2
	        //1�������жϵ�ǰλ���Ƿ�Ϊ����λ��
				//��Ϊ����λ�ã���ֱ�ӷ�����Ӯ���
	            //������������к����ж�
			//2�����ж��Ƿ��������ӣ�
	            //��δ���������ж������Ƿ��������������򷵻�ƽ�ֽ����3
	            //���򷵻�0��������

	int colour = currentChess.getColour();//0��1��

	int currentRow = currentChess.getRow();
	int currentCol = currentChess.getCol();
	chessBoardFlagTmp[currentRow][currentCol] -= 2;//����ʱ����ֵ��ȥ2��Ŀǰ����λ�õ�ֵ��������2

	if (!colour) {//�����ǰ����Ϊ����
		if (rule.isForbidden(chessBoardFlagTmp, currentChess))//��Υ�����ֹ���
			return 2;//���ذ���ʤ���ı�־
	}

	if (rule.isFive(chessBoardFlagTmp, currentChess)) {//�ж��Ƿ�����5��
		return colour == 0 ? 1 : 2;//��Ϊ0�򷵻�1������0�򷵻�2
	}

	chessboard.setChessBoardFlag(chessBoardFlagTmp);//��õ�ǰ״̬��Ϣ
	if (chessboard.isFull()) {//����������
		return 3;
	}

	return 0;//����0���������
}

void Referee::showWinner(int winner) {
	switch (winner)
	{
	case 1:
		std::cout << std::endl << "*******�����ʤ*******" << std::endl;
		break;
	case 2:
		std::cout << std::endl << "*******�����ʤ*******" << std::endl;
		break;
	case 3:
		std::cout << std::endl << "*******ƽ��*******" << std::endl;
		break;
	default:
		break;
	}
}