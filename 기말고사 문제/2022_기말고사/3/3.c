#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int min = 10000;

void pick(int* items, int n, int* picked, int m, int toPick, int N) {
    int lastIndex, i, smallest;
    int sum = 0;
    int count = 0; // 최솟값

    lastIndex = m - toPick - 1;
    for (i = 0; i <= lastIndex; i++)
        sum = sum + items[picked[i]];

    if (sum > N)
        return;

    if (sum == N) {
        for (i = 0; i <= lastIndex; i++) 
            count++;
        if (min > count)
            min = count;
        return;
    }

    if (toPick == 0)
        return;

    if (m == toPick)
        smallest = 0;
    else
        smallest = picked[lastIndex];

    for (i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1, N);
    }
}

int main(void) {
    int items[100];
    int N;
    int* bucket;
    int bucketSize;

    scanf("%d", &N);

    for (int i = 0; i < 100; i++) {
        items[i] = (i + 1) * (i + 1);
    }

    bucketSize = 5;
    bucket = (int*)malloc(sizeof(int) * bucketSize);

    pick(items, 100, bucket, bucketSize, bucketSize, N);
    printf("%d\n", min);

    free(bucket);
    
    return 0;
}