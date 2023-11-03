#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int digit(int n) { // n의 자릿수 계산
	int digit = 0;
	while (n != 0) {
		n /= 10;
		digit++;
	}
	return digit;
}

int kth_digit(int n, int k) { // n 안의 k번째 수를 구함.
	int i, ret;
	for (i = 0; i < k; i++) {
		ret = n % 10;
		n /= 10;
	}
	return ret;
}

int solution(int n) { // n번째 숫자는 i 안에 있다.
	int i = 0;
	int totalDigits = 0; // 자릿수의 누적합

	while (totalDigits < n) { // n = 11일 때, totalDigits가 11보다 커지면 루프 탈출
		i++;
		totalDigits += digit(i); // 1의 자릿수 + 2의 자릿수 + ...
	}
	return kth_digit(i, totalDigits - n + 1); // n 안의 k번째 수를 구함.
}

int main(void) {
	int n;

	scanf("%d", &n);
	printf("%d\n", solution(n));

	return 0;
}