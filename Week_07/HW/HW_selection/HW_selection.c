#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
	int id, kor, eng, mat;
};

void selectionSort(struct Student* s, int n) {
	struct Student temp; // 구조체형 임시 변수

	for (int i = 0; i < n - 1; i++) {
		int max = s[0].kor;
		int max_index = 0;

		for (int j = 1; j < n - i; j++) {
			if (max < s[j].kor) {
				max = s[j].kor;
				max_index = j;
			}
		}

		// kor 값을 바탕으로 배열 전체를 정렬한다.
		temp = s[max_index]; // 임시 값에 j 루프 중 제일 큰 값(max) 저장
		s[max_index] = s[n - i - 1]; // max에 마지막 배열의 값 저장
		s[n - i - 1] = temp; // 마지막 배열에 max 저장
	}
	return;
}

int main(void) {
	int n;
	printf("학생 수: ");
	scanf("%d", &n);

	struct Student* s = (struct Student*)malloc(sizeof(struct Student) * n); // 구조체 배열 동적 할당
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		s[i].id = i + 1;
		s[i].kor = rand() % 101;
		s[i].eng = rand() % 101;
		s[i].mat = rand() % 101;
	}

	for (int i = 0; i < n; i++) {
		printf("학번: %d\t", s[i].id);
		printf("국어: %d\t", s[i].kor);
		printf("영어: %d\t", s[i].eng);
		printf("수학: %d\n", s[i].mat);
	}

	printf("\n");
	selectionSort(s, n);

	for (int i = n - 1; i >= 0; i--) {
		printf("학번: %d\t", s[i].id);
		printf("국어: %d\t", s[i].kor);
		printf("영어: %d\t", s[i].eng);
		printf("수학: %d\n", s[i].mat);
	}

	free(s);
	return 0;
}