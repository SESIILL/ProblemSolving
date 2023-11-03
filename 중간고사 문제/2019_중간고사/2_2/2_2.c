#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100]; // 충분히 큰 배열 선언
	printf("숫자 입력: ");
	scanf("%s", str);

	int last_digit = str[strlen(str) - 1] - '0'; // 배열의 마지막 자릿수

	// 2의 배수 판별
	if (last_digit % 2 == 0)
		printf("1");
	else
		printf("0");

	// 3의 배수 판별
	int i = 0;
	int three_sum = 0; // 각 자릿수의 합 저장

	while (str[i] != '\0') {
		three_sum += str[i] - '0';
		i++;
	}

	if (three_sum % 3 == 0)
		printf("1");
	else
		printf("0");

	// 4의 배수 판별
	int four_sum = 0;
	for (i = 0; i <= 1; i++)
		four_sum = (four_sum * 10) + (str[strlen(str) - 2 + i] - '0');

	if (four_sum % 4 == 0)
		printf("1");
	else
		printf("0");

	// 5의 배수 판별
	if (last_digit == 5 || last_digit == 0)
		printf("1\n");
	else
		printf("0\n");

	return 0;
}