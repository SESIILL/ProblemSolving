#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int get_cycle_number(int n) {
    //trivial case
    if (n == 1)
        return 1;
    //recursive case
    else if (n % 2 == 0)
        return get_cycle_number(n / 2) + 1;
    else
        return get_cycle_number(n * 3 + 1) + 1;
}

void main() {
    int n = 22;
    printf("%d의 사이클 길이: %d\n", n, get_cycle_number(n));
}