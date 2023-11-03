#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, m, start;
    char ladder[100][100];

    scanf("%d %d", &n, &m, &start);
    scanf("%d", &start);

    for (int i = 0; i < m; i++) {
        scanf("%s", ladder[i]);
    }

    int pos = start;
    for (int i = 0; i < m; i++) {
        if (ladder[i][pos] == '1') { // 우대각선으로 갈 수 있으면
            pos++; // 기준점을 우로 옮긴다.
        }
        else if (pos > 0 && ladder[i][pos - 1] == '1') { // 좌대각선으로 갈 수 있으면
            pos--; // 기준점을 좌로 옮긴다.
        }
    }
    printf("%d\n", pos);

    return 0;
}