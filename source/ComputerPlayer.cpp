#include "ComputerPlayer.h"

Chess ComputerPlayer::InputChess(int colour, ChessBoard &chessboard) {

	if (chessboard.isEmpty()) {//�������Ϊ�գ������м�λ��
		currentChess.setColour(colour);
		currentChess.setPosition(7, 7);
	}
	else
		currentChess = ai.computeChess(colour, chessboard);

	return currentChess;
}