#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n1, n2; //두 개의 자연수
    int r1, r2; //각 자연수의 마지막 자릿수
    int carry = 0; 
    int carry_count = 0;

    printf("두 개의 자연수 입력: ");
    scanf("%d %d", &n1, &n2);

    while (n1 != 0 || n2 != 0) { 
        r1 = n1 % 10;
        r2 = n2 % 10;

        if (r1 + r2 + carry >= 10) {
            carry = 1; //carry는 1, 0 둘 중에 하나이다.
            carry_count++;
        }
        else
            carry = 0;

        //recursion
        n1 = n1 / 10;
        n2 = n2 / 10;
    }

    printf("carry의 발생 횟수: %d\n", carry_count);
}