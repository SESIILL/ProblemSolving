#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H(int n, int* M) {
	int i;
	int sum = 0;

	if (n == 1)
		return 1;
	else {
		for (i = 0; i < n; i++) {
			if (M[i] == 0)
				M[i] = H(i, M);
			sum += (i * M[i]);
		}
		return sum;
	}
}

int main(void) {
	int n, i;
	int* M;

	scanf("%d", &n);
	M = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		M[i] = 0;

	printf("%d\n", H(n, M));
	free(M);

	return 0;
}