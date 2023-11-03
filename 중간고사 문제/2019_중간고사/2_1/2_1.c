#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[101];
	printf("자연수 입력: ");
	scanf("%s", str);

	int i = 0;
	int num = str[strlen(str) - 1] - '0';
	// strlen은 null 문자를 제외한 문자열의 길이를 반환하므로, 마지막 문자열의 인덱스 번호는 -1을 해 줘야 한다.

	printf("result: ");
	if (num % 2 == 0)
		printf("1\n");
	else
		printf("0\n");

	return 0;
}