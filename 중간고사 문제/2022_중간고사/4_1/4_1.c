#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int isSequence(int* a, int n) {
	int i = 0;
	int d = a[1] - a[0]; // 첫째 항의 등차

	for (i = 1; i < n - 1; i++) { // 길이가 n인 배열이므로 인덱스 번호는 n-1 까지임.
		if (d != a[i + 1] - a[i])
			return 0; // 등차수열이 아닌 경우
	}
	return 1; // 등차수열인 경우
}

int main(void) {
	int n; // 배열의 길이
	int* a; // 길이가 n인 배열

	printf("배열의 길이 입력: ");
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int) * n);

	printf("배열 입력: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	printf("%d\n", isSequence(a, n));
	free(a);
	
	return 0;
}
