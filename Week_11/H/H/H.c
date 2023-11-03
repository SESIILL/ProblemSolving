#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H(int n) {
	if (n == 0 || n == 1)
		return 1;
	else {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += H(i) * H(n - i - 1);
		}
		return sum;
	}
}

int main(void) {
	int n;
	printf("0보다 큰 정수: "); // 배열의 크기는 n+1이어야 하고, 초기화도 1부터 해야 한다.
	scanf("%d", &n);
	printf("결과: %d\n", H(n));

	return 0;
}