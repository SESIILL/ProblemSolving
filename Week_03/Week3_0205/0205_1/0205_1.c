#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_cycle_number(int n) {
	int cycle_length = 1;

	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else if (n % 2 == 1) {
			n = n * 3 + 1;
		}
		cycle_length++;
	}

	return cycle_length;
}

int main() {
	int n = 22;
	printf("%d의 사이클 길이: %d\n", n, get_cycle_number(n));
}
