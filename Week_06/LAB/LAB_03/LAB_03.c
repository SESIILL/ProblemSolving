#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// items[]: n 만큼의 요소가 저장된 배열
// bucket[]: bucketSize 만큼의 요소가 저장될 배열
// 순열: bucket에 새로운 item을 할당할 때, bucket에 존재하지 않는 아이템 중에서 뽑는다.

void pick(char** actors, int n, int* bucket, int bucketSize, int k) { 
    int i, lastIndex, smallest, item;
    if (k == 0) {
        for (i = 0; i < bucketSize; i++)
            printf("\t%s", actors[bucket[i]]);
        printf("\n");
        return;
    }

    lastIndex = bucketSize - k - 1;
    smallest = 0; // 순열은 순서를 고려하므로, 오름차순으로 뽑지 않는다. 전체 item이 나올 수 있는 candidate item이 된다.

    for (item = smallest; item < n; item++) { // 모든 아이템 중에 뽑는다.
        int j = 0; int flag = 0;
        for (j = 0; j <= lastIndex; j++) // 현재 bucket 안에 있는 모든 아이템 조사
            if (bucket[j] == item) flag = 1; // bucket 안에 있는 것이 item(후보)이면 flag = 1
        if (flag == 1) continue; // flag = 1 이면 밑줄의 코드 실행하지 않고, 중복이 나오지 않을 때까지 item을 늘려가며 조사한다.
        bucket[lastIndex + 1] = item;
        pick(actors, n, bucket, bucketSize, k - 1);
    }
}

int main(void) { // 동적 할당 순열
    char* actors[5] = { "공유", "김수현", "송중기", "지성", "현빈" }; // 2차원 포인터 배열
    int bucketSize;
    printf("상의 종류는? ");
    scanf("%d", &bucketSize);
    int* bucket = (int*)malloc(sizeof(int) * bucketSize);

    for (int i = 0; i < bucketSize; i++) {
        printf("\t상 %d", i + 1);
    }
    printf("\n");
    pick(actors, 5, bucket, bucketSize, bucketSize);
    free(bucket);

    return 0;
}