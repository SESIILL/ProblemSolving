#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int min = 10000;

void pick(int* items, int n, int* bucket, int m, int toPick, int sum) { // 조합
    int lastIndex, i, smallest;

    if (toPick == 0) {
        int sumA = 0;
        int sumB = 0;
        int diff = 0; // 두 팀 능력치의 차이

        for (i = 0; i < m; i++) {
            sumA += items[bucket[i]]; // sumA에 3명의 능력치를 더함.
        }

        sumB = sum - sumA;
        diff = ((sumA > sumB) ? (sumA - sumB) : (sumB - sumA)); // 음수값 방지

        //for (i = 0; i < m; i++) {
        //    printf("%d ", bucket[i]);
        //}
        //printf("%d\n", diff);

        if (min > diff)
            min = diff;

        return;
    }

    lastIndex = m - toPick - 1;

    if (m == toPick)
        smallest = 0;
    else
        smallest = bucket[lastIndex] + 1;

    for (i = smallest; i < n; i++) {
        bucket[lastIndex + 1] = i;
        pick(items, n, bucket, m, toPick - 1, sum);
    }
}

int main() {
    int n, i;
    int* capacity;
    int* bucket;
    int sum = 0; // 전체 학생의 능력치

    scanf("%d", &n);

    bucket = (int*)malloc(sizeof(int) * (n / 2)); // 3명을 뽑으면 자동으로 나머지 3명이 정해지므로, bucketSize = 3
    capacity = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) { // 6명의 능력치 입력받기
        scanf("%d", &capacity[i]);
        sum += capacity[i];
    }

    bucket[0] = 0; // 3명 중에 한 명은 무조건 0번의 사람이다.
    pick(capacity, n, bucket, n / 2, n / 2 - 1, sum); // 0번의 사람을 제외하고 2명만 뽑음.
    printf("%d\n", min);

    return 0;
}