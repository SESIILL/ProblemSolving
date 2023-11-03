#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int repeat(char* str) {
    int max = 0;  // 최대 반복 횟수를 저장하는 변수
    int current = 0;  // 현재 문자의 반복 횟수를 저장하는 변수
    char previous = '\0';  // 이전 문자를 저장하는 변수(널 문자로 초기화)

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == previous) {  // 현재 문자와 이전 문자가 같은 경우
            current++;
        }
        else {  // 현재 문자와 이전 문자가 다른 경우
            current = 1;
        }

        if (current > max) {
            max = current;  // 최대 반복 횟수 갱신
        }
        previous = str[i];
    }

    return max;
}

int main(void) {
    char str[100];
    scanf("%s", str);
    printf("%d\n", repeat(str));

    return 0;
}