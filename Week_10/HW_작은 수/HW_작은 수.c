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

int selection(int* A, int p, int r, int find) {
	int q = partition(A, p, r); // 피벗의 인덱스(기준)
	int leftSize = q - p + 1; // 왼쪽 배열의 크기

	if (leftSize == find) { // find번째 작은 수를 찾은 경우
		return A[q];
	}
	else if (find < leftSize) { // 찾고자 하는 인덱스가 왼쪽 배열 크기보다 작으면
		return selection(A, p, q - 1, find); // 시작점부터 피벗-1까지 재귀 호출
	}
	else { // 찾고자 하는 인덱스가 오른쪽 배열 크기보다 크면
		return selection(A, q + 1, r, find - leftSize); // 피벗+1부터 끝까지 재귀 호출
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
	int find;

	printf("배열의 길이: ");
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}

	printList(arr, 0, n - 1);

	printf("몇 번째 작은 수: ");
	scanf("%d", &find);
	printf("%d번째 작은 수는 %d\n", find, selection(arr, 0, n - 1, find));

	free(arr);

	return 0;
}