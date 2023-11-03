#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// F[n] = F[n-1] + F[n-2]

int fib(int n, int* m) {
	if (n == 1 || n == 2)
		return 1;
	else {
		if (m[n - 1] == 0) // 메모에 값이 저장되어 있지 않다면
			m[n - 1] = fib(n - 1, m); // 재귀 호출하여 할당해준다.
		else if (m[n - 2] == 0)
			m[n - 2] = fib(n - 2, m);

		return m[n - 1] + m[n - 2];
	}
}

int main(void) {
	int n, i;
	int* m;

	printf("몇 번째까지의 피보나치 수열: ");
	scanf("%d", &n);

	m = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 1; i <= n; i++) {
		m[i] = 0; // 성립할수 없는 수로 초기화
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", fib(i, m));
	}
	printf("\n");

	free(m);

	return 0;
}