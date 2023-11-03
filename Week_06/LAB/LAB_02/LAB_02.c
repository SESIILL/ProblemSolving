#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// items[]: n 만큼의 요소가 저장된 배열
// bucket[]: bucketSize 만큼의 요소가 저장될 배열

void pick(char** actors, int n, int* bucket, int bucketSize, int k) { // char** actors: 2차원 포인터 배열
    int i, lastIndex, smallest, item;

    if (k == 0) {
        for (i = 0; i < bucketSize; i++)
            printf("\t%s", actors[bucket[i]]);
        printf("\n");
        return;
    }

    lastIndex = bucketSize - k - 1;

    if (bucketSize == k)
        smallest = 0;
    else
        smallest = bucket[lastIndex] + 1;

    for (item = smallest; item < n; item++) {
        bucket[lastIndex + 1] = item;
        pick(actors, n, bucket, bucketSize, k - 1);
    }
}

int main(void) { // 동적 할당 조합
    char* actors[5] = { "공유", "김수현", "송중기", "지성", "현빈" }; // 2차원 포인터 배열
    int bucketSize;
    printf("인기상 몇 명? ");
    scanf("%d", &bucketSize);
    int* bucket = (int*)malloc(sizeof(int) * bucketSize);
    pick(actors, 5, bucket, bucketSize, bucketSize);
    free(bucket);

    return 0;
}