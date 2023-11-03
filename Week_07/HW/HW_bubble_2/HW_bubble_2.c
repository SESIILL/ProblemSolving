#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
	int id, kor, eng, mat;
};

void swap(struct Student* a, struct Student* b) {
	struct Student temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(struct Student* s, int n, int choice) {
	struct Student temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			switch (choice) {
			case 1:
				if (s[j].kor < s[j + 1].kor)
					swap(&s[j], &s[j + 1]);
				break;
			case 2:
				if (s[j].mat < s[j + 1].mat)
					swap(&s[j], &s[j + 1]);
				break;
			case 3:
				if (s[j].eng < s[j + 1].eng)
					swap(&s[j], &s[j + 1]);
				break;
			case 4:
				if (s[j].id > s[j + 1].id)
					swap(&s[j], &s[j + 1]);
				break;
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
	printS(s, n);

	int choice = -1;
	while (choice != 0) {
		printf("정렬 기준 선택<1: 국어, 2: 수학, 3: 영어, 4: id(오름차순), 0: 끝내기>: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			bubbleSort(s, n, 1);
			printS(s, n);
			break;
		case 2:
			bubbleSort(s, n, 2);
			printS(s, n);
			break;
		case 3:
			bubbleSort(s, n, 3);
			printS(s, n);
			break;
		case 4:
			bubbleSort(s, n, 4);
			printS(s, n);
			break;
		}
	}
	free(s);

	return 0;
}