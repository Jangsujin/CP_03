#include <stdio.h>
#include <ctype.h>

void main() {
	enum {false, true}; // false와 true가 각각 0,1의 정수를 의미하도록 함
	int check = true; // 변수가 될 수 있는지 없는지를 확인하기 위한 변수, 초기화는 true로 한다.
	printf("변수 이름을 입력해주세요 : "); // 변수 이름을 입력받기 위한 안내문
	char v1 = getchar(); // 첫 번째 문자 입력받아 v1에 넣음
	char v2 = getchar(); // 두 번째 문자 입력받아 v2에 넣음
	char v3 = getchar(); // 세 번째 문자 입력받아 v3에 넣음
	char v4 = getchar(); // 네 번째 문자 입력받아 v4에 넣음
	char v5 = getchar(); // 다섯 번재 문자 입력받아 v5에 넣음

	if ((isalpha(v1)>0 | ((!ispunct(v1)) > 0 | v1 == '_') > 0)&(!isdigit(v1) > 0 )&(!isspace(v1))>0) {
		/*
		 알파벳이거나 구두점 문자 중 '_'을 가짐 & 숫자를 가지지 않음 & 공백을 가지지 않음
		 함수들이 참일 때 0이 아닌 값을 반환하기 때문에, 0보다 크면 참이 되도록 함 
		*/
			check = check & true; // check와 true를 & 연산하여 check에 넣음
	}
	else {
		check = false; // 아닌 경우에는 check에 false를 넣음
	}
	if ((isalnum(v2) > 0 | ((!ispunct(v2)) > 0 | v2 == '_') > 0)&(!isspace(v2)) > 0) {
		/*
		 알파벳 또는 숫자이거나 구두점 문자 중 '_'을 가짐 &  공백을 가지지 않음
		 함수들이 참일 때 0이 아닌 값을 반환하기 때문에, 0보다 크면 참이 되도록 함
		*/
			check = check & true;
			// check와 true를 & 연산하여 check에 넣음. 하나라도 false이면 false가 되도록 하기 위함
	}
	else {
		check = false; // 아닌 경우에는 check에 false를 넣음
	}
	if ((isalnum(v3) > 0 | ((!ispunct(v3)) > 0 | v3 == '_') > 0)&(!isspace(v3)) > 0) {
		/*
		 알파벳 또는 숫자이거나 구두점 문자 중 '_'을 가짐 &  공백을 가지지 않음
		 함수들이 참일 때 0이 아닌 값을 반환하기 때문에, 0보다 크면 참이 되도록 함
		*/
			check = check & true;
			// check와 true를 & 연산하여 check에 넣음. 하나라도 false이면 false가 되도록 하기 위함
	}
	else {
		check = false; // 아닌 경우에는 check에 false를 넣음
	}
	if ((isalnum(v4) > 0 | ((!ispunct(v4)) > 0 | v4 == '_') > 0)&(!isspace(v4)) > 0) {
		/*
		 알파벳 또는 숫자이거나 구두점 문자 중 '_'을 가짐 &  공백을 가지지 않음
		 함수들이 참일 때 0이 아닌 값을 반환하기 때문에, 0보다 크면 참이 되도록 함
		*/
			check = check & true;
			// check와 true를 & 연산하여 check에 넣음. 하나라도 false이면 false가 되도록 하기 위함
	}
	else {
		check = false; // 아닌 경우에는 check에 false를 넣음
	}
	if ((isalnum(v5) > 0 | ((!ispunct(v5)) > 0 | v5 == '_') > 0)&(!isspace(v5)) > 0) {
		/*
		 알파벳 또는 숫자이거나 구두점 문자 중 '_'을 가짐 &  공백을 가지지 않음
		 함수들이 참일 때 0이 아닌 값을 반환하기 때문에, 0보다 크면 참이 되도록 함
		*/
			check = check & true;
			// check와 true를 & 연산하여 check에 넣음. 하나라도 false이면 false가 되도록 하기 위함
	}
	else {
		check = false; // 아닌 경우에는 check에 false를 넣음
	}

	// 5문자 키워드인 경우
	if (v1 == 's'&v2 == 'h'&v3 == 'o'&v4 == 'r'&v5 == 't') {
		// 입력받은 변수가 short인 경우
		check = false; // check에 false를 넣음
	}
	else if (v1 == 'u'&v2 == 'n'&v3 == 'i'&v4 == 'o'&v5 == 'n') {
		// 입력받은 변수가 union인 경우
		check = false; // check에 false를 넣음
	}
	else if (v1 == 'b'&v2 == 'r'&v3 == 'e'&v4 == 'a'&v5 == 'k') {
		// 입력받은 변수가 break인 경우
		check = false; // check에 false를 넣음
	}
	else if (v1 == 'w'&v2 == 'h'&v3 == 'i'&v4 == 'l'&v5 == 'e') {
		// 입력받은 변수가 while인 경우
		check = false; // check에 false를 넣음
	}
	else if (v1 == 'c'&v2 == 'o'&v3 == 'n'&v4 == 's'&v5 == 't') {
		// 입력받은 변수가 const인 경우
		check = false; // check에 false를 넣음
	}
	else if (v1 == 'f'&v2 == 'l'&v3 == 'o'&v4 == 'a'&v5 == 't') {
		// 입력받은 변수가 float인 경우
		check = false; // check에 false를 넣음
	}

	printf("%c%c%c%c%c는 변수로 사용할 수 %s", v1, v2, v3, v4, v5, check ? "있습니다." : "없습니다.");
	// 입력받았던 문자들을 출력하고, 변수로 사용할 수 있는지 없는지를 삼항연산자를 이용하여 출력한다.
}