#include <stdio.h>

int main() {
	char ch; // �Է¹��� ���� ������ ����
	printf("���ڸ� �Է��ϼ��� : "); // ���� �Է� �ȳ���
	ch = getchar(); // getchar()�� ���� ���ڸ� �Է¹޾� ch�� ����
	printf("Left   : %-c\n", ch); // ���� ����
	printf("Middle : %5c\n", ch);
	// ��� ���� - ���� �������� �ٿ� ������ �����ϸ� ��� ����
	printf("Right  : %9c\n", ch); // ������ ����
}