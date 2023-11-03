#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int carry_count = 0;

int minusCarryCountR(int n1, int n2, int carry) {
	if (n1 == 0)
		return carry_count;
	else {
		int r1 = n1 % 10;
		int r2 = n2 % 10;

		if (r1 - r2 - carry < 0) {
			carry = 1;
			minusCarryCountR(n1 / 10, n2 / 10, carry);
			carry_count++;
		}
		else
			minusCarryCountR(n1 / 10, n2 / 10, carry);
	}
}

int main(void) {
	int num1, num2;
	int carry = 0;
	printf("두 개의 자연수: ");
	scanf("%d %d", &num1, &num2);
	printf("minusCarry: %d\n", minusCarryCountR(num1, num2, carry));

	return 0;
}
