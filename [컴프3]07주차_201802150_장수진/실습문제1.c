#include <stdio.h>
#include <string.h>

int main() {
	char name[5][10]; // 이차원 배열 선언. 5명을 입력받을 것이므로 열이 5
	char s_name[10]; // 검색하고자 하는 이름을 저장할 배열
	for (int i = 0; i < 5; i++) {
		// 5회 반복
		printf("input students name [%d] : ",i); // 저장하고자 하는 이름을 입력하라는 안내문
		scanf_s("%s", name[i], 9); // name[i]를 시작주소로 하여 입력받음
		
	}
	printf("input complete\n"); // 다 들어간 후에는 입력이 완료되었다는 안내문 출력
	printf("Search for name : "); // 찾을 이름을 입력하라는 안내문
	scanf_s("%s", s_name,9); // s_name을 시작주소로 하여 입력받음

	for (int k = 0; k < 5; k++) {
		// 저장된 이름이 5개 이므로 5회 반복
		if (strcmp(name[k], s_name) == 0) {
			// strcmp는 같으면 0을 반환하므로 반환 값이 0일 경우
			printf("found it!"); // 찾았다는 안내문을 출력 후
			return 0; // 프로그램 종료
		}
	}
	printf("nope"); // 여기까지 왔다면 찾지 못했다는 의미이므로 없다는 안내문을 출력 후
	return 0; // 프로그램 종료
}