#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

insertionSort2(int* A, int s, int e) {
	int i, j, k, temp;

	for (i = s + 1; i <= e; i++) { // A[0]은 정렬되어 있다고 보고, A[1]부터 검사
		for (j = s; j < i; j++) { // 처음부터 자기 바로 앞 정렬되어 있는 배열까지
			if (A[j] > A[i]) // 자기보다 큰 수를 만나자마자 break
				break;
		}
		temp = A[i];
		for (k = i; k > j; k--)
			A[k] = A[k - 1];
		A[j] = temp;
	}
}
		
int main(void) {
	int n, s, e;
	int* A;

	scanf("%d", &n);
	A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	scanf("%d %d", &s, &e);
	insertionSort2(A, s, e);

	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	free(A);

	return 0;
}