#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Coefficient {
	int F1;
	int F0;
};

struct Coefficient fibo(int n, struct Coefficient* memo) {
	struct Coefficient ret;

	if (memo[n].F1 != -1) // Memoization이 일어났다면
		return memo[n];

	if (n == 0) { // F0 = 0F1 + 1F0
		ret.F1 = 0;
		ret.F0 = 1;
		memo[n] = ret; // Memoization이 일어나지 않았다면
		return ret;
	}
	else if (n == 1) { // F1 = 1F1 + 0F0
		ret.F1 = 1;
		ret.F0 = 0;
		memo[n] = ret; // Memoization이 일어나지 않았다면
		return ret;
	}
	else { // recursive case
		struct Coefficient fib1;
		struct Coefficient fib2;

		fib1 = fibo(n - 1, memo); // n-1번째 항의 F1, F0 계수 계산
		fib2 = fibo(n - 2, memo); // n-2번째 항의 F1, F0 계수 계산

		ret.F1 = fib1.F1 + fib2.F1; // ret 구조체의 F1에 계산된 계수를 넣음
		ret.F0 = fib1.F0 + fib2.F0; // ret 구조체의 F0에 계산된 계수를 넣음
		memo[n] = ret; // Memoization이 일어나지 않았다면
		return ret;
	}
}

int main(void) {
	int n, i;
	struct Coefficient fib;
	struct Coefficient* memo;

	scanf("%d", &n);

	memo = (struct Coefficient*)malloc(sizeof(struct Coefficient) * (n + 1));
	for (i = 0; i < n + 1; i++) {
		memo[i].F1 = -1;
		memo[i].F0 = -1;
	}

	fib = fibo(n, memo);
	printf("%d %d\n", fib.F1, fib.F0);

	return 0;
}