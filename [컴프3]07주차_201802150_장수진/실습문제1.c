#include <stdio.h>
#include <string.h>

int main() {
	char name[5][10]; // ������ �迭 ����. 5���� �Է¹��� ���̹Ƿ� ���� 5
	char s_name[10]; // �˻��ϰ��� �ϴ� �̸��� ������ �迭
	for (int i = 0; i < 5; i++) {
		// 5ȸ �ݺ�
		printf("input students name [%d] : ",i); // �����ϰ��� �ϴ� �̸��� �Է��϶�� �ȳ���
		scanf_s("%s", name[i], 9); // name[i]�� �����ּҷ� �Ͽ� �Է¹���
		
	}
	printf("input complete\n"); // �� �� �Ŀ��� �Է��� �Ϸ�Ǿ��ٴ� �ȳ��� ���
	printf("Search for name : "); // ã�� �̸��� �Է��϶�� �ȳ���
	scanf_s("%s", s_name,9); // s_name�� �����ּҷ� �Ͽ� �Է¹���

	for (int k = 0; k < 5; k++) {
		// ����� �̸��� 5�� �̹Ƿ� 5ȸ �ݺ�
		if (strcmp(name[k], s_name) == 0) {
			// strcmp�� ������ 0�� ��ȯ�ϹǷ� ��ȯ ���� 0�� ���
			printf("found it!"); // ã�Ҵٴ� �ȳ����� ��� ��
			return 0; // ���α׷� ����
		}
	}
	printf("nope"); // ������� �Դٸ� ã�� ���ߴٴ� �ǹ��̹Ƿ� ���ٴ� �ȳ����� ��� ��
	return 0; // ���α׷� ����
}