#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int digit(int n) {
	int count = 0;
	while (n != 0) {
		n /= 10;
		count++;
	}

	return count;
}

int main(void) {
	int n;
	int result = 0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		result += digit(i);
	}

	printf("%d\n", result);

	return 0;
}