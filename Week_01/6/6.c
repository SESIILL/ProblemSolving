#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

void lotto(void) {
	printf("*** 로또 번호 생성기 ***\n");
	printf("생성 번호: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", rand() % 46);
	}
	printf("\n");
}

int main(void) {
	srand(time(NULL));
	char answer = 'a';

	while (answer != 'n') {
		lotto();
		printf("다시 생성하겠습니까? (y/n): ");
		scanf("%c", &answer);
		while (getchar() != '\n'); // 버퍼 비워주기
		printf("\n");
	}

	return 0;
}