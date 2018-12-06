#include "Rule.h"

int Rule::ChessTypeJudge(int ChessFlagTmp[9]) {
	//判断棋型
	int currentFlag = ChessFlagTmp[4];
	int opponentFlag;

	if (currentFlag == 1) {//设置对手标志位，若当前标志显示为黑棋
		opponentFlag = 2;
	}
	else if (currentFlag == 2) {
		opponentFlag = 1;
	}

	int count = 1;//与中心棋子同颜色且相连的棋子个数
	int leftCutPos, rightCutPos;//和中心棋子连线断开的位置记录
	int leftCutFlag, rightCutFlag;//和中心棋子连线断开的标志记录

	for (int i = 1; i <= 4; i++) {//记录断开位置及flag
		if (ChessFlagTmp[4 - i] == currentFlag)
			count++;//同色
		else {
			leftCutPos = 4 - i;//保存断开位置
			leftCutFlag = ChessFlagTmp[4 - i];//保存断开flag
			break;
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (ChessFlagTmp[4 + i] == currentFlag)
			count++;//同色
		else {
			rightCutPos = 4 + i;//保存断开位置
			rightCutFlag = ChessFlagTmp[4 + i];//保存断开flag
			break;
		}
	}

	if (count >= 6)
		return ChangLian;//多个1

	if (count == 5) {
		return Lian5;//11111 连5
	}

	if (count == 4) {
		if (leftCutFlag == 0 && rightCutFlag == 0)
			return Huo4;//0 1111 0  活4
		if (leftCutFlag == 0 && rightCutFlag == opponentFlag || leftCutFlag == opponentFlag && rightCutFlag == 0)
			return HighChong4;//2 1111 0 或 0 1111 2 冲4_1
	}

	if (count == 3) {

		int leftCutExpFlag1 = ChessFlagTmp[leftCutPos - 1];
		int	rightCutExpFlag1 = ChessFlagTmp[rightCutPos + 1];//断开位置往外拓展一个棋子的标志记录

		if (leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag)
			return DoubleChong4;// 10 111 01 双冲4_1

		if (leftCutFlag == 0 && leftCutExpFlag1 == currentFlag || rightCutFlag == 0 && rightCutExpFlag1 == currentFlag)
			return LowChong4;//10 111或111 01  冲4_2

		if (leftCutFlag == 0 && rightCutFlag == 0)//在两边都无棋子的情况下
			if (leftCutExpFlag1 == 0 || rightCutExpFlag1 == 0)//只要有一侧的外部无棋子
				return Huo3;// 00 111 0 或 0 111 00  活3

		if ((leftCutFlag == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == 0) ||
			(rightCutFlag == opponentFlag && leftCutFlag == 0 && leftCutExpFlag1 == 0))
			return Mian3;//2 111 00 或 00 111 2 眠3_1

		if (leftCutFlag == 0 && leftCutExpFlag1 == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == opponentFlag)
			return Mian3;//20 111 02 眠3_6

	}

	if (count == 2) {

		int leftCutExpFlag1 = ChessFlagTmp[leftCutPos - 1];
		int	rightCutExpFlag1 = ChessFlagTmp[rightCutPos + 1];//断开位置往外拓展一个棋子的标志记录
		int leftCutExpFlag2 = ChessFlagTmp[leftCutPos - 2];
		int	rightCutExpFlag2 = ChessFlagTmp[rightCutPos + 2];//断开位置往外拓展两个棋子的标志记录
		
		if (rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag &&
			leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag)
			return DoubleChong4;//110 11 011  双冲4_2

		if ((rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag) ||
			(leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag))
			return LowChong4;//110 11 或 11 011  冲4_3

		if ((rightCutFlag == 0 && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == 0) ||
			(leftCutFlag == 0 && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == 0))
			return Tiao3;//010 11 0 或 0 11 010 跳3

		if ((rightCutFlag == opponentFlag && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == 0) ||
			(leftCutFlag == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == 0))
			return Mian3;//2 11 010 或 010 11 2 眠3_2

		if ((rightCutFlag == 0 && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == opponentFlag) ||
			(leftCutFlag == 0 && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == opponentFlag))
			return Mian3;//0 11 012 或 210 11 0 眠3_3

		if ((rightCutFlag == 0 && rightCutExpFlag1 == 0 && rightCutExpFlag2 == currentFlag) ||
			(leftCutFlag == 0 && leftCutExpFlag1 == 0 && leftCutExpFlag2 == currentFlag))
			return Mian3;// 11 001 或 100 11 眠3_4

		if (rightCutFlag == 0 && rightCutExpFlag1 == 0 && leftCutFlag == 0 && leftCutExpFlag1 == 0)
			return Huo2;//00 11 00 活2_1

		if ((rightCutFlag == opponentFlag && leftCutFlag == 0 && leftCutExpFlag1 == 0 && leftCutExpFlag2 == 0) ||
			(leftCutFlag == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == 0 && rightCutExpFlag2 == 0))
			return Mian2;//000 11 2 或 2 11 000 眠2_1

	}

	if (count == 1) {

		int leftCutExpFlag1 = ChessFlagTmp[leftCutPos - 1];
		int	rightCutExpFlag1 = ChessFlagTmp[rightCutPos + 1];//断开位置往外拓展一个棋子的标志记录
		int leftCutExpFlag2 = ChessFlagTmp[leftCutPos - 2];
		int	rightCutExpFlag2 = ChessFlagTmp[rightCutPos + 2];//断开位置往外拓展两个棋子的标志记录
		int leftCutExpFlag3 = ChessFlagTmp[leftCutPos - 3];
		int	rightCutExpFlag3 = ChessFlagTmp[rightCutPos + 3];//断开位置往外拓展三个棋子的标志记录

		if (leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == currentFlag &&
			rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == currentFlag)
			return DoubleChong4;// 1110 1 01111  双冲4_3

		if (leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == currentFlag)
			return LowChong4;//1110 1 冲4_2
		if (rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == currentFlag)
			return LowChong4;//1 0111 冲4_2

		if (leftCutFlag == 0 && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == 0)
			return Tiao3;//0 1 0110 跳3
		if (rightCutFlag == 0 && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == 0)
			return Tiao3;//0110 1 0 跳3

		if (leftCutFlag == 0 && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == opponentFlag)
			return Mian3;//0 1 0112 眠3_2
		if (rightCutFlag == 0 && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == opponentFlag)
			return Mian3;//2110 1 0 眠3_2

		if (leftCutFlag == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == 0)
			return Mian3;//2 1 0110 眠3_3
		if (rightCutFlag == opponentFlag && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == 0)
			return Mian3;//0110 1 2 眠3_3

		if (leftCutFlag == 0 && leftCutExpFlag1 == 0 && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == currentFlag)
			return Mian3;//1100 1 眠3_4
		if (rightCutFlag == 0 && rightCutExpFlag1 == 0 && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == currentFlag)
			return Mian3;//1 0011 眠3_4

		if (leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag)
			return Mian3;// 10 1 01 眠3_5
		if (leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == 0 && leftCutExpFlag3 == currentFlag)
			return Mian3;//1010 1 眠3_5
		if (rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == 0 && rightCutExpFlag3 == currentFlag)
			return Mian3;//1 0101 眠3_5

		if (leftCutFlag == 0 && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == 0)
			return Tiao2;//0 1 010 跳2_1
		if (rightCutFlag == 0 && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == 0)
			return Tiao2;//010 1 0 跳2_1

		if (leftCutFlag == 0 && rightCutFlag == 0 && rightCutExpFlag1 == 0 && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == 0)
			return Tiao2;// 0 1 0010 跳2_2
		if (rightCutFlag == 0 && leftCutFlag == 0 && leftCutExpFlag1 == 0 && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == 0)
			return Tiao2;//0100 1 0  跳2_2

		if (leftCutFlag == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == 0 && rightCutExpFlag3 == 0)
			return Mian2;//2 1 0100 眠2_2
		if (rightCutFlag == opponentFlag && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == 0 && leftCutExpFlag3 == 0)
			return Mian2;//0010 1 2 眠2_2

		if (leftCutFlag == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == 0 && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == 0)
			return Mian2;//2 1 0010 眠2_3
		if (rightCutFlag == opponentFlag && leftCutFlag == 0 && leftCutExpFlag1 == 0 && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == 0)
			return Mian2;//0100 1 2 眠2_3

		if (leftCutFlag == 0 && leftCutExpFlag1 == 0 && leftCutExpFlag2 == 0 && leftCutExpFlag3 == currentFlag)
			return Mian2;//1000 1 眠2_4
		if (rightCutFlag == 0 && rightCutExpFlag1 == 0 && rightCutExpFlag2 == 0 && rightCutExpFlag3 == currentFlag)
			return Mian2;//1 0001 眠2_4

	}

	return 0;
}

void Rule::ChessArrange(ChessBoard &chessboard, Chess &currentChess, int direction, int ChessFlagTmp[9]) {
																										
	int currentRow = currentChess.getRow();
	int currentCol = currentChess.getCol();//获得当前棋子坐标

	int currentFlag, opponentFlag;//棋子标志信息  0无棋子，1黑棋，2白棋	
	if (!currentChess.getColour()) {//如果是黑棋
		currentFlag = 1;
		opponentFlag = 2;
	}
	else {
		currentFlag = 2;
		opponentFlag = 1;
	}

	ChessFlagTmp[4] = currentFlag;
	switch (direction) {
	case 0://左 → 右

		for (int i = currentRow, j = 1; j <= 4; j++) {//当前位置左边棋子整理，若出界则填充成对方颜色
			int col = currentCol - j;
			if (col < 0) {
				while (j <= 4) {
					ChessFlagTmp[4 - j] = opponentFlag;
					j++;
				}
				break;
			}
			ChessFlagTmp[4 - j] = chessboard.getFlag(i, col);//若没出界则将棋盘标志信息复制到对应位置即可
		}
		for (int i = currentRow, j = 1; j <= 4; j++) {//当前位置右边棋子整理，若出界则填充成对方颜色
			int col = currentCol + j;
			if (col > 14) {
				while (j <= 4) {
					ChessFlagTmp[4 + j] = opponentFlag;
					j++;
				}
				break;
			}
			ChessFlagTmp[4 + j] = chessboard.getFlag(i, col);//若没出界则将棋盘标志信息复制到对应位置即可
		}
		break;

	case 1://上 → 下

		for (int i = 1, j = currentCol; i <= 4; i++) {//当前位置上边棋子整理，若出界则填充成对方颜色
			int row = currentRow - i;
			if (row < 0) {
				while (i <= 4) {
					ChessFlagTmp[4 - i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 - i] = chessboard.getFlag(row, j);//若没出界则将棋盘标志信息复制到对应位置即可	
		}
		for (int i = 1, j = currentCol; i <= 4; i++) {//当前位置上边棋子整理，若出界则填充成对方颜色
			int row = currentRow + i;
			if (row > 14) {
				while (i <= 4) {
					ChessFlagTmp[4 + i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 + i] = chessboard.getFlag(row, j);//若没出界则将棋盘标志信息复制到对应位置即可
		}
		break;
	
	case 2://左上 → 右下
		for (int i = 1, j = 1; i <= 4; i++, j++) {//当前位置左上边棋子整理，若出界则填充成对方颜色
			int row = currentRow - i;
			int col = currentCol - j;
			if (row < 0 || col < 0) {//其中一个出界
				while (i <= 4) {
					ChessFlagTmp[4 - i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 - i] = chessboard.getFlag(row, col);//若没出界则将棋盘标志信息复制到对应位置即可
		}
		for (int i = 1, j = 1; i <= 4; i++, j++) {//当前位置右下边棋子整理，若出界则填充成对方颜色
			int row = currentRow + i;
			int col = currentCol + j;
			if (row > 14 || col > 14) {//其中一个出界
				while (i <= 4) {
					ChessFlagTmp[4 + i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 + i] = chessboard.getFlag(row, col);//若没出界则将棋盘标志信息复制到对应位置即可
		}
		break;

	case 3://右上 → 左下
		for (int i = 1, j = 1; i <= 4; i++, j++) {//当前位置右上边棋子整理，若出界则填充成对方颜色
			int row = currentRow - i;
			int col = currentCol + j;
			if (row < 0 || col > 14) {//其中一个出界
				while (i <= 4) {
					ChessFlagTmp[4 - i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 - i] = chessboard.getFlag(row, col);//若没出界则将棋盘标志信息复制到对应位置即可
		}
		for (int i = 1, j = 1; i <= 4; i++, j++) {//当前位置左下边棋子整理，若出界则填充成对方颜色
			int row = currentRow + i;
			int col = currentCol - j;
			if (row > 14 || col < 0) {//其中一个出界
				while (i <= 4) {
					ChessFlagTmp[4 + i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 + i] = chessboard.getFlag(row, col);//若没出界则将棋盘标志信息复制到对应位置即可
		}
		break;

	default:
		break;
	}

}

int Rule::ChessTypeGet(ChessBoard &chessboard, Chess &currentChess,int direction) {

	int ChessType;//棋型
	int ChessFlagTmp[9] = { 0 };//某一个方向的棋子暂存

	ChessArrange(chessboard, currentChess, direction, ChessFlagTmp);//将某一个方向的棋子整理为合适格式
	ChessType = ChessTypeJudge(ChessFlagTmp);

	return ChessType;
}

int Rule::forbiddenTypeJudge(ChessBoard &chessboard, Chess &currentChess) {

	int ChessType;//棋型

	int ChangLianNum = 0;
	int Lian5Num = 0;
	int Huo4Num = 0;
	int DoubleChong4Num = 0;
	int HighChong4Num = 0;
	int LowChong4Num = 0;
	int Huo3Num = 0;
	int Tiao3Num = 0;

	for (int direction = 0; direction < 4; direction++) {
		ChessType = ChessTypeGet(chessboard, currentChess, direction);// 棋型获得函数
		switch (ChessType) {
		case ChangLian:
			ChangLianNum++;
			break;
		case Lian5:
			Lian5Num++;
			break;
		case Huo4:
			Huo4Num++;
			break;
		case DoubleChong4:
			DoubleChong4Num++;
			break;
		case HighChong4:
			HighChong4Num++;
			break;
		case LowChong4:
			LowChong4Num++;
			break;
		case Huo3:
			Huo3Num++;
			break;
		case Tiao3:
			Tiao3Num++;
			break;
		default:
			break;
		}
	}

	if (Lian5Num >= 1)
		return 0;//若发现连五，则不考虑禁手的影响

	if (ChangLianNum >= 1) {
		return 3;//长连禁手
	}

	if (DoubleChong4Num >= 1) {
		return 2;//双4禁手 同一方向形成双四禁手
	}

	if (Huo4Num + LowChong4Num + HighChong4Num >= 2) {
		return 2;//双4禁手 不同方向形成双四禁手
	}

	if (Huo3Num + Tiao3Num>= 2) {
		return 1;//双活3禁手
	}

	return 0;

}

int Rule::isFive(ChessBoard &chessboard,Chess &currentChess) {//colour：黑0 白1  flag：黑1 白2

	int count;//计数器

	int currentRow = currentChess.getRow();
	int currentCol = currentChess.getCol();

	int currentFlag;//当前棋子的标志信息
	if (!currentChess.getColour()) {//如果是黑棋
		currentFlag = 1;
	}
	else
		currentFlag = 2;

	int i, j;
	int rowmin, rowmax;
	int colmin, colmax;

	count = 0;//横向计数
	colmin = currentCol - 4 < 0 ? 0 : currentCol - 4;
	colmax = currentCol + 4 > 14 ? 14 : currentCol + 4;//边界条件
	for (i = currentRow, j = colmin; j <= colmax; j++) {
		if (chessboard.getFlag(i, j) == currentFlag){
			count++;
			if (count == 5)
				return 1;
		}
		else
			count = 0;			
	}

	count = 0;//纵向计数
	rowmin = currentRow - 4 < 0 ? 0 : currentRow - 4;
	rowmax = currentRow + 4 > 14 ? 14 : currentRow + 4;//边界条件
	for (i = rowmin, j = currentCol; i <= rowmax; i++) {
		if (chessboard.getFlag(i, j) == currentFlag) {
			count++;
			if (count == 5)
				return 1;
		}
		else
			count = 0;
	}

	count = 0;//左上到右下
	rowmin = currentRow - 4;
	colmin = currentCol - 4;
	if (rowmin < 0 || colmin < 0) {
		if (currentRow > currentCol) {
			colmin = 0;
			rowmin = currentRow - currentCol;
		}
		else {
			rowmin = 0;
			colmin = currentCol - currentRow;
		}
	}//左上角边界条件
	rowmax = currentRow + 4;
	colmax = currentCol + 4;
	if (rowmax > 14 || colmax > 14) {
		if (14 - currentRow < 14 - currentCol) {
			rowmax = 14;
			colmax = currentCol + (14 - currentRow);
		}
		else {
			colmax = 14;
			rowmax = currentRow + (14 - currentCol);
		}
	}//右下角边界条件
	for (i = rowmin, j = colmin; i <= rowmax, j <= colmax; i++, j++) {//从左上到右下遍历
		if (chessboard.getFlag(i, j) == currentFlag) {
			count++;
			if (count == 5)
				return 1;
		}
		else
			count = 0;
	}

	count = 0;//右上到左下
	rowmin = currentRow - 4;
	colmax = currentCol + 4;
	if (rowmin < 0 || colmax > 14) {
		if (currentRow - 0 <14 - currentCol) {
			rowmin = 0;
			colmax = currentCol + (currentRow - 0);
		}
		else {
			colmax = 14;
			rowmin = currentRow - (14 - currentCol);
		}
	}//右上角边界条件
	rowmax = currentRow + 4;
	colmin = currentCol - 4;
	if (rowmax > 14 || colmin < 0) {
		if (14 - currentRow < currentCol - 0) {
			rowmax = 14;
			colmin = currentCol - (14 - currentRow);
		}
		else {
			colmin = 0;
			rowmax = currentRow + (currentCol - 0);
		}
	}//左下角边界条件
	for (i = rowmin, j = colmax; i <= rowmax, j >= colmin; i++, j--) {//从右上到左下遍历
		if (chessboard.getFlag(i, j) == currentFlag) {
			count++;
			if (count == 5)
				return 1;
		}
		else
			count = 0;
	}

	return 0;
}