#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// items[]: n 만큼의 요소가 저장된 배열
// bucket[]: bucketSize 만큼의 요소가 저장될 배열

void pick(char* alphabet, int n, int* bucket, int bucketSize, int k) {
	int i, lastIndex, smallest, item;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%c ", alphabet[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1; // m - toPick - 1

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (item = smallest; item < n; item++) { // item은 candidate item의 의미를 가짐.
		bucket[lastIndex + 1] = item;
		pick(alphabet, n, bucket, bucketSize, k - 1);
	}
}

int main(void) { // 조합
	char alphabet[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	int bucket[3];
	pick(alphabet, 7, bucket, 3, 3);

	return 0;
}