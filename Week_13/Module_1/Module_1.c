#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

int main(void) {
    char key[] = "PROGRAMMING";
    remove_duplicated_char(key);
    printf("%s\n", key); // "PROGAMIN" 출력(M, G 제거)

    return 0;
}