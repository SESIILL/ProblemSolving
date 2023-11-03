#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n1, n2, n3, n4, n5;
	int key;

	printf("Enter 5개의 정수: ");
	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
	printf("Enter a key: ");
	scanf("%d", &key);

	if (key == n1) 
		printf("1번째에 있다.\n");
	else if (key == n2)
		printf("2번째에 있다.\n");
	else if (key == n3)
		printf("3번째에 있다.\n");
	else if (key == n4)
		printf("4번째에 있다.\n");
	else if (key == n5)
		printf("5번째에 있다.\n");
	else
		printf("없다.\n");

	return 0;
}