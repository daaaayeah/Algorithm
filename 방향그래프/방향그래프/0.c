//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//// 1 위상순서 찾기 -> 인접리스트 구조(배열)
//typedef struct incidence {
//	int ei;
//	struct incidence *next;
//}incidence;
//typedef struct vertex {
//	char name;
//	int inDegree; // 진입차수 inDegree
//	incidence inEdges, outEdges;
//}vertex;
//typedef struct edge {
//	char origin, destination;
//}edge;
//typedef struct Queue {
//	int front, rear;
//	int arr[100];
//}Queue;
//
//int n, m, flag; // 정점의 수 n, 간선의 수 m
//vertex vertices[100];
//edge edges[1000];
//vertex topOrder[101];
//
//void printIncidence(incidence *inci);
//void buildGraph();
//void insertVertex(char vName, int vi);
//void insertDirectedEdge(char uName, char wName, int i);
//void addIncidence(incidence *inci, int i);
//void topologicalSort();
//Queue *createQueue();
//int isEmpty(Queue *Q);
//void enqueue(Queue *Q, vertex *v);
//vertex dequeue(Queue *Q);
//void printQ(Queue *Q);
//
//int main() {
//	buildGraph();
//	for (int i = 0;i < n;i++) {
//		printf("정점 이름 : %c\n", vertices[i].name);
//		printf("진입 차수 : %d\n", vertices[i].inDegree);
//		printf("inEdges\n");
//		printIncidence(vertices[i].inEdges.next);
//		printf("\noutEdges\n");
//		printIncidence(vertices[i].outEdges.next);
//		printf("\n");
//	}
//	for (int i = 0;i < m;i++)
//		printf(" %c%c(%d)", edges[i].origin, edges[i].destination, i);
//	printf("\n");
//
//	topologicalSort();
//	
//	if (flag == 0)
//		printf("0\n");
//	else {
//		for (int i = 0;i < n + 1;i++)
//			printf("%c\n", topOrder[i].name);
//	}
//	return 0;
//}
//
//void printIncidence(incidence *inci) {
//	if (inci == NULL) return;
//	printf(" %d", inci->ei);
//	printIncidence(inci->next);
//}
//void buildGraph() { //
//	char vName, uName, wName;
//
//	// 정점리스트 vertices 생성
//	scanf("%d", &n);
//	getchar();
//	for (int i = 0;i < n;i++) {
//		scanf("%c", &vName);
//		getchar();
//		insertVertex(vName, i);
//	}
//	// 간선리스트 edges 생성
//	scanf("%d", &m);
//	getchar();
//	for (int i = 0;i < m;i++) {
//		scanf("%c %c", &uName, &wName);
//		getchar();
//		insertDirectedEdge(uName, wName, i);
//	}
//
//	return;
//}
//void insertVertex(char vName, int vi) { //
//	vertices[vi].name = vName;
//	vertices[vi].inDegree = 0;
//	vertices[vi].inEdges.next = NULL;
//	vertices[vi].outEdges.next = NULL;
//}
//void insertDirectedEdge(char uName, char wName, int ei) { //
//	int u, w;
//
//	for (int i = 0;i < n;i++) {
//		if (vertices[i].name == uName) {
//			edges[ei].origin = vertices[i].name;
//			u = i;
//		}
//		else if (vertices[i].name == wName) {
//			edges[ei].destination = vertices[i].name;
//			w = i;
//		}
//	}
//
//	addIncidence(&(vertices[u].outEdges), ei);
//	addIncidence(&(vertices[w].inEdges), ei);
//	vertices[w].inDegree++;
//
//	return;
//}
//void addIncidence(incidence *inci, int i) { //
//	incidence *new;
//	new = (incidence *)malloc(sizeof(incidence));
//	new->ei = i;
//	new->next = NULL;
//
//	if (inci->next != NULL)
//		new->next = inci->next;
//	inci->next = new;
//}
//void topologicalSort() {
//	Queue *Q = createQueue();
//	vertex deleted, *w = NULL;
//	int t = 1, ei;
//
//	for (int i = 0;i < n;i++) {
//		if (vertices[i].inDegree == 0) {
//			printf("zero inDegree : %c\n", vertices[i].name);
//			enqueue(Q, vertices + i);
//		}
//	}
//	printQ(Q);
//	printf("\n");
//	while (isEmpty(Q) == 0) {
//		deleted = dequeue(Q);
//		printf("deleted : %c\n", deleted.name);
//		topOrder[t] = deleted;
//		printf("topOrder[%d] = %c\n", t, topOrder[t].name);
//		t++;
//
//		while (deleted.outEdges.next != NULL) {
//			ei = deleted.outEdges.next->ei;
//			//printf("ei : %d\n", ei);
//			for (int i = 0;i < n;i++) {
//				if (vertices[i].name == edges[ei].destination) {
//					w = vertices + i;
//					break;
//				}
//			}
//			w->inDegree--;
//			if (w->inDegree == 0)
//				enqueue(Q, w);
//			deleted.outEdges.next = deleted.outEdges.next->next;
//		}
//	}
//	if (t <= n)
//		flag = 0;
//	else
//		flag = 1;
//	
//}
//Queue *createQueue() {
//	Queue *Q;
//	Q = (Queue *)malloc(sizeof(Queue));
//	Q->front = -1;
//	Q->rear = -1;
//	return Q;
//}
//int isEmpty(Queue *Q) {
//	if (Q->front == Q->rear) return 1;
//	else return 0;
//}
//void enqueue(Queue *Q, vertex *v) {
//	int vi;
//	for (int i = 0;i < n;i++) {
//		if (vertices[i].name == v->name) {
//			vi = i;
//			break;
//		}
//	}
//	Q->rear++;
//	Q->arr[Q->rear] = vi;
//}
//vertex dequeue(Queue *Q) {
//	vertex v;
//	Q->front++;
//	v = vertices[Q->arr[Q->front]];
//	return v;
//}
//void printQ(Queue *Q) {
//	for (int i = Q->front + 1;i <= Q->rear;i++)
//		printf(" %d", Q->arr[i]);
//}