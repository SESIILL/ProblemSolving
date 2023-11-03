#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* A, * B;
    int temp, N, K, L;

    scanf("%d", &N);
    scanf("%d", &K);
    scanf("%d", &L);

    A = malloc(sizeof(int) * N);
    B = malloc(sizeof(int) * K);

    for (int i = 0; i < N; i++)
        A[i] = i;
    for (int i = 0; i < K; i++)
        scanf("%d", &B[i]);

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (B[i] == A[j])
            {
                if (j != 0)
                {
                    temp = A[j - 1];
                    A[j - 1] = A[j];
                    A[j] = temp;
                }
            }
        }
    }
    printf("%d", A[L]);

    return 0;
}