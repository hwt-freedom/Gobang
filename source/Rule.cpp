#include "Rule.h"

int Rule::ChessTypeJudge(int ChessFlagTmp[9]) {
	//�ж�����
	int currentFlag = ChessFlagTmp[4];
	int opponentFlag;

	if (currentFlag == 1) {//���ö��ֱ�־λ������ǰ��־��ʾΪ����
		opponentFlag = 2;
	}
	else if (currentFlag == 2) {
		opponentFlag = 1;
	}

	int count = 1;//����������ͬ��ɫ�����������Ӹ���
	int leftCutPos, rightCutPos;//�������������߶Ͽ���λ�ü�¼
	int leftCutFlag, rightCutFlag;//�������������߶Ͽ��ı�־��¼

	for (int i = 1; i <= 4; i++) {//��¼�Ͽ�λ�ü�flag
		if (ChessFlagTmp[4 - i] == currentFlag)
			count++;//ͬɫ
		else {
			leftCutPos = 4 - i;//����Ͽ�λ��
			leftCutFlag = ChessFlagTmp[4 - i];//����Ͽ�flag
			break;
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (ChessFlagTmp[4 + i] == currentFlag)
			count++;//ͬɫ
		else {
			rightCutPos = 4 + i;//����Ͽ�λ��
			rightCutFlag = ChessFlagTmp[4 + i];//����Ͽ�flag
			break;
		}
	}

	if (count >= 6)
		return ChangLian;//���1

	if (count == 5) {
		return Lian5;//11111 ��5
	}

	if (count == 4) {
		if (leftCutFlag == 0 && rightCutFlag == 0)
			return Huo4;//0 1111 0  ��4
		if (leftCutFlag == 0 && rightCutFlag == opponentFlag || leftCutFlag == opponentFlag && rightCutFlag == 0)
			return HighChong4;//2 1111 0 �� 0 1111 2 ��4_1
	}

	if (count == 3) {

		int leftCutExpFlag1 = ChessFlagTmp[leftCutPos - 1];
		int	rightCutExpFlag1 = ChessFlagTmp[rightCutPos + 1];//�Ͽ�λ��������չһ�����ӵı�־��¼

		if (leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag)
			return DoubleChong4;// 10 111 01 ˫��4_1

		if (leftCutFlag == 0 && leftCutExpFlag1 == currentFlag || rightCutFlag == 0 && rightCutExpFlag1 == currentFlag)
			return LowChong4;//10 111��111 01  ��4_2

		if (leftCutFlag == 0 && rightCutFlag == 0)//�����߶������ӵ������
			if (leftCutExpFlag1 == 0 || rightCutExpFlag1 == 0)//ֻҪ��һ����ⲿ������
				return Huo3;// 00 111 0 �� 0 111 00  ��3

		if ((leftCutFlag == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == 0) ||
			(rightCutFlag == opponentFlag && leftCutFlag == 0 && leftCutExpFlag1 == 0))
			return Mian3;//2 111 00 �� 00 111 2 ��3_1

		if (leftCutFlag == 0 && leftCutExpFlag1 == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == opponentFlag)
			return Mian3;//20 111 02 ��3_6

	}

	if (count == 2) {

		int leftCutExpFlag1 = ChessFlagTmp[leftCutPos - 1];
		int	rightCutExpFlag1 = ChessFlagTmp[rightCutPos + 1];//�Ͽ�λ��������չһ�����ӵı�־��¼
		int leftCutExpFlag2 = ChessFlagTmp[leftCutPos - 2];
		int	rightCutExpFlag2 = ChessFlagTmp[rightCutPos + 2];//�Ͽ�λ��������չ�������ӵı�־��¼
		
		if (rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag &&
			leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag)
			return DoubleChong4;//110 11 011  ˫��4_2

		if ((rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag) ||
			(leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag))
			return LowChong4;//110 11 �� 11 011  ��4_3

		if ((rightCutFlag == 0 && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == 0) ||
			(leftCutFlag == 0 && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == 0))
			return Tiao3;//010 11 0 �� 0 11 010 ��3

		if ((rightCutFlag == opponentFlag && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == 0) ||
			(leftCutFlag == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == 0))
			return Mian3;//2 11 010 �� 010 11 2 ��3_2

		if ((rightCutFlag == 0 && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == opponentFlag) ||
			(leftCutFlag == 0 && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == opponentFlag))
			return Mian3;//0 11 012 �� 210 11 0 ��3_3

		if ((rightCutFlag == 0 && rightCutExpFlag1 == 0 && rightCutExpFlag2 == currentFlag) ||
			(leftCutFlag == 0 && leftCutExpFlag1 == 0 && leftCutExpFlag2 == currentFlag))
			return Mian3;// 11 001 �� 100 11 ��3_4

		if (rightCutFlag == 0 && rightCutExpFlag1 == 0 && leftCutFlag == 0 && leftCutExpFlag1 == 0)
			return Huo2;//00 11 00 ��2_1

		if ((rightCutFlag == opponentFlag && leftCutFlag == 0 && leftCutExpFlag1 == 0 && leftCutExpFlag2 == 0) ||
			(leftCutFlag == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == 0 && rightCutExpFlag2 == 0))
			return Mian2;//000 11 2 �� 2 11 000 ��2_1

	}

	if (count == 1) {

		int leftCutExpFlag1 = ChessFlagTmp[leftCutPos - 1];
		int	rightCutExpFlag1 = ChessFlagTmp[rightCutPos + 1];//�Ͽ�λ��������չһ�����ӵı�־��¼
		int leftCutExpFlag2 = ChessFlagTmp[leftCutPos - 2];
		int	rightCutExpFlag2 = ChessFlagTmp[rightCutPos + 2];//�Ͽ�λ��������չ�������ӵı�־��¼
		int leftCutExpFlag3 = ChessFlagTmp[leftCutPos - 3];
		int	rightCutExpFlag3 = ChessFlagTmp[rightCutPos + 3];//�Ͽ�λ��������չ�������ӵı�־��¼

		if (leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == currentFlag &&
			rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == currentFlag)
			return DoubleChong4;// 1110 1 01111  ˫��4_3

		if (leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == currentFlag)
			return LowChong4;//1110 1 ��4_2
		if (rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == currentFlag)
			return LowChong4;//1 0111 ��4_2

		if (leftCutFlag == 0 && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == 0)
			return Tiao3;//0 1 0110 ��3
		if (rightCutFlag == 0 && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == 0)
			return Tiao3;//0110 1 0 ��3

		if (leftCutFlag == 0 && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == opponentFlag)
			return Mian3;//0 1 0112 ��3_2
		if (rightCutFlag == 0 && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == opponentFlag)
			return Mian3;//2110 1 0 ��3_2

		if (leftCutFlag == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == 0)
			return Mian3;//2 1 0110 ��3_3
		if (rightCutFlag == opponentFlag && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == 0)
			return Mian3;//0110 1 2 ��3_3

		if (leftCutFlag == 0 && leftCutExpFlag1 == 0 && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == currentFlag)
			return Mian3;//1100 1 ��3_4
		if (rightCutFlag == 0 && rightCutExpFlag1 == 0 && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == currentFlag)
			return Mian3;//1 0011 ��3_4

		if (leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag)
			return Mian3;// 10 1 01 ��3_5
		if (leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == 0 && leftCutExpFlag3 == currentFlag)
			return Mian3;//1010 1 ��3_5
		if (rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == 0 && rightCutExpFlag3 == currentFlag)
			return Mian3;//1 0101 ��3_5

		if (leftCutFlag == 0 && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == 0)
			return Tiao2;//0 1 010 ��2_1
		if (rightCutFlag == 0 && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == 0)
			return Tiao2;//010 1 0 ��2_1

		if (leftCutFlag == 0 && rightCutFlag == 0 && rightCutExpFlag1 == 0 && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == 0)
			return Tiao2;// 0 1 0010 ��2_2
		if (rightCutFlag == 0 && leftCutFlag == 0 && leftCutExpFlag1 == 0 && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == 0)
			return Tiao2;//0100 1 0  ��2_2

		if (leftCutFlag == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == 0 && rightCutExpFlag3 == 0)
			return Mian2;//2 1 0100 ��2_2
		if (rightCutFlag == opponentFlag && leftCutFlag == 0 && leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == 0 && leftCutExpFlag3 == 0)
			return Mian2;//0010 1 2 ��2_2

		if (leftCutFlag == opponentFlag && rightCutFlag == 0 && rightCutExpFlag1 == 0 && rightCutExpFlag2 == currentFlag && rightCutExpFlag3 == 0)
			return Mian2;//2 1 0010 ��2_3
		if (rightCutFlag == opponentFlag && leftCutFlag == 0 && leftCutExpFlag1 == 0 && leftCutExpFlag2 == currentFlag && leftCutExpFlag3 == 0)
			return Mian2;//0100 1 2 ��2_3

		if (leftCutFlag == 0 && leftCutExpFlag1 == 0 && leftCutExpFlag2 == 0 && leftCutExpFlag3 == currentFlag)
			return Mian2;//1000 1 ��2_4
		if (rightCutFlag == 0 && rightCutExpFlag1 == 0 && rightCutExpFlag2 == 0 && rightCutExpFlag3 == currentFlag)
			return Mian2;//1 0001 ��2_4

	}

	return 0;
}

void Rule::ChessArrange(ChessBoard &chessboard, Chess &currentChess, int direction, int ChessFlagTmp[9]) {
																										
	int currentRow = currentChess.getRow();
	int currentCol = currentChess.getCol();//��õ�ǰ��������

	int currentFlag, opponentFlag;//���ӱ�־��Ϣ  0�����ӣ�1���壬2����	
	if (!currentChess.getColour()) {//����Ǻ���
		currentFlag = 1;
		opponentFlag = 2;
	}
	else {
		currentFlag = 2;
		opponentFlag = 1;
	}

	ChessFlagTmp[4] = currentFlag;
	switch (direction) {
	case 0://�� �� ��

		for (int i = currentRow, j = 1; j <= 4; j++) {//��ǰλ������������������������ɶԷ���ɫ
			int col = currentCol - j;
			if (col < 0) {
				while (j <= 4) {
					ChessFlagTmp[4 - j] = opponentFlag;
					j++;
				}
				break;
			}
			ChessFlagTmp[4 - j] = chessboard.getFlag(i, col);//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���
		}
		for (int i = currentRow, j = 1; j <= 4; j++) {//��ǰλ���ұ��������������������ɶԷ���ɫ
			int col = currentCol + j;
			if (col > 14) {
				while (j <= 4) {
					ChessFlagTmp[4 + j] = opponentFlag;
					j++;
				}
				break;
			}
			ChessFlagTmp[4 + j] = chessboard.getFlag(i, col);//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���
		}
		break;

	case 1://�� �� ��

		for (int i = 1, j = currentCol; i <= 4; i++) {//��ǰλ���ϱ��������������������ɶԷ���ɫ
			int row = currentRow - i;
			if (row < 0) {
				while (i <= 4) {
					ChessFlagTmp[4 - i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 - i] = chessboard.getFlag(row, j);//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���	
		}
		for (int i = 1, j = currentCol; i <= 4; i++) {//��ǰλ���ϱ��������������������ɶԷ���ɫ
			int row = currentRow + i;
			if (row > 14) {
				while (i <= 4) {
					ChessFlagTmp[4 + i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 + i] = chessboard.getFlag(row, j);//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���
		}
		break;
	
	case 2://���� �� ����
		for (int i = 1, j = 1; i <= 4; i++, j++) {//��ǰλ�����ϱ��������������������ɶԷ���ɫ
			int row = currentRow - i;
			int col = currentCol - j;
			if (row < 0 || col < 0) {//����һ������
				while (i <= 4) {
					ChessFlagTmp[4 - i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 - i] = chessboard.getFlag(row, col);//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���
		}
		for (int i = 1, j = 1; i <= 4; i++, j++) {//��ǰλ�����±��������������������ɶԷ���ɫ
			int row = currentRow + i;
			int col = currentCol + j;
			if (row > 14 || col > 14) {//����һ������
				while (i <= 4) {
					ChessFlagTmp[4 + i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 + i] = chessboard.getFlag(row, col);//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���
		}
		break;

	case 3://���� �� ����
		for (int i = 1, j = 1; i <= 4; i++, j++) {//��ǰλ�����ϱ��������������������ɶԷ���ɫ
			int row = currentRow - i;
			int col = currentCol + j;
			if (row < 0 || col > 14) {//����һ������
				while (i <= 4) {
					ChessFlagTmp[4 - i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 - i] = chessboard.getFlag(row, col);//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���
		}
		for (int i = 1, j = 1; i <= 4; i++, j++) {//��ǰλ�����±��������������������ɶԷ���ɫ
			int row = currentRow + i;
			int col = currentCol - j;
			if (row > 14 || col < 0) {//����һ������
				while (i <= 4) {
					ChessFlagTmp[4 + i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 + i] = chessboard.getFlag(row, col);//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���
		}
		break;

	default:
		break;
	}

}

int Rule::ChessTypeGet(ChessBoard &chessboard, Chess &currentChess,int direction) {

	int ChessType;//����
	int ChessFlagTmp[9] = { 0 };//ĳһ������������ݴ�

	ChessArrange(chessboard, currentChess, direction, ChessFlagTmp);//��ĳһ���������������Ϊ���ʸ�ʽ
	ChessType = ChessTypeJudge(ChessFlagTmp);

	return ChessType;
}

int Rule::forbiddenTypeJudge(ChessBoard &chessboard, Chess &currentChess) {

	int ChessType;//����

	int ChangLianNum = 0;
	int Lian5Num = 0;
	int Huo4Num = 0;
	int DoubleChong4Num = 0;
	int HighChong4Num = 0;
	int LowChong4Num = 0;
	int Huo3Num = 0;
	int Tiao3Num = 0;

	for (int direction = 0; direction < 4; direction++) {
		ChessType = ChessTypeGet(chessboard, currentChess, direction);// ���ͻ�ú���
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
		return 0;//���������壬�򲻿��ǽ��ֵ�Ӱ��

	if (ChangLianNum >= 1) {
		return 3;//��������
	}

	if (DoubleChong4Num >= 1) {
		return 2;//˫4���� ͬһ�����γ�˫�Ľ���
	}

	if (Huo4Num + LowChong4Num + HighChong4Num >= 2) {
		return 2;//˫4���� ��ͬ�����γ�˫�Ľ���
	}

	if (Huo3Num + Tiao3Num>= 2) {
		return 1;//˫��3����
	}

	return 0;

}

int Rule::isFive(ChessBoard &chessboard,Chess &currentChess) {//colour����0 ��1  flag����1 ��2

	int count;//������

	int currentRow = currentChess.getRow();
	int currentCol = currentChess.getCol();

	int currentFlag;//��ǰ���ӵı�־��Ϣ
	if (!currentChess.getColour()) {//����Ǻ���
		currentFlag = 1;
	}
	else
		currentFlag = 2;

	int i, j;
	int rowmin, rowmax;
	int colmin, colmax;

	count = 0;//�������
	colmin = currentCol - 4 < 0 ? 0 : currentCol - 4;
	colmax = currentCol + 4 > 14 ? 14 : currentCol + 4;//�߽�����
	for (i = currentRow, j = colmin; j <= colmax; j++) {
		if (chessboard.getFlag(i, j) == currentFlag){
			count++;
			if (count == 5)
				return 1;
		}
		else
			count = 0;			
	}

	count = 0;//�������
	rowmin = currentRow - 4 < 0 ? 0 : currentRow - 4;
	rowmax = currentRow + 4 > 14 ? 14 : currentRow + 4;//�߽�����
	for (i = rowmin, j = currentCol; i <= rowmax; i++) {
		if (chessboard.getFlag(i, j) == currentFlag) {
			count++;
			if (count == 5)
				return 1;
		}
		else
			count = 0;
	}

	count = 0;//���ϵ�����
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
	}//���ϽǱ߽�����
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
	}//���½Ǳ߽�����
	for (i = rowmin, j = colmin; i <= rowmax, j <= colmax; i++, j++) {//�����ϵ����±���
		if (chessboard.getFlag(i, j) == currentFlag) {
			count++;
			if (count == 5)
				return 1;
		}
		else
			count = 0;
	}

	count = 0;//���ϵ�����
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
	}//���ϽǱ߽�����
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
	}//���½Ǳ߽�����
	for (i = rowmin, j = colmax; i <= rowmax, j >= colmin; i++, j--) {//�����ϵ����±���
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