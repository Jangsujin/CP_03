#include <stdio.h>

int check_data(int, int, int); // check_data 함수 선언

int main() {
	int year, month, day; // 입력받은 연, 월, 일 을 저장할 변수
	int check; // check_data로부터 반환받는 정수를 저장할 변수 check
	do {
		printf("날짜를 연 월 일 순으로 입력해주세요 (0 0 0 입력시 종료) : ");
		// 연 월 일 입력 안내문
		scanf_s("%d %d %d", &year, &month, &day); // 입력
		check = check_data(year, month, day);
		// 함수로부터 반환되는 값을 check 변수에 넣음.
		if ((year == 0 && month == 0 && day == 0)) {
			break;
			// year, month, day가 모두 0일 경우 break
		}
		if (check) {
			// 만약 유효한 날짜를 입력받았다면
			printf("유효한 날짜이므로 종료합니다.\n"); // 유효한 날짜이므로 종료한다는 것을 출력함.
		}
	} while (check==0); // check가 0일 경우에 계속 반복
}

int check_data(int year, int month, int day) {
	// 입력받은 연 월 일이 유효한 날짜인지를 검사하는 함수
	if (year <= 0) {
		return 0; // year이 0보다 작다면 유효하지 않음
	}
	else if (0 >= month || month >= 13) {
		return 0;
		// month가 0보다 작거나, 13보다 큰 경우에는 유효하지 않음
	}
	else {
		switch (month) {
		case 1 : case 3 : case 5 : case 7 : case 8 :
		case 10 : case 12:
			// 1, 3, 5, 7, 8, 10, 12월의 경우에는 일이 1-31일까지 있으므로
			if (day < 1 || day > 31) {
				return 0;
				// day가 0보다 작거나, 31보다 큰 경우에는 유효하지 않음
			}
			else {
				return 1;
				// 위의 경우가 아니라면 유효하므로 1 반환
			}
		case 2:
			// 2월의 경우
			if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0) {
				// 윤년일 때는 29일까지 있으므로
				if (day < 1 || day > 29) {
					return 0;
					// day가 0보다 작거나, 29보다 큰 경우에는 유효하지 않음
				}
				else {
					return 1;
					// 위의 경우가 아니라면 유효하므로 1 반환
				}
			}
			else {
				// 윤년이 아닐 경우
				if (day < 1 || day > 28) {
					return 0;
					// day가 0보다 작거나, 28보다 큰 경우에는 유효하지 않음
				}
				else {
					return 1;
					// 위의 경우가 아니라면 유효하므로 1 반환
				}
			}
		case 4 : case 6 : case 9 : case 11:
			// 4, 6, 9, 11월의 경우에는 1-30일까지 있으므로
			if (day < 1 || day > 30) {
				return 0;
				// day가 1보다 작거나, 30보다 큰 경우에는 유효하지 않음
			}
			else {
				return 1;
				// 위의 경우가 아니라면 유효하므로 1 반환
			}
		}
	}
}