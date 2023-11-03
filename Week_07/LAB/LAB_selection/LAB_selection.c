#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int* arr, int n) { // arr와 arr의 길이
	for (int i = 0; i < n - 1; i++) { // 마지막 배열 요소는 정렬할 필요가 없으므로 n-1회 반복
		int max = arr[0];
		int max_index = 0;

		for (int j = 1; j < n - i; j++) { // 정렬된 배열을 제외하고 처음부터 끝까지 검사
			if (max < arr[j]) {
				max = arr[j]; // 임시 값 max에 제일 큰 수 저장
				max_index = j;
			}
		}

		int temp = arr[max_index]; // 임시 값에 j 루프 중 제일 큰 값(max) 저장
		arr[max_index] = arr[n - i - 1]; // max에 마지막 배열의 값 저장
		arr[n - i - 1] = temp; // 마지막 배열에 max 저장
	}
	return;
}

int main(void) {
	srand(time(NULL));

	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	printf("정렬 전: ");
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 1000; // 0부터 999까지
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("정렬 후: ");
	selection_sort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	free(arr);

	return 0;
}