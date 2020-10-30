//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//// 2 BFS(너비우선탐색) 순회 - 인접행렬
//typedef struct vertex {
//	int num, label;
//}vertex;
//typedef struct edge {
//	int startNode, endNode;
//}edge;
//typedef struct Queue {
//	int front, rear;
//	int *a;
//}Queue;
//
//int n, m, s; // 정점 개수 n, 간선 개수 m, 순회 시작 vertex 번호 s
//vertex vertices[101];
//edge edges[1000];
//int adjacencyMatrix[101][101];
//
//void makeEdges(int i, int startNode, int endNode);
//void makeGraph();
//void BFS();
//void BFS1(Queue *q);
//
//int main() {
//	scanf("%d %d %d", &n, &m, &s);
//
//	makeGraph();
//	BFS();
//}
//
//void makeEdges(int i, int startNode, int endNode) {
//	edges[i].startNode = startNode;
//	edges[i].endNode = endNode;
//}
//void makeGraph() {
//	int inputEdgeStart, inputEdgeEnd;
//
//	// 정점리스트 vertices 생성
//	for (int i = 1;i <= n;i++) {
//		vertices[i].num = i;
//		vertices[i].label = 0;
//	}
//
//	// 간선리스트 edges 생성
//	for (int i = 0;i < m;i++) {
//		scanf("%d %d", &inputEdgeStart, &inputEdgeEnd);
//		makeEdges(i, inputEdgeStart, inputEdgeEnd);
//	}
//
//	// 인접행렬 adjacencyMatrix 생성
//	for (int i = 1;i <= n;i++) {
//		for (int j = 1;j <= n;j++)
//			adjacencyMatrix[i][j] = -1;
//	}
//	for (int i = 1;i <= n;i++) {
//		for (int j = 1;j <= n;j++) {
//			for (int k = 0;k < m;k++) {
//				if ((i == edges[k].startNode && j == edges[k].endNode) || (j == edges[k].startNode && i == edges[k].endNode))
//					adjacencyMatrix[i][j] = k;
//			}
//		}
//	}
//}
//void BFS() {
//	Queue queue;
//	queue.a = (int *)malloc((2 * m) * sizeof(int));
//	BFS1(&queue);
//}
//void BFS1(Queue *q) {
//	int vNum, *L, ei, k = 0;
//	L = (int *)malloc(n * sizeof(int));
//
//	if (vertices[s].label == 1) return;
//
//	q->front = 0;
//	q->rear = 1;
//	q->a[q->front] = s;
//
//	while (q->front != q->rear) {
//		vNum = q->a[q->front];
//		q->front++;
//
//		if (vertices[vNum].label == 1) continue;
//
//		L[k++] = vNum;
//		vertices[vNum].label = 1;
//
//		for (int i = 1;i <= n;i++) {
//			ei = adjacencyMatrix[vNum][i];
//			if (ei == -1) continue;
//			if (edges[ei].startNode == vNum) {
//				q->a[q->rear] = edges[ei].endNode;
//				q->rear++;
//			}
//			else {
//				q->a[q->rear] = edges[ei].startNode;
//				q->rear++;
//			}
//		}
//	}
//	for (int i = 0;i < n;i++)
//		printf("%d\n", L[i]);
//}