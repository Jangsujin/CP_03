#include <stdio.h>

#define Pi 3.14 // 원주율 상수로 선언

int main() {
	float r; // 반지름 변수
	printf("반지름을 입력해주세요 : "); // 반지름 입력 안내문
	scanf_s("%f", &r, 4); // float형 이므로 4바이트 scanf_s
	printf("원의 면적은 %.2f 입니다.", r*r*Pi);
	// 계산하고 원의 면적 출력 소수점 둘째자리까지만 출력

	return 0;
}