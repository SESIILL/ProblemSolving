#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	int result = 1;
	for (int i = 0; i < n; i++) {
		result *= 2;
	}
	printf("%d", result);

	return 0;
}