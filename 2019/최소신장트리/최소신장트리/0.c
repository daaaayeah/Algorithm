#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#define INF 10000L

//1 Prim-Jarnki 알고리즘
typedef struct vertex {
	int num, distance;
}vertex;
typedef struct edge {
	int startVertex, endVertex;
	int weight;
}edge;

int n, m; // 정점 개수 n, 간선 개수 m
vertex vertices[100];
edge edges[1000];
int heap[100];
int index;

void makeEdges(int i, int startVertex, int endVertex, int weight);
void makeGraph();
vertex oppositeVertex(vertex *v, int ei);
void Prim_Jarnik_MST();
void swap(int *a, int *b);
void insertItem(int key);
int removeMin();
void replaceItem(int i, int key);
void upHeap(int i);
void downHeap(int i, int last);

int main() {
	makeGraph();
	Prim_Jarnik_MST();
}

void makeEdges(int i, int startVertex, int endVertex, int weight) {
	edges[i].startVertex = startVertex;
	edges[i].endVertex = endVertex;
	edges[i].weight = weight;
}
void makeGraph() {
	int inputEdgeStart, inputEdgeEnd, inputWeight;

	scanf("%d %d", &n, &m);

	// 정점리스트 vertices 생성
	for (int i = 0;i < n;i++) {
		vertices[i].num = i + 1;
		vertices[i].distance = INF;
	}

	// 간선리스트 edges 생성
	for (int i = 0;i < m;i++) {
		scanf("%d %d %d", &inputEdgeStart, &inputEdgeEnd, &inputWeight);
		makeEdges(i, inputEdgeStart, inputEdgeEnd, inputWeight);
	}
}
vertex oppositeVertex(vertex *v, int ei) {
	vertex opposite;
	int vNum;

	if (v->num == edges[ei].startVertex)
		vNum = edges[ei].endVertex;
	else if (v->num == edges[ei].endVertex)
		vNum = edges[ei].startVertex;

	for (int i = 0;i < n;i++) {
		if (vertices[i].num == vNum) {
			opposite = vertices[i];
			break;
		}
	}

	return opposite;
}
void Prim_Jarnik_MST() {
	vertex *MST, opposite[1000] = { 0 };
	int minDist, place, mstIdx = 0, oppositeIdx = 0;
	int sumWeight = 0;
	MST = (vertex *)malloc(n * sizeof(vertex));

	vertices->distance = 0;
	for (int i = 0;i < n;i++)
		insertItem(vertices[i].distance);

	while (index > 0) {
		minDist = removeMin();
		for (int i = 0;i < n;i++) {
			if (vertices[i].distance == minDist)
				MST[mstIdx] = vertices[i];
		}
		for (int i = 0;i < mstIdx;i++) {
			for (int j = 0;j < m;j++) {
				if (MST[i].num == edges[j].startVertex || MST[i].num == edges[j].endVertex) {
					opposite[oppositeIdx] = oppositeVertex(MST + i, j);
					opposite[oppositeIdx].distance = edges[j].weight;
					oppositeIdx++;
				}
			}
		}
		for (int j = 0;opposite[j].num != 0;j++) {
			place = opposite[j].num - 1;
			replaceItem(place, opposite[j].distance);
		}
		for (int j = 0;j < n;j++) {
			for (int k = 0;k < n;k++) {
				if (vertices[j].num == opposite[k].num)
					vertices[j] = opposite[k];
			}
		}
	}
}
void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void insertItem(int key) {
	heap[++index] = key;
	upHeap(index);
}
int removeMin() {
	int key;
	key = heap[1];
	heap[1] = heap[index--];
	downHeap(1, index);
	return key;
}
void replaceItem(int i, int key) {
	heap[i] = key;
	upHeap(i);
	downHeap(i, index);
}
void upHeap(int i) {
	if (i == 1 || (heap[i / 2] < heap[i])) return;
	else {
		swap(&heap[i], &heap[i / 2]);
		upHeap(i / 2);
	}
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