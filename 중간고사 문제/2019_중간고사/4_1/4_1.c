#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(char* operator, int n, int* bucket, int bucketSize, int k, int N) {
	int i, lastIndex, smallest, item;
	int result = 0;
	int count = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			switch (operator[bucket[i]]) {
			case '+':
				result += (i + 1);
				break;
			case '-':
				result -= (i + 1);
				break;
			}
		}
		
		if (result == N)
			return 1; // count에 누적될 값(N으로 계산되면 +1)
		else
			return 0;
	}

	lastIndex = bucketSize - k - 1;
	smallest = 0;
	// 매번 하나도 뽑지 않은 것처럼. 전체 item이 candidate item이 된다.
	// 중복을 허용하고, 순서를 고려한다(오름차순이 아니다).

	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		count += pick(operator, n, bucket, bucketSize, k - 1, N); // 계산되는 경우의 수 count
	}

	return count;
}

int main(void) { // 중복순열
	char operator[] = "+-";
	int bucketSize, N;
	printf("Enter n and N: ");
	scanf("%d %d", &bucketSize, &N);
	int* bucket = (int*)malloc(sizeof(int) * bucketSize);
	pick(operator, bucketSize, bucket, bucketSize, bucketSize, N);

	if (pick(operator, 2, bucket, bucketSize, bucketSize, N) > 0) // N으로 계산되는 경우가 하나라도 있으면
		printf("1\n"); // 1 출력
	else
		printf("0\n"); // 0 출력(pick() == 0)

	return 0;
}