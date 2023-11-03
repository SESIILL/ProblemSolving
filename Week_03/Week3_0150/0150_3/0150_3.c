#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int generate_number_ones(int length) {
    int result = 0;

    for (int i = 0; i < length; i++) {
        result = result * 10 + 1;
    }

    return result;
}

int main() {
    int A, C;
    int count = 1;
    
    printf("Enter A: ");
    scanf("%d", &A);

    while (1) {
        C = generate_number_ones(count);

        //count를 늘려 가면서 count만큼의 length를 가진 1을 생성한다.
        if (C % A == 0) {
            printf("1의 개수: %d\n", count);
            break;
        }
        count++;
    }
    
}
