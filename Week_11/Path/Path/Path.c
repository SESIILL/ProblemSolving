#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int matrixPath(int** m, int r, int c, int i, int j) {
	if (i == 0 && j == 0) // (0, 0)의 최소 경로를 구한다.
		return m[i][j];
	else if (i == 0) // 천장
		return matrixPath(m, r, c, 0, j - 1) + m[i][j];
	else if (j == 0) // 벽
		return matrixPath(m, r, c, i - 1, 0) + m[i][j];
	else {
		int a, b;
		a = matrixPath(m, r, c, i - 1, j);
		b = matrixPath(m, r, c, i, j - 1);
		return ((a < b) ? a : b) + m[i][j];
	}
}

int main(void) {
	int** m;
	int i, j, r, c;
	r = c = 4;

	m = (int**)malloc(sizeof(int) * r);
	for (i = 0; i < r; i++) { // (0, 0)부터
		m[i] = (int*)malloc(sizeof(int) * c); // (r-1, c-1) 까지 행렬
	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
		}
	}

	printf("%d\n", matrixPath(m, r, c, 3, 3)); // m, 4, 4, 3, 3

	return 0;
}