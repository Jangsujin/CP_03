#include <stdio.h>
#include <stdlib.h>

#define BLANK  ' ' // BLANK�� ' '�� �Ѵٰ� ������

void main() {
	int x = 0, y = 0, turn = 0; // ��ǥ�� ������ x,y ������ ����Ƚ���� ������ turn ���� �ʱ�ȭ
	int mode; // �Է¹��� ��带 ������ ���� mode
	char board[3][3]; // ������ ũ��
	for (x = 0; x < 3; x++) {
		for (y = 0; y < 3; y++) {
			board[x][y] = BLANK;
		}
	}
	// board�� ��� BLANK�� �ʱ�ȭ
	printf("LET'S START TIC-TAC-TOE GAME\n");
	printf("Play with Friend : 1\n");
	printf("Play with Computer : 2\n");
	// ���� ���� �ȳ�
	printf("Select Game Mode >> ");
	scanf_s("%d", &mode);
	// ��� �Է� ����
	system("cls"); // ȭ�� û��
	if (mode == 1) { // mode 1�� �Է¹��� ���
		printf("x|y[0]|[1]|[2]\n");
		for (int a = 0; a < 3; a++) {
			printf("   ---|---|---\n");
			printf("[%d]   |   |   \n", a);
		}
		printf("   ---|---|---\n");
		// ���� ���
		do {
			printf("turn %d\n", turn); // �� ��° turn���� ���
			do {
				printf("Player1's turn (x y) : "); // Player1�� �Է� �ȳ���
				scanf_s("%d %d", &x, &y); // �Է¹���
				if (board[x][y] != BLANK || (x > 2 || y > 2)) {
					// �Է¹��� ���� ��ǥ�� �̹� �Է¹޾Ҵ� ��ǥ��� Ȥ�� �迭�� �Ѿ�� ��ǥ���
					printf("Wrong Position\n"); // �߸��� ��ǥ���� �˷��ִ� �ȳ��� ���
				}
			} while (board[x][y] != BLANK || (x > 2 || y > 2));
			// BLANK�� �ƴϸ� �̹� �Է��� ���� �ڸ���� �ǹ�, �� ��ǥ���� 2���� ũ�ٸ� �迭�� �Ѿ�� �ڸ���� �ǹ��̹Ƿ� ����� �� �Է��� ���� ������ �ݺ�
			board[x][y] = 'O'; // do-while ���� �������� �� �� �ڸ��� O�� ����.
			printf("x|y[0]|[1]|[2]\n");
			for (int a = 0; a < 3; a++) {
				y = 0; // ���� ����� ���� �ϱ� ���� y�� 0���� ��.
				printf("   ---|---|---\n");
				printf("[%d] %c | %c | %c \n", a, board[a][y], board[a][y + 1], board[a][y + 2]);
			}
			printf("   ---|---|---\n");
			// �Է��� �޾����Ƿ� board �� �� ���

			if ((board[0][0] == 'O'&board[0][1] == 'O' & board[0][2] == 'O') | (board[1][0] == 'O'&board[1][1] == 'O' & board[1][2] == 'O') | (board[2][0] == 'O'&board[2][1] == 'O' & board[2][2] == 'O')
				| (board[0][0] == 'O'&board[1][0] == 'O' & board[2][0] == 'O') | (board[0][1] == 'O'&board[1][1] == 'O' & board[2][1] == 'O') | (board[0][2] == 'O'&board[1][2] == 'O' & board[2][2] == 'O')
				| (board[0][0] == 'O'&board[1][1] == 'O' & board[2][2] == 'O') | (board[2][0] == 'O'&board[1][1] == 'O' & board[0][2] == 'O')) {
				// �� ���ǵ��� �̱� �� �ִ� ���ǵ� 8������ ��� ��Ƴ��� ��. �̸� ������ ���
				printf("Player1 Win!\n"); // Player1�� �¸����� ����ϰ�
				break; // ���� ����
			}
			if (turn >= 4) {
				printf("Draw!\n");
				// ĭ�� 9���̹Ƿ� turn�� 4�̻��ε� Player1�� �Է¿��� ������ ������ �ʾҴٸ�, draw�� ����ϰ�
				break; // ���� ����
			}
			do {
				printf("Player2's turn (x y) : "); // Player2�� �Է� �ȳ���
				scanf_s("%d %d", &x, &y); // �Է¹���
				if (board[x][y] != BLANK || (x > 2 || y > 2)) {
					// �Է¹��� ���� ��ǥ�� �̹� �Է¹޾Ҵ� ��ǥ��� Ȥ�� �迭�� �Ѿ�� ��ǥ���
					printf("Wrong Position\n"); // �߸��� ��ǥ���� �˷��ִ� �ȳ��� ���
				}
			} while (board[x][y] != BLANK ||(x>2 || y>2));
			// BLANK�� �ƴϸ� �̹� �Է��� ���� �ڸ���� �ǹ�, �� ��ǥ���� 2���� ũ�ٸ� �迭�� �Ѿ�� �ڸ���� �ǹ��̹Ƿ� ����� �� �Է��� ���� ������ �ݺ�
			board[x][y] = 'X'; // do-while ���� �������� �� �� �ڸ��� X�� ����.
			system("cls"); // ȭ���� ���� ���ϰ� �ϱ� ���� û��
			printf("x|y[0]|[1]|[2]\n");
			for (int a = 0; a < 3; a++) {
				y = 0; // ���� ����� ���� �ϱ� ���� y�� 0���� ��.
				printf("   ---|---|---\n");
				printf("[%d] %c | %c | %c \n", a, board[a][y], board[a][y + 1], board[a][y + 2]);
			}
			printf("   ---|---|---\n");
			// �Է��� �޾����Ƿ� board �� �� ���

			if ((board[0][0] == 'X'&board[0][1] == 'X' & board[0][2] == 'X') | (board[1][0] == 'X'&board[1][1] == 'X' & board[1][2] == 'X') | (board[2][0] == 'X'&board[2][1] == 'X' & board[2][2] == 'X')
				| (board[0][0] == 'X'&board[1][0] == 'X' & board[2][0] == 'X') | (board[0][1] == 'X'&board[1][1] == 'X' & board[2][1] == 'X') | (board[0][2] == 'X'&board[1][2] == 'X' & board[2][2] == 'X')
				| (board[0][0] == 'X'&board[1][1] == 'X' & board[2][2] == 'X') | (board[2][0] == 'X'&board[1][1] == 'X' & board[0][2] == 'X')) {
				// �� ���ǵ��� �̱� �� �ִ� ���ǵ� 8������ ��� ��Ƴ��� ��. �̸� ������ ���
				printf("Player2 Win!\n"); // Player2�� �¸����� ����ϰ�
				break; // ���� ����
			}
			turn++; // turn�� 1ȸ ������Ŵ
		} while (1); // break�� �ɸ��� ������ ���ѹݺ�
	}
	else if (mode == 2) { // mode 2�� �Է¹��� ���
		printf("x|y[0]|[1]|[2]\n");
		for (int a = 0; a < 3; a++) {
			printf("   ---|---|---\n");
			printf("[%d]   |   |   \n", a);
		}
		printf("   ---|---|---\n");
		// ���� ���
		do {
			printf("turn %d\n", turn); // �� ��° turn���� ���
			do {
				printf("Player1's turn (x y) : "); // Player1�� �Է� �ȳ���
				scanf_s("%d %d", &x, &y); // �Է¹���
				if (board[x][y] != BLANK || (x > 2 || y > 2)) {
					// �Է¹��� ���� ��ǥ�� �̹� �Է¹޾Ҵ� ��ǥ��� Ȥ�� �迭�� �Ѿ�� ��ǥ���
					printf("Wrong Position\n"); // �߸��� ��ǥ���� �˷��ִ� �ȳ��� ���
				}
			} while (board[x][y] != BLANK || (x > 2 || y > 2));
			// BLANK�� �ƴϸ� �̹� �Է��� ���� �ڸ���� �ǹ�, �� ��ǥ���� 2���� ũ�ٸ� �迭�� �Ѿ�� �ڸ���� �ǹ��̹Ƿ� ����� �� �Է��� ���� ������ �ݺ�
			board[x][y] = 'O'; // do-while ���� �������� �� �� �ڸ��� O�� ����.
			printf("x|y[0]|[1]|[2]\n");
			for (int a = 0; a < 3; a++) {
				y = 0; // ���� ����� ���� �ϱ� ���� y�� 0���� ��.
				printf("   ---|---|---\n");
				printf("[%d] %c | %c | %c \n", a, board[a][y], board[a][y + 1], board[a][y + 2]);
			}
			printf("   ---|---|---\n");
			// �Է��� �޾����Ƿ� board �� �� ���

			if ((board[0][0] == 'O'&board[0][1] == 'O' & board[0][2] == 'O') | (board[1][0] == 'O'&board[1][1] == 'O' & board[1][2] == 'O') | (board[2][0] == 'O'&board[2][1] == 'O' & board[2][2] == 'O')
				| (board[0][0] == 'O'&board[1][0] == 'O' & board[2][0] == 'O') | (board[0][1] == 'O'&board[1][1] == 'O' & board[2][1] == 'O') | (board[0][2] == 'O'&board[1][2] == 'O' & board[2][2] == 'O')
				| (board[0][0] == 'O'&board[1][1] == 'O' & board[2][2] == 'O') | (board[2][0] == 'O'&board[1][1] == 'O' & board[0][2] == 'O')) {
				// �� ���ǵ��� �̱� �� �ִ� ���ǵ� 8������ ��� ��Ƴ��� ��. �̸� ������ ���
				printf("Player1 Win!\n"); // Player1�� �¸����� ����ϰ�
				break; // ���� ����
			}
			if (turn >= 4) {
				printf("Draw!\n");
				// ĭ�� 9���̹Ƿ� turn�� 4�̻��ε� Player1�� �Է¿��� ������ ������ �ʾҴٸ�, draw�� ����ϰ�
				break; // ���� ����
			}
			printf("Computer's turn\n"); // ��ǻ���� �Է�
			do {
				x = rand() % 4;
				y = rand() % 4;
				// ��ǥ�� 0-3 ���� ���� ���ڿ��� �ϹǷ� 4�� ���� ������ ���� �̿�
			} while (board[x][y] != BLANK || (x > 2 || y > 2));
			// BLANK�� �ƴϸ� �̹� �Է��� ���� �ڸ���� �ǹ�, �� ��ǥ���� 2���� ũ�ٸ� �迭�� �Ѿ�� �ڸ���� �ǹ��̹Ƿ� ����� �� ��ǥ ������ ������ �ݺ�
			board[x][y] = 'X'; // do-while ���� �������� �� �� �ڸ��� X�� ����.
			system("cls"); // ȭ���� ���� ���ϰ� �ϱ� ���� û��
			printf("x|y[0]|[1]|[2]\n");
			for (int a = 0; a < 3; a++) {
				y = 0; // ���� ����� ���� �ϱ� ���� y�� 0���� ��.
				printf("   ---|---|---\n");
				printf("[%d] %c | %c | %c \n", a, board[a][y], board[a][y + 1], board[a][y + 2]);
			}
			printf("   ---|---|---\n");
			// �Է��� �޾����Ƿ� board �� �� ���

			if ((board[0][0] == 'X'&board[0][1] == 'X' & board[0][2] == 'X') | (board[1][0] == 'X'&board[1][1] == 'X' & board[1][2] == 'X') | (board[2][0] == 'X'&board[2][1] == 'X' & board[2][2] == 'X')
				| (board[0][0] == 'X'&board[1][0] == 'X' & board[2][0] == 'X') | (board[0][1] == 'X'&board[1][1] == 'X' & board[2][1] == 'X') | (board[0][2] == 'X'&board[1][2] == 'X' & board[2][2] == 'X')
				| (board[0][0] == 'X'&board[1][1] == 'X' & board[2][2] == 'X') | (board[2][0] == 'X'&board[1][1] == 'X' & board[0][2] == 'X')) {
				// �� ���ǵ��� �̱� �� �ִ� ���ǵ� 8������ ��� ��Ƴ��� ��. �̸� ������ ���
				printf("Computer Win!\n"); // Computer�� �¸����� ����ϰ�
				break; // ���� ����
			}
			turn++; // turn�� 1ȸ ������Ŵ
		} while (1); // break�� �ɸ��� ������ ���ѹݺ�
	}
	else {
		// mode�� 1,2 �� �� �ƴ� ���
		printf("Quit\n"); // ���� ���� ���� ����
	}
}