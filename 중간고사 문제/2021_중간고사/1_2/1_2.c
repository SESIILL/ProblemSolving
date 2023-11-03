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
	char s1[101], s2[101];
	scanf("%s %s", s1, s2);

	char r_s1[101], r_s2[101];
	reverse(s1, r_s1);
	reverse(s2, r_s2);

	int carry = 0;
	int carry_count = 0;
	int i = 0;

	// 문자열의 길이가 다른 경우, 더 긴 문자열의 길이만큼 0을 채워줌.
	if (strlen(r_s1) >= strlen(r_s2)) {
		for (int j = strlen(r_s2); j < strlen(r_s1); j++)
			r_s2[j] = '0';
	}
	else {
		for (int j = strlen(r_s1); j < strlen(r_s2); j++)
			r_s1[j] = '0';
	}
		
	while (i < strlen(r_s1)) {
		int r1 = r_s1[i] - '0';
		int r2 = r_s2[i] - '0'; // 문자를 숫자로 변환

		if (r1 + r2 + carry >= 10) {
			carry_count++;
			carry = 1;
		}
		else
			carry = 0; // 다음 번에 carry가 발생하지 않았으면 0으로 초기화

		i++;
	}
	printf("%d", carry_count);

	return 0;
}