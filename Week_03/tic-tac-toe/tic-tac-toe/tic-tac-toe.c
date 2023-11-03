#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 게임판을 빈칸으로 초기화
void init_board(char b[][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            b[i][j] = ' ';
        }
    }
}

// 게임판 출력
void display(char b[][3]) {
    int i, j;
    printf("   0  1  2\n");
    for (i = 0; i < 3; i++) {
        printf("%d: ", i);
        for (j = 0; j < 3; j++) {
            printf("%c  ", b[i][j]);
        }
        printf("\n");
    }
}

// 게임판 채우기
int input_board(char b[][3], int row, int col, char mark) {
    if (row < 0 || row > 2 || col < 0 || col > 2) { // 보드에서 벗어난 칸을 선택할 경우
        return 0;
    }
    else if (b[row][col] == ' ') { 
        b[row][col] = mark;
        return 1;
    }
    else { // 이미 채운 칸을 선택했을 경우
        return 0;
    }
}

// 이긴 사람 찾기
int check_win(char b[][3], char mark) {
    for (int i = 0; i < 3; i++) { // 가로 체크
        if (b[i][0] == mark && b[i][1] == mark && b[i][2] == mark) {
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) { // 세로 체크
        if (b[0][i] == mark && b[1][i] == mark && b[2][i] == mark) {
            return 1;
        }
    }

    if (b[0][0] == mark && b[1][1] == mark && b[2][2] == mark) { // 대각선 체크
        return 1;
    }
    if (b[0][2] == mark && b[1][1] == mark && b[2][0] == mark) {
        return 1;
    }

    return 0; // 무승부
}

int main(void) {
    char b[3][3];

    init_board(b);
    display(b);

    int row, col;
    int count = 0;
    char mark;

    while (1) {
        while (1) {  
            printf("Player X<행 열>: ");
            scanf("%d %d", &row, &col);
            if (input_board(b, row, col, 'X') == 1) {
                printf("\n");
                display(b);
                count++;
                break;
            }
            else { // input_board = 0이면 다시 입력받음.
                continue;
            }
        }
        if (check_win(b, 'X') == 1) {
            printf("Player X wins!");
            break;
        }
        else if (count == 9) {
            printf("Nobody wins!");
            break;
        }

        while (1) {
            printf("Player O<행 열>: ");
            scanf("%d %d", &row, &col);
            if (input_board(b, row, col, 'O') == 1) {
                printf("\n");
                display(b);
                count++;
                break;
            }
            else { // input_board = 1이면 다시 입력받음.
                continue;
            }
        }
        if (check_win(b, 'O') == 1) {
            printf("Player O wins!");
            break;
        }
        else if (count == 9) {
            printf("Nobody wins!");
            break;
        }
    }

    return 0;
}