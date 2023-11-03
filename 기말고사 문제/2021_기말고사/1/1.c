#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N;
	int f = 1;
	int count = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		f *= i;
	}

	for (int i = 0; i < N; i++) {
		if (f % 10 == 0) {
			count++;
			f /= 10;
		}
		else
			break;
	}
	printf("%d\n", count);

	return 0;
}