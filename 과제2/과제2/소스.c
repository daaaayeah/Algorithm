#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

n = 100000;

typedef struct resultOfInPlacePartition {
	int a;
	int b;
}result;

void swap(int *a, int *b);
int *createArray();
void insertionSort(int *A);
result inPlacePartition(int *A, int l, int r, int k);
void quickSort(int *A, int Limit, int mode);
void rQuickSort(int *A, int l, int r, int Limit, int mode);
int findPivot(int *A, int l, int r, int mode);

int main() {
	int *A, *AA, Limit[4] = { 1, 100, 500, 1000 };
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	A = createArray();
	AA = (int *)malloc(n * sizeof(int));
	if (AA == NULL) return -1;

	printf("Limit		결정적1			결정적3			무작위1			무작위3\n");
	for (int i = 0;i < 4;i++) {
		printf("%d", Limit[i]);
		for (int j = 1;j <= 4;j++) { // mode j
			for (int k = 0;k < n;k++)
				AA[k] = A[k];
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			quickSort(AA, Limit[i], j);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("		%.8f", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
		}
		printf("\n");
	}

	free(A);
	free(AA);

	return 0;
}

void swap(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
int *createArray() {
	int *A;

	A = (int *)malloc(n * sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0;i < n;i++)
		A[i] = ((((long)rand() << 15) | rand()) % n) + 1;

	return A;
}
void insertionSort(int *A) {
	int key, i, j;

	for (i = 1;i < n;i++) {
		key = A[i];
		for (j = i;j > 0;j--) {
			if (key < A[j - 1])
				A[j] = A[j - 1];
			else
				break;
		}
		A[j] = key;
	}
}
result inPlacePartition(int *A, int l, int r, int k) {
	result res;
	int i, j, flag = 0, p = A[k];

	swap(&A[k], &A[r]);
	i = l;
	j = r - 1;
	while (i <= j) {
		while ((i <= j) && (A[i] < p))
			i++;
		while ((j >= i) && (A[j] >= p))
			j--;
		if (i < j)
			swap(&A[i], &A[j]);
	}
	swap(&A[i], &A[r]);
	for (i = l;i <= r;i++) {
		if (A[i] == p) {
			res.a = i; // a값 설정
			break;
		}
	}
	for (j = i;j <= r;j++) {
		if (A[j] != p) {
			res.b = j - 1; // b값 설정
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		res.b = r;

	return res;
}
void quickSort(int *A, int Limit, int mode) {
	rQuickSort(A, 0, n - 1, Limit, mode);
	if (Limit > 1)
		insertionSort(A);
}
void rQuickSort(int *A, int l, int r, int Limit, int mode) {
	result res;
	int a, b, k;

	if (r - l >= Limit) {
		k = findPivot(A, l, r, mode); // pivot k
		res = inPlacePartition(A, l, r, k);
		a = res.a;
		b = res.b;
		rQuickSort(A, l, a - 1, Limit, mode);
		rQuickSort(A, b + 1, r, Limit, mode);
	}
}
int findPivot(int *A, int l, int r, int mode) {
	int a, b, c;
	
	if (mode == 1) // deterministic 1
		return r;
	if (mode == 2) { // randomized 1
		srand((unsigned)time(NULL));
		return ((((long)rand() << 15) | rand()) % (r - l + 1)) + l;
	}
	if (r - l == 1)
		return l;
	switch (mode) {
		case 3: { // deterministic 3
			a = l;
			b = (l + r) / 2;
			c = r;
		}
		break;
		case 4: { // randomized 3
			srand((unsigned)time(NULL));
			a = ((((long)rand() << 15) | rand()) % (r - l + 1)) + l;
			b = ((((long)rand() << 15) | rand()) % (r - l + 1)) + l;
			c = ((((long)rand() << 15) | rand()) % (r - l + 1)) + l;
		}
		break;
	}
	if (A[a] <= A[b]) {
		if (A[b] <= A[c])
			return b;
		else if (A[a] <= A[c])
			return c;
		else
			return a;
	}
	else {
		if (A[a] <= A[c])
			return a;
		else if (A[b] <= A[c])
			return c;
		else
			return b;
	}
}