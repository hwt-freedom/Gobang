#include"HumanPlayer.h"

void HumanPlayer::Input() {
	char alphabet;
	int number; //����������Ϣ

	std::cout << "�������������꣬���H��8��,������H8����(ע���д):";
	std::cin >> alphabet;
	std::cin >> number;
	while (!std::cin || !('A' <= alphabet && alphabet <= 'O') || !(1 <= number && number <= 15)) {
		std::cout << "���벻���Ϲ淶�򳬳����̳ߴ磬����������" << std::endl;
		std::cout << "�������������꣬���H��8��,������H8����(ע���д):";
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cin >> alphabet;
		std::cin >> number;
	}

	int y = alphabet - 'A';
	int x = 15 - number;//����������Ӷ�Ӧ�ĺ�������

	currentChess.setPosition(x, y);
}

Chess HumanPlayer::InputValidChess(int colour, ChessBoard &chessboard) {

	while (1) {
		std::cout << std::endl;
		if (!colour)
			std::cout << "*******��������*******" << std::endl;
		else
			std::cout << "*******��������*******" << std::endl;

		Input();

		if (chessboard.isValid(currentChess))//������Ч
			break;
	}

	currentChess.setColour(colour);//����������ɫ

	return currentChess;
}

Chess HumanPlayer::InputChess(int colour, ChessBoard &chessboard){

	while (1) {
		currentChess = InputValidChess(colour, chessboard);//������������
		if (!colour) {//���Ϊ����
			int forbiddenType = referee.judgeForbidden(currentChess, chessboard);
			if (forbiddenType) {//�ж��Ƿ���֣����� ��forbiddenType���㣩 ����������
				referee.showForbidden(forbiddenType);
				continue;
			}
			else
				break;
		}
		else//���Ϊ������ֱ���˳�ѭ��
			break;
	}

	return currentChess;
}
