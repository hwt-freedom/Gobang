#include "ComputerPlayer.h"

Chess ComputerPlayer::InputChess(int colour, ChessBoard &chessboard) {

	if (chessboard.isEmpty()) {//如果棋盘为空，则下中间位置
		currentChess.setColour(colour);
		currentChess.setPosition(7, 7);
	}
	else
		currentChess = ai.computeChess(colour, chessboard);

	return currentChess;
}