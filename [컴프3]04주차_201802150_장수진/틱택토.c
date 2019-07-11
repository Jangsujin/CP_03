#include <stdio.h>
#include <stdlib.h>

#define BLANK  ' ' // BLANK를 ' '로 한다고 정의함

void main() {
	int x = 0, y = 0, turn = 0; // 좌표를 저장할 x,y 변수와 실행횟수를 저장할 turn 변수 초기화
	int mode; // 입력받을 모드를 저장할 변수 mode
	char board[3][3]; // 보드의 크기
	for (x = 0; x < 3; x++) {
		for (y = 0; y < 3; y++) {
			board[x][y] = BLANK;
		}
	}
	// board를 모두 BLANK로 초기화
	printf("LET'S START TIC-TAC-TOE GAME\n");
	printf("Play with Friend : 1\n");
	printf("Play with Computer : 2\n");
	// 게임 시작 안내
	printf("Select Game Mode >> ");
	scanf_s("%d", &mode);
	// 모드 입력 받음
	system("cls"); // 화면 청소
	if (mode == 1) { // mode 1을 입력받을 경우
		printf("x|y[0]|[1]|[2]\n");
		for (int a = 0; a < 3; a++) {
			printf("   ---|---|---\n");
			printf("[%d]   |   |   \n", a);
		}
		printf("   ---|---|---\n");
		// 보드 출력
		do {
			printf("turn %d\n", turn); // 몇 번째 turn인지 출력
			do {
				printf("Player1's turn (x y) : "); // Player1의 입력 안내문
				scanf_s("%d %d", &x, &y); // 입력받음
				if (board[x][y] != BLANK || (x > 2 || y > 2)) {
					// 입력받은 값의 좌표가 이미 입력받았던 좌표라면 혹은 배열을 넘어가는 좌표라면
					printf("Wrong Position\n"); // 잘못된 좌표임을 알려주는 안내문 출력
				}
			} while (board[x][y] != BLANK || (x > 2 || y > 2));
			// BLANK가 아니면 이미 입력을 받은 자리라는 의미, 각 좌표값이 2보다 크다면 배열을 넘어가는 자리라는 의미이므로 제대로 된 입력을 받을 때까지 반복
			board[x][y] = 'O'; // do-while 문을 빠져나온 후 그 자리에 O를 넣음.
			printf("x|y[0]|[1]|[2]\n");
			for (int a = 0; a < 3; a++) {
				y = 0; // 보드 출력을 쉽게 하기 위해 y를 0으로 함.
				printf("   ---|---|---\n");
				printf("[%d] %c | %c | %c \n", a, board[a][y], board[a][y + 1], board[a][y + 2]);
			}
			printf("   ---|---|---\n");
			// 입력을 받았으므로 board 한 번 출력

			if ((board[0][0] == 'O'&board[0][1] == 'O' & board[0][2] == 'O') | (board[1][0] == 'O'&board[1][1] == 'O' & board[1][2] == 'O') | (board[2][0] == 'O'&board[2][1] == 'O' & board[2][2] == 'O')
				| (board[0][0] == 'O'&board[1][0] == 'O' & board[2][0] == 'O') | (board[0][1] == 'O'&board[1][1] == 'O' & board[2][1] == 'O') | (board[0][2] == 'O'&board[1][2] == 'O' & board[2][2] == 'O')
				| (board[0][0] == 'O'&board[1][1] == 'O' & board[2][2] == 'O') | (board[2][0] == 'O'&board[1][1] == 'O' & board[0][2] == 'O')) {
				// 위 조건들은 이길 수 있는 조건들 8가지를 모두 모아놓은 것. 이를 만족할 경우
				printf("Player1 Win!\n"); // Player1의 승리임을 출력하고
				break; // 게임 종료
			}
			if (turn >= 4) {
				printf("Draw!\n");
				// 칸이 9개이므로 turn이 4이상인데 Player1의 입력에도 게임이 끝나지 않았다면, draw를 출력하고
				break; // 게임 종료
			}
			do {
				printf("Player2's turn (x y) : "); // Player2의 입력 안내문
				scanf_s("%d %d", &x, &y); // 입력받음
				if (board[x][y] != BLANK || (x > 2 || y > 2)) {
					// 입력받은 값의 좌표가 이미 입력받았던 좌표라면 혹은 배열을 넘어가는 좌표라면
					printf("Wrong Position\n"); // 잘못된 좌표임을 알려주는 안내문 출력
				}
			} while (board[x][y] != BLANK ||(x>2 || y>2));
			// BLANK가 아니면 이미 입력을 받은 자리라는 의미, 각 좌표값이 2보다 크다면 배열을 넘어가는 자리라는 의미이므로 제대로 된 입력을 받을 때까지 반복
			board[x][y] = 'X'; // do-while 문을 빠져나온 후 그 자리에 X를 넣음.
			system("cls"); // 화면을 보기 편하게 하기 위해 청소
			printf("x|y[0]|[1]|[2]\n");
			for (int a = 0; a < 3; a++) {
				y = 0; // 보드 출력을 쉽게 하기 위해 y를 0으로 함.
				printf("   ---|---|---\n");
				printf("[%d] %c | %c | %c \n", a, board[a][y], board[a][y + 1], board[a][y + 2]);
			}
			printf("   ---|---|---\n");
			// 입력을 받았으므로 board 한 번 출력

			if ((board[0][0] == 'X'&board[0][1] == 'X' & board[0][2] == 'X') | (board[1][0] == 'X'&board[1][1] == 'X' & board[1][2] == 'X') | (board[2][0] == 'X'&board[2][1] == 'X' & board[2][2] == 'X')
				| (board[0][0] == 'X'&board[1][0] == 'X' & board[2][0] == 'X') | (board[0][1] == 'X'&board[1][1] == 'X' & board[2][1] == 'X') | (board[0][2] == 'X'&board[1][2] == 'X' & board[2][2] == 'X')
				| (board[0][0] == 'X'&board[1][1] == 'X' & board[2][2] == 'X') | (board[2][0] == 'X'&board[1][1] == 'X' & board[0][2] == 'X')) {
				// 위 조건들은 이길 수 있는 조건들 8가지를 모두 모아놓은 것. 이를 만족할 경우
				printf("Player2 Win!\n"); // Player2의 승리임을 출력하고
				break; // 게임 종료
			}
			turn++; // turn을 1회 증가시킴
		} while (1); // break에 걸리기 전까지 무한반복
	}
	else if (mode == 2) { // mode 2를 입력받을 경우
		printf("x|y[0]|[1]|[2]\n");
		for (int a = 0; a < 3; a++) {
			printf("   ---|---|---\n");
			printf("[%d]   |   |   \n", a);
		}
		printf("   ---|---|---\n");
		// 보드 출력
		do {
			printf("turn %d\n", turn); // 몇 번째 turn인지 출력
			do {
				printf("Player1's turn (x y) : "); // Player1의 입력 안내문
				scanf_s("%d %d", &x, &y); // 입력받음
				if (board[x][y] != BLANK || (x > 2 || y > 2)) {
					// 입력받은 값의 좌표가 이미 입력받았던 좌표라면 혹은 배열을 넘어가는 좌표라면
					printf("Wrong Position\n"); // 잘못된 좌표임을 알려주는 안내문 출력
				}
			} while (board[x][y] != BLANK || (x > 2 || y > 2));
			// BLANK가 아니면 이미 입력을 받은 자리라는 의미, 각 좌표값이 2보다 크다면 배열을 넘어가는 자리라는 의미이므로 제대로 된 입력을 받을 때까지 반복
			board[x][y] = 'O'; // do-while 문을 빠져나온 후 그 자리에 O를 넣음.
			printf("x|y[0]|[1]|[2]\n");
			for (int a = 0; a < 3; a++) {
				y = 0; // 보드 출력을 쉽게 하기 위해 y를 0으로 함.
				printf("   ---|---|---\n");
				printf("[%d] %c | %c | %c \n", a, board[a][y], board[a][y + 1], board[a][y + 2]);
			}
			printf("   ---|---|---\n");
			// 입력을 받았으므로 board 한 번 출력

			if ((board[0][0] == 'O'&board[0][1] == 'O' & board[0][2] == 'O') | (board[1][0] == 'O'&board[1][1] == 'O' & board[1][2] == 'O') | (board[2][0] == 'O'&board[2][1] == 'O' & board[2][2] == 'O')
				| (board[0][0] == 'O'&board[1][0] == 'O' & board[2][0] == 'O') | (board[0][1] == 'O'&board[1][1] == 'O' & board[2][1] == 'O') | (board[0][2] == 'O'&board[1][2] == 'O' & board[2][2] == 'O')
				| (board[0][0] == 'O'&board[1][1] == 'O' & board[2][2] == 'O') | (board[2][0] == 'O'&board[1][1] == 'O' & board[0][2] == 'O')) {
				// 위 조건들은 이길 수 있는 조건들 8가지를 모두 모아놓은 것. 이를 만족할 경우
				printf("Player1 Win!\n"); // Player1의 승리임을 출력하고
				break; // 게임 종료
			}
			if (turn >= 4) {
				printf("Draw!\n");
				// 칸이 9개이므로 turn이 4이상인데 Player1의 입력에도 게임이 끝나지 않았다면, draw를 출력하고
				break; // 게임 종료
			}
			printf("Computer's turn\n"); // 컴퓨터의 입력
			do {
				x = rand() % 4;
				y = rand() % 4;
				// 좌표는 0-3 범위 내의 숫자여야 하므로 4로 나눈 나머지 값을 이용
			} while (board[x][y] != BLANK || (x > 2 || y > 2));
			// BLANK가 아니면 이미 입력을 받은 자리라는 의미, 각 좌표값이 2보다 크다면 배열을 넘어가는 자리라는 의미이므로 제대로 된 좌표 설정할 때까지 반복
			board[x][y] = 'X'; // do-while 문을 빠져나온 후 그 자리에 X를 넣음.
			system("cls"); // 화면을 보기 편하게 하기 위해 청소
			printf("x|y[0]|[1]|[2]\n");
			for (int a = 0; a < 3; a++) {
				y = 0; // 보드 출력을 쉽게 하기 위해 y를 0으로 함.
				printf("   ---|---|---\n");
				printf("[%d] %c | %c | %c \n", a, board[a][y], board[a][y + 1], board[a][y + 2]);
			}
			printf("   ---|---|---\n");
			// 입력을 받았으므로 board 한 번 출력

			if ((board[0][0] == 'X'&board[0][1] == 'X' & board[0][2] == 'X') | (board[1][0] == 'X'&board[1][1] == 'X' & board[1][2] == 'X') | (board[2][0] == 'X'&board[2][1] == 'X' & board[2][2] == 'X')
				| (board[0][0] == 'X'&board[1][0] == 'X' & board[2][0] == 'X') | (board[0][1] == 'X'&board[1][1] == 'X' & board[2][1] == 'X') | (board[0][2] == 'X'&board[1][2] == 'X' & board[2][2] == 'X')
				| (board[0][0] == 'X'&board[1][1] == 'X' & board[2][2] == 'X') | (board[2][0] == 'X'&board[1][1] == 'X' & board[0][2] == 'X')) {
				// 위 조건들은 이길 수 있는 조건들 8가지를 모두 모아놓은 것. 이를 만족할 경우
				printf("Computer Win!\n"); // Computer의 승리임을 출력하고
				break; // 게임 종료
			}
			turn++; // turn을 1회 증가시킴
		} while (1); // break에 걸리기 전까지 무한반복
	}
	else {
		// mode가 1,2 둘 다 아닐 경우
		printf("Quit\n"); // 게임 진행 하지 않음
	}
}