#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int nonuple = n * 9;
    char str[10];
    int i = 0;

    while (nonuple != 0) { // nonuple의 몫이 0이 아닐 때까지
        int reverse_num = nonuple % 10;
        str[i] = reverse_num + '0';
        nonuple /= 10;
        i++;
    }

    // 배열에 저장된 값을 역순으로 출력
    for (int j = i - 1; j >= 0; j--) { // j = i - 1로 설정함으로써, null 문자를 제외한 숫자부터 역순으로 출력한다.
        printf("%c ", str[j]);
    }
    printf("\n");

    return 0;
}