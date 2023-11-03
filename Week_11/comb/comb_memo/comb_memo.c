#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comb(int n, int r, int** m) {
	if (r == 0 || r == n)
		return 1;
	else {
		if (m[n - 1][r - 1] == 0)
			m[n - 1][r - 1] = comb(n - 1, r - 1, m);
		else if (m[n - 1][r] == 0)
			m[n - 1][r] = comb(n - 1, r, m);
		return comb(n - 1, r - 1, m) + comb(n - 1, r, m);
	}
}

int main(void) {
	int C, n, r;
	int** m;

	scanf("%d %d", &n, &r);

	m = (int**)malloc(sizeof(int*) * (n + 1)); // n은 1부터 n까지
	for (int i = 1; i <= n; i++) {
		m[i] = (int*)malloc(sizeof(int) * (r + 1)); // r은 1부터 r까지
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= r; j++) {
			m[i][j] = 0;
		}
	}

	C = comb(4, 2, m);
	printf("%d\n", C);

	for (int i = 1; i <= n; i++) {
		free(m[i]);
	}
	free(m);

	return 0;
}