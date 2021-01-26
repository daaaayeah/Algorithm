//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct vertex {
//	int data;
//	struct vertex *next;
//}vertex;
//
//typedef struct Edge {
//	int a, b;
//}Edge;
//
//vertex *vertices;
//Edge *edge;
//int N = 0, n, m;
//int *visit;
//
//void makeWay(int x, int y);
//vertex *newNode();
//void DFS(int s);
//void rDFS(vertex p);
//void print(int m);
//
//void main() {
//	int s, i, x, y;
//
//	scanf("%d%d%d", &n, &m, &s);
//
//	vertices = (vertex *)malloc(sizeof(vertex)*n);
//	edge = (Edge *)malloc(sizeof(Edge)*m);
//
//	for (i = 0; i < n; i++) {
//		vertices[i].data = i + 1;
//		vertices[i].next = NULL;
//	}
//
//	for (i = 0; i < m; i++) {
//		scanf("%d%d", &x, &y);
//		makeWay(x, y);
//	}
//
//	DFS(s);
//}
//
//vertex *newNode() {
//	vertex *p;
//
//	p = (vertex *)malloc(sizeof(vertex));
//	p->data = '\n';
//	p->next = NULL;
//
//	return p;
//}
//
//void makeWay(int x, int y) {
//	vertex *p, *q = NULL, *New;
//	int tmp;
//
//	if (x > y) {
//		tmp = x;
//		x = y;
//		y = tmp;
//	}
//
//	edge[N].a = x;
//	edge[N].b = y;
//
//	p = &vertices[x - 1];
//	while (p->next != NULL) {
//		if (edge[p->next->data].a == x) {
//			if (edge[p->next->data].b < y)
//				p = p->next;
//			else if (edge[p->next->data].b > y) {
//				q = p->next;
//				break;
//			}
//		}
//		else if (edge[p->next->data].b == x) {
//			if (edge[p->next->data].a < y)
//				p = p->next;
//			else if (edge[p->next->data].a > y) {
//				q = p->next;
//				break;
//			}
//		}
//	}
//	New = newNode();
//	p->next = New;
//	New->data = N;
//	New->next = q;
//
//	q = NULL;
//	p = &vertices[y - 1];
//	while (p->next != NULL) {
//		if (edge[p->next->data].a == y) {
//			if (edge[p->next->data].b < x)
//				p = p->next;
//			else if (edge[p->next->data].b > x) {
//				q = p->next;
//				break;
//			}
//		}
//		else if (edge[p->next->data].b == y) {
//			if (edge[p->next->data].a < x)
//				p = p->next;
//			else if (edge[p->next->data].a > x) {
//				q = p->next;
//				break;
//			}
//		}
//	}
//	New = newNode();
//	p->next = New;
//	New->data = N;
//	New->next = q;
//
//	N++;
//}
//
//void DFS(int s) {
//	int i;
//	vertex p;
//
//	visit = (int *)malloc(sizeof(int)*n);
//	for (i = 0; i < n; i++)
//		visit[i] = 0;
//
//	p = vertices[s - 1];
//	rDFS(p);
//}
//
//void rDFS(vertex p) {
//	int e, now;
//	vertex *q;
//
//
//	now = p.data;
//	if (visit[now - 1] == 0) {
//		printf("%d\n", now);
//		visit[now - 1] = 1;
//	}
//	else
//		return;
//
//	q = &p;
//	while (q->next != NULL) {
//		q = q->next;
//		e = q->data;
//		if (edge[e].a == now)
//			rDFS(vertices[edge[e].b - 1]);
//		else if (edge[e].b == now)
//			rDFS(vertices[edge[e].a - 1]);
//	}
//}