#include <stdio.h>

int check_data(int, int, int); // check_data �Լ� ����

int main() {
	int year, month, day; // �Է¹��� ��, ��, �� �� ������ ����
	int check; // check_data�κ��� ��ȯ�޴� ������ ������ ���� check
	do {
		printf("��¥�� �� �� �� ������ �Է����ּ��� (0 0 0 �Է½� ����) : ");
		// �� �� �� �Է� �ȳ���
		scanf_s("%d %d %d", &year, &month, &day); // �Է�
		check = check_data(year, month, day);
		// �Լ��κ��� ��ȯ�Ǵ� ���� check ������ ����.
		if ((year == 0 && month == 0 && day == 0)) {
			break;
			// year, month, day�� ��� 0�� ��� break
		}
		if (check) {
			// ���� ��ȿ�� ��¥�� �Է¹޾Ҵٸ�
			printf("��ȿ�� ��¥�̹Ƿ� �����մϴ�.\n"); // ��ȿ�� ��¥�̹Ƿ� �����Ѵٴ� ���� �����.
		}
	} while (check==0); // check�� 0�� ��쿡 ��� �ݺ�
}

int check_data(int year, int month, int day) {
	// �Է¹��� �� �� ���� ��ȿ�� ��¥������ �˻��ϴ� �Լ�
	if (year <= 0) {
		return 0; // year�� 0���� �۴ٸ� ��ȿ���� ����
	}
	else if (0 >= month || month >= 13) {
		return 0;
		// month�� 0���� �۰ų�, 13���� ū ��쿡�� ��ȿ���� ����
	}
	else {
		switch (month) {
		case 1 : case 3 : case 5 : case 7 : case 8 :
		case 10 : case 12:
			// 1, 3, 5, 7, 8, 10, 12���� ��쿡�� ���� 1-31�ϱ��� �����Ƿ�
			if (day < 1 || day > 31) {
				return 0;
				// day�� 0���� �۰ų�, 31���� ū ��쿡�� ��ȿ���� ����
			}
			else {
				return 1;
				// ���� ��찡 �ƴ϶�� ��ȿ�ϹǷ� 1 ��ȯ
			}
		case 2:
			// 2���� ���
			if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0) {
				// ������ ���� 29�ϱ��� �����Ƿ�
				if (day < 1 || day > 29) {
					return 0;
					// day�� 0���� �۰ų�, 29���� ū ��쿡�� ��ȿ���� ����
				}
				else {
					return 1;
					// ���� ��찡 �ƴ϶�� ��ȿ�ϹǷ� 1 ��ȯ
				}
			}
			else {
				// ������ �ƴ� ���
				if (day < 1 || day > 28) {
					return 0;
					// day�� 0���� �۰ų�, 28���� ū ��쿡�� ��ȿ���� ����
				}
				else {
					return 1;
					// ���� ��찡 �ƴ϶�� ��ȿ�ϹǷ� 1 ��ȯ
				}
			}
		case 4 : case 6 : case 9 : case 11:
			// 4, 6, 9, 11���� ��쿡�� 1-30�ϱ��� �����Ƿ�
			if (day < 1 || day > 30) {
				return 0;
				// day�� 1���� �۰ų�, 30���� ū ��쿡�� ��ȿ���� ����
			}
			else {
				return 1;
				// ���� ��찡 �ƴ϶�� ��ȿ�ϹǷ� 1 ��ȯ
			}
		}
	}
}