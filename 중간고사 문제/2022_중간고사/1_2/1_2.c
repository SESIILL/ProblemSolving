#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int result = 0; // 전역 변수

int transformR(int n, int* a, int k) {
	if (n != 0) {
		a[result] = n % k;
		result++;
		transformR(n / k, a, k);
	}
	else
		return result; // n == 0 일 때 result(size) 반환
}

void testPrint(int* a, int size) {
	for (int i = size - 1; i >= 0; i--)
		printf("%d ", a[i]);
	printf("\n");
}

int main(void) {
	int n, k;
	int a[100], size;

	printf("Enter n and k: ");
	scanf("%d %d", &n, &k);

	size = transformR(n, a, k);
	testPrint(a, size);

	return 0;
}
