#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void printCode(char c[]) {
	int i;

	for (i = 0; i < 26; i++) {
		printf("%c", 'A' + i);
	}
	printf("\n");

	printf("encoded:\t");
	for (i = 0; i < 26; i++) {
		printf("%c", c[i]);
	}
	printf("\n");
}

void remove_duplicated_char(char* word) {
	int len = strlen(word);
	int index = 0; // 중복이 아닌 문자를 저장할 인덱스
	int i, j;

	for (i = 0; i < len; i++) {
		int is_duplicate = 0; // 현재 문자가 중복되는지 아닌지를 확인할 변수

		for (j = 0; j < index; j++) {
			if (word[i] == word[j]) {
				is_duplicate = 1;
				break;
			}
		}

		if (!is_duplicate) {
			word[index] = word[i];
			index++;
		}
	}
	word[index] = '\0';

	return;
}

void makeCode(char code[], int d, char key[]) {
	int i, j;
	int isSame = 0;
	int index = d;
	
	// 먼저 code의 중간에 key 값을 넣는다.
	for (i = 0; key[i] != '\0'; i++) {
		if (index == 26) {
			index = 0; // 미루지 않은 것과 같다.
		}
		code[index] = key[i];
		index++;
	}

	// key값을 제외한 나머지 알파벳을 code에 넣는 과정
	for (i = 'A'; i <= 'Z'; i++) {
		for (j = 0; key[j] != '\0'; j++) {
			if (i == key[j]) {
				isSame = 1;
			}
		}

		if (isSame == 0) { // 중복이 아니라면
			if (index == 26) { // 만약 index가 끝에 다다랐는데도 남은 알파벳이 있으면
				index = 0; // code[0] 부터 순차적으로 삽입
			}
			code[index++] = i; // key 뒤부터 알파벳을 넣음.
		}
	}
	code[26] = '\0';
}

int main(void) {
	int distance;
	char code[27];
	char key[30];

	printf("Enter a word to use for encoding: ");
	scanf("%s", &key);

	printf("Enter a distance for encoding: ");
	scanf("%d", &distance);

	remove_duplicated_char(key); 
	makeCode(code, distance, key);
	printCode(code);

	return 0;
}