#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max = -100000;

int pick(char* operator, int* A, int n, int* bucket, int bucketSize, int k) {
	int i, lastIndex, smallest, item;
	int result = 0;

	if (k == 0) {
		if (operator[bucket[0]] != '*') {
			for (i = 0; i < bucketSize; i++) {
				switch (operator[bucket[i]]) {
				case '+':
					result += A[i];
					break;
				case '-':
					result -= A[i];
					break;
				case '*':
					result *= A[i];
					break;
				}
			}
		}

		if (result > max)
			max = result;

		return max;
	}

	lastIndex = bucketSize - k - 1;
	smallest = 0;

	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		pick(operator, A, n, bucket, bucketSize, k - 1);
	}
}

int main(void) { 
	char operator[] = "+-*";
	int N;
	scanf("%d", &N);

	int *A = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int* bucket = (int*)malloc(sizeof(int) * N);
	pick(operator, A, N, bucket, N, N);

	printf("%d\n", max);

	return 0;
}