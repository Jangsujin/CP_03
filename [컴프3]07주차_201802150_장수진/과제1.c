#include <stdio.h>
#include <string.h>

#define DECODE 0 // DECODE�� ��� 0���� ����
#define INCODE 1 // INCODE�� ��� 1�� ���� 

void caesar(char *, char *, const int, const int); // ���� �Լ� ����
int isAlpha(char *); // ���ĺ����� �Է¹޾Ҵ��� Ȯ���ϴ� �Լ� ����



int main() {
	char str[33]; // ���� ������ �Է¹��� �迭
	char outstr[33]; // incode�� ������ ���� �迭
	char outstr_2[33]; // decode�� ������ ���� �迭
	// 32�ڱ����� �Է¹��� ���̹Ƿ� NULL���� ũ�⸦ 33���� ������
	int key=0; // key ���� 0���� �ʱ�ȭ
	
	printf("please input your string : ");
	scanf_s("%s", str, 32); // 32����Ʈ������ �Է¹���
	if (!isAlpha(str)) {
		// �Է¹��� ���ڿ��� ���ĺ������� �̷���� ���� �ʴٸ�
		printf("�Է¹��� ���ڿ��� ���ĺ������� �̷���� ���� �ʽ��ϴ�.\n"); // ���ĺ������� �̷���� ���� �ʴٴ� �ȳ����� ����� ��
		return 0; // ���α׷� ����
	}
	printf("please input caesar Key number : ");
	scanf_s("%d", &key); // incode�� key���� �Է¹���
	printf("Encoded string is : ");
	caesar(str, outstr, key, INCODE); // �Լ� ȣ��
	// outstr�� key���� ���� incode�� ���ڿ��� ���� ��
	printf("%s\n", outstr); // incode�� ���ڿ� ���
	printf("please input caesar Key number : ");
	scanf_s("%d", &key); // decode�� key���� �Է¹���
	printf("Decoded string is : ");
	caesar(outstr, outstr_2, key, DECODE); // �Լ� ȣ��
	// outstr_2�� key���� ���� decode�� ���ڿ��� ���� ��
	printf("%s\n", outstr_2); // decode�� ���ڿ� ���


}

void caesar(char * input, char* output, const int key, const int type) {
	int count = 0;
	if (type == INCODE) {
		// ���ڵ�
		while (input[count] != '\0') {
			// input�� count��° ���� NULL�� �ƴ� ������ �ݺ�
			*output = input[count] + key;
			// input�� ���� key���� �̿��Ͽ� ��ȯ�ϰ� output�� ����(���ڵ��ϴϱ� key���� ����)
			if (!('A' <= *output && *output <= 'Z')) {
				// ���� A-Z ���̿� ���� ���̶��
				if ('a' <= *output && *output <= 'z') {
					// a-z���̿� �ִ� ������ Ȯ���ϰ� �´ٸ�
					output++;
					*output = NULL;
					count++;
					continue;
					/* ���� �״�� ������
					continue �� ���̹Ƿ� output�� �� ĭ �̵���Ű��,
					���� output ���� NULL�� �ʱ�ȭ�ϰ�, count�� 1�������� ���� �ε����� Ȯ���� �� �ֵ��� ��.
					(���� ���� �״�� �� �� �� ��)
					*/
				}
				else {
					// ���� �װ��� �ƴ϶��
					*output -= 26;
					// 26�� ���� ���ĺ� ���̿� ���� �� �ֵ��� ��.
				}
			}
			output++; // output�� �� ĭ �̵���Ű��,
			*output = NULL; // ���� output ���� NULL�� �ʱ�ȭ�ϰ�,
			count++; //count�� 1�������� ���� �ε����� Ȯ���� �� �ֵ��� ��.
		}
		return; // return�Ͽ� �Լ��� ����
	}
	else {
		// ���ڵ�
		while (input[count] != '\0') {
			// input�� count��° ���� NULL�� �ƴ� ������ �ݺ�
			*output = input[count] - key;
			// input�� ���� key���� �̿��Ͽ� ��ȯ�ϰ� output�� ����(���ڵ��̴ϱ� key���� ��)
			if (!('a' <= *output && *output <= 'z')) {
				// ���� a-z ���̿� ���� ���̶��
				if ('A' <= *output && *output <= 'Z') {
					// A-Z���̿� �ִ� ������ Ȯ���ϰ� �´ٸ�
					output++;
					*output = NULL;
					count++;
					continue;
					/* ���� �״�� ������
					continue �� ���̹Ƿ� output�� �� ĭ �̵���Ű��,
					���� output ���� NULL�� �ʱ�ȭ�ϰ�, count�� 1�������� ���� �ε����� Ȯ���� �� �ֵ��� ��.
					(���� ���� �״�� �� �� �� ��)
					*/
				}
				else {
					// ���� �װ��� �ƴ϶��
					*output += 26; // 26�� ���ؼ� ���ĺ� ���̿� ���� �� �ֵ��� ��.
				}
			}
			output++;  // output�� �� ĭ �̵���Ű��,
			*output = NULL; // ���� output ���� NULL�� �ʱ�ȭ�ϰ�,
			count++; //count�� 1�������� ���� �ε����� Ȯ���� �� �ֵ��� ��.
		}
		return; // return�Ͽ� �Լ��� ����
	}
}

int isAlpha(char * str) {
	// ���ĺ������� �̷���� �ִ��� Ȯ���ϴ� �Լ�. ��ȯ�� ������
	while (*str != '\0') {
		// null�� ���� ������ �ݺ��ϸ鼭
		if (!('a' <= *str && *str <= 'z')) {
			// a-z ���̿� ����
			if (!('A' <= *str && *str <= 'Z')) {
				// A-Z ���̿� ������
				return 0; // 0�� ��ȯ (���ĺ������� �������� �ʾҴٴ� �ǹ�)
			}
		}
		str++; // ������ �� ĭ �̵�
	}
	return 1; // �ƴ϶�� 1�� ��ȯ (���ĺ������� �����Ǿ��ٴ� �ǹ�)
}