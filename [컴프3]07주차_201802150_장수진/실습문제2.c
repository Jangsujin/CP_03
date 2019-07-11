#include <stdio.h>
#include <string.h>

void toUpperCase(char*, char*); // 대문자로 바꾸는 함수 선언
void subString(char*, char*, int, int); // 문자열을 자르는 함수 선언

int main() {
	char str[] = "Hello world"; // str 배열에 문자열 저장
	char dst[50]; // 충분한 크기의 배열 선언. 대문자로 바꾼 문자열과 자른 문자열을 담을 공간임
	toUpperCase(str, dst); // 소문자를 대문자로 바꾸는 함수 호출
	printf("toUpperCase : %s -> %s\n", str, dst); // 출력
	subString(str, dst, 2, 7); // 문자열을 자르는 함수 호출
	printf("subString : subString, %d, %d -> %s", 2,7, dst); // 출력


}

void toUpperCase(char *src, char* dst) {
	// 소문자를 대문자로 바꾸는 함수. 파라미터로 포인터 2개 받음
	while (*src != '\0') {
		// null을 만날 때까지 반복
		if ('a' <= *src && *src <= 'z') {
			// 소문자라면
			*dst = *src - 32; // src의 값에서 32만큼 뺀 값으로 dst의 값을 변경 (소문자와 대문자가 아스키코드로 32만큼 차이남)
		}
		else {
			// 아니라면, 즉 대문자라면
			*dst = *src; // 값을 변경하지 않음
		}
		src++; // 포인터 한 칸 이동
		dst++; // 포인터 한 칸 이동
		*dst = NULL; // 쓰레기 값이 들어가지 않도록 그 다음자리를 NULL로 비워줌
	}
	

}

void subString(char* src, char* dst, int start, int end) {
	// 문자열을 자르는 함수. 파라미터로 포인터 2개와 정수 2개(시작점과 끝점을 나타냄)를 받음
	for (int i = start; i < end; i++) {
		// 시작점부터 끝점까지 반복하며
		*dst = src[i]; // dst의 값을 src의 i번째 인덱스의 값으로 바꿈
		dst++; // 포인터 한 칸 이동
		*dst = NULL; // 쓰레기 값이 들어가지 않도록 그 다음자리를 NULL로 비워줌
	}

}