#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

insertionSort(int* A, int n) { // n: 배열의 크기
    int i, j, k, temp;
    for (i = 1; i < n; i++) { // 인덱스 1부터 n - 1까지(인덱스 0 제외하고 배열 전체 순회)
        for (j = 0; j < i; j++)
            if (A[j] < A[i]) break;
        temp = A[i];
        for (k = i; k > j; k--)
            A[k] = A[k - 1];
        A[j] = temp;
    }
}

int main(void) {
    int r, c; // r = 5, c = 4
    int i, j;
    int** matrix; // r = 5, c = 4인 2차원 배열
    int** result; // r = 2, c = 4인 2차원 배열
    int* index;

    scanf("%d %d", &c, &r); // 4, 5

    matrix = (int**)malloc(sizeof(int*) * r);
    for (i = 0; i < r; i++)
        matrix[i] = (int*)malloc(sizeof(int) * c);

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);
    }

    result = (int**)malloc(sizeof(int*) * 2);
    for (i = 0; i < 2; i++)
        result[i] = (int*)malloc(sizeof(int) * c);

    for (i = 0; i < 2; i++) { // result 배열 초기화
        for (j = 0; j < c; j++)
            result[i][j] = 0;
    }

    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) {
            if (matrix[j][i] == 0)
                result[1][i] += 1; // 못 푼 사람의 수
        }
        result[0][i] = (i + 1); // 문제 번호
    }

    index = (int*)malloc(sizeof(int) * c);
    for (i = 0; i < c; i++)
        index[i] = result[1][i]; // index 배열에 그대로 복사

    insertionSort(index, c); // 못 푼 사람의 수가 많은 순서대로 정렬(내림차순)

    for (i = 0; i < c; i++) {
        for (j = 0; j < c; j++) {
            if (index[i] == result[1][j]) { // 정렬된 점수와 아닌 점수가 같다면
                printf("%d ", result[0][j]); // 문제 번호 출력
                break;
            }
        }
    }
    printf("\n");

    return 0;
}