#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void makeCode(char code[], int dist) {
    for (int i = 0; i < 26; i++) 
        code[i] = 'A' + ((i + dist) % 26);
}

void printCode(char code[]) {
    int i;
    for (i = 0; i < 26; i++) { // 일반 알파벳 출력
        printf("%c", 'A' + i);
    }
    printf("\n");

    for (i = 0; i < 26; i++) { // 암호화된 알파벳 출력
        printf("%c", code[i]);
    }
    printf("\n");
}

void encode(char code[], char s[], char e[]) {
    int i = 0;
    for (i = 0; i < strlen(s); i++) {
        char ch = s[i]; // I

        if ('A' <= ch && ch <= 'Z') { // 대문자라면
            int relative_pos = ch - 'A'; // I - A = 9
            e[i] = code[relative_pos]; // code[9] = I와 대응하는 암호화된 알파벳
        }
        else // 소문자라면
            e[i] = ch;
    }
    e[i] = '\0';
}

int main(void) {
    int distance;
    char code[26]; // 암호화된 대문자 알파벳
    char sentence[80], encodedSentence[80];

    printf("Enter a distance for encoding: ");
    scanf("%d", &distance);

    makeCode(code, distance);
    printCode(code);

    gets(sentence);
    printf("Enter a sentence to encode: ");
    gets(sentence);

    printf("original sentence:\t");
    puts(sentence);

    encode(code, sentence, encodedSentence);
    printf("encoded sentence:\t");
    puts(encodedSentence);

    return 0;
}