#include <stdio.h>
#include <string.h>

#define NOT 0 // 올바르지 못한 입력 상태
#define OK 1 // 올바른 입력 상태

void size_check(char *, int*); // 패스워드 크기 체크 함수 선언
void contain_check(char *, int *); // 숫자, 소문자, 대문자 체크 함수 선언
void contain2_check(char *, int *); // 특수문자 체크 함수 선언
void continuation_check(char *, int *); // 연속되는 문자 체크 함수 선언


int main() {
	int _check = OK; // 변수 _check를 만들고, 초기 설정은 올바른 입력 상태로 둠
	int * check = &_check; // 변수 _check의 값을 변경할 수 있도록 포인터 선언
	char password[51]; // 패스워드를 저장할 배열. 크기는 넉넉하게 함.

	printf("패스워드를 입력하세요 : ");
	scanf_s("%s", password, 50); // 패스워드를 50자까지 입력받을 수 있음
	size_check(password, check); // 패스워드 크기 체크 함수 호출
	contain_check(password, check); // 숫자, 소문자, 대문자 체크 함수 호출
	contain2_check(password, check); // 특수문자 체크 함수 호출
	continuation_check(password, check); // 연속되는 문자 체크 함수 호출

	if (*check) {
		// check가 가리키고 있는 변수의 값이 1이라면, 즉 올바른 입력 상태라면
		printf("올바른 패스워드 입니다.\n"); // 올바른 패스워드라고 출력함
	}

	return 0;
}

void size_check(char * pw, int* check) {
	// 패스워드 크기 체크하는 함수. 매개변수로 포인터 2개를 받음
	int count = 0; // count를 0으로 초기화함
	while (*pw != '\0') {
		count++;
		pw++;
		/* null을 만날 때까지 반복하면서 count를 1씩 증가시킴.
		-> 문자 개수 세는 것
		그 다음 한 칸 이동해야 하므로 pw도 1증가시킴
		*/
	}
	if (count < 10) {
		// 패스워드 크기가 10이 되지 않으면
		printf("패스워드 크기가 10을 넘어야 합니다.\n");
		// 10을 넘지 않는다는 문장을 출력하고,
		*check = NOT;
		// check가 가리키는 변수의 값을 NOT으로 바꿈 (올바르지 못한 상태)
	}
}

void contain_check(char * pw, int* check) {
	// 숫자, 소문자, 대문자 체크 함수. 매개변수로 포인터 2개를 받음
	int num = 0; // num을 0으로 초기화 함 - 숫자 개수
	int low = 0; // low를 0으로 초기화 함 - 소문자 개수
	int up = 0; // up을 0으로 초기화 함 - 대문자 개수
	while (*pw != '\0') {
		// null을 만날 때까지 반복하면서
		if ('0' <= *pw && *pw <= '9') {
			num++;
			// 숫자를 만나면 num을 1 증가
		}
		else if ('a' <= *pw && *pw <= 'z') {
			low++;
			// 소문자를 만나면 low를 1 증가
		}
		else if ('A' <= *pw && *pw <= 'Z') {
			up++;
			// 대문자를 만나면 up을 1 증가
		}
		pw++; // 포인터 한 칸 이동
	}
	if ((num == 0) || (low == 0) || (up == 0)) {
		printf("하나 이상의 숫자, 소문자, 대문자가 포함되어야 합니다.\n");
		// 만약 num, low, up 중 하나라도 0인 것이 있다면 하나 이상 포함되어야 한다는 안내문 출력
		*check = NOT; // check가 가리키는 변수의 값을 NOT으로 바꿈 (올바르지 못한 상태)
	}
}
void contain2_check(char * pw, int* check) {
	// 특수문자 체크 함수. 매개변수로 포인터 2개를 받음
	while (*pw != '\0') {
		// null을 만날 때까지 반복하면서
		if (*pw == '@') {
			return;
			// @를 만나면 함수를 종료시킴 (특수문자가 하나라도 있으면 되기 때문에 문제가 없다는 의미)
		}
		else if (*pw == '#') {
			return;
			// #를 만나면 함수를 종료시킴 (특수문자가 하나라도 있으면 되기 때문에 문제가 없다는 의미)
		}
		else if (*pw == '%') {
			return;
			// %를 만나면 함수를 종료시킴 (특수문자가 하나라도 있으면 되기 때문에 문제가 없다는 의미)
		}
		pw++; // 포인터 한 칸 이동

	}
	printf("특수문자 @, #, % 중 하나는 반드시 포함되어야 합니다.\n");
	// 위에서 종료되지 못했다면, 특수문자가 포함되어 있지 않다는 의미이므로 특수문자가 포함되어야 한다는 안내문을 출력
	*check = NOT; // check가 가리키는 변수의 값을 NOT으로 바꿈 (올바르지 못한 상태)
}

void continuation_check(char * pw, int * check) {
	// 연속되는 문자 체크 함수. 매개변수로 포인터 2개를 받음
	while (*pw != '\0') {
		// null을 만날 때까지 반복하면서
		if ((*(pw + 1) - *pw) == 1 || (*pw - *(pw + 1)) == 1) {
			// 값이 연속되는, 즉 아스키코드로 1 차이가 나는 경우 연속되는 것이므로 
			printf("연속된 2문자 이상은 존재할 수 없습니다.\n"); // 연속된 2문자 이상은 사용해서는 안된다는 안내문을 출력
			*check = NOT; // // check가 가리키는 변수의 값을 NOT으로 바꿈 (올바르지 못한 상태)
			return; // 발견했다면 더 이상 문자열을 검색해보지 않아도 잘못 입력된 것이므로 함수 종료
		}
		pw++; // 포인터 한 칸 이동
	}
}