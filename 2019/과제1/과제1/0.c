/*#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int L[100001];

void buildList(int L[], int n, int min, int max);
void swap(int *a, int *b);
void downHeap(int L[], int i, int n);
void buildHeap(int L[], int n);
void popHeap(int L[], int n);
int findKthSmallest(int L[], int n, int k);

int main() {
	int kArray[4] = { 1, 100, 99900, 99999 };
	int output;
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	buildList(L, 10, 1, 100);
	for (int i = 1; i <= 10; i++)
		printf(" %d", L[i]); // Line 1
	printf("\n");
	buildHeap(L, 10);
	for (int k = 1; k <= 3; k++) {
		output = findKthSmallest(L, 10, k);
		printf(" %d", output); // Line 2
	}
	printf("\n");

	buildList(L, 100000, 1, 1000000);
	buildHeap(L, 100000);
	for (int k = 0; k < 4; k++) {
		QueryPerformanceFrequency(&ticksPerSec);
		QueryPerformanceCounter(&start);
		output = findKthSmallest(L, 100000, kArray[k]);
		QueryPerformanceCounter(&end);
		diff.QuadPart = end.QuadPart - start.QuadPart;
		printf("결과: %d, ", output);
		printf("실행시간: %.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart)); // Line 3, 4, 5, 6
	}

	free(L);
	return 0;
}

void buildList(int L[], int n, int min, int max) {
	int num;
	srand(time(NULL));
	for (int i = 1; i <= n; i++) {
		num = ((((long)rand() << 15) | rand()) % max) + min; // min ~ max 범위의 난수 생성
		L[i] = num;
	}
}
void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void downHeap(int L[], int i, int n) {
	int smaller;
	if ((n < (i * 2)) && (n < (i * 2 + 1))) return;
	smaller = i * 2;
	if (n >= i * 2 + 1) {
		if (L[i * 2 + 1] < L[smaller])
			smaller = i * 2 + 1;
	}
	if (L[i] <= L[smaller]) return;
	swap(&L[i], &L[smaller]);
	downHeap(L, smaller, n);
}
void buildHeap(int L[], int n) { // 상향식 힙 생성 -> O(n)
	for (int i = n / 2; i >= 1; i--)
		downHeap(L, i, n);
}
void popHeap(int L[], int n) {
	swap(&L[1], &L[n--]); // 루트 키 삭제
	downHeap(L, 1, n);
}
int findKthSmallest(int L[], int n, int k) { // -> O(klogn)
	while (k > 1) { // k - 1개 삭제
		popHeap(L, n--);
		k--;
	}
	return L[1];
}*/