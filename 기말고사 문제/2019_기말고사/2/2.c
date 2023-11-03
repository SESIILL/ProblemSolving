#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void printCode(char c[]) {
	int i;
	for (i = 0; i < 26; i++) {
		printf("%c", c[i]);
	}
	printf("\n");
}

void makeCode(char code[], int distance) {
	int i, j;
	int index = distance - 1; // 4
	int k = 0;

	for (i = 0; i < 26; i++) {
		if (index >= 25)
			break;

		code[index] = 'A' + i;
		index += distance;
	}

	printf("%d\n", i); // 5

	for (j = 0; j < 26; j++) {
		if ((j + 1) % distance != 0) {
			code[k] = 'A' + i;
			i++;
		}
		k++;
	}
	code[26] = '\0';
}


int main(void) {
	int distance;
	char code[27];

	scanf("%d", &distance);
	makeCode(code, distance);
	printCode(code);

	return 0;
}