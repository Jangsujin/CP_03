#include <stdio.h>

float GetMid(float, float, float); // GetMid �Լ� ����
float GetMin(float, float, float); // GetMin �Լ� ����
float GetMax(float, float, float); // GetMax �Լ� ����


int main() {
	float f1, f2, f3;
	printf("3���� �Ǽ��� �Է����ּ��� : "); // �Ǽ� �Է� �ȳ���
	scanf_s("%f %f %f", &f1, &f2, &f3); // �Է� ����
	printf("%f %f %f�� ������\n%f %f %f �Դϴ�.\n", f1, f2, f3, GetMin(f1, f2, f3), GetMid(f1, f2, f3), GetMax(f1, f2, f3));
	// ������� ���

	return 0;


}

float GetMid(float num1, float num2, float num3) {
	// �߰��� ��ȯ
	while (1) {
		if (((num1 < num2) && (num2 < num3))||((num1>num2) && (num2>num3))) {
			// num2�� �߰����� �� 
			return num2; // num2�� ����
		}
		else {
			// ���� num2�� �߰����� �ƴ� ���
			float temp = num1;
			num1 = num3;
			num3 = num2;
			num2 = temp;
			// num1,2,3�� ������ �ٲ�
		}
	}
}

float GetMin(float num1, float num2, float num3) {
	// �ּҰ� ��ȯ
	float fir_check, se_check;
	// ó�� Ȯ���ϰ� ���� �� ���� ����, �� ��° Ȯ���ϰ� ���� �� ���� ����
	fir_check = (num1 < num2) ? num1 : num2;
	// �� ���� ���� fir_check�� ����
	se_check = (fir_check < num3) ? fir_check : num3;
	// �� ���� ���� se_check�� ����

	return se_check; // se_check ��ȯ
}

float GetMax(float num1, float num2, float num3) {
	// �ִ밪 ��ȯ
	float fir_check, se_check;
	// ó�� Ȯ���ϰ� ū �� ���� ����, �� ��° Ȯ���ϰ� ū �� ���� ����
	fir_check = (num1 < num2) ? num2 : num1;
	// �� ū ���� fir_check�� ����
	se_check = (fir_check < num3) ? num3 : fir_check;
	// �� ū ���� se_check�� ����

	return se_check; // se_check ��ȯ
}
