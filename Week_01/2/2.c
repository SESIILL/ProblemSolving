#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isPrime(int x) {
	int flag = 1; // 소수

	if (x == 1) // 1은 소수가 아니다.
		flag = 0;
	else {
		for (int i = 2; i < x - 1; i++) {
			if (x % i == 0) {
				flag = 0; // 소수가 아님.
				break;
			}
		}
	}

	if (flag == 1)
		return 1;
	else
		return 0;
}

int main(void) {
	for (int i = 1; i <= 30; i++) {
		if (isPrime(i) == 1)
			printf("%d ", i);
	}
	printf("\n");

	return 0;
}