#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFINITY 9999

void dijkstra(int G[101][101], int n, int s);

int main()
{
	int G[101][101] = { 0 }, i = 0;
	int n = 0, m = 0, s = 0;
	int a = 0, b = 0, c = 0;
	scanf("%d %d %d", &n, &m, &s);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		G[a][b] = c;
		G[b][a] = c;
	}

	dijkstra(G, n, s);

	return 0;
}

void dijkstra(int G[101][101], int n, int s)
{
	int result[101][101] = { 0 }, distance[101] = { 0 }, pred[101] = { s };
	int visited[101] = { 0 };//ó������ �湮�� ��� ��������
	int min, nextnode, i, j, k;
	int cnt = 0;
	//distance�� ���� ������ ����ġ�� �����ϴ� ��
	//�ִ� �Ÿ��� ���ϴ� �����̹Ƿ� cost�Լ��� 0�� ����ġ�� ������ �����ʵ��� �ִ��� ���� �־��ش�


	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < n + 1; j++)
		{
			if (G[i][j] == 0)
			{
				result[i][j] = INFINITY;//���Ѵ��� ���� cost�Լ��� �־���
			}
			else
			{
				result[i][j] = G[i][j];
			}
		}
	}

	for (i = 1; i < n + 1; i++)
	{
		distance[i] = result[s][i];//�ڱⰡ ó������ �ٸ� ������ ���� �Ÿ��� ������
	}

	distance[s] = 0;//INFINITY �ο����� ���� �ڱ��ڽ��� ���̹Ƿ� 0���� �ʱ�ȭ
	visited[s] = 1;//������ �湮 ó��
	for (k = 0; k < n; k++)
	{
		min = INFINITY;

		for (i = 1; i < n + 1; i++)
		{
			if (distance[i] < min && !visited[i])//�Ÿ��� ���� ª�� �湮 ���� ���� ����� �ε���
			{
				min = distance[i];
				nextnode = i;//���߿� �ϳ��� ���ؼ� �湮�迭���� �湮�ߴٰ� ó�� ����
			}
		}
		//�ش� ��忡�� ���� �Ÿ��� ����� ����� �ε����� ����

		visited[nextnode] = 1;
		for (i = 1; i < n + 1; i++)
			//�ش� ��忡 �湮���� �ʾ����� 
			if (!visited[i])
				if (min + result[nextnode][i] < distance[i])
				{
					distance[i] = min + result[nextnode][i];
					pred[i] = nextnode;
				}

	}


	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < n + 1; j++)
		{
			if (G[i][j] == 0)
			{
				cnt++;
			}// ȥ�� �������ִ� �ִ� �����Ѵ�
		}
		if (cnt != n)
		{
			if (i != s)
			{
				printf("%d %d\n", i, distance[i]);

			}
		}

		cnt = 0;
	}
}