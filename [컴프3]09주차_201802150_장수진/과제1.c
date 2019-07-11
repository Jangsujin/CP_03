#include <stdio.h>

typedef struct student {
	char name[10]; // 이름
	char start_uni[20]; // 학번
	double grade; // 평점
} student;
// typedef를 이용하여 student 구조체를 선언할 때 편하게 함.

int main() {
	student s[5]; // 5명의 학생을 저장할 student형 배열 선언
	double s_grade=0.0; // 가장 높은 평점 저장할 변수
	double sum_grade=0.0; // 전체 학생의 평점 다 더할 변수
	for (int i = 0; i < 5; i++) {
		printf("%d번째 학생의 이름을 입력해주세요 : ", i + 1);
		scanf_s("%s", &s[i].name, 10);
		printf("%d번째 학생의 학번을 입력해주세요 : ", i + 1);
		scanf_s("%s", &s[i].start_uni,20);
		printf("%d번째 학생의 평점을 입력해주세요 : ", i + 1);
		scanf_s("%lf", &s[i].grade);
	}
	// 각 학생들의 이름과 학번, 평점을 입력받음

	for (int i = 0; i < 5; i++) {
		if (s_grade < s[i].grade) {
			s_grade = s[i].grade;
		}
		/* 가장 높은 평점의 학생 찾음
		(s_grade과 비교하여 현재 인덱스의 학생의 점수가 더 높을 때 s_grade에 저장되는 값을 현재 인덱스의 학생의 점수가 되도록 함)
		*/
		sum_grade += s[i].grade; // 전체 학생의 평점 합
	}
	for (int i = 0; i < 5; i++) {
		if (s[i].grade == s_grade) {
			printf("평점이 가장 높은 학생의 이름 : %s, 학번 : %s, 평점 : %.2lf\n", s[i].name, s[i].start_uni, s[i].grade);
		}
		/*
		평점이 가장 높은 학생 출력. 평점은 소숫점 둘째자리까지만 출력
		가장 높은 사람이 여러 명이면 모두 다 출력해주기 위해 반복문 이용
		*/
	}
	printf("전체 학생의 평균 : %.2lf, 최고점 : %.2lf", sum_grade / 5, s_grade);
	// 전체 학생의 평균과 최고점을 출력 (평균은 학생이 총 5명이기 때문에, 총합을 5로 나눈 값을 이용)

	return 0;
}