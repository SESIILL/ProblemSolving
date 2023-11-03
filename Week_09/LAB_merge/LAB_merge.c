#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
	A[]: 정렬할 배열(p~r)
	p: 정렬할 부분의 시작 인덱스
	q: 정렬할 부분의 중간 인덱스(p~q, q+1~r)
	r: 정렬할 부분의 끝 인덱스
	temp: 병합 과정에서 임시로 사용되는 배열
*/

void merge(int A[], int p, int q, int r, int* temp) {
	int i = p; // 왼쪽 배열 시작 인덱스
	int j = q + 1; // 오른쪽 배열 시작 인덱스
	int t = p; // 임시 배열 시작 인덱스

	while (i <= q && j <= r) { 
		if (A[i] < A[j]) { // 작은 값이 A[i]에 있을 경우
			temp[t] = A[i]; // temp[t]에 작은 값을 넣음.
			t++; 
			i++; 
		}
		else { // 작은 값이 A[j]에 있을 경우
			temp[t] = A[j]; // temp[t]에 작은 값을 넣음.
			t++;
			j++;
		}
	}

	if (j > r) { // j가 먼저 r을 넘어서면
		for (; i <= q; i++, t++)
			temp[t] = A[i]; // 남은 i 요소들을 그대로 temp에 복사
	}
	else { // i가 먼저 q를 넘어서면
		for (; j <= r; j++, t++)
			temp[t] = A[j]; // 남은 j 요소들을 그대로 temp에 복사
	}

	for (i = p; i <= r; i++) 
		A[i] = temp[i]; // 임시 배열에 저장해둔 원소들을 A로 복사
}

void printList(int A[], int s, int e) {
	for (int i = s; i <= e; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main(void) {
	int list[] = { 10, 20, 30, 70, 80, 11, 33, 44, 55, 66 };
	int* temp = (int*)malloc(sizeof(int) * 10); // merge 결과를 저장할 임시 배열

	printList(list, 0, 9);
	merge(list, 0, 4, 9, temp);
	printList(list, 0, 9);

	free(temp);

	return 0;
}