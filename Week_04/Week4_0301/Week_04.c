#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int picked[], int m, int toPick) {
	int i, lastIndex, smallest; // 필요한 변수 3가지

	// trivial case
	if (toPick == 0) { // 다 뽑았으면
		for (i = 0; i < m; i++) {
			printf("%d ", picked[i]);
		}
		printf("\n");
		return; // 프로그램 종료
	}

	lastIndex = m - toPick - 1; // picked[] 에서 마지막에 채워진 요소의 인덱스

	// recursive case
	if (m == toPick) { // 처음 고르는 거면
		smallest = 0; // 들어갈 제일 작은 수는 0이다.
	}
	else { // 처음 고르는 게 아니면
		smallest = picked[lastIndex] + 1; // 들어갈 제일 작은 수는 직전 수의 +1이다.
	}

	for (i = smallest; i < n; i++) { // smallest의 모든 경우의 수를 생각해서
		picked[lastIndex + 1] = i; // lastIndex의 다음 칸에 넣는다.
		pick(n, picked, m, toPick - 1); // toPick == 0이 될 때까지 재귀 호출
	}
}

int main(void) {
	int n, m;
	printf("Enter n and m: ");
	scanf("%d %d", &n, &m);

	int* picked = (int*)malloc(sizeof(int) * m);
	pick(n, picked, m, m);

	free(picked);

	return 0;
}