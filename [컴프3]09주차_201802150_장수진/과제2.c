#include <stdio.h>

typedef struct polynomial {
	int coeff; // 계수
	int exp; // 지수
} polynomial;
// typedef를 이용하여 polynomial 구조체를 선언할 때 편하게 함.

int main() {
	polynomial poly[6]; // 5차수 계산이기 때문에 상수까지 최대 6개의 항 필요
	int x=0; // x값을 입력받아 저장할 변수
	int count = 0; // 항의 개수
	int sum = 0; // x값 대입해서 나온 결과

	printf("항의 개수를 입력해주세요 : ");
	scanf_s("%d", &count);
	printf("\n");
	// 항의 개수를 입력받음

	for (int i = 0; i < count; i++) {
		printf("계수를 입력해주세요 : ");
		scanf_s("%d", &poly[i].coeff);
		printf("지수를 입력해주세요 : ");
		scanf_s("%d", &poly[i].exp);
	}
	// 항의 개수만큼 계수와 지수를 입력받음 -> 다항식 완성
	printf("\n식에 대입할 x 값을 입력해주세요 : ");
	scanf_s("%d", &x);
	// 계산할 것이기 때문에 식에 대입할 x값 입력받음
	for (int i = 0; i < count; i++) {
		int result=1;
		// result를 1로 초기화 (1은 곱셈의 항등원)
		for (int j = 0; j < poly[i].exp; j++) {
			result *= x;
		}
		/*
		지수만큼 x를 곱하여 result에 넣음 
		 -> 여기에 계수만 곱하면 하나의 항 계산완료
		*/

		sum += poly[i].coeff * result;
		// 계산을 끝낸 항을 sum에 누적시킴
	}
	// for문이 끝나면 모든 항의 합, 즉 다항식의 결과가 sum에 저장됨
	printf("식의 결과는 %d 입니다.\n", sum);
	// 결과 출력
}