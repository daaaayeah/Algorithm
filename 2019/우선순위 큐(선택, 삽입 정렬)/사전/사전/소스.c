#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

//1 ����Ž��-��͹���
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
			if (arr[i] <= k) // x <= k x�� ���� ū ���� �ε���
				return i;
		}
		else
			return -1;
	}
}

/*
//2 ����Ž��-����͹���
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
			if (arr[i] >= k) // x >= k x�� ���� ���� ���� �ε���
				return i;
		}
		else
			return n;
	}
}
*/