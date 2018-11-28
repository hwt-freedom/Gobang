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
		return ChangLian;

	if (count == 4) {
		if (leftCutFlag == 0 && rightCutFlag == 0)
			return Huo4;
		else if (leftCutFlag == opponentFlag || rightCutFlag == opponentFlag)
			return Chong4;
	}

	if (count == 3) {

		int leftCutExpFlag1 = ChessFlagTmp[leftCutPos - 1];
		int	rightCutExpFlag1 = ChessFlagTmp[rightCutPos + 1];//断开位置往外拓展一个棋子的标志记录

		if (leftCutFlag == 0 && rightCutFlag == 0) {//截断处都无棋子
			if (leftCutExpFlag1 == currentFlag || rightCutExpFlag1 == currentFlag)//判断是否形成跳4,若拓展一个位置和中心位置棋子相同
				return TiaoChong4;
			else if (leftCutExpFlag1 == 0 || rightCutExpFlag1 == 0)//判断是否形成活3，若扩展一个位置均无棋子
				return Huo3;
		}
		else if (leftCutFlag == 0 || rightCutFlag == 0) {//截断处有一个位置有棋子
			if (leftCutFlag == opponentFlag) {//假设左边为对手的棋子
				if(rightCutExpFlag1 == currentFlag)//右边拓展一个位置和中心位置棋子相同
					return TiaoChong4;
			}
			if (rightCutFlag == opponentFlag) {//假设右边为对手的棋子
				if (leftCutExpFlag1 == currentFlag)//左边拓展一个位置和中心位置棋子相同
					return TiaoChong4;
			}
		}
	}

	if (count == 2) {

		int leftCutExpFlag1 = ChessFlagTmp[leftCutPos - 1];
		int	rightCutExpFlag1 = ChessFlagTmp[rightCutPos + 1];//断开位置往外拓展一个棋子的标志记录
		int leftCutExpFlag2 = ChessFlagTmp[leftCutPos - 2];
		int	rightCutExpFlag2 = ChessFlagTmp[rightCutPos + 2];//断开位置往外拓展两个棋子的标志记录
		
		if (leftCutFlag == 0 && rightCutFlag == 0) {//截断处都无棋子
			if ((leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag) ||
				(rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag))//断开位置往外拓展两个棋子都有且和中心位置棋子相同
				return TiaoChong4;

			if ((leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == 0) ||
				(rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == 0))
				return Tiao3;
		}
		else if (leftCutFlag == 0 || rightCutFlag == 0) {
			if (leftCutFlag == opponentFlag) {//左边为对手的棋子
				if(rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag)
					return TiaoChong4;
			}
			if (rightCutFlag == opponentFlag) {
				if(leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag)
					return TiaoChong4;
			}
		}
	}

	if (count == 1) {

		int leftCutExpFlag1 = ChessFlagTmp[leftCutPos - 1];
		int	rightCutExpFlag1 = ChessFlagTmp[rightCutPos + 1];//断开位置往外拓展一个棋子的标志记录
		int leftCutExpFlag2 = ChessFlagTmp[leftCutPos - 2];
		int	rightCutExpFlag2 = ChessFlagTmp[rightCutPos + 2];//断开位置往外拓展两个棋子的标志记录
		int leftCutExpFlag3 = ChessFlagTmp[leftCutPos - 3];
		int	rightCutExpFlag3 = ChessFlagTmp[rightCutPos + 3];//断开位置往外拓展三个棋子的标志记录

		if (leftCutFlag == 0 && leftCutExpFlag1 == currentFlag &&
			leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == currentFlag)
			return TiaoChong4;
		if (rightCutFlag == 0 && rightCutExpFlag1 == currentFlag &&
			rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == currentFlag)
			return TiaoChong4;
		if (leftCutFlag == 0 && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag &&
			rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == 0)
			return Huo3;
		if (leftCutFlag == 0 && rightCutFlag == 0 && leftCutExpFlag1 == currentFlag &&
			leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == 0)
			return Huo3;
	}

	return 0;
}

