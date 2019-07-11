#include <stdio.h>

void main() {
	enum {false, true}; // false와 true가 각각 0,1의 정수를 의미하도록 함
	int check = true; // 변수가 될 수 있는지 없는지를 확인하기 위한 변수, 초기화는 true로 한다.

	printf("변수 이름을 입력해주세요 : "); // 변수 이름을 입력받기 위한 안내문
	char v1 = getchar(); // 첫 번째 문자 입력받아 v1에 넣음
	char v2 = getchar(); // 두 번째 문자 입력받아 v2에 넣음
	char v3 = getchar(); // 세 번째 문자 입력받아 v3에 넣음
	char v4 = getchar(); // 네 번째 문자 입력받아 v4에 넣음
	char v5 = getchar(); // 다섯 번째 문자 입력받아 v5에 넣음
	
	int i_v1 = (int)v1; // v1을 int형으로 형변환하여 변수 i_v1에 넣음
	int i_v2 = (int)v2; // v2를 int형으로 형변환하여 변수 i_v2에 넣음
	int i_v3 = (int)v3; // v3를 int형으로 형변환하여 변수 i_v3에 넣음
	int i_v4 = (int)v4; // v4를 int형으로 형변환하여 변수 i_v4에 넣음
	int i_v5 = (int)v5; // v5를 int형으로 형변환하여 변수 i_v5에 넣음


	if (((i_v1 >= 65 & i_v1 <= 90) | (i_v1 == 95) | (i_v1 >= 97 && i_v1 <= 122))  ) {
		/*
		(i_v1이 65보다 크거나 같고 90보다 작거나 같음(대문자) | i_v1이 95임('_') | i_v1이 97보다 크거나 같고 122보다 작거나 같음(소문자))
		*/
		check = check & true; // check와 true를 & 연산하여 check에 넣음
	}
	else {
		check = false; // 아닌 경우에는 check에 false를 넣음
	}
	if (((i_v2 >=48 & i_v2<=57)|(i_v2 >= 65 & i_v2 <= 90) | (i_v2 == 95) | (i_v2 >= 97 && i_v2 <= 122))) {
		/*
		(i_v2가 48보다 크거나 같고 57보다 작거나 같음(숫자) | i_v2가 65보다 크거나 같고 90보다 작거나 같음(대문자) | i_v2가 95임('_') | i_v2가 97보다 크거나 같고 122보다 작거나 같음(소문자))
		*/
		check = check & true; // check와 true를 & 연산하여 check에 넣음. 하나라도 false이면 false가 되도록 하기 위함
	}
	else {
		check = false; // 아닌 경우에는 check에 false를 넣음
	}
	if (((i_v3 >= 48 & i_v3 <= 57) | (i_v3 >= 65 & i_v3 <= 90) | (i_v3 == 95) | (i_v3 >= 97 && i_v3 <= 122))) {
		/*
		(i_v3가 48보다 크거나 같고 57보다 작거나 같음(숫자) | i_v3가 65보다 크거나 같고 90보다 작거나 같음(대문자) | i_v3가 95임('_') | i_v3가 97보다 크거나 같고 122보다 작거나 같음(소문자))
		*/
		check = check & true; // check와 true를 & 연산하여 check에 넣음. 하나라도 false이면 false가 되도록 하기 위함
	}
	else {
		check = false; // 아닌 경우에는 check에 false를 넣음
	}
	if (((i_v4 >= 48 & i_v4 <= 57) | (i_v4 >= 65 & i_v4 <= 90) | (i_v4 == 95) | (i_v4 >= 97 && i_v4 <= 122))) {
		/*
		(i_v4가 48보다 크거나 같고 57보다 작거나 같음(숫자) | i_v4가 65보다 크거나 같고 90보다 작거나 같음(대문자) | i_v4가 95임('_') | i_v4가 97보다 크거나 같고 122보다 작거나 같음(소문자))
		*/
		check = check & true; // check와 true를 & 연산하여 check에 넣음. 하나라도 false이면 false가 되도록 하기 위함
	}
	else {
		check = false; // 아닌 경우에는 check에 false를 넣음
	}
	
	if (((i_v5 >= 48 & i_v5 <= 57) | (i_v5 >= 65 & i_v5 <= 90) | (i_v5 == 95) | (i_v5 >= 97 && i_v5 <= 122))) {
		/*
		(i_v5가 48보다 크거나 같고 57보다 작거나 같음(숫자) | i_v5가 65보다 크거나 같고 90보다 작거나 같음(대문자) | i_v5가 95임('_') | i_v5가 97보다 크거나 같고 122보다 작거나 같음(소문자))
		*/
		check = check & true; // check와 true를 & 연산하여 check에 넣음. 하나라도 false이면 false가 되도록 하기 위함
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