#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

//1 DFS(깊이우선탐색) 순회 - 인접리스트
typedef struct vertex {
	int num, label;
	struct vertex *next;
}vertex;
typedef struct edge {
	int label;
	int startNode, endNode;
}edge;

int n, m, s; // 정점 개수 n, 간선 개수 m, 순회 시작 vertex 번호 s
vertex vertices[100];
edge edges[1000];

void intSwap(int *a, int *b);
int findEdgePlace(int ei, int inputEdgeStart, int inputEdgeEnd);
void makeEdges(int i, int startNode, int endNode);
void makeGraph();
vertex *oppositeNode(int nodeNum, int ei);
void DFS(vertex *v, vertex *vIncidence);

int main() {
	scanf("%d %d %d", &n, &m, &s);

	makeGraph();
	DFS(vertices + s, vertices[s].next);
}

void intSwap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int findEdgePlace(int ei, int inputEdgeStart, int inputEdgeEnd) {
	edge tmp[999];

	for (int i = 0;i < ei;i++) {
		if (edges[i].startNode < inputEdgeStart)
			continue;
		else if (inputEdgeStart == edges[i].startNode) {
			if (edges[i].endNode < inputEdgeEnd)
				continue;
		}
		for (int j = i;j < ei;j++)
			tmp[j] = edges[j];
		for (int j = i;j < ei;j++)
			edges[j + 1] = tmp[j];
		return i;
	}
}
void makeEdges(int i, int startNode, int endNode) {
	edges[i].startNode = startNode;
	edges[i].endNode = endNode;
}
void makeIncidenceLists(vertex *v, int ei) {
	vertex *input;
	input = (vertex *)malloc(sizeof(vertex));
	input->num = ei;
	input->next = NULL;

	if (v->next == NULL)
		v->next = input;
	else
		makeIncidenceLists(v->next, ei);
}
void makeGraph() {
	int inputIndex, inputEdgeStart, inputEdgeEnd;

	// 정점리스트 vertices 생성
	for (int i = 1;i <= n;i++) {
		vertices[i].num = i;
		vertices[i].label = 0;
		vertices[i].next = NULL;
	}

	// 간선리스트 edges 생성
	for (int i = 0;i < m;i++) {
		scanf("%d %d", &inputEdgeStart, &inputEdgeEnd);
		if (inputEdgeStart > inputEdgeEnd)
			intSwap(&inputEdgeStart, &inputEdgeEnd);

		if (i == 0) inputIndex = i;
		else
			inputIndex = findEdgePlace(i, inputEdgeStart, inputEdgeEnd);
		makeEdges(inputIndex, inputEdgeStart, inputEdgeEnd);
	}

	// 부착리스트 incidenceLists 생성
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j < m;j++) {
			if (vertices[i].num == edges[j].startNode || vertices[i].num == edges[j].endNode)
				makeIncidenceLists(vertices + i, j);
		}
	}
}
vertex *oppositeNode(int nodeNum, int ei) {
	int vNum;
	if (nodeNum == edges[ei].startNode)
		vNum = edges[ei].endNode;
	else if (nodeNum == edges[ei].endNode)
		vNum = edges[ei].startNode;
	for (int i = 1;i <= n;i++) {
		if (vertices[i].num == vNum)
			return (vertices + i);
	}
}
void DFS(vertex *v, vertex *vIncidence) {
	vertex *w;
	v->label = 1;
	printf("%d\n", v->num);
	while (vIncidence != NULL) {
		w = oppositeNode(v->num, vIncidence->num);
		if (w->label == 0) // Fresh
			rDFS(w, w->next);
		else // Visited
			vIncidence = vIncidence->next;
	}
}