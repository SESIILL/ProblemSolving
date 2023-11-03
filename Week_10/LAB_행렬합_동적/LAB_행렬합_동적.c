#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int** a, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}

void matrixAdd(int** a, int** b, int** x, int r, int c) { 
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			x[i][j] = a[i][j] + b[i][j];
		}
	}
}

void printMatrix(int** a, int r, int c) { 
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	int** A, ** B, ** X; // A + B
	int aRow, aCol;
	int i, j;

	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &aRow, &aCol);

	A = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		A[i] = (int*)malloc(sizeof(int) * aCol);

	B = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		B[i] = (int*)malloc(sizeof(int) * aCol);

	X = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		X[i] = (int*)malloc(sizeof(int) * aCol);

	printf("\n(%d x %d) 행렬 A 입력:\n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("\n(%d x %d) 행렬 B 입력:\n", aRow, aCol);
	readMatrix(B, aRow, aCol);
	printf("\n[행렬합]\n");
	matrixAdd(A, B, X, aRow, aCol);
	printMatrix(X, aRow, aCol);

	for (i = 0; i < aRow; i++) {
		free(A[i]);
		free(B[i]);
		free(X[i]);
	}

	free(A);
	free(B);
	free(X);

	return 0;
}