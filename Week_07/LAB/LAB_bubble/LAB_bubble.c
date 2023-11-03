#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	bubble_sort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	free(arr);

	return 0;
}