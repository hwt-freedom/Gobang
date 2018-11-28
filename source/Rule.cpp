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
		return ChangLian;

	if (count == 4) {
		if (leftCutFlag == 0 && rightCutFlag == 0)
			return Huo4;
		else if (leftCutFlag == opponentFlag || rightCutFlag == opponentFlag)
			return Chong4;
	}

	if (count == 3) {

		int leftCutExpFlag1 = ChessFlagTmp[leftCutPos - 1];
		int	rightCutExpFlag1 = ChessFlagTmp[rightCutPos + 1];//�Ͽ�λ��������չһ�����ӵı�־��¼

		if (leftCutFlag == 0 && rightCutFlag == 0) {//�ضϴ���������
			if (leftCutExpFlag1 == currentFlag || rightCutExpFlag1 == currentFlag)//�ж��Ƿ��γ���4,����չһ��λ�ú�����λ��������ͬ
				return TiaoChong4;
			else if (leftCutExpFlag1 == 0 || rightCutExpFlag1 == 0)//�ж��Ƿ��γɻ�3������չһ��λ�þ�������
				return Huo3;
		}
		else if (leftCutFlag == 0 || rightCutFlag == 0) {//�ضϴ���һ��λ��������
			if (leftCutFlag == opponentFlag) {//�������Ϊ���ֵ�����
				if(rightCutExpFlag1 == currentFlag)//�ұ���չһ��λ�ú�����λ��������ͬ
					return TiaoChong4;
			}
			if (rightCutFlag == opponentFlag) {//�����ұ�Ϊ���ֵ�����
				if (leftCutExpFlag1 == currentFlag)//�����չһ��λ�ú�����λ��������ͬ
					return TiaoChong4;
			}
		}
	}

	if (count == 2) {

		int leftCutExpFlag1 = ChessFlagTmp[leftCutPos - 1];
		int	rightCutExpFlag1 = ChessFlagTmp[rightCutPos + 1];//�Ͽ�λ��������չһ�����ӵı�־��¼
		int leftCutExpFlag2 = ChessFlagTmp[leftCutPos - 2];
		int	rightCutExpFlag2 = ChessFlagTmp[rightCutPos + 2];//�Ͽ�λ��������չ�������ӵı�־��¼
		
		if (leftCutFlag == 0 && rightCutFlag == 0) {//�ضϴ���������
			if ((leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == currentFlag) ||
				(rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == currentFlag))//�Ͽ�λ��������չ�������Ӷ����Һ�����λ��������ͬ
				return TiaoChong4;

			if ((leftCutExpFlag1 == currentFlag && leftCutExpFlag2 == 0) ||
				(rightCutExpFlag1 == currentFlag && rightCutExpFlag2 == 0))
				return Tiao3;
		}
		else if (leftCutFlag == 0 || rightCutFlag == 0) {
			if (leftCutFlag == opponentFlag) {//���Ϊ���ֵ�����
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
		int	rightCutExpFlag1 = ChessFlagTmp[rightCutPos + 1];//�Ͽ�λ��������չһ�����ӵı�־��¼
		int leftCutExpFlag2 = ChessFlagTmp[leftCutPos - 2];
		int	rightCutExpFlag2 = ChessFlagTmp[rightCutPos + 2];//�Ͽ�λ��������չ�������ӵı�־��¼
		int leftCutExpFlag3 = ChessFlagTmp[leftCutPos - 3];
		int	rightCutExpFlag3 = ChessFlagTmp[rightCutPos + 3];//�Ͽ�λ��������չ�������ӵı�־��¼

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

void Rule::ChessArrange(int chessBoardFlagTmp[15][15], Chess currentChess, int direction, int ChessFlagTmp[9]) {//����д����������ߣ����÷���
	
	int currentFlag;//��ǰ���ӵı�־��Ϣ 
	int opponentFlag;//�������ӵı�־��Ϣ
	//���ӱ�־��Ϣ  0�����ӣ�1���壬2����
																											
	int currentRow = currentChess.getRow();
	int currentCol = currentChess.getCol();
	currentFlag = chessBoardFlagTmp[currentRow][currentCol];

	if (currentFlag == 1) {//���ö��ֱ�־λ������ǰ��־��ʾΪ����
		opponentFlag = 2;
	}
	else if (currentFlag == 2) {
		opponentFlag = 1;
	}

	ChessFlagTmp[4] = currentFlag;
	switch (direction) {
	case 0://����
		for (int i = currentRow, j = 1; j <= 4; j++) {//��ǰλ������������������������ɶԷ���ɫ
			int col = currentCol - j;
			if (col < 0) {
				while (j <= 4) {
					ChessFlagTmp[4 - j] = opponentFlag;
					j++;
				}
				break;
			}
			else
				ChessFlagTmp[4 - j] = chessBoardFlagTmp[i][col];//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���			
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
			else
				ChessFlagTmp[4 + j] = chessBoardFlagTmp[i][col];//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���		
		}
		break;

	case 1://����
		for (int i = 1, j = currentCol; i <= 4; i++) {//��ǰλ���ϱ��������������������ɶԷ���ɫ
			int row = currentRow - i;
			if (row < 0) {
				while (i <= 4) {
					ChessFlagTmp[4 - i] = opponentFlag;
					i++;
				}
				break;
			}
			else
				ChessFlagTmp[4 - i] = chessBoardFlagTmp[row][j];//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���			
		}
		for (int i = 1, j = currentCol; i <= 4; i++) {//��ǰλ���ϱ��������������������ɶԷ���ɫ
			int row = currentRow + i;
			if (row < 0) {
				while (i <= 4) {
					ChessFlagTmp[4 + i] = opponentFlag;
					i++;
				}
				break;
			}
			else
				ChessFlagTmp[4 + i] = chessBoardFlagTmp[row][j];//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���			
		}
		break;
	
	case 2://��������
		for (int i = 1, j = 1; i <= 4; i++, j++) {//��ǰλ�����ϱ��������������������ɶԷ���ɫ
			int row = currentRow - i;
			int col = currentCol - j;
			if (row < 0 || col <0) {//����һ������
				while (i <= 4) {
					ChessFlagTmp[4 - i] = opponentFlag;
					i++;
				}
				break;
			}
			ChessFlagTmp[4 - i] = chessBoardFlagTmp[row][col];//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���
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
			ChessFlagTmp[4 + i] = chessBoardFlagTmp[row][col];//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���
		}
		break;

	case 3://��������
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
			ChessFlagTmp[4 - i] = chessBoardFlagTmp[row][col];//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���
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
			ChessFlagTmp[4 + i] = chessBoardFlagTmp[row][col];//��û���������̱�־��Ϣ���Ƶ���Ӧλ�ü���
		}
		break;

	default:
		break;
	}

}

int Rule::ChessTypeGet(int chessBoardFlagTmp[15][15], Chess currentChess,int direction) {

	int ChessType;//����
	int ChessFlagTmp[9] = { 0 };//ĳһ������������ݴ�

	ChessArrange(chessBoardFlagTmp, currentChess, direction, ChessFlagTmp);//��ĳһ���������������Ϊ���ʸ�ʽ
	ChessType = ChessTypeJudge(ChessFlagTmp);

	return ChessType;
}

int Rule::fobiddenTypeJudge(int chessBoardFlagTmp[15][15], Chess currentChess) {

	int ChessType;//����

	int ChangLianNum = 0;
	int Huo4Num = 0;
	int Chong4Num = 0;
	int TiaoChong4Num = 0;
	int Huo3Num = 0;

	for (int direction = 0; direction < 4; direction++) {
		ChessType = ChessTypeGet(chessBoardFlagTmp, currentChess, direction);// ���ͻ�ú���
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
		return 3;//��������
	}
	else if (Huo4Num + Chong4Num + TiaoChong4Num >= 2) {
		return 2;//˫4����
	}
	else if (Huo3Num >= 2) {
		return 1;//˫��3����
	}
	return 0;

}

int Rule::isForbidden(int chessBoardFlagTmp[15][15], Chess currentChess) {

	//���ֹ��򣺻������������ж� ���������ж���Ҫ���⹹������������Rule����ʵ�ּ���
		//�����жϺ���ʵ��˼��
		//      1�����Ȼ���ĸ���������ͣ�ͬһ��������Ҫ���9�����ӣ�
						//���ж���������֮ǰ��Ҫ�Ȼ��ڵ�ǰ����λ�ô���߽��������Զ��ֵ���ɫ������䣩
	                    //������߽�����֮��Ϳ��Խ������͵��ж�
					//���������������������++
		//      2�������ݷ��ص����ͣ��жϸ�λ���Ƿ����ڽ���λ��

	int fobiddenType = 0;//��������

	fobiddenType = fobiddenTypeJudge(chessBoardFlagTmp, currentChess);
	switch (fobiddenType) {
	case 1:
		std::cout << std::endl << "*********Υ��˫��3����*********" << std::endl;
		break;
	case 2:
		std::cout << std::endl << "*********Υ��˫4����*********" << std::endl;
		break;
	case 3:
		std::cout << std::endl << "*********Υ����������*********" << std::endl;
		break;
	default:
		break;
	}

	return fobiddenType == 0 ? 0 : 1;//�����������Ϊ0����˵��û�н��֣�����0
}

int Rule::isFive(int chessBoardFlagTmp[15][15],Chess currentChess) {

	int count;//������
	int currentFlag;//��ǰ���ӵı�־��Ϣ

	int currentRow = currentChess.getRow();
	int currentCol = currentChess.getCol();
	currentFlag = chessBoardFlagTmp[currentRow][currentCol];

	int i, j;
	int rowmin, rowmax;
	int colmin, colmax;

	count = 0;//�������
	colmin = currentCol - 4 < 0 ? 0 : currentCol - 4;
	colmax = currentCol + 4 > 14 ? 14 : currentCol + 4;//�߽�����
	for (i = currentRow, j = colmin; j <= colmax; j++) {
		if (chessBoardFlagTmp[i][j] == currentFlag){
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
		if (chessBoardFlagTmp[i][j] == currentFlag) {
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
		if (chessBoardFlagTmp[i][j] == currentFlag) {
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