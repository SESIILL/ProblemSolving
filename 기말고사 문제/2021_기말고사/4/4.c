#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count = 0;

void pick(int* items, int n, int* picked, int m, int toPick, int num) { // 중복조합
    int lastIndex, i, smallest;
    int sum = 0;

    lastIndex = m - toPick - 1;
    for (i = 0; i <= lastIndex; i++) // 매번 뽑힌 수까지의 합을 구해 봄.
        sum = sum + items[picked[i]];

    if (sum > num) // sum이 num보다 커지면 더 이상 호출 X
        return;

    if (sum == num) { // 재귀 호출의 중간이라도 sum = num이 되면 호출을 중단하고 출력
        count++;
        return;
    }

    if (toPick == 0) // 다 뽑았을 때 sum < num인 경우
        return; // 답이 아니다.

    if (m == toPick)
        smallest = 0;
    else
        smallest = picked[lastIndex];

    for (i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1, num);
    }
}

int main() {
    int num;
    int items[] = { 1, 2 };
    int* picked;
    int picked_size;

    scanf("%d", &num);

    picked_size = num; // 모두 1로 뽑히는 경우의 수
    picked = (int*)malloc(sizeof(int) * picked_size);

    pick(items, 2, picked, picked_size, num, num);
    printf("%d\n", count);

    free(picked);

    return 0;
}