#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void echo(int arr[]) {
	printf("5개의 정수 입력: ");
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);
}

void reverse(int arr[]) {
	printf("배열 역순 출력: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[5 - i - 1]);
	printf("\n");
}

int main(void) {
	int arr[5];
	echo(arr);
	reverse(arr);

	return 0;
}