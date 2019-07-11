#include <stdio.h>
#include <stdlib.h>

#define SIZE 20 // SIZE를 20으로 정의

int find(int[], int, int); // find 함수 선언

int main() {
	int ary[SIZE]; // 크기가 20인 배열 생성
	int exist; // 존재하는 변수인지 입력 받을 것
	int index; // 반환하는 인덱스를 저장할 변수
	for (int i = 0; i < SIZE; i++) {
		ary[i] = rand()%41 + 10;
		// 10-50 사이의 랜덤한 값으로 배열 값 초기화
		printf("%d ", ary[i]); // 배열에 있는 값 출력
	}
	printf("\n");
	printf("확인하고 싶은 정수를 입력하세요 : "); // 확인하고 싶은 정수 입력 안내문
	scanf_s("%d", &exist); // 정수 입력 받음
	index = find(ary, exist, SIZE-1); // find 함수를 부르고 반환값을 index에 저장
	if (index!=-1) {
		// index가 -1이 아니라면 배열에 있다는 의미이므로
		printf("그 값은 배열의 인덱스 %d에 있습니다.\n", index);
		// 인덱스 어디에 있는지를 출력
	}
	else {
		// index가 -1이라면 배열에 없다는 의미이므로
		printf("검색결과가 없습니다.");
		// 검색결과 없음을 출력
	}

	return 0;
	
}

int find(int ary[], int exist,int i) {
	// find 함수
	if (i < 0)
		// i가 0보다 작다면 배열에 없다는 의미이므로
		return -1; // -1 반환 (base case)
	else
		// 아니라면
		if (exist == ary[i]) {
			// 찾는 값이 배열의 i번째에 있다면
			return i;
			// 인덱스 i를 반환
			// 중복된 값이 있을 경우에는 더 뒤에 있는 값을 출력
		}
		else {
			// 못 찾았을 경우에는
			find(ary, exist, i - 1);
			// find 함수를 다시 호출하며 진행
		}
}