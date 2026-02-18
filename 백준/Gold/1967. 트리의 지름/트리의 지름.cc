#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define MIN -1

using namespace std;

int n;
vector<pair<int, int>> node[10001];
bool visitCheck[10001];
int maxDist = 0;
int farthestNode = 0;

void DFS(int current, int currentDist)
{
	if (visitCheck[current] == true)
	{
		return;
	}
	visitCheck[current] = true;

	if (maxDist < currentDist)
	{
		maxDist = currentDist;
		farthestNode = current;
	}

	for (auto next : node[current])
	{
		int nextVertext = next.second;
		int weight = next.first;

		if (visitCheck[nextVertext] == false)
		{
			DFS(nextVertext, currentDist + weight);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n; 

	for (int i = 0; i < n-1; i++)
	{
		int cur, next, weight;
		cin >> cur >> next >> weight;

		node[cur].push_back({ weight, next });
		node[next].push_back({ weight, cur });
	}
	
	memset(visitCheck, false, sizeof(visitCheck));
	maxDist = 0;
	DFS(1, 0);

	memset(visitCheck, false, sizeof(visitCheck));
	maxDist = 0;
	DFS(farthestNode, 0);

	cout << maxDist;
	return 0; 

}