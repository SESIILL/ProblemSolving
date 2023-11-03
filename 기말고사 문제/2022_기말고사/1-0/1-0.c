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
	scanf("%d", &n);

	printf("%d\n", digit(n));

	return 0;
}