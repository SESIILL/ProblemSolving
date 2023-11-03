#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char ladder[100][100];
	int N, M; // 6, 3
	int location;

	scanf("%d %d %d", &N, &M, &location);
	while (getchar() != '\n'); // 버퍼 비워주기

	for (int i = 0; i < M; i++) { // 줄 수만큼 입력받는다.
		scanf("%s", ladder[i]); // %s는 개행 문자로 자동 구분 가능
	}

	for (int i = 0; i < M; i++) {
		if (ladder[i][location] == '1' && location < N - 1) // 우대각선으로 갈 수 있고, 
			location++;
		else if (ladder[i][location - 1] == '1' && location > 0) // 좌대각선으로 갈 수 있고, location이 0보다 크면
			location--;
	}
	printf("최종 위치: %d\n", location);

	return 0;
}