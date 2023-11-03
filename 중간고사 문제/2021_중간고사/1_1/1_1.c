#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse(char src_s[], char s[]) {
	int i = 0;
	int len = strlen(src_s);
	while (i < len) {
		s[i] = src_s[len - i - 1];
		i++;
	}
	s[i] = '\0'; // s의 마지막 문자열에 null 문자를 넣어줌.
}

int main(void) {
	char src_s[101];
	char s[101];
	scanf("%s", src_s);
	reverse(src_s, s);
	printf("%s\n", s);

	return 0;
}