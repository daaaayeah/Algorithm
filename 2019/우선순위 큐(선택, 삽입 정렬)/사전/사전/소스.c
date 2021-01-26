#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

//1 이진탐색-재귀버전
int findPosition(int *arr, int n, int k);

int main() {
	int n, *arr, k;
	int res;

	scanf("%d %d", &n, &k);
	arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL) return -1;
	for (int i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	res = findPosition(arr, n, k);
	printf(" %d\n", res);

	free(arr);
}

int findPosition(int *arr, int n, int k) {
	int flag = 0;

	for (int i = 0;i < n;i++) {
		if (arr[i] <= k)
			flag = 1;
	}
	for (int i = 0;i < n;i++) {
		if (flag == 1) {
			if (arr[i] <= k) // x <= k x중 가장 큰 값의 인덱스
				return i;
		}
		else
			return -1;
	}
}

/*
//2 이진탐색-비재귀버전
int findPosition(int *arr, int n, int k);

int main() {
	int n, *arr, k;
	int res;

	scanf("%d %d", &n, &k);
	arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL) return -1;
	for (int i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	res = findPosition(arr, n, k);
	printf(" %d\n", res);

	free(arr);
}

int findPosition(int *arr, int n, int k) {
	int flag = 0;

	for (int i = 0;i < n;i++) {
		if (arr[i] >= k)
			flag = 1;
	}
	for (int i = 0;i < n;i++) {
		if (flag == 1) {
			if (arr[i] >= k) // x >= k x중 가장 작은 값의 인덱스
				return i;
		}
		else
			return n;
	}
}
*/