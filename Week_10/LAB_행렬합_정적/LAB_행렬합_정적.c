#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void readMatrix(int a[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}

void matrixAdd(int a[][3], int b[][3], int x[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			x[i][j] = a[i][j] + b[i][j];
		}
	}
}

void printMatrix(int a[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	int a[3][3];
	int b[3][3];
	int x[3][3];

	printf("(3 x 3) 행렬 A 입력:\n");
	readMatrix(a);
	printf("\n(3 x 3) 행렬 B 입력:\n");
	readMatrix(b);

	printf("\n[행렬합]\n");
	matrixAdd(a, b, x);
	printMatrix(x);

	return 0;
}