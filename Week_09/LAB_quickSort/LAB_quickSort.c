#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A[]: 정렬할 배열
// p: 정렬할 부분의 시작 인덱스
// r: 정렬할 부분의 끝 인덱스

int partition(int* A, int p, int r) {
	int i = p - 1; // 피벗보다 작은 값들의 마지막 인덱스
	int j; // loop variable
	int t;

	for (j = p; j < r; j++) { // 피벗(r)을 제외한 나머지 요소 탐색
		if (A[j] < A[r]) { // A[j]가 피벗보다 작은 경우
			i++; // i를 증가시키고

			// A[i]와 A[j]를 교환한다. 이로써 피벗보다 작은 값은 A[i]의 왼쪽에 위치하게 된다.
			t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}

	i++; // i+1 로 만듬.
	t = A[i]; // A[i+1] = 피벗, A[i+1]를 기준으로 피벗보다 작은 값, 큰 값 나눠짐.
	A[i] = A[r];
	A[r] = t;

	return i; // 피벗이 있는 위치 return
}

void quickSort(int* A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

void printList(int A[], int s, int e) {
	for (int i = s; i <= e; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main(void) {
	srand(time(NULL));

	int n;
	printf("배열의 길이: ");
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100000;
	}

	printList(arr, 0, n - 1);
	quickSort(arr, 0, n - 1);
	printList(arr, 0, n - 1);

	free(arr);

	return 0;
}


// 내림차순 정렬
int partition(int* A, int p, int r) {
	int i = p - 1; // 피벗보다 작은 값들의 마지막 인덱스
	int j; // loop variable
	int t;

	for (j = p; j < r; j++) { // 피벗(r)을 제외한 나머지 요소 탐색
		if (A[j] > A[r]) { // A[j]가 피벗보다 큰 경우
			i++; // i를 증가시키고

			// A[i]와 A[j]를 교환한다. 이로써 피벗보다 큰 값은 A[i]의 왼쪽에 위치하게 된다.
			t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}

	i++; // i+1 로 만듬.
	t = A[i]; // A[i+1] = 피벗, A[i+1]를 기준으로 피벗보다 작은 값, 큰 값 나눠짐.
	A[i] = A[r];
	A[r] = t;

	return i; // 피벗이 있는 위치 return
}

void quickSort(int* A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}