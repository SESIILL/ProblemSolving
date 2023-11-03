#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count = 0;

void pick(int* items, int n, int* picked, int m, int toPick, int key) { // 중복조합
    int lastIndex, i, smallest;
    int sum = 0;

    lastIndex = m - toPick - 1;
    for (i = 0; i <= lastIndex; i++) // 매번 뽑힌 수까지의 합을 구해 봄.
        sum = sum + items[picked[i]];

    if (sum > key) // sum이 exchange보다 커지면 더 이상 호출 X
        return;

    if (sum == key) { // 재귀 호출의 중간이라도 sum = 6000원이 되면 호출을 중단하고 출력
        count++;
        return;
    }

    if (toPick == 0) // 다 뽑았을 때 sum < exchange인 경우
        return; // 답이 아니다.

    if (m == toPick)
        smallest = 0;
    else
        smallest = picked[lastIndex];

    for (i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1, key);
    }
}


int main(void) {
    int n, bucketSize;
	int a[3] = { 1, 2, 3 };
    int* bucket;

	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);
    bucketSize = n;

	pick(a, 3, bucket, bucketSize, n, n);
	printf("%d\n", count);

	free(bucket);

	return 0;
}