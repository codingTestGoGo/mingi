#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;

vector<int> adjInform[501];
bool visitcheck[501];

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

	int answer = 0;
	queue<int> arrQueue;
	arrQueue.push(1);
	visitcheck[1] = true;

	for (int i = 0; i < adjInform[1].size(); i++)
	{
		visitcheck[adjInform[1][i]] = true;
		arrQueue.push(adjInform[1][i]);
		answer++;
	}

	while (arrQueue.empty() == false)
	{
		int cur = arrQueue.front();
		arrQueue.pop();
			
		for (auto nextNode : adjInform[cur])
		{
			if (visitcheck[nextNode] == true)
				continue;
			visitcheck[nextNode] = true;
			answer++;
		}
	}

	cout << answer;

	return 0;
}