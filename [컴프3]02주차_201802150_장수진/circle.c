#include <stdio.h>

#define Pi 3.14 // ������ ����� ����

int main() {
	float r; // ������ ����
	printf("�������� �Է����ּ��� : "); // ������ �Է� �ȳ���
	scanf_s("%f", &r, 4); // float�� �̹Ƿ� 4����Ʈ scanf_s
	printf("���� ������ %.2f �Դϴ�.", r*r*Pi);
	// ����ϰ� ���� ���� ��� �Ҽ��� ��°�ڸ������� ���

	return 0;
}