//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
////1 Prim-Jarnki 알고리즘
//typedef struct vertex {
//	int num, distance;
//}vertex;
//typedef struct edge {
//	int startVertex, endVertex;
//	int weight;
//}edge;
//
//int n, m; // 정점 개수 n, 간선 개수 m
//vertex vertices[100];
//edge edges[1000];
//int heap[100];
//int index;
//
//void makeEdges(int i, int startVertex, int endVertex, int weight);
//void makeGraph();
//vertex *oppositeVertex(vertex *v);
//void Prim_Jarnik_MST();
//void swap(int *a, int *b);
//void insertItem(int key);
//int removeMin();
//void upHeap(int i);
//void downHeap(int i, int last);
//void heapSort();
//
//int main() {
//	makeGraph();
//
//	printf("<< vertices >>");
//	for (int i = 0;i < n;i++)
//		printf(" %d(%d)", vertices[i].num, vertices[i].distance);
//	printf("\n<< edges >>");
//	for (int i = 0;i < m;i++)
//		printf(" %d%d(%d)", edges[i].startVertex, edges[i].endVertex, edges[i].weight);
//	printf("\n");
//	Prim_Jarnik_MST();
//}
//
//void makeEdges(int i, int startVertex, int endVertex, int weight) {
//	edges[i].startVertex = startVertex;
//	edges[i].endVertex = endVertex;
//	edges[i].weight = weight;
//}
//void makeGraph() {
//	int inputEdgeStart, inputEdgeEnd, inputWeight;
//
//	scanf("%d %d", &n, &m);
//
//	// 정점리스트 vertices 생성
//	for (int i = 0;i < n;i++) {
//		vertices[i].num = i + 1;
//		vertices[i].distance = -1;
//	}
//
//	// 간선리스트 edges 생성
//	for (int i = 0;i < m;i++) {
//		scanf("%d %d %d", &inputEdgeStart, &inputEdgeEnd, &inputWeight);
//		makeEdges(i, inputEdgeStart, inputEdgeEnd, inputWeight);
//	}
//}
//vertex *oppositeVertex(vertex *v) {
//	vertex opposite[1000] = { 0 };
//	int vNum[1000], j = 0, k = 0;
//
//	for (int i = 0;i < m;i++) {
//		if (v->num == edges[i].startVertex)
//			vNum[j++] = edges[i].endVertex;
//		else if (v->num == edges[i].endVertex)
//			vNum[j++] = edges[i].startVertex;
//	}
//	for (int i = 0, j = 0;i < n;i++) {
//		if (vertices[i].num == vNum[j]) {
//			opposite[k++] = vertices[i];
//			j++;
//		}
//	}
//
//	return opposite;
//}
//void Prim_Jarnik_MST() {
//	vertex *v, *opposite, *u, *z;
//	vertex *MST;
//	int sizeMST = 0, removed, sumWeight = 0;
//	MST = (vertex *)malloc(n * sizeof(vertex));
//
//	for (int i = 0;i < n;i++) {
//		MST[i].num = 0;
//		MST[i].distance = -1;
//	}
//	index = 0;
//	vertices->distance = 0;
//	MST = vertices;
//	sizeMST++;
//
//	for (int i = 0;i < sizeMST;i++) {
//		opposite = oppositeVertex(MST + i);
//		for (int j = 0;opposite[j].num != 0;j++) {
//			for (int k = 0;k < m;k++) {
//				if (opposite[j].num == edges[k].startVertex || opposite[j].num == edges[k].endVertex) {
//					opposite[j].distance = edges[k].weight;
//					break;
//				}
//			}
//		}
//		for (int j = 0;opposite[j].num != 0;j++)
//			printf("%d(%d)\n", opposite[j].num, opposite[j].distance);
//
//		for (int j = 0;j < n;j++) {
//			for (int k = 0;k < n;k++) {
//				if (vertices[j].num == opposite[k].num)
//					vertices[j] = opposite[k];
//			}
//		}
//	}
//
//	for (int i = 0;i < n;i++)
//		printf(" %d(%d)", vertices[i].num, vertices[i].distance);
//	printf("\n");
//	for (int i = 0;i < n;i++)
//		insertItem(vertices[i].distance);
//
//	while (index > 0) {
//		removed = removeMin();
//		printf("%d\n",removed);
//	}
//	//heapSort();
//
//	
//}
//void swap(int *a, int *b) {
//	int tmp;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void insertItem(int key) {
//	printf("index : %d, key : %d\n", index, key);
//	heap[++index] = key;
//	upHeap(index);
//}
//int removeMin() {
//	int key;
//	key = heap[1];
//	heap[1] = heap[index--];
//	downHeap(1, index);
//	return key;
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
//	for (int i = index / 2; i >= 1; i--)
//		downHeap(i, index);
//	id = index;
//	for (int i = 1; i <= index; i++) {
//		printf(" %d", heap[1]);
//		heap[1] = heap[id--];
//		downHeap(1, id);
//	}
//}