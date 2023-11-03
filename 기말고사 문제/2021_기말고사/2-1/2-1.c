#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int is_in(char word[], char ch) {
	int i;
	for (i = 0; word[i] != '\0'; i++)
		if (word[i] == ch)
			return 1;
	return 0;
}

void makeCode(char code[], char word[]) {
	int i, j;
	int index = 0;
	int len = strlen(word);

	// 암호화표의 나머지 문자들을 'A'부터 차례로 넣음
	for (i = 0; i < 26; i++) {
		char ch = 'A' + i;

		if (!is_in(word, ch)) {
			code[index++] = ch;
		}
	}

	// 암호화표의 가장 뒤에 keyWord를 추가
	for (j = 0; j < len; j++) {
		code[index++] = word[j];
	}
}

void printCode(char code[]) {
	int i;
	for (i = 0; i < 26; i++)
		printf("%c", code[i]);
	printf("\n");
}

int main(void) {
	char code[26]; 
	char keyWord[10];

	scanf("%s", keyWord);
	
	makeCode(code, keyWord);
	printCode(code);

	return 0;
}