#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int matrixPath(int** m, int r, int c, int i, int j, int** M) {
    if (i == 0 && j == 0) // (0, 0)의 최소 경로를 구한다.
        return m[i][j];
    else if (i == 0) { // 천장
        if (M[0][j - 1] == 0)
            M[0][j - 1] = matrixPath(m, r, c, 0, j - 1, M);
        return M[0][j - 1] + m[i][j]; // 구한 이전의 위치 + 현재 위치
    } 
    else if (j == 0) { // 벽
        if (M[i - 1][0] == 0)
            M[i - 1][0] = matrixPath(m, r, c, i - 1, 0, M);
        return M[i - 1][0] + m[i][j];
    }
    else {
        if (M[i - 1][j] == 0)
            M[i - 1][j] = matrixPath(m, r, c, i - 1, j, M);
        if (M[i][j - 1] == 0)
            M[i][j - 1] = matrixPath(m, r, c, i, j - 1, M);
        return ((M[i - 1][j] < M[i][j - 1]) ? M[i - 1][j] : M[i][j - 1]) + m[i][j];
    }
}

int main(void) {
    int** m, ** M;
    int i, j, r, c;
    r = c = 4;

    m = (int**)malloc(sizeof(int*) * r); // 행렬 할당
    M = (int**)malloc(sizeof(int*) * r); // 메모 할당

    for (i = 0; i < r; i++) { // (0, 0)부터 (r-1, c-1)까지
        m[i] = (int*)malloc(sizeof(int) * c);
        M[i] = (int*)malloc(sizeof(int) * c);
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
            M[i][j] = 0; // 메모 초기화
        }
    }

    printf("%d\n", matrixPath(m, r, c, 3, 3, M)); // m, 4, 4, 3, 3, M

    for (i = 0; i < r; i++) {
        free(m[i]);
        free(M[i]);
    }
    free(m);
    free(M);

    return 0;
}