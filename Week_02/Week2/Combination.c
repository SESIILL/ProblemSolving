#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pick(int n, int picked[], int m, int toPick) {
	int smallest, lastIndex, i;

	// 더 이상 뽑을 것이 없으면 뽑힌 배열을 출력한다.
	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			printf("%d ", picked[i]);
		}
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1; // 마지막에 뽑힌 수의 인덱스 번호
	
	if (toPick == m) { // 처음 뽑는다면
		smallest = 0; // 뽑아야 하는 수 중 가장 작은 수는 0이다.
	}
	else { // 처음 뽑는 것이 아니라면
		smallest = picked[lastIndex] + 1; // 뽑아야 하는 가장 작은 수는 마지막에 뽑힌 수의 + 1 이다.
	}

	for (i = smallest; i < n; i++) { // smallest부터 마지막 수까지 루프를 돌면서
		picked[lastIndex + 1] = i; // 마지막 인덱스의 다음 칸에 smallest를 넣는다.
		pick(n, picked, m, toPick - 1); // 앞으로 뽑아야 하는 수에서 -1을 적용하여 재귀 호출
	}
}

int main() {
	int picked[4];
	pick(7, picked, 4, 4);

	return 0;
}