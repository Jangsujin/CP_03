#include <stdio.h>

typedef struct student {
	char name[10]; // �̸�
	char start_uni[20]; // �й�
	double grade; // ����
} student;
// typedef�� �̿��Ͽ� student ����ü�� ������ �� ���ϰ� ��.

int main() {
	student s[5]; // 5���� �л��� ������ student�� �迭 ����
	double s_grade=0.0; // ���� ���� ���� ������ ����
	double sum_grade=0.0; // ��ü �л��� ���� �� ���� ����
	for (int i = 0; i < 5; i++) {
		printf("%d��° �л��� �̸��� �Է����ּ��� : ", i + 1);
		scanf_s("%s", &s[i].name, 10);
		printf("%d��° �л��� �й��� �Է����ּ��� : ", i + 1);
		scanf_s("%s", &s[i].start_uni,20);
		printf("%d��° �л��� ������ �Է����ּ��� : ", i + 1);
		scanf_s("%lf", &s[i].grade);
	}
	// �� �л����� �̸��� �й�, ������ �Է¹���

	for (int i = 0; i < 5; i++) {
		if (s_grade < s[i].grade) {
			s_grade = s[i].grade;
		}
		/* ���� ���� ������ �л� ã��
		(s_grade�� ���Ͽ� ���� �ε����� �л��� ������ �� ���� �� s_grade�� ����Ǵ� ���� ���� �ε����� �л��� ������ �ǵ��� ��)
		*/
		sum_grade += s[i].grade; // ��ü �л��� ���� ��
	}
	for (int i = 0; i < 5; i++) {
		if (s[i].grade == s_grade) {
			printf("������ ���� ���� �л��� �̸� : %s, �й� : %s, ���� : %.2lf\n", s[i].name, s[i].start_uni, s[i].grade);
		}
		/*
		������ ���� ���� �л� ���. ������ �Ҽ��� ��°�ڸ������� ���
		���� ���� ����� ���� ���̸� ��� �� ������ֱ� ���� �ݺ��� �̿�
		*/
	}
	printf("��ü �л��� ��� : %.2lf, �ְ��� : %.2lf", sum_grade / 5, s_grade);
	// ��ü �л��� ��հ� �ְ����� ��� (����� �л��� �� 5���̱� ������, ������ 5�� ���� ���� �̿�)

	return 0;
}