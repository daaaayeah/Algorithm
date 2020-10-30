#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
//
//int *heap, n;
//
//void swap(int *a, int *b) {
//	int tmp;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void upHeap(int i) {
//	if (i == 1 || (heap[i / 2] < heap[i])) return;
//	else {
//		swap(&heap[i], &heap[i / 2]);
//		upHeap(i / 2);
//	}
//}
//void downHeap(int i, int last) {
//	if (i * 2 > last) return; // 자식이 존재하지 않는 경우
//
//	else if (i * 2 < last) { // 자식이 모두 존재하는 경우
//		if (heap[i * 2] < heap[i * 2 + 1]) { // 왼쪽 자식이 더 작은 경우
//			if (heap[i] > heap[i * 2]) {
//				swap(&heap[i], &heap[i * 2]);
//				downHeap(i * 2, last);
//			}
//			else return;
//		}
//		else { // 오른쪽 자식이 더 작은 경우
//			if (heap[i] > heap[i * 2 + 1]) {
//				swap(&heap[i], &heap[i * 2 + 1]);
//				downHeap(i * 2 + 1, last);
//			}
//			else return;
//		}
//	}
//
//	else { // 왼쪽 자식만 존재하는 경우
//		if (heap[i] > heap[i * 2]) {
//			swap(&heap[i], &heap[i * 2]);
//			downHeap(i * 2, last);
//		}
//		else return;
//	}
//}
//void heapSort() {
//	int id;
//	for (int i = n / 2; i >= 1; i--)
//		downHeap(i, n);
//	id = n;
//	for (int i = 1; i <= n; i++) {
//		printf("%d\n", heap[1]);
//		heap[1] = heap[id--];
//		downHeap(1, id);
//	}
//}
//
//int main() {
//	scanf("%d", &n);
//	heap = (int *)malloc(sizeof(int) * (n + 1));
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &heap[i]);
//	heapSort();
//}
int heap[100];
int index;


void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void upHeap(int i) {
	if (i == 1 || (heap[i / 2] < heap[i])) return;
	else {
		swap(&heap[i], &heap[i / 2]);
		upHeap(i / 2);
	}
}
void insertItem(int key) {
	printf("index : %d, key : %d\n", index, key);
	heap[++index] = key;
	upHeap(index);
}
void downHeap(int i, int last) {
	if (i * 2 > last) return; // 자식이 존재하지 않는 경우

	else if (i * 2 < last) { // 자식이 모두 존재하는 경우
		if (heap[i * 2] < heap[i * 2 + 1]) { // 왼쪽 자식이 더 작은 경우
			if (heap[i] > heap[i * 2]) {
				swap(&heap[i], &heap[i * 2]);
				downHeap(i * 2, last);
			}
			else return;
		}
		else { // 오른쪽 자식이 더 작은 경우
			if (heap[i] > heap[i * 2 + 1]) {
				swap(&heap[i], &heap[i * 2 + 1]);
				downHeap(i * 2 + 1, last);
			}
			else return;
		}
	}

	else { // 왼쪽 자식만 존재하는 경우
		if (heap[i] > heap[i * 2]) {
			swap(&heap[i], &heap[i * 2]);
			downHeap(i * 2, last);
		}
		else return;
	}
}
void heapSort() {
	int id;
	for (int i = index / 2; i >= 1; i--)
		downHeap(i, index);
	id = index;
	for (int i = 1; i <= index; i++) {
		printf(" %d", heap[1]);
		heap[1] = heap[id--];
		downHeap(1, id);
	}
}

void main() {
	int num;
	for (int i = 1;i <= 10;i++) {
		scanf("%d", &num);
		insertItem(num);
	}
	for (int i = 1;i <= index;i++)
		printf(" %d", heap[i]);
	printf("\n");
	heapSort();
	printf("\n");

}