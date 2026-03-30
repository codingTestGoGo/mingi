#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define MAX 999999999
using namespace std;

int n, m, x;
vector<pair<int, int>> edgeGraph[1001];
vector<pair<int, int>> revEdgeGraph[1001];

vector<int> Dijkstra(int start, vector<pair<int, int>> graph[])
{
	vector<int> dist(n + 1, MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (pq.empty() == false)
	{
		int curNode =  pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		if (dist[curNode] < curDist) continue;

		for (auto edge : graph[curNode])
		{
			int nextNode = edge.second;
			int nextDist = edge.first;

			if (dist[nextNode] > curDist + nextDist)
			{
				dist[nextNode] = curDist + nextDist;
				pq.push({ dist[nextNode], nextNode});
			}
		}
	}
	return dist;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x;

	for (int i = 1; i <= m; i++)
	{
		int start, end, dist;
		cin >> start >> end >> dist;

		edgeGraph[start].push_back({ dist, end });
		revEdgeGraph[end].push_back({ dist, start });
	}

	vector<int> goX = Dijkstra(x, revEdgeGraph);
	vector<int> backHome = Dijkstra(x, edgeGraph);

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result = max(goX[i] + backHome[i], result);
	}
	cout << result;
	return 0;

}