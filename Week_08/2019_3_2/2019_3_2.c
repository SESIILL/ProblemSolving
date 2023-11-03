#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int calcDigit(int n) { // 자릿수 계산
	int count = 0;
	while (n != 0) {
		n /= 10;
		count++;
	}
	return count;
}

int main(void) {
	int pNum; // N번째 사람
	int digit; // 자릿수
	int three = 0; // 3을 더해갈 숫자

	printf("N번째 사람: ");
	scanf("%d", &pNum);

	while (pNum > 0) {
		three += 3;
		digit = calcDigit(three); // 3의 배수의 자릿수(1, 2, 3, 4...)

		if (pNum <= digit) {
			for (int i = 0; i < digit - pNum; i++) {
				three = three / 10;
			}
			printf("%d\n", three % 10);
		}
		pNum = pNum - digit;
	}
	
	return 0;
}