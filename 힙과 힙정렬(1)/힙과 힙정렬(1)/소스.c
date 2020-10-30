#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

//1
int H[100], n = 0;

void insertItem(int key);
int removeMax();
void upHeap(int i);
void downHeap(int i);
void printHeap();

int main() {
	char select;
	int key;

	while (1) {
		scanf("%c", &select);
		if (select == 'i') {
			scanf("%d", &key);
	
			insertItem(key);
			printf("0\n");
		}
		else if (select == 'd')
			printf("%d\n", removeMax());
		else if (select == 'p')
			printHeap();
		else if (select == 'q')
			break;
	}

}

void insertItem(int key) {
	H[++n] = key;
	upHeap(n);
}
int removeMax() {
	int key;
	key = H[1];
	H[1] = H[n--];
	downHeap(1);
	return key;
}
void upHeap(int i) {
	int temp;
	if (i == 1)
		return;
	if (H[i] <= H[i / 2])
		return;
	temp = H[i];
	H[i] = H[i / 2];
	H[i / 2] = temp;
	upHeap(i / 2);
}
void downHeap(int i) {
	int bigger, temp;
	if ((n < (i * 2)) && (n < (i * 2 + 1)))
		return;
	bigger = i * 2;
	if (n >= i * 2 + 1) {
		if (H[i * 2 + 1] > H[bigger])
			bigger = i * 2 + 1;
	}
	if (H[i] >= H[bigger])
		return;
	temp = H[i];
	H[i] = H[bigger];
	H[bigger] = temp;
	downHeap(bigger);
}
void printHeap() {
	for (int i = 1; i < n + 1; i++)
		printf(" %d", H[i]);
	printf("\n");
}
/*
//2
int H[100], n = 0;

void upHeap(int i);
void downHeap(int i);
void rBuildHeap(int i);
void buildHeap();
void printHeap();

void main() {
	int keyNumber, value, i;
	scanf("%d", &keyNumber);
	for (i = 1; i < keyNumber + 1; i++) {
		scanf("%d", &value);
		H[i] = value;
		n++;
	}
	rBuildHeap(1);
	//buildHeap();
	printHeap();
}

void upHeap(int i) {
	int temp;
	if (i == 1) return;
	if (H[i] <= H[i / 2]) return;
	temp = H[i];
	H[i] = H[i / 2];
	H[i / 2] = temp;
	upHeap(i / 2);
}
void downHeap(int i) {
	int bigger, temp;
	if ((n < (i * 2)) && (n < (i * 2 + 1)))
		return;
	bigger = i * 2;
	if (n >= i * 2 + 1) {
		if (H[i * 2 + 1] > H[bigger])
			bigger = i * 2 + 1;
	}
	if (H[i] >= H[bigger])
		return;
	temp = H[i];
	H[i] = H[bigger];
	H[bigger] = temp;
	downHeap(bigger);
}
void rBuildHeap(int i) {
	if (i > n) return;
	rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	downHeap(i);
}
void buildHeap() {
	for (int i = n / 2; i >= 1; i--)
		downHeap(i);
}
void printHeap() {
	for (int i = 1; i < n + 1; i++)
		printf(" %d", H[i]);
	printf("\n");
}*/