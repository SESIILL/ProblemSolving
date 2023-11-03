#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void input(char name[]) {
	printf("Enter your name: ");
	scanf("%s", name);
}

void reverse(char name[]) {
	int len = strlen(name);
	printf("Reverse: ");
	for (int i = 0; i < len; i++)
		printf("%c", name[len - i - 1]);
	printf("\n");
}

int main(void) {
	char name[100]; // 충분히 긴 값으로 문자열 초기화
	input(name);
	reverse(name);

	return 0;
}