void Rule::ChessArrange(int chessBoardFlagTmp[15][15], Chess currentChess, int direction, int ChessFlagTmp[9]) {//可以写到其他类里边，调用方法
	
	int currentFlag;//当前棋子的标志信息 
	int opponentFlag;//对手棋子的标志信息
	//棋子标志信息  0无棋子，1黑棋，2白棋
																											
	int currentRow = currentChess.getRow();
	int currentCol = currentChess.getCol();
	currentFlag = chessBoardFlagTmp[currentRow][currentCol];

	if (currentFlag == 1) {//设置对手标志位，若当前标志显示为黑棋
		opponentFlag = 2;
	}
	else if (currentFlag == 2) {
		opponentFlag = 1;
	}

	ChessFlagTmp[4] = currentFlag;
	switch (direction) {
	case 0://横向
		for (int i = currentRow, j = 1; j <= 4; j++) {//当前位置左边棋子整理，若出界则填充成对方颜色
			int col = currentCol - j;
			if (col < 0) {
				while (j <= 4) {
					ChessFlagTmp[4 - j] = opponentFlag;
					j++;
				}
				break;
			}
			else
				ChessFlagTmp[4 - j] = chessBoardFlagTmp[i][col];//若没出界则将棋盘标志信息复制到对应位置即可			
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
			else
				ChessFlagTmp[4 + j] = chessBoardFlagTmp[i][col];//若没出界则将棋盘标志信息复制到对应位置即可		
		}
		break;

	case 1://纵向
		for (int i = 1, j = currentCol; i <= 4; i++) {//当前位置上边棋子整理，若出界则填充成对方颜色
			int row = currentRow - i;
			if (row < 0) {
				while (i <= 4) {
					ChessFlagTmp[4 - i] = opponentFlag;
					i++;
				}
				break;
			}
			else
				ChessFlagTmp[4 - i] = chessBoardFlagTmp[row][j];//若没出界则将棋盘标志信息复制到对应位置即可			
		}
		for (int i = 1, j = currentCol; i <= 4; i++) {//当前位置上边棋子整理，若出界则填充成对方颜色
			int row = currentRow + i;
			if (row < 0) {
				while (i <= 4) {
					ChessFlagTmp[4 + i] = opponentFlag;
					i++;
				}
				break;
			}
			else
				ChessFlagTmp[4 + i] = chessBoardFlagTmp[row][j];//若没出界则将棋盘标志信息复制到对应位置即可			
		}
		break;
	
	case 2://左上右下
		for (int i = 1, j = 1; i <= 4; i++, j++) {//当前位置左上边棋子整理，若出界则填充成对方颜色
			int row = currentRow - i;
			int col = currentCol - j;
			if (row < 0 || col <0) {//其中一个出界
				while (i <= 4) {
					ChessFlagTmp[4 - i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 - i] = chessBoardFlagTmp[row][col];//若没出界则将棋盘标志信息复制到对应位置即可
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
			ChessFlagTmp[4 + i] = chessBoardFlagTmp[row][col];//若没出界则将棋盘标志信息复制到对应位置即可
		}
		break;

	case 3://右上左下
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
			ChessFlagTmp[4 - i] = chessBoardFlagTmp[row][col];//若没出界则将棋盘标志信息复制到对应位置即可
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
			ChessFlagTmp[4 + i] = chessBoardFlagTmp[row][col];//若没出界则将棋盘标志信息复制到对应位置即可
		}
		break;

	default:
		break;
	}

}

int Rule::ChessTypeGet(int chessBoardFlagTmp[15][15], Chess currentChess,int direction) {

	int ChessType;//棋型
	int ChessFlagTmp[9] = { 0 };//某一个方向的棋子暂存

	ChessArrange(chessBoardFlagTmp, currentChess, direction, ChessFlagTmp);//将某一个方向的棋子整理为合适格式
	ChessType = ChessTypeJudge(ChessFlagTmp);

	return ChessType;
}

int Rule::fobiddenTypeJudge(int chessBoardFlagTmp[15][15], Chess currentChess) {

	int ChessType;//棋型

	int ChangLianNum = 0;
	int Huo4Num = 0;
	int Chong4Num = 0;
	int TiaoChong4Num = 0;
	int Huo3Num = 0;

	for (int direction = 0; direction < 4; direction++) {
		ChessType = ChessTypeGet(chessBoardFlagTmp, currentChess, direction);// 棋型获得函数
		switch (ChessType) {
		case ChangLian:
			ChangLianNum++;
			break;
		case Huo4:
			Huo4Num++;
			break;
		case Chong4:
			Chong4Num++;
			break;
		case TiaoChong4:
			TiaoChong4Num++;
			break;
		case Huo3:
			Huo3Num++;
			break;
		default:
			break;
		}
	}

	if (ChangLianNum >= 1) {
		return 3;//长连禁手
	}
	else if (Huo4Num + Chong4Num + TiaoChong4Num >= 2) {
		return 2;//双4禁手
	}
	else if (Huo3Num >= 2) {
		return 1;//双活3禁手
	}
	return 0;

}

int Rule::isForbidden(int chessBoardFlagTmp[15][15], Chess currentChess) {

	//禁手规则：基于棋子类型判断 棋子类型判断需要另外构建函数，就在Rule类中实现即可
		//棋型判断函数实现思想
		//      1、首先获得四个方向的棋型（同一个方向需要获得9个棋子）
						//在判断棋子类型之前需要先基于当前棋子位置处理边界条件（以对手的颜色进行填充）
	                    //处理完边界条件之后就可以进行类型的判断
					//若满足棋子类型则该类型++
		//      2、最后根据返回的类型，判断该位置是否属于禁手位置

	int fobiddenType = 0;//禁手类型

	fobiddenType = fobiddenTypeJudge(chessBoardFlagTmp, currentChess);
	switch (fobiddenType) {
	case 1:
		std::cout << std::endl << "*********违反双活3禁手*********" << std::endl;
		break;
	case 2:
		std::cout << std::endl << "*********违反双4禁手*********" << std::endl;
		break;
	case 3:
		std::cout << std::endl << "*********违反长连禁手*********" << std::endl;
		break;
	default:
		break;
	}

	return fobiddenType == 0 ? 0 : 1;//如果禁手类型为0，则说明没有禁手，返回0
}

int Rule::isFive(int chessBoardFlagTmp[15][15],Chess currentChess) {

	int count;//计数器
	int currentFlag;//当前棋子的标志信息

	int currentRow = currentChess.getRow();
	int currentCol = currentChess.getCol();
	currentFlag = chessBoardFlagTmp[currentRow][currentCol];

	int i, j;
	int rowmin, rowmax;
	int colmin, colmax;

	count = 0;//横向计数
	colmin = currentCol - 4 < 0 ? 0 : currentCol - 4;
	colmax = currentCol + 4 > 14 ? 14 : currentCol + 4;//边界条件
	for (i = currentRow, j = colmin; j <= colmax; j++) {
		if (chessBoardFlagTmp[i][j] == currentFlag){
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
		if (chessBoardFlagTmp[i][j] == currentFlag) {
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
		if (chessBoardFlagTmp[i][j] == currentFlag) {
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
		if (chessBoardFlagTmp[i][j] == currentFlag) {
			count++;
			if (count == 5)
				return 1;
		}
		else
			count = 0;
	}

	return 0;
}