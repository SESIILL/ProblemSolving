#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sameArray(int arr1[], int arr2[]) {
	int flag = 1; // 두 개의 배열은 같다.
	for (int i = 0; i < 5; i++) {
		if (arr1[i] != arr2[i]) { // 루프 도중 하나라도 다르면
			flag = 0; // 두 개의 배열은 다르다.
			break;
		}
	}
	return flag;
}

int main(void) {
	int arr1[5], arr2[5];

	printf("Enter arr1: ");
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr1[i]);

	printf("Enter arr2: ");
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr2[i]);

	if (sameArray(arr1, arr2) == 1)
		printf("두 개의 배열은 같다.\n");
	else
		printf("두 개의 배열은 다르다.\n");

	return 0;
}