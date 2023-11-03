#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// F[n] = F[n-1] + F[n-2]

int fib(int n) {
	if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

int main(void) {
	int n, i;

	printf("몇 번째까지의 피보나치 수열: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		printf("%d ", fib(i));
	}
	printf("\n");

	return 0;
}