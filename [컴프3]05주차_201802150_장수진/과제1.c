#include <stdio.h>

float GetMid(float, float, float); // GetMid 함수 선언
float GetMin(float, float, float); // GetMin 함수 선언
float GetMax(float, float, float); // GetMax 함수 선언


int main() {
	float f1, f2, f3;
	printf("3개의 실수를 입력해주세요 : "); // 실수 입력 안내문
	scanf_s("%f %f %f", &f1, &f2, &f3); // 입력 받음
	printf("%f %f %f의 순서는\n%f %f %f 입니다.\n", f1, f2, f3, GetMin(f1, f2, f3), GetMid(f1, f2, f3), GetMax(f1, f2, f3));
	// 순서대로 출력

	return 0;


}

float GetMid(float num1, float num2, float num3) {
	// 중간값 반환
	while (1) {
		if (((num1 < num2) && (num2 < num3))||((num1>num2) && (num2>num3))) {
			// num2가 중간값일 때 
			return num2; // num2를 리턴
		}
		else {
			// 만약 num2가 중간값이 아닐 경우
			float temp = num1;
			num1 = num3;
			num3 = num2;
			num2 = temp;
			// num1,2,3의 순서를 바꿈
		}
	}
}

float GetMin(float num1, float num2, float num3) {
	// 최소값 반환
	float fir_check, se_check;
	// 처음 확인하고 작은 값 넣을 변수, 두 번째 확인하고 작은 값 넣을 변수
	fir_check = (num1 < num2) ? num1 : num2;
	// 더 작은 값을 fir_check에 넣음
	se_check = (fir_check < num3) ? fir_check : num3;
	// 더 작은 값을 se_check에 넣음

	return se_check; // se_check 반환
}

float GetMax(float num1, float num2, float num3) {
	// 최대값 반환
	float fir_check, se_check;
	// 처음 확인하고 큰 값 넣을 변수, 두 번째 확인하고 큰 값 넣을 변수
	fir_check = (num1 < num2) ? num2 : num1;
	// 더 큰 값을 fir_check에 넣음
	se_check = (fir_check < num3) ? num3 : fir_check;
	// 더 큰 값을 se_check에 넣음

	return se_check; // se_check 반환
}
