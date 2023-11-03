#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int n, int* bucket, int bucketSize, int k) { // 조합
	int i, lastIndex, smallest, item;
	int sum = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++){
			printf("%d ", bucket[i] + 1);
			sum += items[bucket[i]];
		}
		printf(": %d\n", sum);
		return;
	}

	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		pick(items, n, bucket, bucketSize, k - 1);
	}
}

int main(void) {
    int s;
    int* items;
    int* picked;
    int picked_size;

    scanf("%d", &s); // 학생 수
    items = (int*)malloc(sizeof(int) * s); // 능력치
    for (int i = 0; i < s; i++)
        scanf("%d", &items[i]);

    picked_size = s / 2;
    picked = (int*)malloc(sizeof(int) * picked_size);

    pick(items, s, picked, picked_size, picked_size);

	free(items);
    free(picked);

    return 0;
}