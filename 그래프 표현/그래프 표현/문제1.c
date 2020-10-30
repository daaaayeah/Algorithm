#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

//1 ��������Ʈ ����
typedef struct vertex {
	int num;
	struct vertex *next;
}vertex;
typedef struct edge {
	int startNode, endNode;
	int element;
}edge;

vertex vertices[6];
edge edges[21];
int edgesLength = 8;

void makeEdges(int i, int startNode, int endNode, int element);
void makeIncidenceLists(vertex *v, int num);
void makeGraph();
int findVertex(int num);
int returnVertexIndex(int num);
void printIncidenceLists(vertex *v, int vi);
void changeEdge(int startNode, int endNode, int w);
void deleteEdge(int startNode, int endNode);
void updateIncidenceLists(vertex *v, int vi);

int main() {
	char instruction;
	int nodeNum, vi, a, b, w;

	for (int i = 0;i < 21;i++) {
		edges[i].startNode = 0;
		edges[i].endNode = 0;
		edges[i].element = 0;
	}
	makeGraph();

	while (scanf("%c", &instruction)) {
		switch (instruction) {
		case 'a':
			scanf("%d", &nodeNum);
			if (findVertex(nodeNum) == 0)
				printf("-1");
			else {
				vi = returnVertexIndex(nodeNum);
				printIncidenceLists(vertices + vi, vi);
			}
			printf("\n");
			break;
		case 'm':
			scanf("%d %d %d", &a, &b, &w);
			if (findVertex(a) == 0 || findVertex(b) == 0)
				printf("-1\n");
			else if (findVertex(a) == 1 && findVertex(b) == 1) {
				if (w == 0)
					deleteEdge(a, b);
				else
					changeEdge(a, b, w);
				for (int i = 0;i < 6;i++) {
					(vertices + i)->next = NULL;
					updateIncidenceLists(vertices + i, i);
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
void makeIncidenceLists(vertex *v, int num) {
	vertex *input;
	input = (vertex *)malloc(sizeof(vertex));
	input->num = num;
	input->next = NULL;

	if (v->next == NULL)
		v->next = input;
	else
		makeIncidenceLists(v->next, num);
}
void makeGraph() {
	// ��������Ʈ vertices ����
	for (int i = 0;i < 6;i++) {
		vertices[i].num = i + 1;
		vertices[i].next = NULL;
	}
	// ��������Ʈ edges ����
	makeEdges(0, 0, 1, 1);
	makeEdges(1, 0, 2, 1);
	makeEdges(2, 0, 3, 1);
	makeEdges(3, 0, 5, 2);
	makeEdges(4, 1, 2, 1);
	makeEdges(5, 2, 4, 4);
	makeEdges(6, 4, 4, 4);
	makeEdges(7, 4, 5, 3);
	// ��������Ʈ incidenceLists ����
	for (int i = 0;i < 6;i++) { // vertices�� ���� for��
		for (int j = 0;j < edgesLength;j++) { // edges�� ���� for��
			if (i == edges[j].startNode || i == edges[j].endNode)
				makeIncidenceLists(vertices + i, j);
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
int returnVertexIndex(int num) {
	for (int i = 0;i < 6;i++) {
		if (num == vertices[i].num)
			return i;
	}
}
void printIncidenceLists(vertex *v, int vi) {
	int ei;
	if (v->next == NULL) return;
	ei = v->next->num;
	if (vi == edges[ei].startNode)
		printf(" %d", edges[ei].endNode + 1);
	else if (vi == edges[ei].endNode)
		printf(" %d", edges[ei].startNode + 1);
	printf(" %d", edges[ei].element);
	if (v->next->next != NULL)
		printIncidenceLists(v->next, vi);
}
void changeEdge(int startNode, int endNode, int w) {
	edge tmp[21];
	int ei, flag = 0, temp;
	for (int i = 0;i < edgesLength;i++) { // ������ �����ϴ� ��� ����ġ ����
		if ((startNode - 1 == edges[i].startNode && endNode - 1 == edges[i].endNode) || (startNode - 1 == edges[i].endNode && endNode - 1 == edges[i].startNode)) {
			flag = 1;
			ei = i;
			break;
		}
	}
	if (flag == 0) { // ������ �������� �ʴ� ��� ���ο� ���� ����
		edgesLength++;
		if (startNode > endNode) { // �ڱ� �ڽ����� ���� ������ �ƴ� ���
			temp = startNode;
			startNode = endNode;
			endNode = temp;
		}
		if (edges[edgesLength - 2].startNode < (startNode - 1)) // ���ο� ������ (6, 6)�� ���
			ei = edgesLength - 1;
		else {
			for (int i = 0;i < edgesLength;i++) {
				if (edges[i].startNode < startNode - 1)
					continue;
				else { // edges[i].startNode >= startNode - 1
					if (edges[i].startNode == startNode - 1) {
						if (edges[i].endNode < endNode - 1)
							continue;
					}
				}
				ei = i;
				break;
			}
			for (int i = ei;i < edgesLength;i++)
				tmp[i] = edges[i];
			for (int i = ei;i < edgesLength;i++)
				edges[i + 1] = tmp[i];
		}
		edges[ei].startNode = startNode - 1;
		edges[ei].endNode = endNode - 1;
	}
	edges[ei].element = w;
}
void deleteEdge(int startNode, int endNode) {
	int ei, flag = 0;
	for (int i = 0;i < edgesLength;i++) { // ������ �����ϴ� ��� ����
		if ((startNode - 1 == edges[i].startNode && endNode - 1 == edges[i].endNode) || (startNode - 1 == edges[i].endNode && endNode - 1 == edges[i].startNode)) {
			flag = 1;
			ei = i;
			break;
		}
	}
	if (flag == 0) { // ������ �������� �ʴ� ��� �ߴ�
		printf("-1\n");
		return;
	}
	for (int i = ei;i < edgesLength;i++)
		edges[i] = edges[i + 1];
	edgesLength--;
}
void updateIncidenceLists(vertex *v, int vi) {
	for (int i = 0;i < edgesLength;i++) {
		if (vi == edges[i].startNode || vi == edges[i].endNode)
			makeIncidenceLists(v, i);
	}
}