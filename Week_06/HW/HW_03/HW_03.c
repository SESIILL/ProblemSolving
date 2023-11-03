#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* money, int n, int* bucket, int bucketSize, int k) { 
	int i, lastIndex, smallest, item;
	int sum = 0; 

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			sum += money[bucket[i]]; // 뽑힌 money들을 sum에 저장
		}

		if (sum == (bucketSize * 1000)) { // 만약 sum이 입력받은 bucketSize와 같다면
			for (i = 0; i < bucketSize; i++) { 
				if (money[bucket[i]] != 0) // money가 0이 아닌 경우에만
					printf("%d ", money[bucket[i]]); // money를 출력한다.
			}
			printf("\n");
		}
		return;
	}

	lastIndex = bucketSize - k - 1;
	
	if (bucketSize == k)
		smallest = 0;
	else
		// 크거나 같은 것을 뽑을 수 있기 때문에, 조합처럼 bucket[lastIndex] + 1 하지 않음.
		smallest = bucket[lastIndex];
	
	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		pick(money, n, bucket, bucketSize, k - 1);
	}
}

int main(void) { // 중복조합
	int money[4] = { 0, 1000, 5000, 10000 }; // 길이가 4인 int형 배열
	int bucketSize;
	printf("세뱃돈 입력: ");
	scanf("%d", &bucketSize);
	bucketSize /= 1000; // bucketSize를 6으로 하기 위해 1000을 나눠 준다.
	int* bucket = (int*)malloc(sizeof(int) * bucketSize);
	pick(money, 4, bucket, bucketSize, bucketSize); // bucketSize = 6

	return 0;
}