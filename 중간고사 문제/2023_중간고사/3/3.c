#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int* arr, int n) { // arr와 arr의 길이
	for (int i = 0; i < n - 1; i++) { // 마지막 배열 요소는 정렬할 필요가 없으므로 n-1회 반복
		for (int j = 0; j < n - i - 1; j++) { // 정렬된 배열을 제외하고 처음부터 끝까지 검사
			if (arr[j] > arr[j + 1]) { // 만약 뒤의 요소보다 앞의 요소가 더 크다면 두 값의 자리 바꿈.
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return;
}

int main(void) {
	int N, K;
	int* A;
	int* B;
	int total = 0;

	scanf("%d %d", &N, &K);

	A = (int*)malloc(sizeof(int) * N);
	B = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &B[i]);

	bubble_sort(A, N);
	bubble_sort(B, N);

	for (int i = 0; i < K; i++)
		B[i] = A[N - i - 1];

	for (int i = 0; i < N; i++)
		total += B[i];

	printf("%d\n", total);
	
	free(A);
	free(B);

	return 0;
}