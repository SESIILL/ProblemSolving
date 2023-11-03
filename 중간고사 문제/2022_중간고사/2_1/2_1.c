#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int minusCarryCount(int n1, int n2) {
	int carry = 0;
	int carry_count = 0;
	int r1, r2;

	while (n1 != 0 || n2 != 0) {
		r1 = n1 % 10;
		r2 = n2 % 10;

		if (r1 - r2 - carry < 0) {
			carry = 1;
			carry_count++;
		}
		else
			carry = 0;

		n1 /= 10;
		n2 /= 10;
	}

	return carry_count;
}

int main(void) {
	int num1, num2; // 항상 num1 > num2
	printf("두 개의 자연수: ");
	scanf("%d %d", &num1, &num2);
	printf("minusCarry: %d\n", minusCarryCount(num1, num2));

	return 0;
}