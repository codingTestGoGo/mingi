#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adjInform[101];
int baconForEachNode[101];
bool visitCheck[101];
int answer = 9999999;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v; 
		cin >> u >> v; 
		adjInform[u].push_back(v);
		adjInform[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		queue<int> q;
		int curBaconNodes = 1;
		int nextBaconNodes = 0;
		int baconLevel = 1;
		
		q.push(i);
		visitCheck[i] = true;

		while (q.empty() == false)
		{
			if (curBaconNodes == 0)
			{
				baconLevel++;
				curBaconNodes = nextBaconNodes;
				nextBaconNodes = 0;
			}

			int cur = q.front();
			q.pop();
			curBaconNodes--;

			for (auto nextNode : adjInform[cur])
			{
				if (visitCheck[nextNode] == true)
				{
					continue;
				}
				visitCheck[nextNode] = true;
				baconForEachNode[i] += baconLevel;
				q.push(nextNode);
				nextBaconNodes++;
			}
		}
		fill(visitCheck, visitCheck + 101, false);
	}

	for (int i = 1; i <= n; i++)
	{
		answer = min(answer, baconForEachNode[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (answer == baconForEachNode[i])
		{
			cout << i;
			break; 
		}
	}

	return 0;
}