#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	unsigned long long n;
	int k;
	char result[100]; // k진법으로 변환할 수

	printf("Enter n and k: ");
	scanf("%llu %d", &n, &k);

	int i = 0;
	while (n != 0) {
		if (n % k > 10) { // 10 이상의 숫자라면 알파벳으로 표현
			result[i] = n % k + '0' + 7;
		}
		else { // 0~9 사이 숫자라면 문자열로 변환만 하면 됨.
			result[i] = n % k + '0';
		}
		n /= k;
		i++;
	}
	result[i] = '\0'; // 배열의 끝에 null 문자 추가

	int count = 0;
	for (i = 0; i < strlen(result) / 2; i++) {
		if (result[i] == result[strlen(result) - i - 1]) {
			count++;
		}
	}

	if (count == strlen(result) / 2)
		printf("palindrome");
	else
		printf("not palindrome");

	return 0;
}