#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
/*
//1 �и������ �ؽ����̺�
typedef struct Bucket {
	int key;
	struct Bucket *next;
}Bucket;

Bucket *bucketArr;
int M, ranking;

void insertItem(Bucket *B, int inputKey);
int findElement(Bucket *B, int inputKey);
int returnRanking(Bucket *B, int inputKey);
void removeElement(Bucket *B, int inputKey);
void printHashTable(Bucket *B);

int main() {
	char command;
	int inputKey, index, searchResult;

	scanf("%d", &M);
	bucketArr = (Bucket *)malloc(M * sizeof(Bucket));
	for (int i = 0;i < M;i++)
		bucketArr[i].next = NULL;

	while (scanf("%c", &command)) {
		switch (command) {
		case 'i': // �ؽ����̺� key ���� -> h(x) = x % M
			scanf("%d", &inputKey);
			index = inputKey % M;
			insertItem(bucketArr + index, inputKey);
			break;
		case 's': // key Ž�� �� ����� ���� �μ�, ������ 0 �μ�
			scanf("%d", &inputKey);
			index = inputKey % M;
			ranking = 1;
			searchResult = findElement(bucketArr + index, inputKey);
			if (searchResult == 0)
				printf("0\n");
			else {
				searchResult = returnRanking(bucketArr + index, inputKey);
				printf("%d\n", searchResult);
			}
			break;
		case 'd': // key ���� �� ����� ���� �μ�, ������ 0 �μ�
			scanf("%d", &inputKey);
			index = inputKey % M;
			ranking = 1;
			searchResult = findElement(bucketArr + index, inputKey);
			if (searchResult == 0)
				printf("0\n");
			else {
				searchResult = returnRanking(bucketArr + index, inputKey);
				printf("%d\n", searchResult);
				removeElement(bucketArr + index, inputKey);
			}
			break;
		case 'p': // �ؽ����̺� ����� Ű ������� �μ�
			for (int i = 0;i < M;i++) {
				if (bucketArr[i].next == NULL)
					continue;
				printHashTable(bucketArr + i);
			}
			printf("\n");
			break;
		case 'e': // ���α׷� ����
			return;
		}
	}

	free(bucketArr);
}

void insertItem(Bucket *B, int key) {
	Bucket *input;
	input = (Bucket *)malloc(sizeof(Bucket));
	input->key = key;
	input->next = NULL;

	if (B->next != NULL)
		input->next = B->next;
	B->next = input;
}
int findElement(Bucket *B, int inputKey) { // Ű ���� ���� ��ȯ
	if (B->next == NULL)
		return 0;
	if (B->next->key == inputKey)
		return 1;
	findElement(B->next, inputKey);
}
int returnRanking(Bucket *B, int inputKey) { // Ű�� ����� ���� ��ȯ
	if (B->next->key == inputKey)
		return ranking;
	ranking++;
	returnRanking(B->next, inputKey);
}
void removeElement(Bucket *B, int inputKey) {
	Bucket *tmp;
	if (B->next->key == inputKey) {
		tmp = B->next;
		if (B->next->next == NULL)
			B->next = NULL;
		else
			B->next = B->next->next;
		free(tmp);
	}
	else
		removeElement(B->next, inputKey);
}
void printHashTable(Bucket *B) {
	printf(" %d", B->next->key);
	if (B->next->next != NULL)
		printHashTable(B->next);
}
*/