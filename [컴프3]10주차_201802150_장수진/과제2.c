#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char string[200]; // ���Ͽ��� �о�� ������ ������ �迭
	char string2[10][20]; // 10���� ���ڿ��� ������ �� �ִ� �迭 
	int index = 0; // string2�� �ε���
	char * token; // �ڸ� token ������
	FILE *f; // ���� ������
	char text[] = "text.txt"; // ���ڿ��� ����ִ� ����
	char text_c[] = "text_copy.txt"; // ����Ͽ� �ٲ� ������ ������ ���� 

	if(fopen_s(&f, text, "r") !=0){
		// ������ �� �� ���� ��� (�б�� ����)
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
		// �� �� ���ٰ� ��� �� ����
	}
	
	while (!feof(f)) {
		// ������ ���� ������
		fgets(string, 100, f); // ���Ͽ��� �о�� ���� string�� ����
		token = strtok(string, " ");  //�������� �������� ���ڿ� �ڸ�
		while (token != NULL) {
			// token�� NULL�� �ƴ� ���ȿ�
			strcpy(string2[index], token); // token ���� string2[index]�� ����
			if ('a' <= string2[index][0] && string2[index][0] <= 'z') {
				// �� �� ���ڰ� �ҹ��ڶ��
				string2[index][0] = (string2[index][0] - ('a' - 'A'));
				// �ҹ��ڸ� �빮�ڷ� ��ȯ
			}
			index++; // �ε��� ����
			token = strtok(NULL, " "); // ���� ���ڿ��� �̵��Ͽ� �ڸ�
		}
	}

	fclose(f); // ������ ������ �ݾ���.
	
	// ������ �Ͽ� �迭�� ���ڿ��� ������ ��. -> �ٸ� ���Ͽ� ��¸� �ϸ� ��

	if (fopen_s(&f, text_c, "w") != 0) {
		// ������ �� �� ���� ��� (����� ����)
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
		// �� �� ���ٰ� ����� �� ���� 
	}
	for (int i = 0; i < index; i++) {
		// string2�� ����Ǿ� �ִ� �ܾ��� ������ŭ �ݺ�
		fprintf(f, "%s ", string2[i]);
		// string2[i]�� �ִ� ���ڿ��� ���Ͽ� ���
	}
	fclose(f); // ������ ������ �ݾ��� (��� �� ���ڿ� ����� ����)
}