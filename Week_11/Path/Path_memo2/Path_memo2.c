#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int matrixPath(int** m, int r, int c, int i, int j, int** M) {
    if (M[i][j] != 0) // 이미 계산된 값이 있으면
        return M[i][j];

    if (i == 0 && j == 0) // 시작점(0, 0)
        return m[i][j];
    else if (i == 0) {
        M[i][j] = matrixPath(m, r, c, 0, j - 1, M) + m[i][j];
        return M[i][j];
    }
    else if (j == 0) {
        M[i][j] = matrixPath(m, r, c, i - 1, 0, M) + m[i][j];
        return M[i][j];
    }
    else {
        int a, b;
        a = matrixPath(m, r, c, i - 1, j, M);
        b = matrixPath(m, r, c, i, j - 1, M);
        M[i][j] = ((a < b) ? a : b) + m[i][j];
        return M[i][j];
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