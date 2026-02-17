#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 999999999

using namespace std;

int v, e, start;
vector<pair<int,int>> edgeInform[20001];
int shortDist[20001];

void GetShortDist()
{
	priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> vertexQueue;
	fill(shortDist, shortDist + 20001, INF);

	shortDist[start] = 0;
	vertexQueue.push({ 0, start });

	while (vertexQueue.empty() == false)
	{
		int curVertex = vertexQueue.top().second;
		int curCost = vertexQueue.top().first;
		vertexQueue.pop();

		// 우선순위큐에서 뽑은 현재 노드까지의 거리보다 이미 기록된 거리가 작다는건 이미 더 짧은 거리로 방문했다는 것이므로 생략
		if (curCost > shortDist[curVertex])
		{
			continue;
		}

		for (auto next : edgeInform[curVertex])
		{
			int nextVertex = next.second;
			int nextCost = next.first;

			// 간선이 없거나 자기자신인 경우
			if (nextCost == INF)
			{
				continue;
			}

			//// 초기 거리 갱신이경우 바로 갱신
			//else if (shortDist[i] == -1)
			//{
			//	shortDist[i] = shortDist[curVertex] + edgeInform[curVertex][i];
			//	vertexQueue.push(i);
			//	continue;
			//}

			// 기존보다 현재 버택스를 통해 가는게 최단이경우 갱신
			else if (shortDist[nextVertex] > shortDist[curVertex] + nextCost)
			{
				shortDist[nextVertex] = shortDist[curVertex] + nextCost;
				vertexQueue.push(make_pair(shortDist[nextVertex], nextVertex));
				continue;
			}
		}
	}


	for (int i = 1; i <= v; i++)
	{
		if (shortDist[i] == INF)
		{
			cout << "INF\n";
		}
		else
		{
			cout << shortDist[i] << "\n";
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	cin >> v >> e;
	cin >> start;

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edgeInform[u].push_back(make_pair(w, v));
	}

	GetShortDist();

	return 0;
}