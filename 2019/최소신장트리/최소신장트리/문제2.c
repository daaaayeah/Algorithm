//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
////2 Kruskal 알고리즘
//typedef struct {
//	int v; // 정점1 
//	int u; // 정점2 
//	int key; // 간선의 weight
//}Element;
//typedef struct {
//	Element heap[1000];
//	int heap_size;
//}HeapType;
//
//int parent[100];
//int num[100];
//int n, m;
//
//void insertHeap(HeapType *h, Element item);
//Element deleteHeap(HeapType *h);
//int setFind(int v);
//void setUnion(int v1, int v2);
//void insertHeapEdge(HeapType *h, int v, int u, int weight);
//int kruskal();
//
//int main() {
//	scanf("%d %d", &n, &m);w
//	kruskal(n);
//}
//void insertHeap(HeapType *h, Element item) {
//	int i = ++(h->heap_size);
//	while (i != 1 && item.key < h->heap[i / 2].key) {
//		h->heap[i] = h->heap[i / 2];
//		i /= 2;
//	}
//	h->heap[i] = item;
//}
//Element deleteHeap(HeapType *h) {
//	int parent = 1, child = 2;
//	Element data, temp;
//
//	data = h->heap[parent];
//	temp = h->heap[(h->heap_size)--];
//	while (child <= h->heap_size) {
//		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
//			child++;
//		if (temp.key <= h->heap[child].key) break;
//		h->heap[parent] = h->heap[child];
//		parent = child;
//		child *= 2;
//	}
//	h->heap[parent] = temp;
//
//	return data;
//}
//int setFind(int v) {
//	int i, p, tmp;
//
//	for (i = v;(p = parent[i]) >= 0;i = p);
//	tmp = i;
//	for (i = v;(p = parent[i]) >= 0;i = p)
//		parent[i] = tmp;
//
//	return tmp;
//}
//void setUnion(int v1, int v2) {
//	if (num[v1] < num[v2])	{
//		parent[v1] = v2;
//		num[v1] += num[v2];
//	}
//	else {
//		parent[v2] = v1;
//		num[v2] += num[v1];
//	}
//}
//void insertHeapEdge(HeapType *h, int v, int u, int weight) {
//	Element node;
//	node.v = v;
//	node.u = u;
//	node.key = weight;
//
//	insertHeap(h, node);
//}
//int kruskal() {
//	Element e;
//	HeapType h;
//	int uSet, vSet, edgeCount = 0, sum = 0;
//	int start, end, weight;
//
//	h.heap_size = 0;
//	for (int i = 0;i < 100;i++) {
//		parent[i] = -1;
//		num[i] = 1;
//	}
//
//	for (int i = 0;i < m;i++) {
//		scanf("%d %d %d", &start, &end, &weight);
//		insertHeapEdge(&h, start, end, weight);
//	}
//
//	while (edgeCount < n - 1) {
//		e = deleteHeap(&h); // 최소 힙
//
//		uSet = setFind(e.u);
//		vSet = setFind(e.v);
//
//		if (uSet != vSet) {
//			printf(" %d", e.key);
//			sum += e.key;
//			edgeCount++;
//			setUnion(uSet, vSet);
//		}
//	}
//	printf("\n%d\n", sum);
//}