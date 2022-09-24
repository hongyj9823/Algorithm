#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999
struct Edge
{
	int start, dest, weight;//방향간선
};
typedef struct Graph
{
	int n;//정점의 갯수
	int m;//간선의 갯수
	struct Edge *edge;
}Graph;
struct Graph *create(int n, int m)// 그래프를 생성하는 함수 
{
	struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->n = n;
	graph->m = m;
	graph->edge = (struct Edge*) malloc(graph->m * sizeof(struct Edge));
	//배열로 만들어서 사용할 것
	return graph;
}
void BellmanFord(struct Graph *graph, int startnode)
{
	int n = graph->n;
	int m = graph->m;
	int u = 0, z = 0, w = 0;
	int resultdistance[101];//여기로의 index는 도착점이며 나중에 출력할 것
	int i = 0, j = 0;

	for (i = 0; i < n + 1; i++)
	{
		resultdistance[i] = INFINITY;//초기화 처음의 값은 이렇게 둔다
	}
	resultdistance[startnode] = 0;// 시작하는 값은 0으로 둔다
	for (i = 1; i <= n - 1; i++)
	{
		for (j = 0; j < m; j++)//그래프의 모든 간선에 대하여
		{
			u = graph->edge[j].start;//나자신(출발점)
			z = graph->edge[j].dest;//반대편(도착점)
			w = graph->edge[j].weight;
			if (resultdistance[u] + w < resultdistance[z])
			{
				resultdistance[z] = resultdistance[u] + w;
			}
		}
	}
	for (i = 0; i <= n; ++i)
	{
		if (resultdistance[i] < 90000) //도달할 수 없는 정점을 제외
		{
			if (i != startnode)
			{
				printf("%d %d\n", i, resultdistance[i]);
			}
		}
	}

}
int main()
{

	int n = 0, m = 0, s = 0, i = 0;
	int a = 0, b = 0, c = 0;
	scanf("%d %d %d", &n, &m, &s);
	Graph * graph = create(n, m);

	for (i = 0; i < m; i++)
	{
		scanf("%d", &graph->edge[i].start);
		scanf("%d", &graph->edge[i].dest);
		scanf("%d", &graph->edge[i].weight);
	}

	BellmanFord(graph, s);

	return 0;
}