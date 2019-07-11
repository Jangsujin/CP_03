#include <stdio.h>

int main() {
	char ch; // 입력받은 문자 저장할 변수
	printf("문자를 입력하세요 : "); // 문자 입력 안내문
	ch = getchar(); // getchar()를 통해 문자를 입력받아 ch에 저장
	printf("Left   : %-c\n", ch); // 왼쪽 정렬
	printf("Middle : %5c\n", ch);
	// 가운데 정렬 - 폭을 절반으로 줄여 오른쪽 정렬하면 가운데 정렬
	printf("Right  : %9c\n", ch); // 오른쪽 정렬
}