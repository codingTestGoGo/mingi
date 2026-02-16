#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 10000

using namespace std;

int n, e, v1, v2;
int edgeInform[801][801];
int shortDist[801];

int GetShortestDist(int start, int end)
{
	int curVertex = start;
	queue<int> vertexQueue;
	fill(shortDist, shortDist + 801, -1);

	shortDist[start] = 0;
	vertexQueue.push(start);


	while (vertexQueue.empty() == false)
	{
		curVertex = vertexQueue.front();
		vertexQueue.pop();

		for (int i = 1; i <= n; i++)
		{
			// i가 자기자신이거나, edge 정보가 없는 경우 생략
			if (edgeInform[curVertex][i] == -1)
			{
				continue;
			}

			// 최단경로가 갱신된적이 없는 경우에는 비교하지 않고 갱신
			else if (shortDist[i] == -1)
			{
				shortDist[i] = shortDist[curVertex] + edgeInform[curVertex][i];
				vertexQueue.push(i);
			}

			// 시작에서 cur까지의 거리 + curVertex 부터 i까지의 거리가 기존의 최단경로보다 작은 경우만 갱신
			else if (shortDist[i] > shortDist[curVertex] + edgeInform[curVertex][i])
			{
				shortDist[i] = shortDist[curVertex] + edgeInform[curVertex][i]; 
				vertexQueue.push(i);
			}
			
		}
	}

	return shortDist[end];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> e;

	fill(edgeInform[0], edgeInform[0] + 801 * 801, -1);

	for (int i = 0; i < e; i++)
	{
		int temp1, temp2, weight;
		cin >> temp1 >> temp2 >> weight;
		edgeInform[temp1][temp2] = weight;
		edgeInform[temp2][temp1] = weight;
	}

	cin >> v1 >> v2;

	int distStartToV1 = GetShortestDist(1, v1);
	int distStartToV2 = GetShortestDist(1, v2);
	int distV1ToV2 = GetShortestDist(v1, v2);
	int distV1ToEnd = GetShortestDist(v1, n);
	int distV2ToEnd = GetShortestDist(v2, n);

	int firstRoute = INF;
	int secondRoute = INF;



	if (distStartToV1 != -1 && distV2ToEnd != -1 && distV1ToV2 != -1)
	{
		firstRoute = distStartToV1 + distV1ToV2 + distV2ToEnd;
	}
	if (distStartToV2 != -1 && distV1ToEnd != -1 && distV1ToV2 != -1)
	{
		secondRoute = distStartToV2 + distV1ToV2 + distV1ToEnd;
	}

	int answer = min(firstRoute, secondRoute);

	if (answer == INF)
	{
		answer = -1;
	}

	cout << answer;
	return 0;
}