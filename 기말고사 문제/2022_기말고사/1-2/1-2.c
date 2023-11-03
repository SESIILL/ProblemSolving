#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int digit(int n) { 
	int count = 0;
	while (n != 0) {
		n /= 10;
		count++;
	}
	return count;
}

int main(void) {
	int n;
	int d; // 자릿수
	int result = 0;

	scanf("%d", &n);

	while (n > 0) {
		result = 1 + result;
		d = digit(result);

		if (n <= d) {
			for (int i = 0; i < d - n; i++) {
				result = result / 10;
			}
			printf("%d\n", result % 10);
		}
		n = n - d;
	}

	return 0;
}