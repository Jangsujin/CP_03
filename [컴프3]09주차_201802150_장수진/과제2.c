#include <stdio.h>

typedef struct polynomial {
	int coeff; // ���
	int exp; // ����
} polynomial;
// typedef�� �̿��Ͽ� polynomial ����ü�� ������ �� ���ϰ� ��.

int main() {
	polynomial poly[6]; // 5���� ����̱� ������ ������� �ִ� 6���� �� �ʿ�
	int x=0; // x���� �Է¹޾� ������ ����
	int count = 0; // ���� ����
	int sum = 0; // x�� �����ؼ� ���� ���

	printf("���� ������ �Է����ּ��� : ");
	scanf_s("%d", &count);
	printf("\n");
	// ���� ������ �Է¹���

	for (int i = 0; i < count; i++) {
		printf("����� �Է����ּ��� : ");
		scanf_s("%d", &poly[i].coeff);
		printf("������ �Է����ּ��� : ");
		scanf_s("%d", &poly[i].exp);
	}
	// ���� ������ŭ ����� ������ �Է¹��� -> ���׽� �ϼ�
	printf("\n�Ŀ� ������ x ���� �Է����ּ��� : ");
	scanf_s("%d", &x);
	// ����� ���̱� ������ �Ŀ� ������ x�� �Է¹���
	for (int i = 0; i < count; i++) {
		int result=1;
		// result�� 1�� �ʱ�ȭ (1�� ������ �׵��)
		for (int j = 0; j < poly[i].exp; j++) {
			result *= x;
		}
		/*
		������ŭ x�� ���Ͽ� result�� ���� 
		 -> ���⿡ ����� ���ϸ� �ϳ��� �� ���Ϸ�
		*/

		sum += poly[i].coeff * result;
		// ����� ���� ���� sum�� ������Ŵ
	}
	// for���� ������ ��� ���� ��, �� ���׽��� ����� sum�� �����
	printf("���� ����� %d �Դϴ�.\n", sum);
	// ��� ���
}