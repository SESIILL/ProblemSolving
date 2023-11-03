#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char num[52];
	int two, three, four, five;

	printf("숫자 입력: ");
	scanf("%s", num);
	int len = strlen(num);

	// 2의 배수 확인
	if ((num[strlen(num) - 1] - '0') % 2 == 0)
		two = 1;
	else
		two = 0;

	// 5의 배수 확인
	if ((num[strlen(num) - 1] - '0') == 0 || (num[strlen(num) - 1] - '0') == 5)
		five = 1;
	else
		five = 0;

	// 3의 배수 확인
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += num[i] - '0';

	if (sum % 3 == 0)
		three = 1;
	else
		three = 0;

	// 4의 배수 확인
	four = ((num[strlen(num) - 2] - '0') * 10) + (num[strlen(num) - 1] - '0'); // 입력된 수 끝 2자리
	if (four % 4 == 0)
		four = 1;
	else
		four = 0;

	printf("%d%d%d%d\n", two, three, four, five);

	return 0;
}