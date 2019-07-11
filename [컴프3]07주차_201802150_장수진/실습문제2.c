#include <stdio.h>
#include <string.h>

void toUpperCase(char*, char*); // �빮�ڷ� �ٲٴ� �Լ� ����
void subString(char*, char*, int, int); // ���ڿ��� �ڸ��� �Լ� ����

int main() {
	char str[] = "Hello world"; // str �迭�� ���ڿ� ����
	char dst[50]; // ����� ũ���� �迭 ����. �빮�ڷ� �ٲ� ���ڿ��� �ڸ� ���ڿ��� ���� ������
	toUpperCase(str, dst); // �ҹ��ڸ� �빮�ڷ� �ٲٴ� �Լ� ȣ��
	printf("toUpperCase : %s -> %s\n", str, dst); // ���
	subString(str, dst, 2, 7); // ���ڿ��� �ڸ��� �Լ� ȣ��
	printf("subString : subString, %d, %d -> %s", 2,7, dst); // ���


}

void toUpperCase(char *src, char* dst) {
	// �ҹ��ڸ� �빮�ڷ� �ٲٴ� �Լ�. �Ķ���ͷ� ������ 2�� ����
	while (*src != '\0') {
		// null�� ���� ������ �ݺ�
		if ('a' <= *src && *src <= 'z') {
			// �ҹ��ڶ��
			*dst = *src - 32; // src�� ������ 32��ŭ �� ������ dst�� ���� ���� (�ҹ��ڿ� �빮�ڰ� �ƽ�Ű�ڵ�� 32��ŭ ���̳�)
		}
		else {
			// �ƴ϶��, �� �빮�ڶ��
			*dst = *src; // ���� �������� ����
		}
		src++; // ������ �� ĭ �̵�
		dst++; // ������ �� ĭ �̵�
		*dst = NULL; // ������ ���� ���� �ʵ��� �� �����ڸ��� NULL�� �����
	}
	

}

void subString(char* src, char* dst, int start, int end) {
	// ���ڿ��� �ڸ��� �Լ�. �Ķ���ͷ� ������ 2���� ���� 2��(�������� ������ ��Ÿ��)�� ����
	for (int i = start; i < end; i++) {
		// ���������� �������� �ݺ��ϸ�
		*dst = src[i]; // dst�� ���� src�� i��° �ε����� ������ �ٲ�
		dst++; // ������ �� ĭ �̵�
		*dst = NULL; // ������ ���� ���� �ʵ��� �� �����ڸ��� NULL�� �����
	}

}