#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT 0 // start
#define LEFT 1 // 왼쪽에서 옴
#define UP 2 // 위에서 옴

int matrixpath_memo(int** m, int r, int c, int i, int j, int** M, int** bp) {
    if (i == 0 && j == 0) {
        M[i][j] = 0;
        bp[i][j] = 0;
        return m[i][j];
    }
    else if (i == 0) {
        if (M[i][j - 1] == 0) 
            M[i][j - 1] = matrixpath_memo(m, r, c, i, j - 1, M, bp);
        bp[i][j] = LEFT;
        return M[i][j - 1] + m[i][j];
    }
    else if (j == 0) {
        if (M[i - 1][j] == 0) 
            M[i - 1][j] = matrixpath_memo(m, r, c, i - 1, j, M, bp);
        bp[i][j] = UP;
        return M[i - 1][j] + m[i][j];
    }
    else {
        int a = M[i - 1][j];
        int b = M[i][j - 1];
        if (M[i - 1][j] == 0)
            a = matrixPath_memo(m, r, c, i - 1, j, M, bp);
        if (M[i][j - 1] == 0)
            b = matrixPath_memo(m, r, c, i, j - 1, M, bp);
        M[i][j] = ((a > b) ? b : a) + m[i][j];

        if (a > b)
            bp[i][j] = LEFT;
        else
            bp[i][j] = UP;
        return M[i][j];
    }
}

void print_path(int r, int c, int i, int j, int** bp) {
    if (bp[i][j] == DEFAULT)
        printf("<%d %d> ", i, j);

    if (bp[i][j] == LEFT) {
        print_path(r, c, i, j - 1, bp);
        printf("<%d %d> ", i, j);
    }
    else if (bp[i][j] == UP) {
        print_path(r, c, i - 1, j, bp);
        printf("<%d %d> ", i, j);
    }

    return;
}

int main(void) {
    int** m, ** M, ** bp; // M은 메모
    int i, j, r, c;
    r = c = 4; // 4x4 matrix

    m = (int**)malloc(sizeof(int*) * r);
    M = (int**)malloc(sizeof(int*) * r);
    bp = (int**)malloc(sizeof(int*) * r);

    for (i = 0; i < r; i++) {
        m[i] = (int*)malloc(sizeof(int) * c);
        M[i] = (int*)malloc(sizeof(int) * c);
        bp[i] = (int*)malloc(sizeof(int) * c);
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
            bp[i][j] = DEFAULT; // 백포인터를 start로 초기화
        }
    }

    printf("%d\n", matrixpath_memo(m, r, c, 3, 3, M, bp));
    print_path(r, c, 3, 3, bp);
    printf("\n");

    return 0;
}