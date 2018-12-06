#include "Referee.h"

int Referee::setCurrentColour(int lastColour) {//���õ�ǰ��������ɫ����ʼ������Ĳ�����1��ʹ�÷��ص�colourΪ0����ɫ
	if (lastColour == 1)
		return 0;
	else
		return 1;
}

int Referee::judgeForbidden(Chess &currentChess, ChessBoard &chessboard) {

	//���ֹ��򣺻������������ж� ���������ж���Ҫ���⹹������������Rule����ʵ�ּ���
	//�����жϺ���ʵ��˼��
	//      1�����Ȼ���ĸ���������ͣ�ͬһ��������Ҫ���9�����ӣ�
	//���ж���������֮ǰ��Ҫ�Ȼ��ڵ�ǰ����λ�ô���߽��������Զ��ֵ���ɫ������䣩
	//������߽�����֮��Ϳ��Խ������͵��ж�
	//���������������������++
	//      2�������ݷ��ص����ͣ��жϸ�λ���Ƿ����ڽ���λ��

	int forbiddenType = 0;//��������

	forbiddenType = rule.forbiddenTypeJudge(chessboard, currentChess);

	return forbiddenType;//�����������Ϊ0����˵��û�н��֣�����0

}

void Referee::showForbidden(int forbiddenType) {
	switch (forbiddenType) {
	case 1:
		std::cout << std::endl << "*********Υ��˫��3���֣�����������*******" << std::endl;
		break;
	case 2:
		std::cout << std::endl << "*********Υ��˫4���֣�����������*********" << std::endl;
		break;
	case 3:
		std::cout << std::endl << "*********Υ���������֣�����������*********" << std::endl;
		break;
	default:
		break;
	}
}

int Referee::judgeWinner(Chess &currentChess, ChessBoard &chessboard) {//����winner ��1�����ʤ��2�����ʤ,3ƽ��
	
		//˼�룺������������Ѿ�����ǰ�����ӱ�־��2������
	        //1�������жϵ�ǰλ���Ƿ�Ϊ����λ��
				//��Ϊ����λ�ã���ֱ�ӷ�����Ӯ���
	            //������������к����ж�
			//2�����ж��Ƿ���������
	        //3����δ���������ж������Ƿ��������������򷵻�ƽ�ֽ����3            
				//���򷵻�0��������

	int colour = currentChess.getColour();//0��1��

	if (rule.isFive(chessboard, currentChess)) {//�ж��Ƿ�����5��
		return colour == 0 ? 1 : 2;//��Ϊ0�򷵻�1������0�򷵻�2
	}

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