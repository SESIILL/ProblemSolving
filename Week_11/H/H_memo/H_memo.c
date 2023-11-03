#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H(int n, int* m) {
	if (n == 0 || n == 1)
		return 1;
	else {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (m[i] == 0)
				m[i] = H(i, m);
			else if (m[n - i - 1] == 0)
				m[n - i - 1] = H(n - i - 1, m);
			sum += m[i] * m[n - i - 1];
		}
		return sum;
	}
}

int main(void) {
	int n;
	int* m;
	
	printf("0보다 큰 정수: ");
	scanf("%d", &n);

	m = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		m[i] = 0;
	}

	printf("결과: %d\n", H(n, m));

	free(m);

	return 0;
}