#include <stdio.h>
#include <ctype.h>

void main() {
	enum {false, true}; // false�� true�� ���� 0,1�� ������ �ǹ��ϵ��� ��
	int check = true; // ������ �� �� �ִ��� �������� Ȯ���ϱ� ���� ����, �ʱ�ȭ�� true�� �Ѵ�.
	printf("���� �̸��� �Է����ּ��� : "); // ���� �̸��� �Է¹ޱ� ���� �ȳ���
	char v1 = getchar(); // ù ��° ���� �Է¹޾� v1�� ����
	char v2 = getchar(); // �� ��° ���� �Է¹޾� v2�� ����
	char v3 = getchar(); // �� ��° ���� �Է¹޾� v3�� ����
	char v4 = getchar(); // �� ��° ���� �Է¹޾� v4�� ����
	char v5 = getchar(); // �ټ� ���� ���� �Է¹޾� v5�� ����

	if ((isalpha(v1)>0 | ((!ispunct(v1)) > 0 | v1 == '_') > 0)&(!isdigit(v1) > 0 )&(!isspace(v1))>0) {
		/*
		 ���ĺ��̰ų� ������ ���� �� '_'�� ���� & ���ڸ� ������ ���� & ������ ������ ����
		 �Լ����� ���� �� 0�� �ƴ� ���� ��ȯ�ϱ� ������, 0���� ũ�� ���� �ǵ��� �� 
		*/
			check = check & true; // check�� true�� & �����Ͽ� check�� ����
	}
	else {
		check = false; // �ƴ� ��쿡�� check�� false�� ����
	}
	if ((isalnum(v2) > 0 | ((!ispunct(v2)) > 0 | v2 == '_') > 0)&(!isspace(v2)) > 0) {
		/*
		 ���ĺ� �Ǵ� �����̰ų� ������ ���� �� '_'�� ���� &  ������ ������ ����
		 �Լ����� ���� �� 0�� �ƴ� ���� ��ȯ�ϱ� ������, 0���� ũ�� ���� �ǵ��� ��
		*/
			check = check & true;
			// check�� true�� & �����Ͽ� check�� ����. �ϳ��� false�̸� false�� �ǵ��� �ϱ� ����
	}
	else {
		check = false; // �ƴ� ��쿡�� check�� false�� ����
	}
	if ((isalnum(v3) > 0 | ((!ispunct(v3)) > 0 | v3 == '_') > 0)&(!isspace(v3)) > 0) {
		/*
		 ���ĺ� �Ǵ� �����̰ų� ������ ���� �� '_'�� ���� &  ������ ������ ����
		 �Լ����� ���� �� 0�� �ƴ� ���� ��ȯ�ϱ� ������, 0���� ũ�� ���� �ǵ��� ��
		*/
			check = check & true;
			// check�� true�� & �����Ͽ� check�� ����. �ϳ��� false�̸� false�� �ǵ��� �ϱ� ����
	}
	else {
		check = false; // �ƴ� ��쿡�� check�� false�� ����
	}
	if ((isalnum(v4) > 0 | ((!ispunct(v4)) > 0 | v4 == '_') > 0)&(!isspace(v4)) > 0) {
		/*
		 ���ĺ� �Ǵ� �����̰ų� ������ ���� �� '_'�� ���� &  ������ ������ ����
		 �Լ����� ���� �� 0�� �ƴ� ���� ��ȯ�ϱ� ������, 0���� ũ�� ���� �ǵ��� ��
		*/
			check = check & true;
			// check�� true�� & �����Ͽ� check�� ����. �ϳ��� false�̸� false�� �ǵ��� �ϱ� ����
	}
	else {
		check = false; // �ƴ� ��쿡�� check�� false�� ����
	}
	if ((isalnum(v5) > 0 | ((!ispunct(v5)) > 0 | v5 == '_') > 0)&(!isspace(v5)) > 0) {
		/*
		 ���ĺ� �Ǵ� �����̰ų� ������ ���� �� '_'�� ���� &  ������ ������ ����
		 �Լ����� ���� �� 0�� �ƴ� ���� ��ȯ�ϱ� ������, 0���� ũ�� ���� �ǵ��� ��
		*/
			check = check & true;
			// check�� true�� & �����Ͽ� check�� ����. �ϳ��� false�̸� false�� �ǵ��� �ϱ� ����
	}
	else {
		check = false; // �ƴ� ��쿡�� check�� false�� ����
	}

	// 5���� Ű������ ���
	if (v1 == 's'&v2 == 'h'&v3 == 'o'&v4 == 'r'&v5 == 't') {
		// �Է¹��� ������ short�� ���
		check = false; // check�� false�� ����
	}
	else if (v1 == 'u'&v2 == 'n'&v3 == 'i'&v4 == 'o'&v5 == 'n') {
		// �Է¹��� ������ union�� ���
		check = false; // check�� false�� ����
	}
	else if (v1 == 'b'&v2 == 'r'&v3 == 'e'&v4 == 'a'&v5 == 'k') {
		// �Է¹��� ������ break�� ���
		check = false; // check�� false�� ����
	}
	else if (v1 == 'w'&v2 == 'h'&v3 == 'i'&v4 == 'l'&v5 == 'e') {
		// �Է¹��� ������ while�� ���
		check = false; // check�� false�� ����
	}
	else if (v1 == 'c'&v2 == 'o'&v3 == 'n'&v4 == 's'&v5 == 't') {
		// �Է¹��� ������ const�� ���
		check = false; // check�� false�� ����
	}
	else if (v1 == 'f'&v2 == 'l'&v3 == 'o'&v4 == 'a'&v5 == 't') {
		// �Է¹��� ������ float�� ���
		check = false; // check�� false�� ����
	}

	printf("%c%c%c%c%c�� ������ ����� �� %s", v1, v2, v3, v4, v5, check ? "�ֽ��ϴ�." : "�����ϴ�.");
	// �Է¹޾Ҵ� ���ڵ��� ����ϰ�, ������ ����� �� �ִ��� �������� ���׿����ڸ� �̿��Ͽ� ����Ѵ�.
}