#include <stdio.h>
#include <stdlib.h>

typedef struct profile_s {
	char name[10]; // �л��� �̸�
	char start_uni[20]; // �л��� �й�
	double grade; // �л��� ����

}profile;
// �л��� ������ ������ ����ü
// -> typedef�� ���� profile ������ ����� �� �ֵ��� ��


int main() {
	profile input_s; // �л��� ������ �Է¹��� ����ü ����
	FILE *f; // ���� ������
	profile profile_s[5]; // 5���� �л��� ������ ������ profile �迭
	double s_grade = 0.0; // �ְ��� �л��� ������ ������ ����
	double sum_grade = 0.0; // �л��� ������ �� ���� ����
	int index = 0; // profile_s �迭 �ε���

	char profile[] = "profile.txt"; // �л������� ������ ����

	// �������

	if (fopen_s(&f, profile, "w") != 0) {
		// ������ �� �� ���� ��� (����� ����)
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
		// �� �� ���ٰ� ��� �� ����
	}

	printf("5���� �̸�, �й�, ������ �Է����ּ���. \n");
	// 5���� �л��� ������ �Է¹���
	for (int i = 0; i < 5; i++) {
		fscanf_s(stdin, "%s %s %lf", &input_s.name,10, &input_s.start_uni,20, &input_s.grade);
		// �л��� ������ �Է¹޾Ƽ�
		fprintf(f, "%s %s %lf\n", input_s.name, input_s.start_uni, input_s.grade);
		// ���Ͽ� ������
	}
	fclose(f); // ������ ������ �ݾ���
	
	// ������� �ּ�ó���� ���, �Է��� ���� ���� �ʰ� ���Ͽ� ����� ������ ������ ����� ������ �� �ֽ��ϴ�.

	if (fopen_s(&f, profile, "r") != 0) {
		// ������ �� �� ���� ��� (�б�� ����)
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
		// �� �� ���ٰ� ��� �� ����
	}

	while(!feof(f)){
		// ������ ���� ������
		fscanf_s(f, "%s %s %lf", &profile_s[index].name,10,&profile_s[index].start_uni,20, &profile_s[index].grade);
		// ���Ͽ� ����Ǿ� �ִ� �л��� ������ ����ü �迭 index���� ����
		index++; // index�� 1�÷� ���� ĭ�� ����� �� �ֵ��� ��
	}
	
	fclose(f); // ������ ������ �ݾ���
	

	for (int i = 0; i < 5; i++) {
		// 5���� �л��̱� ������ 5�� �ݺ�
		if (s_grade < profile_s[i].grade) {
			s_grade = profile_s[i].grade;
		}
		/* ���� ���� ������ �л� ã��
		(s_grade�� ���Ͽ� ���� �ε����� �л��� ������ �� ���� �� s_grade�� ����Ǵ� ���� ���� �ε����� �л��� ������ �ǵ��� ��)
		*/
		sum_grade += profile_s[i].grade; // ��ü �л��� ���� ��
	}
	for (int i = 0; i < 5; i++) {
		if (profile_s[i].grade == s_grade) {
			printf("������ ���� ���� �л��� �̸� : %s, �й� : %s, ���� : %.2lf\n", profile_s[i].name, profile_s[i].start_uni, profile_s[i].grade);
		}
		/*
		������ ���� ���� �л� ���. ������ �Ҽ��� ��°�ڸ������� ���
		���� ���� ����� ���� ���̸� ��� �� ������ֱ� ���� �ݺ��� �̿�
		*/
	}
	printf("��ü �л��� ��� : %.2lf, �ְ��� : %.2lf", sum_grade / 5, s_grade);
	// ��ü �л��� ��հ� �ְ����� ��� (����� �л��� �� 5���̱� ������, ������ 5�� ���� ���� �̿�)
}