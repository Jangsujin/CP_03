#include <stdio.h>
#include <stdlib.h>

#define SIZE 20 // SIZE�� 20���� ����

int find(int[], int, int); // find �Լ� ����

int main() {
	int ary[SIZE]; // ũ�Ⱑ 20�� �迭 ����
	int exist; // �����ϴ� �������� �Է� ���� ��
	int index; // ��ȯ�ϴ� �ε����� ������ ����
	for (int i = 0; i < SIZE; i++) {
		ary[i] = rand()%41 + 10;
		// 10-50 ������ ������ ������ �迭 �� �ʱ�ȭ
		printf("%d ", ary[i]); // �迭�� �ִ� �� ���
	}
	printf("\n");
	printf("Ȯ���ϰ� ���� ������ �Է��ϼ��� : "); // Ȯ���ϰ� ���� ���� �Է� �ȳ���
	scanf_s("%d", &exist); // ���� �Է� ����
	index = find(ary, exist, SIZE-1); // find �Լ��� �θ��� ��ȯ���� index�� ����
	if (index!=-1) {
		// index�� -1�� �ƴ϶�� �迭�� �ִٴ� �ǹ��̹Ƿ�
		printf("�� ���� �迭�� �ε��� %d�� �ֽ��ϴ�.\n", index);
		// �ε��� ��� �ִ����� ���
	}
	else {
		// index�� -1�̶�� �迭�� ���ٴ� �ǹ��̹Ƿ�
		printf("�˻������ �����ϴ�.");
		// �˻���� ������ ���
	}

	return 0;
	
}

int find(int ary[], int exist,int i) {
	// find �Լ�
	if (i < 0)
		// i�� 0���� �۴ٸ� �迭�� ���ٴ� �ǹ��̹Ƿ�
		return -1; // -1 ��ȯ (base case)
	else
		// �ƴ϶��
		if (exist == ary[i]) {
			// ã�� ���� �迭�� i��°�� �ִٸ�
			return i;
			// �ε��� i�� ��ȯ
			// �ߺ��� ���� ���� ��쿡�� �� �ڿ� �ִ� ���� ���
		}
		else {
			// �� ã���� ��쿡��
			find(ary, exist, i - 1);
			// find �Լ��� �ٽ� ȣ���ϸ� ����
		}
}