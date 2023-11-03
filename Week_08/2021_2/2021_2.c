#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int n;
	scanf("%d", &n);
	n = n * 9; // 수를 9배 한다.

	char nineNum[100];
	int i = 0;

	while (n > 0) {
		nineNum[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	nineNum[i] = '\0';

	int len = strlen(nineNum);
	for (i = 0; i < len; i++)
		printf("%c ", nineNum[len - i - 1]);
	printf("\n");

	return 0;
}