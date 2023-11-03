#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse(char src_s[], char s[]) {
	int len = strlen(src_s);
	for (int i = 0; i < len; i++) {
		s[i] = src_s[len - i - 1];
	}
	s[len] = '\0';
}

int carry(char s1[], char s2[]) {
	int carry = 0;
	int carry_count = 0;
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if (len1 > len2) {
		for (int i = len2; i < len1; i++) 
			s2[i] = '0';
	}

	if (len1 < len2) {
		for (int i = len1; i < len2; i++)
			s1[i] = '0';
	}

	int j = 0;
	while (j < len1) {
		if ((s1[j] - '0') + (s2[j] - '0') + carry >= 10) {
			carry = 1;
			carry_count++;
		}
		else
			carry = 1;
		
		j++;
	}
	return carry_count;
}

int main(void) {
	char src_s1[101], src_s2[101];
	char s1[101], s2[101];

	scanf("%s", src_s1);
	scanf("%s", src_s2);

	reverse(src_s1, s1);
	reverse(src_s2, s2);

	printf("carry: %d\n", carry(s1, s2));

	return 0;
}