//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
////1 무방향 양의 가중그래프에서 최단거리 찾기 (Dijkstra 알고리즘)
//typedef struct Vertex {
//	int vNum;
//	int dist;
//}Vertex;
//typedef struct Edge {
//	int startVertex, endVertex;
//	int weight;
//}Edge;
//
//int n, m, s; // 정점 개수 n, 간선 개수 m, 출발정점 번호 s
//Vertex vertices[100];
//Edge edges[1000];
//Vertex Heap[101];
//int hIdx = 0;
//
//void makeGraph();
//void swapElements(Vertex *a, Vertex *b);
//void insertItem(Vertex v);
//void upHeap(int i);
//Vertex removeMin();
//void replaceItem(int i, int key);
//void downHeap(int i);
//Vertex *oppositeVertex(int ei, Vertex v);
//void DijkstraShortestPaths(Vertex *s);
//
//int main() {
//	makeGraph();
//	printf("<< vertices >>\n");
//	for (int i = 0;i < n;i++)
//		printf(" %d(%d)", vertices[i].vNum, vertices[i].dist);
//	printf("\n<< edges >>\n");
//	for (int i = 0;i < m;i++)
//		printf(" %d%d(%d)", edges[i].startVertex, edges[i].endVertex, edges[i].weight);
//	printf("\n");
//
//	for (int i = 0;i < n;i++) {
//		if (vertices[i].vNum == s) {
//			DijkstraShortestPaths(vertices + i);
//			break;
//		}
//	}
//	for (int i = 0;i < n;i++) {
//		if ((vertices[i].vNum == s) || (vertices[i].dist == 30000)) continue;
//		printf(" %d(%d)", vertices[i].vNum, vertices[i].dist);
//	}
//}
//
//void makeGraph() {
//	int inputStart, inputEnd, inputWeight;
//
//	scanf("%d %d %d", &n, &m, &s);
//
//	// 정점리스트 vertices 생성
//	for (int i = 0;i < n;i++)
//		vertices[i].vNum = i + 1;
//
//	// 간선리스트 edges 생성
//	for (int i = 0;i < m;i++) {
//		scanf("%d %d %d", &inputStart, &inputEnd, &inputWeight);
//		edges[i].startVertex = inputStart;
//		edges[i].endVertex = inputEnd;
//		edges[i].weight = inputWeight;
//	}
//}
//void swapElements(Vertex *a, Vertex *b) {
//	Vertex tmp;
//
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void insertItem(Vertex v) {
//	Heap[++hIdx] = v;
//	upHeap(hIdx);
//}
//void upHeap(int i) {
//	int parentIdx = i / 2;
//
//	if ((i == 1) || (Heap[i].dist >= Heap[parentIdx].dist)) return;
//	swapElements(&Heap[i], &Heap[parentIdx]);
//	upHeap(parentIdx);
//}
//Vertex removeMin() {
//	Vertex k;
//
//	k = Heap[1];
//	Heap[1] = Heap[hIdx--];
//	downHeap(1);
//
//	return k;
//}
//void replaceItem(int i, int key) {
//	Vertex oldKey = Heap[i];
//
//	Heap[i].dist = key;
//	if (key < oldKey.dist)
//		upHeap(i);
//	else
//		downHeap(i);
//}
//void downHeap(int i) {
//	int lChildIdx = i * 2, rChildIdx = i * 2 + 1;
//	int smaller;
//
//	if ((lChildIdx > hIdx) && (rChildIdx > hIdx)) return;
//	smaller = lChildIdx;
//	if (rChildIdx <= hIdx) {
//		if (Heap[rChildIdx].dist < Heap[smaller].dist)
//			smaller = rChildIdx;
//	}
//	if (Heap[i].dist <= Heap[smaller].dist) return;
//	swapElements(&Heap[i], &Heap[smaller]);
//	downHeap(smaller);
//}
//Vertex *oppositeVertex(int ei, Vertex v) {
//	int oppositeNum;
//
//	if (v.vNum == edges[ei].startVertex)
//		oppositeNum = edges[ei].endVertex;
//	else if (v.vNum == edges[ei].endVertex)
//		oppositeNum = edges[ei].startVertex;
//
//	for (int i = 0;i < n;i++) {
//		if (vertices[i].vNum == oppositeNum)
//			return vertices + i;
//	}
//}
//void DijkstraShortestPaths(Vertex *s) {
//	Vertex u, *z;
//	int weight;
//
//	for (int i = 0;i < n;i++)
//		vertices[i].dist = 30000; // 무한대값 30000으로 설정
//	s->dist = 0;
//	for (int i = 0;i < n;i++)
//		insertItem(vertices[i]);
//
//	while (hIdx > 0) {
//		printf("\nhIdx = %d\n", hIdx);
//		u = removeMin();
//		printf("u = %d(%d)\n", u.vNum, u.dist);
//		for (int i = 0;i < m;i++) {
//			if (u.vNum == edges[i].startVertex || u.vNum == edges[i].endVertex) {
//				z = oppositeVertex(i, u);
//				printf("z = %d(%d)\n", z->vNum, z->dist);
//				for (int j = 1;j <= hIdx;j++) {
//					if (z->vNum == Heap[j].vNum) {
//						for (int k = 0;k < m;k++) {
//							if ((edges[k].startVertex == u.vNum && edges[k].endVertex == z->vNum) || (edges[k].startVertex == z->vNum && edges[k].endVertex == u.vNum)) {
//								weight = edges[k].weight;
//								printf("weight = %d\n", weight);
//								break;
//							}
//						}
//						if (u.dist + weight < z->dist) {
//							z->dist = u.dist + weight;
//							printf("z->dist = %d\n", z->dist);
//							replaceItem(j, z->dist);
//						}
//					}
//				}
//			}
//		}
//	}
//
//}