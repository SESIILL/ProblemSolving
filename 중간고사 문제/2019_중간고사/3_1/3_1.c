#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int solution(int n) {
	int count = 0;
	while (n != 0) {
		n /= 10;
		count++;
	}

	return count;
}

int main(void) {
	int n;
	printf("자연수 입력: ");
	scanf("%d", &n);
	printf("자릿수: %d\n", solution(n));

	return 0;
}