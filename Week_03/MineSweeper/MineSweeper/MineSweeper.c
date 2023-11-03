#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define X_VALUE 5 //2차원 배열의 행의 수
#define Y_VALUE 5 //2차원 배열의 열의 수

void readBombInfo(char grid[][Y_VALUE + 1]) {
	// grid 및 지뢰 정보 입력
	printf("Input Grid\n");
	for (int i = 0; i < X_VALUE; i++)
		scanf("%s", grid[i]);
	printf("\n");
}

void countBomb(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE]) {
	int i, j;

	for (i = 0; i < X_VALUE; i++)
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*') {
				// 현재 위치가 지뢰일 경우, 주변의 8개 위치의 지뢰 개수를 증가시킴.
				if (i > 0 && j > 0) //좌상단
					numOfBombs[i - 1][j - 1]++;
				if (i > 0) //상단
					numOfBombs[i - 1][j]++;
				if (i > 0 && j < Y_VALUE - 1) //우상단
					numOfBombs[i - 1][j + 1]++;
				if (j > 0) //좌측
					numOfBombs[i][j - 1]++;
				if (j < Y_VALUE - 1) //우측
					numOfBombs[i][j + 1]++;
				if (i < X_VALUE - 1 && j > 0) //좌하단
					numOfBombs[i + 1][j - 1]++;
				if (i < X_VALUE - 1) //하단
					numOfBombs[i + 1][j]++;
				if (i < X_VALUE - 1 && j < Y_VALUE - 1) //우하단
					numOfBombs[i + 1][j + 1]++;
			}
}

// 지뢰가 설치되어 있지 않은 셀 위치에 주변 지뢰의 개수를 출력한다.
void digitsAround(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE]) {
	int i, j;
	for (i = 0; i < X_VALUE; i++) {
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*')
				printf("*");
			else
				printf("%d", numOfBombs[i][j]);
		printf("\n");
	}
}

int main(void) {
	char grid[X_VALUE][Y_VALUE + 1]; // 문자열의 경우 마지막에 NULL이 들어가야 하므로 5X5 배열이 아닌 5X6 배열이 되어야 한다.
	int numOfBombs[X_VALUE][Y_VALUE] = { 0 }; // 지뢰의 개수를 넣는 정수형 5X5 배열

	readBombInfo(grid);
	countBomb(grid, numOfBombs);
	digitsAround(grid, numOfBombs);
}
