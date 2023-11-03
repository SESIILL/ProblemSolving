#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* item, int n, int* bucket, int m, int toPick, int target, int* min) {
    int i, lastIndex, smallest;
    int sum = 0;
    lastIndex = m - toPick - 1;

    for (i = 0; i <= lastIndex; i++)
        sum = sum + (item[bucket[i]] * item[bucket[i]]);

    if ((lastIndex + 1) > *min) // 이미 뽑힌 min보다 새로 뽑은 항의 개수가 더 크다면
        return; // 더 이상 min보다 작은 항의 개수가 나오지 않을 것이므로 return

    if (sum == target) {
        if (*min > (lastIndex + 1)) // 항의 개수는 인덱스의 값 + 1
            *min = lastIndex + 1;
        return;
    }

    if (sum > target)
        return;

    if (toPick == 0)
        return;

    if (m == toPick)
        smallest = 0;
    else
        smallest = bucket[lastIndex];

    for (i = smallest; i < n; i++) {
        bucket[lastIndex + 1] = i;
        pick(item, n, bucket, m, toPick - 1, target, min);
    }
}

int main() {
    int n;
    int* item;
    int* bucket;
    int min = 0;
    int i = 0;

    scanf("%d", &n); // 1000

    bucket = (int*)malloc(sizeof(int) * n); // 1000칸
    item = (int*)malloc(sizeof(int) * (n - 1)); // 999칸

    for (i = n - 2; i >= 1; i--) // item의 크기가 n-1 이므로 인덱스는 n-2부터 시작
        item[i] = i; // 998, 997, 996, ... 1

    min = n; // min이 될 수 있는 최댓값은 n
    pick(item, n - 1, bucket, n, n, n, &min);

    printf("%d\n", min);

    return 0;
}