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

void matrixMul(int** a, int** b, int** x, int ar, int ac, int br, int bc) { // 행렬곱
	for (int i = 0; i < ar; i++) {
		for (int j = 0; j < bc; j++) {
			x[i][j] = 0;
			for (int k = 0; k < ac; k++) {
				x[i][j] += a[i][k] * b[k][j];
			}
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
}

void transposedMatrix(int** a, int** d, int r, int c) { // 전치행렬
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			d[i][j] = a[j][i];
		}
	}
}

int main(void) {
	int** A, ** B, ** C, ** D;
	int ar, ac;
	int br, bc;
	int i, j;

	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &ar, &ac);
	printf("Enter 행렬 B의 행과 열의 개수(B의 행은 %d이어야): ", ac);
	scanf("%d %d", &br, &bc);

	A = (int**)malloc(sizeof(int*) * ar);
	for (i = 0; i < ar; i++)
		A[i] = (int*)malloc(sizeof(int) * ac);

	B = (int**)malloc(sizeof(int*) * br);
	for (i = 0; i < br; i++)
		B[i] = (int*)malloc(sizeof(int) * bc);

	C = (int**)malloc(sizeof(int*) * ar); // 행렬곱
	for (i = 0; i < ar; i++)
		C[i] = (int*)malloc(sizeof(int) * bc);

	D = (int**)malloc(sizeof(int*) * ac); // 전치행렬
	for (i = 0; i < ac; i++)
		D[i] = (int*)malloc(sizeof(int) * ar);

	printf("\n(%d x %d) 행렬 A 입력:\n", ar, ac);
	readMatrix(A, ar, ac);
	printf("\n(%d x %d) 행렬 B 입력:\n", br, bc);
	readMatrix(B, br, bc);

	printf("\n[행렬곱]\n");
	matrixMul(A, B, C, ar, ac, br, bc);
	printMatrix(C, ar, bc);

	printf("\n[전치행렬]\n");
	transposedMatrix(A, D, ar, ac);
	printMatrix(D, ac, ar);

	for (i = 0; i < ar; i++) {
		free(A[i]);
	}

	for (i = 0; i < br; i++) {
		free(B[i]);
		free(C[i]);
	}

	for (i = 0; i < ac; i++) {
		free(D[i]);
	}

	free(A);
	free(B);
	free(C);
	free(D);

	return 0;
}