#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void encode(char s[], char e[]) {
    int i;
    for (i = 0; i < strlen(s); i++) {
        char ch = s[i];
        if ('A' <= ch && ch <= 'Z') { 
            e[i] = 'Z' - (ch - 'A');
        }
    }
    e[i] = '\0';
}

int main(void) {
    char s[26], e[26];
    scanf("%s", s);
    encode(s, e);
    printf("%s\n", e);

    return 0;
}