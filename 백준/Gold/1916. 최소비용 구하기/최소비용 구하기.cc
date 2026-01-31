#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_VALUE 100000001
using namespace std;

vector<pair<int, int>> nodes[1001];
priority_queue<pair<int, int>> pq;
int dist[1001];
int n, m;
int startNode, endNode;

void Dijkstra()
{
	dist[startNode] = 0;
	pq.push(make_pair(0, startNode));
	while (pq.empty() == false)
	{
		int curNode = pq.top().second;		// 현재 머물러 있는 노드
		int curCost = pq.top().first;		// 현재 간선까지의 비용
		pq.pop();

		if (curCost > dist[curNode]) continue;

		for (auto node : nodes[curNode])	// 현재 노드와 연결되어 있는 노드 순회
		{
			int nextNode = node.second;		// 다음에 방문할 노드
			int nextCost = node.first;		// 현재 노드부터 다음 노드까지의 비용
			if (dist[curNode] + nextCost < dist[nextNode])	// 기존의 비용보다 현재노드까지의 비용 + 다음 노드까지의 비용이 작으면 
			{
				dist[nextNode] = dist[curNode] + nextCost;		// 다음 노드까지의 비용 갱신
				pq.push(node);								// 해당 노드를 우선순위 큐에 추가
			}
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n >> m;

	fill(dist, dist + 1001, MAX_VALUE);

	for (int i = 0; i < m; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		nodes[x].push_back({cost, y});
	}

	cin >> startNode >> endNode;

	Dijkstra();
	cout << dist[endNode];

	return 0;
}