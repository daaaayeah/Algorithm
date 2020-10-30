//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//#define INF 10000L
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
//int *dist;
//
//void makeEdges(int i, int startVertex, int endVertex, int weight);
//void makeGraph();
//vertex oppositeVertex(vertex *v, int ei);
//int findMin();
//int findSecondMin(int a);
//void Prim_Jarnik_MST();
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
//		vertices[i].distance = INF;
//	}
//
//	// 간선리스트 edges 생성
//	for (int i = 0;i < m;i++) {
//		scanf("%d %d %d", &inputEdgeStart, &inputEdgeEnd, &inputWeight);
//		makeEdges(i, inputEdgeStart, inputEdgeEnd, inputWeight);
//	}
//}
//vertex oppositeVertex(vertex *v, int ei) {
//	vertex opposite;
//	int vNum = 0;
//
//	if (v->num == edges[ei].startVertex)
//		vNum = edges[ei].endVertex;
//	else if (v->num == edges[ei].endVertex)
//		vNum = edges[ei].startVertex;
//
//	for (int i = 0;i < n;i++) {
//		if (vertices[i].num == vNum) {
//			opposite = vertices[i];
//			break;
//		}
//	}
//
//	return opposite;
//}
//int findMin() {
//	int min = dist[0];
//	for (int i = 1;i < n;i++) {
//		if (dist[i] < min)
//			min = dist[i];
//	}
//	return min;
//}
//int findSecondMin(int a) {
//	int min = dist[0];
//	for (int i = 1;i < n;i++) {
//		if (dist[i] < min && dist[i] > a)
//			min = dist[i];
//	}
//	return min;
//}
//void Prim_Jarnik_MST() {
//	vertex *MST, opposite[1000] = { 0 }, tmp;
//	int minDist, place, mstIdx = 0, oppositeIdx = 0;
//	int sumWeight = 0, cnt = n, flag = 0;
//	MST = (vertex *)malloc(n * sizeof(vertex));
//	dist = (int *)malloc(n * sizeof(vertex));
//
//	vertices->distance = 0;
//	for (int i = 0;i < n;i++)
//		dist[i] = vertices[i].distance;
//
//
//	for (int i = 0;i < n;i++)
//		printf(" %d", dist[i]);
//	printf("\n");
//	
//	while (cnt > 0) {
//		for (int i = 0;i < n;i++)
//			printf(" %d(%d)", vertices[i].num, vertices[i].distance);
//		printf("\n");
//		flag = 0;
//		minDist = findMin();
//		printf("minDist : %d\n", minDist);
//		for (int i = 0;i < n;i++) {
//			if (vertices[i].distance == minDist) {
//				for (int j = 0;j < mstIdx;j++) {
//					if (vertices[i].num == MST[j].num)
//						minDist = findSecondMin(findMin());
//				}
//			}
//		}
//		printf("changed minDist : %d\n", minDist);
//		for (int i = 0;i < n;i++) {
//			if (vertices[i].distance == minDist) {
//				MST[mstIdx] = vertices[i];
//				printf("print : %d ***\n", MST[mstIdx++].num);
//			}
//		}
//		for (int i = 0;i < n;i++) {
//			if (minDist == dist[i])
//				dist[i] = INF;
//		}
//		printf("MST\n");
//		for (int i = 0;i < mstIdx;i++) {
//			printf(" %d", MST[i].num);
//		}
//		printf("\n");
//		oppositeIdx = 0;
//		for (int i = 0;i < mstIdx;i++) {
//			for (int j = 0;j < m;j++) {
//				flag = 0;
//				if (MST[i].num == edges[j].startVertex || MST[i].num == edges[j].endVertex) {
//					tmp = oppositeVertex(MST + i, j);
//					for (int k = 0;k < mstIdx;k++) {
//						if (tmp.num == MST[k].num) {
//							printf("mst : %d\n", MST[k].num);
//							flag = 1;
//							break;
//						}
//					}
//					for (int k = 0;opposite[k].num != 0;k++) {
//						if (tmp.num == opposite[k].num) {
//							flag = 1;
//							break;
//						}
//					}
//
//					if (flag == 1) continue;
//					printf("tmp num : %d\n", tmp.num);
//					opposite[oppositeIdx] = tmp;
//					opposite[oppositeIdx].distance = edges[j].weight;
//					oppositeIdx++;
//				}
//			}
//		}
//		printf("opposite\n");
//		for (int j = 0;opposite[j].num != 0;j++) {
//			printf(" %d(%d)", opposite[j].num, opposite[j].distance);
//		}
//		printf("\n");
//		for (int j = 0;opposite[j].num != 0;j++) {
//			place = opposite[j].num - 1;
//			if (dist[place] < opposite[j].distance) continue;
//			dist[place] = opposite[j].distance;
//		}
//		printf("dist\n");
//		for (int i = 0;i < n;i++)
//			printf(" %d", dist[i]);
//		printf("\n");
//		for (int j = 0;j < n;j++) {
//			for (int k = 0;k < n;k++) {
//				if (vertices[j].num == opposite[k].num)
//					vertices[j] = opposite[k];
//			}
//		}
//		cnt--;
//	}
//
//	for (int i = 0;i < n;i++) {
//		//sumWeight += vertices[i].distance;
//		printf(" %d(%d)", vertices[i].num, vertices[i].distance);
//	}
//	//printf("\n%d\n", sumWeight);
//}