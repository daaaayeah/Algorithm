#include <stdio.h>
#include <stdlib.h>

//2 ���� ���߱׷������� �ִܰŸ� ã�� (Bellman-Ford �˰���)
typedef struct Vertex {
	int vNum;
	int dist;
}Vertex;
typedef struct Edge {
	int startVertex, endVertex;
	int weight;
}Edge;

int n, m, s; // ���� ���� n, ���� ���� m, ������� ��ȣ s
Vertex vertices[100];
Edge edges[1000];

void makeGraph();
int smaller(int a, int b);
void Bellman_FordShortestPaths(Vertex *s);

int main() {
	makeGraph();

	for (int i = 0; i < n; i++) {
		if (vertices[i].vNum == s) {
			Bellman_FordShortestPaths(vertices + i);
			break;
		}
	}


	for (int i = 0; i < n; i++) {
		if ((vertices[i].vNum == s) || (vertices[i].dist == 30000)) continue;
		printf("%d %d\n", vertices[i].vNum, vertices[i].dist);
	}
}

void makeGraph() {
	int inputStart, inputEnd, inputWeight;

	scanf("%d %d %d", &n, &m, &s);

	// ��������Ʈ vertices ����
	for (int i = 0; i < n; i++)
		vertices[i].vNum = i + 1;

	// ��������Ʈ edges ����
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &inputStart, &inputEnd, &inputWeight);
		edges[i].startVertex = inputStart;
		edges[i].endVertex = inputEnd;
		edges[i].weight = inputWeight;
	}
}
int smaller(int a, int b) {
	return a < b ? a : b;
}
void Bellman_FordShortestPaths(Vertex *s) {
	Vertex *u = NULL, *z = NULL;

	for (int i = 0; i < n; i++)
		vertices[i].dist = 30000; // ���Ѵ밪 30000���� ����
	s->dist = 0;

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < m; j++) {
			u = vertices + (edges[j].startVertex - 1);
			z = vertices + (edges[j].endVertex - 1);

			if ((u->dist != 30000) && (u->dist + edges[j].weight < z->dist))
				z->dist = u->dist + edges[j].weight;
		}
	}
}