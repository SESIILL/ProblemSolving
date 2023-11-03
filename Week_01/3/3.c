#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int total(int n) {
	int total = 0;
	for (int i = 1; i <= n; i++)
		total += i;
	return total;
}

int main(void) {
	int n;
	printf("Input a number(exit -1): ");
	scanf("%d", &n);

	while (n != -1) {
		printf("1부터 %d까지의 합은 %d\n", n, total(n));
		printf("Input a number(exit -1): ");
		scanf("%d", &n);
	}

	return 0;
}