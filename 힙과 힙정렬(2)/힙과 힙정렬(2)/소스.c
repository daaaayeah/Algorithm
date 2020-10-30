//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
////1 (1단계 최대힙 생성, 2단계 오름차순 정렬)
//int H[100];
//int n;
//
//void swap(int *a, int *b);
//void inPlaceHeapSort();
//void printArray();
//void downHeap(int i, int last);
//void insertItem(int key);
//void upHeap(int i);
//
//void main() {
//	int n, value;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &value);
//		insertItem(value);
//	}
//	inPlaceHeapSort();
//	printArray();
//}
//
//void swap(int *a, int *b) {
//	int tmp;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void inPlaceHeapSort() { // -> O(nlogn)
//	for (int i = n;i > 1; i--) {
//		swap(&H[1], &H[i]);
//		downHeap(1, i - 1);
//	}
//}
//void printArray() {
//	for (int i = 1; i <= n; i++)
//		printf(" %d", H[i]);
//	printf("\n");
//}
//void downHeap(int i, int last) {
//	int bigger;
//	if ((last < (i * 2)) && (last < (i * 2 + 1)))
//		return;
//	bigger = i * 2;
//	if (last >= i * 2 + 1) {
//		if (H[i * 2 + 1] > H[bigger])
//			bigger = i * 2 + 1;
//	}
//	if (H[i] >= H[bigger])
//		return;
//	swap(&H[i], &H[bigger]);
//	downHeap(bigger, last);
//}
//void insertItem(int key) {
//	H[++n] = key;
//	upHeap(n);
//}
//void upHeap(int i) {
//	if (i == 1) return;
//	if (H[i] <= H[i / 2]) return;
//	swap(&H[i], &H[i / 2]);
//	upHeap(i / 2);
//}