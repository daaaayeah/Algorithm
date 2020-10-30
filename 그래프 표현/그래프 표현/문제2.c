#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

//2 인접행렬 구현
typedef struct vertex {
	int num;
	int index;
}vertex;
typedef struct edge {
	int startNode, endNode;
	int element;
}edge;

vertex vertices[6];
edge edges[21];
int adjacencyMatrix[6][6];
int edgesLength = 8;

void makeEdges(int i, int startNode, int endNode, int element);
void makeGraph();
int findVertex(int num);
void printAdjacencyMatrix(int vi);
int changeEdge(int startNode, int endNode, int w);
void deleteEdge(int startNode, int endNode);
void updateAdjacencyMatrix(int vi);

int main() {
	char instruction;
	int nodeNum, a, b, w;

	for (int i = 0;i < 21;i++) {
		edges[i].startNode = 0;
		edges[i].endNode = 0;
		edges[i].element = 0;
	}
	for (int i = 0;i < 6;i++) {
		for (int j = 0;j < 6;j++)
			adjacencyMatrix[i][j] = -1;
	}
	makeGraph();

	while (scanf("%c", &instruction)) {
		switch (instruction) {
		case 'a':
			scanf("%d", &nodeNum);
			if (findVertex(nodeNum) == 0)
				printf("-1");
			else
				printAdjacencyMatrix(nodeNum - 1);
			printf("\n");
			break;
		case 'm':
			scanf("%d %d %d", &a, &b, &w);
			if (findVertex(a) == 0 || findVertex(b) == 0)
				printf("-1\n");
			else if (findVertex(a) == 1 && findVertex(b) == 1) {
				if (w == 0) {
					deleteEdge(a, b);
					for (int i = 0;i < 6;i++) {
						for (int j = 0;j < 6;j++)
							adjacencyMatrix[i][j] = -1;
						updateAdjacencyMatrix(i);
					}
				}
				else {
					adjacencyMatrix[a - 1][b - 1] = changeEdge(a, b, w);
					if (a != b)
						adjacencyMatrix[b - 1][a - 1] = changeEdge(a, b, w);
				}
			}
			break;
		case 'q':
			return;
		}
	}
}

void makeEdges(int i, int startNode, int endNode, int element) {
	edges[i].startNode = startNode;
	edges[i].endNode = endNode;
	edges[i].element = element;
}
void makeGraph() {
	// 정점리스트 vertices 생성
	for (int i = 0;i < 6;i++) {
		vertices[i].num = i + 1;
		vertices[i].index = i;
	}
	// 간선리스트 edges 생성
	makeEdges(0, 0, 1, 1);
	makeEdges(1, 0, 2, 1);
	makeEdges(2, 0, 3, 1);
	makeEdges(3, 0, 5, 2);
	makeEdges(4, 1, 2, 1);
	makeEdges(5, 2, 4, 4);
	makeEdges(6, 4, 4, 4);
	makeEdges(7, 4, 5, 3);
	// 인접행렬 adjacencyMatrix 생성
	for (int i = 0;i < 6;i++) {
		for (int j = 0;j < 6;j++) {
			for (int k = 0;k < edgesLength;k++) {
				if ((i == edges[k].startNode && j == edges[k].endNode) || (j == edges[k].startNode && i == edges[k].endNode))
					adjacencyMatrix[i][j] = k;
			}
		}
	}
}
int findVertex(int num) {
	for (int i = 0;i < 6;i++) {
		if (num == vertices[i].num)
			return 1;
	}
	return 0;
}
void printAdjacencyMatrix(int vi) {
	int ei;

	for (int j = 0;j < 6;j++) {
		if (adjacencyMatrix[vi][j] == -1)
			continue;
		ei = adjacencyMatrix[vi][j];
		if (vi == edges[ei].startNode)
			printf(" %d", edges[ei].endNode + 1);
		else if (vi == edges[ei].endNode)
			printf(" %d", edges[ei].startNode + 1);
		printf(" %d", edges[ei].element);
	}
}
int changeEdge(int startNode, int endNode, int w) {
	int ei, flag = 0;
	for (int i = 0;i < edgesLength;i++) { // 간선이 존재하는 경우 가중치 변경
		if ((startNode - 1 == edges[i].startNode && endNode - 1 == edges[i].endNode) || (startNode - 1 == edges[i].endNode && endNode - 1 == edges[i].startNode)) {
			flag = 1;
			ei = i;
			break;
		}
	}
	if (flag == 0) { // 간선이 존재하지 않는 경우 새로운 간선 생성
		edgesLength++;
		for (int i = 0;i < edgesLength;i++) {
			if (edges[i].element == 0) {
				ei = i;
				break;
			}
		}
		edges[ei].startNode = startNode - 1;
		edges[ei].endNode = endNode - 1;
	}
	edges[ei].element = w;
	return ei;
}
void deleteEdge(int startNode, int endNode) {
	int ei, flag = 0;
	for (int i = 0;i < edgesLength;i++) { // 간선이 존재하는 경우 삭제
		if ((startNode - 1 == edges[i].startNode && endNode - 1 == edges[i].endNode) || (startNode - 1 == edges[i].endNode && endNode - 1 == edges[i].startNode)) {
			flag = 1;
			ei = i;
			break;
		}
	}
	if (flag == 0) { // 간선이 존재하지 않는 경우 중단
		printf("-1\n");
		return;
	}
	for (int i = ei;i < edgesLength;i++)
		edges[i] = edges[i + 1];
	edgesLength--;
}
void updateAdjacencyMatrix(int vi) {
	for (int i = 0;i < 6;i++) {
		for (int k = 0;k < edgesLength;k++) {
			if ((i == edges[k].startNode && vi == edges[k].endNode) || (vi == edges[k].startNode && i == edges[k].endNode))
				adjacencyMatrix[i][vi] = k;
		}
	}
	for (int j = 0;j < 6;j++) {
		for (int k = 0;k < edgesLength;k++) {
			if ((vi == edges[k].startNode && j == edges[k].endNode) || (j == edges[k].startNode && vi == edges[k].endNode))
				adjacencyMatrix[vi][j] = k;
		}
	}
}