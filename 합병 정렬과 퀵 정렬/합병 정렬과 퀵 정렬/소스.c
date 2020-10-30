#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
//1 단일연결리스트 합병 정렬
typedef struct Node {
	int data;
	struct Node *next;
}Node;

Node *create_node(int data);
void divide(Node *node, int n);
void merge(Node *left, Node *right);
Node *merge_sort(Node *node, int cnt);

int main() {
	int n, tmp;
	Node *node;

	scanf("%d", &n);
	node = (Node *)malloc(n * sizeof(Node));
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		node[i] = *create_node(tmp);
	}

	for (int i = 0; i < n - 1; i++)
		(node + i)->next = (node + i + 1);
	node = merge_sort(node, n);
	while (node != NULL) {
		printf(" %d", node->data);
		node = node->next;
	}
	printf("\n");

	free(node);
}

Node *create_node(int data) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
void divide(Node *node, int n) {
	for (int i = 0; i < n - 1; i++)
		node = node->next;
	node->next = NULL;
}
void merge(Node *left, Node *right) {
	Node *tmp = (Node *)malloc(sizeof(Node));

	while (left != NULL && right != NULL) {
		if (left->data < right->data) {
			tmp->next = left;
			left = left->next;
		}
		else {
			tmp->next = right;
			right = right->next;
		}
		tmp = tmp->next;
	}
	while (left != NULL) {
		tmp->next = left;
		left = left->next;
		tmp = tmp->next;
	}
	while (right != NULL) {
		tmp->next = right;
		right = right->next;
		tmp = tmp->next;
	}
}
Node *merge_sort(Node *node, int cnt) {
	Node *left, *right;
	if (node->next == NULL) return node;
	left = node;
	right = node;
	for (int i = 0; i < cnt / 2; i++)
		right = right->next;
	divide(node, cnt / 2);
	left = merge_sort(left, cnt / 2);
	if (cnt % 2 == 1)
		right = merge_sort(right, cnt / 2 + 1);
	else
		right = merge_sort(right, cnt / 2);
	merge(left, right);
	if (left->data <= right->data)
		return left;
	else return right;
}


//2 퀵 정렬
typedef struct resultOfInPlacePartition {
	int a;
	int b;
}result;

void swap(int *a, int *b);
result inPlacePartition(int *A, int l, int r, int k);
void quickSort(int *A, int n);
void rQuickSort(int *A, int l, int r, int n);
int findPivot(int *A, int l, int r);

int main() {
	int *A, n;

	scanf("%d", &n);
	A = (int *)malloc(n * (sizeof(int)));
	if (A == NULL) return -1;
	for (int i = 0;i < n;i++)
		scanf("%d", &A[i]);
	
	quickSort(A, n);
	for (int i = 0;i < n;i++)
		printf(" %d", A[i]);
	printf("\n");

	free(A);
}

void swap(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
result inPlacePartition(int *A, int l, int r, int k) {
	result res;
	int i, j, flag = 0, pivot = A[k];

	swap(&A[k], &A[r]);
	i = l;
	j = r - 1;
	while (i <= j) {
		while ((i <= j) && (A[i] < pivot))
			i++;
		while ((i <= j) && (A[j] >= pivot))
			j--;
		if (i < j)
			swap(&A[i], &A[j]);
	}
	swap(&A[i], &A[r]);
	for (i = l;i <= r;i++) {
		if (A[i] == pivot) {
			res.a = i;
			break;
		}
	}
	for (j = i;j <= r;j++) {
		if (A[j] != pivot) {
			res.b = j - 1;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		res.b = r;

	return res;
}
void quickSort(int *A, int n) {
	rQuickSort(A, 0, n - 1, n);
}
void rQuickSort(int *A, int l, int r, int n) {
	result res;
	int a, b, k;
	k = findPivot(A, l, r);
	if (l <= r) {
		res = inPlacePartition(A, l, r, k);
		a = res.a;
		b = res.b;
		rQuickSort(A, l, a - 1, n);
		rQuickSort(A, b + 1, r, n);
	}
}
int findPivot(int *A, int l, int r) {
	srand((unsigned int)time(NULL));
	return ((((long)rand() << 15) | rand()) % r) + l;
}
////
*/
void swap(int *a, int *b);
void quick_sort(int *arr, int left, int right);

int main() {
	int *arr, n;

	scanf("%d", &n);
	arr = (int *)malloc(n * (sizeof(int)));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);

	free(arr);

	return 0;
}

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void quick_sort(int *arr, int left, int right) {
	int pivot;
	int l = left, r = right;

	srand((unsigned)time(NULL));
	pivot = ((((long)rand() << 15) | rand()) % r) + l;
	printf("%d", pivot);
	if (right - left < 1) return;
	while (l < r) {
		while (arr[l] < pivot)
			l++;
		while (arr[r] > pivot)
			r--;
		if (l <= r)
			swap(&arr[l++], &arr[r--]);
	}
	quick_sort(arr, left, r);
	quick_sort(arr, l, right);
}