#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char string[100]; // 충분히 긴 값으로 문자열을 초기화한다.
	char character;

	printf("Enter a String: ");
	scanf("%s", string);
	while (getchar() != '\n'); // 버퍼 비워주기

	printf("Enter a Character: ");
	scanf("%c", &character);
	while (getchar() != '\n'); // 버퍼 비워주기

	int count = 0;
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == character)
			count++;
	}
	printf("'%c' is appeared %d times.\n", character, count);

	return 0;
}