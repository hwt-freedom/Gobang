#include "Chess.h"

void Chess::inputChess(int colour) {

	char alphabet;
	int number; //����������Ϣ

	std::cout << std::endl;
	if (!colour)
		std::cout << "*******��������*******" << std::endl;
	else
		std::cout << "*******��������*******" << std::endl;

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
