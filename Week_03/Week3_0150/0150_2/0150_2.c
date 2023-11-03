#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned long long calculateReverse(unsigned long long n) {
    unsigned long long reversed = 0;

    while (n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return reversed;
}

int main() {
    unsigned long long n1, n2, input_n;
    int count = 0;

    printf("정수 입력: ");
    scanf("%llu", &input_n);

    n1 = input_n;
    n2 = calculateReverse(n1);

    // palindrome을 찾지 못했을 경우
    while (n1 != n2) {
        // count를 증가시키고, 더한 숫자가 새로운 n1이 된다.
        count++;
        n1 = n1 + n2;
        n2 = calculateReverse(n1);

        if (count > 1000) {
            printf("NaN\n");
            return 0;
        }
    }

    printf("count: %d, palindrome: %llu\n", count, n1);
}