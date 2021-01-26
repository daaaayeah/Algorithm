#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
/*
// 문제1 선택 정렬
int main() {
	int n, *arr = NULL;
	int i, j, max, maxIndex, tmp;

	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL) return -1;
	for (i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	for (i = n - 1;i >= 0;i--) {
		max = arr[i];
		for (j = i;j >= 0;j--) {
			if (arr[j] >= max) {
				max = arr[j];
				maxIndex = j;
			}
		}
		tmp = arr[i];
		arr[i] = max;
		arr[maxIndex] = tmp;
	}
	for (i = 0;i < n;i++)
		printf(" %d", arr[i]);
	printf("\n");

	free(arr);
}
*/
// 문제2 삽입 정렬
int main() {
	int n, *arr = NULL;
	int i, j, key, tmp;

	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL) return -1;
	for (i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	for (i = 1;i < n;i++) {
		key = arr[i];
		for (j = i;j > 0;j--) {
			if (key < arr[j - 1])
				arr[j] = arr[j - 1];
			else
				break;
		}
		arr[j] = key;
	}
	for (i = 0;i < n;i++)
		printf(" %d", arr[i]);
	printf("\n");

	free(arr);
}
/*
// 문제 3 선택 정렬과 삽입 정렬의 실행시간 비교
int main() {
	int n, *A = NULL, *B = NULL;
	int i, j, max, maxIndex, tmp, key;
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	scanf("%d", &n);
	A = (int *)malloc(n * sizeof(int));
	B = (int *)malloc(n * sizeof(int));
	// 랜덤 데이터
	printf("// 랜덤 데이터\n");
	srand(time(NULL));
	for (i = 0;i < n;i++) {
		A[i] = rand() % n;
		B[i] = rand() % n;
	}
	if (A == NULL) return -1;
	if (B == NULL) return -1;

	// 배열 A -> 선택 정렬
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = n - 1;i >= 0;i--) {
		max = A[i];
		for (j = i;j >= 0;j--) {
			if (A[j] >= max) {
				max = A[j];
				maxIndex = j;
			}
		}
		tmp = A[i];
		A[i] = max;
		A[maxIndex] = tmp;
	}
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("선택 정렬 수행시간 : %.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	
	// 배열 B -> 삽입 정렬
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = 1;i < n;i++) {
		key = B[i];
		for (j = i;j > 0;j--) {
			if (key < B[j - 1])
				B[j] = B[j - 1];
			else
				break;
		}
		B[j] = key;
	}
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("삽입 정렬 수행시간 : %.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	////

	// 정렬 데이터
	printf("\n// 정렬 데이터\n");
	for (i = n - 1;i >= 0;i--) {
		max = A[i];
		for (j = i;j >= 0;j--) {
			if (A[j] >= max) {
				max = A[j];
				maxIndex = j;
			}
		}
		tmp = A[i];
		A[i] = max;
		A[maxIndex] = tmp;
	}
	for (i = n - 1;i >= 0;i--) {
		max = B[i];
		for (j = i;j >= 0;j--) {
			if (B[j] >= max) {
				max = B[j];
				maxIndex = j;
			}
		}
		tmp = B[i];
		B[i] = max;
		B[maxIndex] = tmp;
	}
	if (A == NULL) return -1;
	if (B == NULL) return -1;

	// 배열 A -> 선택 정렬
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = n - 1;i >= 0;i--) {
		max = A[i];
		for (j = i;j >= 0;j--) {
			if (A[j] >= max) {
				max = A[j];
				maxIndex = j;
			}
		}
		tmp = A[i];
		A[i] = max;
		A[maxIndex] = tmp;
	}
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("선택 정렬 수행시간 : %.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	// 배열 B -> 삽입 정렬
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = 1;i < n;i++) {
		key = B[i];
		for (j = i;j > 0;j--) {
			if (key < B[j - 1])
				B[j] = B[j - 1];
			else
				break;
		}
		B[j] = key;
	}
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("삽입 정렬 수행시간 : %.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	////

	// 역정렬 데이터
	printf("\n// 역정렬 데이터\n");
	for (i = 0;i < n;i++) {
		max = A[i];
		for (j = i;j < n;j++) {
			if (A[j] >= max) {
				max = A[j];
				maxIndex = j;
			}
		}
		tmp = A[i];
		A[i] = max;
		A[maxIndex] = tmp;
	}
	for (i = 0;i < n;i++) {
		max = B[i];
		for (j = i;j < n;j++) {
			if (B[j] >= max) {
				max = B[j];
				maxIndex = j;
			}
		}
		tmp = B[i];
		B[i] = max;
		B[maxIndex] = tmp;
	}
	if (A == NULL) return -1;
	if (B == NULL) return -1;

	// 배열 A -> 선택 정렬
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = n - 1;i >= 0;i--) {
		max = A[i];
		for (j = i;j >= 0;j--) {
			if (A[j] >= max) {
				max = A[j];
				maxIndex = j;
			}
		}
		tmp = A[i];
		A[i] = max;
		A[maxIndex] = tmp;
	}
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("선택 정렬 수행시간 : %.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	// 배열 B -> 삽입 정렬
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = 1;i < n;i++) {
		key = B[i];
		for (j = i;j > 0;j--) {
			if (key < B[j - 1])
				B[j] = B[j - 1];
			else
				break;
		}
		B[j] = key;
	}
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("삽입 정렬 수행시간 : %.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	free(A);
	free(B);
}
*/