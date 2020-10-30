#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
/*
//3 개방주소법 해시테이블 - 이중해싱
typedef struct Bucket {
	int key;
}Bucket;

Bucket *bucketArr;
int M, q;

void insertItem(int index, int inputKey);
void findElement(int inputKey);

int main() {
	char command;
	int n, inputKey, index;

	scanf("%d %d %d", &M, &n, &q);
	bucketArr = (Bucket *)malloc(M * sizeof(Bucket));
	for (int i = 0;i < M;i++)
		bucketArr[i].key = 0;

	while (scanf("%c", &command)) {
		switch (command) {
		case 'i': // key 삽입 후 저장된 주소 인쇄 -> h(x) = x % M, h'(x) = q - (x % q)
			scanf("%d", &inputKey);
			index = inputKey % M;
			if (n > 0) {
				insertItem(index, inputKey);
				n--;
			}
			break;
		case 's': // key 탐색 후 저장된 주소와 값 인쇄, 없으면 -1 인쇄
			scanf("%d", &inputKey);
			findElement(inputKey);
			break;
		case 'p':
			for (int i = 0;i < M;i++)
				printf(" %d", bucketArr[i].key);
			printf("\n");
			break;
		case 'e': // 프로그램 종료
			for (int i = 0;i < M;i++)
				printf(" %d", bucketArr[i].key);
			printf("\n");
			return;
		}
	}

	free(bucketArr);
}

void insertItem(int index, int inputKey) {
	if (bucketArr[index].key == 0) { // 버켓에 저장된 키가 없는 경우
		bucketArr[index].key = inputKey;
		printf("%d\n", index);
	}
	else { // 버켓에 저장된 키가 있는 경우
		printf("C");
		index = index + q - (inputKey % q);
		if (index >= M)
			index = index % M;
		insertItem(index, inputKey);
	}
}
void findElement(int inputKey) {
	int flag = 0;
	for (int i = 0;i < M;i++) {
		if (bucketArr[i].key == inputKey) {
			flag = 1;
			printf("%d %d\n", i, inputKey);
		}
	}
	if (flag == 0)
		printf("-1\n");
}
*/