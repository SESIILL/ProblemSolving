#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
	int id, kor, eng, mat;
};

void bubbleSortDescendingByKorean(struct Student* s, int n) {
	struct Student temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (s[j].kor < s[j + 1].kor) {
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
	return;
}

void bubbleSortAscendingById(struct Student* s, int n) {
	struct Student temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (s[j].id > s[j + 1].id) {
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
	return;
}

void printS(struct Student* s, int n) {
	for (int i = 0; i < n; i++) {
		printf("학번: %d\t", s[i].id);
		printf("국어: %d\t", s[i].kor);
		printf("수학: %d\t", s[i].mat);
		printf("영어: %d\n", s[i].eng);
	}
	printf("\n");
}

int main(void) {
	int n;
	printf("학생 수를 입력하세요: ");
	scanf("%d", &n);

	struct Student* s = (struct Student*)malloc(sizeof(struct Student) * n);
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		s[i].id = i + 1;
		s[i].kor = rand() % 101;
		s[i].eng = rand() % 101;
		s[i].mat = rand() % 101;
	}

	bubbleSortDescendingByKorean(s, n);
	printS(s, n);

	bubbleSortAscendingById(s, n);
	printS(s, n);

	free(s);

	return 0;
}