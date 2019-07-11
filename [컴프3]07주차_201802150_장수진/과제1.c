#include <stdio.h>
#include <string.h>

#define DECODE 0 // DECODE인 경우 0으로 정의
#define INCODE 1 // INCODE인 경우 1로 정의 

void caesar(char *, char *, const int, const int); // 시저 함수 선언
int isAlpha(char *); // 알파벳만을 입력받았는지 확인하는 함수 선언



int main() {
	char str[33]; // 본래 문장을 입력받을 배열
	char outstr[33]; // incode한 문장을 담을 배열
	char outstr_2[33]; // decode한 문장을 담을 배열
	// 32자까지만 입력받을 것이므로 NULL까지 크기를 33으로 설정함
	int key=0; // key 값을 0으로 초기화
	
	printf("please input your string : ");
	scanf_s("%s", str, 32); // 32바이트까지만 입력받음
	if (!isAlpha(str)) {
		// 입력받은 문자열이 알파벳만으로 이루어져 있지 않다면
		printf("입력받은 문자열이 알파벳만으로 이루어져 있지 않습니다.\n"); // 알파벳만으로 이루어져 있지 않다는 안내문을 출력한 후
		return 0; // 프로그램 종료
	}
	printf("please input caesar Key number : ");
	scanf_s("%d", &key); // incode할 key값을 입력받음
	printf("Encoded string is : ");
	caesar(str, outstr, key, INCODE); // 함수 호출
	// outstr에 key값에 의해 incode된 문자열을 넣을 것
	printf("%s\n", outstr); // incode된 문자열 출력
	printf("please input caesar Key number : ");
	scanf_s("%d", &key); // decode할 key값을 입력받음
	printf("Decoded string is : ");
	caesar(outstr, outstr_2, key, DECODE); // 함수 호출
	// outstr_2에 key값에 의해 decode된 문자열을 넣을 것
	printf("%s\n", outstr_2); // decode된 문자열 출력


}

void caesar(char * input, char* output, const int key, const int type) {
	int count = 0;
	if (type == INCODE) {
		// 인코딩
		while (input[count] != '\0') {
			// input의 count번째 값이 NULL이 아닐 때까지 반복
			*output = input[count] + key;
			// input의 값을 key값을 이용하여 변환하고 output에 넣음(인코딩하니까 key값을 더함)
			if (!('A' <= *output && *output <= 'Z')) {
				// 만약 A-Z 사이에 없는 값이라면
				if ('a' <= *output && *output <= 'z') {
					// a-z사이에 있는 값인지 확인하고 맞다면
					output++;
					*output = NULL;
					count++;
					continue;
					/* 값을 그대로 유지함
					continue 할 것이므로 output을 한 칸 이동시키고,
					뒤의 output 값을 NULL로 초기화하고, count를 1증가시켜 다음 인덱스를 확인할 수 있도록 함.
					(밑의 것을 그대로 한 번 더 씀)
					*/
				}
				else {
					// 만약 그것이 아니라면
					*output -= 26;
					// 26을 빼서 알파벳 사이에 있을 수 있도록 함.
				}
			}
			output++; // output을 한 칸 이동시키고,
			*output = NULL; // 뒤의 output 값을 NULL로 초기화하고,
			count++; //count를 1증가시켜 다음 인덱스를 확인할 수 있도록 함.
		}
		return; // return하여 함수를 끝냄
	}
	else {
		// 디코딩
		while (input[count] != '\0') {
			// input의 count번째 값이 NULL이 아닐 때까지 반복
			*output = input[count] - key;
			// input의 값을 key값을 이용하여 변환하고 output에 넣음(디코딩이니까 key값을 뺌)
			if (!('a' <= *output && *output <= 'z')) {
				// 만약 a-z 사이에 없는 값이라면
				if ('A' <= *output && *output <= 'Z') {
					// A-Z사이에 있는 값인지 확인하고 맞다면
					output++;
					*output = NULL;
					count++;
					continue;
					/* 값을 그대로 유지함
					continue 할 것이므로 output을 한 칸 이동시키고,
					뒤의 output 값을 NULL로 초기화하고, count를 1증가시켜 다음 인덱스를 확인할 수 있도록 함.
					(밑의 것을 그대로 한 번 더 씀)
					*/
				}
				else {
					// 만약 그것이 아니라면
					*output += 26; // 26을 더해서 알파벳 사이에 있을 수 있도록 함.
				}
			}
			output++;  // output을 한 칸 이동시키고,
			*output = NULL; // 뒤의 output 값을 NULL로 초기화하고,
			count++; //count를 1증가시켜 다음 인덱스를 확인할 수 있도록 함.
		}
		return; // return하여 함수를 끝냄
	}
}

int isAlpha(char * str) {
	// 알파벳만으로 이루어져 있는지 확인하는 함수. 반환은 정수형
	while (*str != '\0') {
		// null을 만날 때까지 반복하면서
		if (!('a' <= *str && *str <= 'z')) {
			// a-z 사이에 없고
			if (!('A' <= *str && *str <= 'Z')) {
				// A-Z 사이에 없으면
				return 0; // 0을 반환 (알파벳만으로 구성되지 않았다는 의미)
			}
		}
		str++; // 포인터 한 칸 이동
	}
	return 1; // 아니라면 1을 반환 (알파벳만으로 구성되었다는 의미)
}