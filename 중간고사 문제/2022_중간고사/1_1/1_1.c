#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, k;
	int result[100];

	printf("Enter n and k: ");
	scanf("%d %d", &n, &k);

	int i = 0;
	int count = 0;
	while (n != 0) { // 진수 변환한 값을 거꾸로 저장
		result[i] = n % k;
		n /= k;
		i++;
	}
	count = i; // count = strlen(result)

	for (int i = 0; i < count; i++) {
		printf("%d ", result[count - i - 1]);
	}

	return 0;
}