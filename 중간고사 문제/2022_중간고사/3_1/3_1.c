#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void testPrint(int* a, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void selectionSortNew(int arr[], int start, int n) {
	for (int i = start; i < n - 1; i++) { // 마지막 배열 요소는 정렬할 필요가 없으므로 n-1회 반복
		int max = arr[start];
		int max_index = start;

		for (int j = start; j < n - i + 1; j++) { // 정렬된 배열을 제외하고 처음부터 끝까지 검사
			if (max < arr[j]) {
				max = arr[j]; // 임시 값 max에 제일 큰 수 저장
				max_index = j;
			}
		}

		int temp = arr[max_index]; // 임시 값에 j 루프 중 제일 큰 값(max) 저장
		arr[max_index] = arr[n - i]; // max에 마지막 배열의 값 저장
		arr[n - i] = temp; // 마지막 배열에 max 저장
	}
	return;
}

int main(void) {
	int n, start;
	int a[100];

	printf("배열의 개수 n: ");
	scanf("%d", &n);

	printf("배열 a의 원소 값: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("정렬을 시작하는 인덱스 start: ");
	scanf("%d", &start);

	selectionSortNew(a, start, n);
	printf("인덱스 %d부터 정렬: ", start);
	testPrint(a, n);
	printf("\n");

	return 0;
}
