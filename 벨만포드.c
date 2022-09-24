#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999
struct Edge
{
	int start, dest, weight;//���Ⱓ��
};
typedef struct Graph
{
	int n;//������ ����
	int m;//������ ����
	struct Edge *edge;
}Graph;
struct Graph *create(int n, int m)// �׷����� �����ϴ� �Լ� 
{
	struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->n = n;
	graph->m = m;
	graph->edge = (struct Edge*) malloc(graph->m * sizeof(struct Edge));
	//�迭�� ���� ����� ��
	return graph;
}
void BellmanFord(struct Graph *graph, int startnode)
{
	int n = graph->n;
	int m = graph->m;
	int u = 0, z = 0, w = 0;
	int resultdistance[101];//������� index�� �������̸� ���߿� ����� ��
	int i = 0, j = 0;

	for (i = 0; i < n + 1; i++)
	{
		resultdistance[i] = INFINITY;//�ʱ�ȭ ó���� ���� �̷��� �д�
	}
	resultdistance[startnode] = 0;// �����ϴ� ���� 0���� �д�
	for (i = 1; i <= n - 1; i++)
	{
		for (j = 0; j < m; j++)//�׷����� ��� ������ ���Ͽ�
		{
			u = graph->edge[j].start;//���ڽ�(�����)
			z = graph->edge[j].dest;//�ݴ���(������)
			w = graph->edge[j].weight;
			if (resultdistance[u] + w < resultdistance[z])
			{
				resultdistance[z] = resultdistance[u] + w;
			}
		}
	}
	for (i = 0; i <= n; ++i)
	{
		if (resultdistance[i] < 90000) //������ �� ���� ������ ����
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