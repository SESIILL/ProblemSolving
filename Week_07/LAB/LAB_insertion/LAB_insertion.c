#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int* arr, int n) { // arr와 arr의 길이
	int i, j, k, temp;
	for (i = 1; i < n; i++) { // 배열의 맨 첫번째 요소는 정렬되어 있다고 보고, index 1부터 정렬 시작
		for (j = 0; j < i; j++) { // 배열의 처음부터 자기 바로 앞 정렬된 배열까지 검사
			if (arr[j] > arr[i])
				break; // arr[i]보다 큰 수 중, 첫 번째 수가 있는 자리를 만나자마자 break
		}
		
		temp = arr[i];
		for (int k = i; k > j; k--)
			arr[k] = arr[k - 1]; // 뒤에서부터 하나씩 앞으로 미룬다.
		arr[j] = temp; // arr[j]의 자리에 arr[i]가 들어가야 한다.
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
		arr[i] = rand() % 100001; // 10만 이하의 난수 생성
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("정렬 후: ");
	insertion_sort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	free(arr);

	return 0;
}