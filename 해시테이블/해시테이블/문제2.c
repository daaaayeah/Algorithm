#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
/*
//2 �����ּҹ� �ؽ����̺� - ���������
typedef struct Bucket {
	int key;
}Bucket;

Bucket *bucketArr;
int M;

void insertItem(int index, int inputKey);
void findElement(int inputKey);

int main() {
	char command;
	int n, inputKey, index;

	scanf("%d %d", &M, &n);
	bucketArr = (Bucket *)malloc(M * sizeof(Bucket));
	for (int i = 0;i < M;i++)
		bucketArr[i].key = 0;

	while (scanf("%c", &command)) {
		switch (command) {
		case 'i': // key ���� �� ����� �ּ� �μ� -> h(x) = x % M
			scanf("%d", &inputKey);
			index = inputKey % M;
			if (n > 0) {
				insertItem(index, inputKey);
				n--;
			}
			break;
		case 's': // key Ž�� �� ����� �ּҿ� �� �μ�, ������ -1 �μ�
			scanf("%d", &inputKey);
			findElement(inputKey);
			break;
		case 'e': // ���α׷� ����
			return;
		}
	}

	free(bucketArr);
}

void insertItem(int index, int inputKey) {
	if (bucketArr[index].key == 0) { // ���Ͽ� ����� Ű�� ���� ���
		bucketArr[index].key = inputKey;
		printf("%d\n", index);
	}
	else { // ���Ͽ� ����� Ű�� �ִ� ���
		printf("C");
		index++;
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