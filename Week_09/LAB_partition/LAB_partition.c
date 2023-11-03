#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// A[]: 정렬할 배열
// p: 정렬할 부분의 시작 인덱스
// r: 정렬할 부분의 끝 인덱스

int partition(int* A, int p, int r) {
	int i = p - 1; // 피벗보다 작은 값들의 마지막 인덱스
	int j; // loop variable
	int t;

	for (j = p; j < r; j++) { // 피벗(r)을 제외한 나머지 요소 탐색
		if (A[j] < A[r]) { // A[j]가 피벗보다 작은 경우
			i++; // i를 증가시키고
			
			// A[i]와 A[j]를 교환한다. 이로써 피벗보다 작은 값은 A[i]의 왼쪽에 위치하게 된다.
			t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}

	i++; // i+1 로 만듬.
	t = A[i]; // A[i+1] = 피벗, A[i+1]를 기준으로 피벗보다 작은 값, 큰 값 나눠짐.
	A[i] = A[r];
	A[r] = t;

	return i; // 피벗이 있는 위치 return
}

void printList(int A[], int s, int e) {
	for (int i = s; i <= e; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main(void) {
	int list1[] = { 0, 20, 55, 66, 10, 40, 88, 77, 30, 49 }; 
	int list2[] = { 0, 20, 10, 40, 30, 49, 88, 77, 55, 66 };
	int loc;

	// test 1
	printList(list1, 0, 9);
	loc = partition(list1, 0, 9); // 피벗의 위치
	printList(list1, 0, 9); // 결과는 list2의 값과 같게 된다.
	printf("%d의 위치는 %d\n\n", 49, loc); // 49(피벗)의 위치는 5
	
	// test 2
	printList(list2, 6, 9); // 88, 77, 55, 66
	loc = partition(list2, 6, 9);
	printList(list2, 6, 9); // 55, 66, 88, 77
	printf("%d의 위치는 %d\n\n", 66, loc); // 66의 위치는 7
	
	// test 3
	printList(list2, 0, 4); // 0, 20, 10, 40, 30
	loc = partition(list2, 0, 4);
	printList(list2, 0, 4); // 0, 20, 10, 30, 40
	printf("%d의 위치는 %d\n\n", 30, loc); // 30의 위치는 3
	
	return 0;
}