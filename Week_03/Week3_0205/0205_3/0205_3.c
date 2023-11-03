#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int H(int i) {
	//trivial case
	if (i == 0 || i == 1) {
		return 1;
	}

	//recursive case
	if (i > 1) {
		int sum = 0;
		for (int j = 0; j < i; j++) {
			sum += H(j) * H(i - j - 1);
		}
	}
}

int main() {
	int n = 10;
	printf("%d\n", H(n));
}
