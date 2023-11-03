#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int solution(int n) { // n의 자릿수를 반환하는 함수
	int count = 0;
	while (n != 0) {
		n /= 10;
		count++;
	}
	return count;
}

int main(void) {
	int N;
	int* arr;
	int remember = 0;
	printf("N번째 사람: ");
	scanf("%d", &N);

	int i = 1; // 3의 배수의 순서
	int three = 3;

	while (i < N) {
		if (three < 10) { // 3, 6, 9 
			i++;
			three += 3;
		}
		else { // 12부터
			int size = solution(three); // 자릿수 구하기
			arr = (int*)malloc(sizeof(int) * size);// 자릿수만큼의 arr 배열
			int temp = three; // three를 변환시키지 않기 위해 임시 변수에 저장

			for (int j = 0; j < size; j++) { 
				arr[size - i - 1] = temp % 10; // 배열에 숫자 하나씩 저장
				if (i == N)
					remember = j;
				temp /= 10;
				i++; // 한 자리씩 저장할 때마다 순번 증가
			}
			
			three += 3;
		}
	}
	
	if (N <= 3)
		printf("%d\n", three);
	else {
		printf("%d\n", arr[remember]);
	}

	free(arr);

	return 0;
}