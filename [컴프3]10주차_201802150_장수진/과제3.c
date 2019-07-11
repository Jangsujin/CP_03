#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE *f1; // 비교할 대상 파일1 포인터
	FILE *f2; // 비교할 대상 파일2 포인터
	char name1[15]; // 비교할 파일1 이름 저장
	char name2[15]; // 비교할 파일2 이름 저장
	char line1[50]; // 파일1에서 읽은 문자열
	char line2[50]; // 파일2에서 읽은 문자열

	printf("첫 번째 파일 이름 : ");
	scanf_s("%s", name1,15); // 첫 번째 파일 이름 입력 받음
	printf("두 번째 파일 이름 : ");
	scanf_s("%s", name2,15); // 두 번째 파일 이름 입력 받음

	if (fopen_s(&f1, name1, "r") != 0) {
		// 첫 번째 파일을 열 수 없을 경우 (읽기로 열음)
		printf("파일이 열리지 않습니다.\n");
		exit(1);
		// 열 수 없다고 출력 후 종료
	}
	if (fopen_s(&f2, name2, "r") != 0) {
		// 두 번째 파일을 열 수 없을 경우 (읽기로 열음)
		printf("파일이 열리지 않습니다.\n");
		exit(1);
		// 열 수 없다고 출력 후 종료
	}
	while (!feof(f1) && !feof(f2)) {
		// 두 파일이 모두 끝나지 않은 동안에
		fgets(line1, 50, f1);
		// 파일1에서 한 줄 읽어옴
		fgets(line2, 50, f2);
		// 파일2에서 한 줄 읽어옴
		if (strcmp(line1, line2) != 0) {
			// 두 문자열을 비교하여 같지않으면
			printf("두 파일은 서로 다릅니다.\n"); // 같지 않다는 안내문을 출력한 후
			fclose(f1);
			fclose(f2);
			// 열었던 두 파일을 닫아준 후
			return 0; // 프로그램 종료
		}
	}
	if ((!feof(f1) && feof(f2)) || (feof(f1) && !feof(f2))) {
		// 두 파일 중 하나라도 끝나지 않은 게 있다면, 같은 내용의 파일이 아니므로
		printf("두 파일은 서로 다릅니다.\n"); // 같지 않다는 안내문을 출력한 후
		fclose(f1);
		fclose(f2);
		// 열었던 두 파일을 닫아준 후
		return 0; // 프로그램 종료
	}
	printf("두 파일은 서로 같습니다.\n");
	// 위의 같지 않은 조건을 모두 만족하지 않은 경우 파일의 내용이 같은 것이므로 같다는 안내문을 출력한 후
	fclose(f1);
	fclose(f2);
	// 열었던 두 파일을 닫아준 후
	return 0; // 프로그램 종료

}