#include <stdio.h>
#include <stdlib.h>

typedef struct profile_s {
	char name[10]; // 학생의 이름
	char start_uni[20]; // 학생의 학번
	double grade; // 학생의 성적

}profile;
// 학생의 정보를 저장할 구조체
// -> typedef를 통해 profile 형으로 사용할 수 있도록 함


int main() {
	profile input_s; // 학생의 정보를 입력받을 구조체 변수
	FILE *f; // 파일 포인터
	profile profile_s[5]; // 5명의 학생의 정보를 저장할 profile 배열
	double s_grade = 0.0; // 최고점 학생의 점수를 저장할 변수
	double sum_grade = 0.0; // 학생의 점수를 다 더할 변수
	int index = 0; // profile_s 배열 인덱스

	char profile[] = "profile.txt"; // 학생정보를 저장할 파일

	// 여기부터

	if (fopen_s(&f, profile, "w") != 0) {
		// 파일을 열 수 없을 경우 (쓰기로 열음)
		printf("파일이 열리지 않습니다.\n");
		exit(1);
		// 열 수 없다고 출력 후 종료
	}

	printf("5명의 이름, 학번, 평점을 입력해주세요. \n");
	// 5명의 학생의 정보를 입력받음
	for (int i = 0; i < 5; i++) {
		fscanf_s(stdin, "%s %s %lf", &input_s.name,10, &input_s.start_uni,20, &input_s.grade);
		// 학생의 정보를 입력받아서
		fprintf(f, "%s %s %lf\n", input_s.name, input_s.start_uni, input_s.grade);
		// 파일에 저장함
	}
	fclose(f); // 열었던 파일을 닫아줌
	
	// 여기까지 주석처리할 경우, 입력을 따로 받지 않고 파일에 저장된 내용을 가지고 계산을 수행할 수 있습니다.

	if (fopen_s(&f, profile, "r") != 0) {
		// 파일을 열 수 없을 경우 (읽기로 열음)
		printf("파일이 열리지 않습니다.\n");
		exit(1);
		// 열 수 없다고 출력 후 종료
	}

	while(!feof(f)){
		// 파일이 끝날 때까지
		fscanf_s(f, "%s %s %lf", &profile_s[index].name,10,&profile_s[index].start_uni,20, &profile_s[index].grade);
		// 파일에 저장되어 있는 학생의 정보를 구조체 배열 index번에 저장
		index++; // index를 1늘려 다음 칸에 저장될 수 있도록 함
	}
	
	fclose(f); // 열었던 파일을 닫아줌
	

	for (int i = 0; i < 5; i++) {
		// 5명의 학생이기 때문에 5번 반복
		if (s_grade < profile_s[i].grade) {
			s_grade = profile_s[i].grade;
		}
		/* 가장 높은 평점의 학생 찾음
		(s_grade과 비교하여 현재 인덱스의 학생의 점수가 더 높을 때 s_grade에 저장되는 값을 현재 인덱스의 학생의 점수가 되도록 함)
		*/
		sum_grade += profile_s[i].grade; // 전체 학생의 평점 합
	}
	for (int i = 0; i < 5; i++) {
		if (profile_s[i].grade == s_grade) {
			printf("평점이 가장 높은 학생의 이름 : %s, 학번 : %s, 평점 : %.2lf\n", profile_s[i].name, profile_s[i].start_uni, profile_s[i].grade);
		}
		/*
		평점이 가장 높은 학생 출력. 평점은 소숫점 둘째자리까지만 출력
		가장 높은 사람이 여러 명이면 모두 다 출력해주기 위해 반복문 이용
		*/
	}
	printf("전체 학생의 평균 : %.2lf, 최고점 : %.2lf", sum_grade / 5, s_grade);
	// 전체 학생의 평균과 최고점을 출력 (평균은 학생이 총 5명이기 때문에, 총합을 5로 나눈 값을 이용)
}