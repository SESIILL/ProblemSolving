#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int total = 0;
int value = 0;

int isSequence(int* a, int n) {
    int i = 0;
    int d = a[1] - a[0]; // 첫째 항의 등차

    for (i = 1; i < n - 1; i++) { // 길이가 n인 배열이므로 인덱스 번호는 n-1 까지임.
        if (d != a[i + 1] - a[i] || -d != a[i + 1] - a[i])
            return 0; // 등차수열이 아닌 경우
    }
    return 1; // 등차수열인 경우
}

void bubble_sort(int* arr, int n) { // arr와 arr의 길이
    for (int i = 0; i < n - 1; i++) { // 마지막 배열 요소는 정렬할 필요가 없으므로 n-1회 반복
        for (int j = 0; j < n - i - 1; j++) { // 정렬된 배열을 제외하고 처음부터 끝까지 검사
            if (arr[j] > arr[j + 1]) { // 만약 뒤의 요소보다 앞의 요소가 더 크다면 두 값의 자리 바꿈.
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return;
}

void pick(int* A, int* B, int n, int* bucket, int bucketSize, int k, int* temp) {
    int i, lastIndex, smallest, item;

    if (k == 0) {
        for (i = 0; i < bucketSize; i++) {
            temp[i] = B[bucket[i]];
            B[bucket[i]] = A[i];
        }

        //for (i = 0; i < n; i++) 
        //   printf("%d ", B[i]);

        if (isSequence(B, n) == 1) {
            value = 1;
            for (int k = 0; k < n; k++)
                total += B[k];
            return;
        }

        for (i = 0; i < bucketSize; i++)
            B[bucket[i]] = temp[i];

        return;
    }

    lastIndex = bucketSize - k - 1;
    smallest = 0;

    for (item = smallest; item < n; item++) {
        int j = 0; int flag = 0;

        for (j = 0; j <= lastIndex; j++)
            if (bucket[j] == item) flag = 1;
        if (flag == 1) continue;

        bucket[lastIndex + 1] = item;
        pick(A, B, n, bucket, bucketSize, k - 1, temp);
    }
}

int main(void) {
    int Na, Nb;
    int* A;
    int* B;

    scanf("%d", &Na);
    A = (int*)malloc(sizeof(int) * Na);
    for (int i = 0; i < Na; i++)
        scanf("%d", &A[i]);

    scanf("%d", &Nb);
    B = (int*)malloc(sizeof(int) * Nb);
    for (int i = 0; i < Nb; i++)
        scanf("%d", &B[i]);

    bubble_sort(A, Na);
    bubble_sort(B, Nb);

    int* bucket = (int*)malloc(sizeof(int) * Na);
    int* temp = (int*)malloc(sizeof(int) * Na);
    pick(A, B, Nb, bucket, Na, Na, temp);

    if (value == 1)
        printf("%d\n", total);
    else
        printf("-1\n");

    return 0;
}