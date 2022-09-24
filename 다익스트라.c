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
	int visited[101] = { 0 };//처음에는 방문을 모두 하지않음
	int min, nextnode, i, j, k;
	int cnt = 0;
	//distance는 최종 더해진 가중치를 저장하는 것
	//최단 거리를 구하는 문제이므로 cost함수에 0인 가중치는 포함이 되지않도록 최대의 값을 넣어준다


	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < n + 1; j++)
		{
			if (G[i][j] == 0)
			{
				result[i][j] = INFINITY;//무한대의 값을 cost함수에 넣어줌
			}
			else
			{
				result[i][j] = G[i][j];
			}
		}
	}

	for (i = 1; i < n + 1; i++)
	{
		distance[i] = result[s][i];//자기가 처음으로 다른 곳으로 가는 거리를 더해줌
	}

	distance[s] = 0;//INFINITY 부여받은 값은 자기자신의 값이므로 0으로 초기화
	visited[s] = 1;//시작점 방문 처리
	for (k = 0; k < n; k++)
	{
		min = INFINITY;

		for (i = 1; i < n + 1; i++)
		{
			if (distance[i] < min && !visited[i])//거리가 제일 짧고 방문 하지 않은 노드의 인덱스
			{
				min = distance[i];
				nextnode = i;//나중에 하나를 정해서 방문배열에서 방문했다고 처리 예정
			}
		}
		//해당 노드에서 가장 거리가 가까운 노드의 인덱스를 담음

		visited[nextnode] = 1;
		for (i = 1; i < n + 1; i++)
			//해당 노드에 방문하지 않았으면 
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
			}// 혼자 떨어져있는 애는 제외한다
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