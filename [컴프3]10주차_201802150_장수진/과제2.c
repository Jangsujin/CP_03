#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char string[200]; // 파일에서 읽어올 문장을 저장할 배열
	char string2[10][20]; // 10개의 문자열을 저장할 수 있는 배열 
	int index = 0; // string2의 인덱스
	char * token; // 자른 token 포인터
	FILE *f; // 파일 포인터
	char text[] = "text.txt"; // 문자열이 들어있는 파일
	char text_c[] = "text_copy.txt"; // 계산하여 바꾼 내용을 저장할 파일 

	if(fopen_s(&f, text, "r") !=0){
		// 파일을 열 수 없을 경우 (읽기로 열음)
		printf("파일이 열리지 않습니다.\n");
		exit(1);
		// 열 수 없다고 출력 후 종료
	}
	
	while (!feof(f)) {
		// 파일이 끝날 때까지
		fgets(string, 100, f); // 파일에서 읽어온 것을 string에 저장
		token = strtok(string, " ");  //공백으로 기준으로 문자열 자름
		while (token != NULL) {
			// token이 NULL이 아닌 동안에
			strcpy(string2[index], token); // token 값을 string2[index]에 복사
			if ('a' <= string2[index][0] && string2[index][0] <= 'z') {
				// 맨 앞 문자가 소문자라면
				string2[index][0] = (string2[index][0] - ('a' - 'A'));
				// 소문자를 대문자로 변환
			}
			index++; // 인덱스 증가
			token = strtok(NULL, " "); // 다음 문자열로 이동하여 자름
		}
	}

	fclose(f); // 열었던 파일을 닫아줌.
	
	// 계산까지 하여 배열에 문자열을 저장해 둠. -> 다른 파일에 출력만 하면 됨

	if (fopen_s(&f, text_c, "w") != 0) {
		// 파일을 열 수 없을 경우 (쓰기로 열음)
		printf("파일이 열리지 않습니다.\n");
		exit(1);
		// 열 수 없다고 출력한 후 종료 
	}
	for (int i = 0; i < index; i++) {
		// string2에 저장되어 있는 단어의 개수만큼 반복
		fprintf(f, "%s ", string2[i]);
		// string2[i]에 있는 문자열을 파일에 출력
	}
	fclose(f); // 열었던 파일을 닫아줌 (계산 된 문자열 출력한 파일)
}