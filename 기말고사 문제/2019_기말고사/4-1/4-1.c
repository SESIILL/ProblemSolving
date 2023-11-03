#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* A, int n) {
    int i, j, k, temp;

    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++)
            if (A[j] > A[i])
                break;

        temp = A[i];
        for (k = i; k > j; k--)
            A[k] = A[k - 1];
        A[j] = temp;
    }
}

int main(void) {
    int s, q;
    int i, j;
    int** M;
    int* R;

    scanf("%d %d", &q, &s);
    M = (int**)malloc(sizeof(int*) * s);
    R = (int*)malloc(sizeof(int) * q); // 문제 수만큼 배열 생성

    for (i = 0; i < s; i++)
        M[i] = (int*)malloc(sizeof(int) * q);

    for (i = 0; i < s; i++) {
        for (j = 0; j < q; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    // R 초기화
    for (i = 0; i < q; i++)
        R[i] = 0;

    for (i = 0; i < q; i++) {
        for (j = 0; j < s; j++) {
            if (M[j][i] == 1)
                R[i] += 1;
        }
    }

    insertionSort(R, q);

    for (i = 0; i < q; i++)
        printf("%d ", R[i]);
    printf("\n");

    return 0;
}