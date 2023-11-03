#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int* bucket, int bucketSize, int k) { 
	int i, lastIndex, smallest, item;
	
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1; 
	smallest = 0;
	// 매번 하나도 뽑지 않은 것처럼. 전체 item이 candidate item이 된다.
	// 중복을 허용하고, 순서를 고려한다(오름차순이 아니다).

	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		pick(n, bucket, bucketSize, k - 1);
	}
}

int main(void) { // 중복순열
	int bucketSize;
	printf("정수 입력: ");
	scanf("%d", &bucketSize);
	int *bucket = (int*)malloc(sizeof(int) * bucketSize);
	pick(4, bucket, bucketSize, bucketSize); // 4진법이므로 0부터 3까지

	return 0;
}