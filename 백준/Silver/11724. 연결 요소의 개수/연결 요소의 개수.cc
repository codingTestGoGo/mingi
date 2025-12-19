#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> adjInform[1001];
bool visitCheck[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n >> m;

	int nComponentNum = 0;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adjInform[u].push_back(v);
		adjInform[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		if (visitCheck[i] == true) continue;

		visitCheck[i] = true;
		nComponentNum++; 
		queue<int> qComponentQueue;
		qComponentQueue.push(i);

		while (qComponentQueue.empty() == false)
		{
			int cur = qComponentQueue.front();
			qComponentQueue.pop();

			for (auto nextNode : adjInform[cur])
			{
				if (visitCheck[nextNode] == true) continue;

				else
				{
					qComponentQueue.push(nextNode);
					visitCheck[nextNode] = true;
				}
			}
		}
	}

	cout << nComponentNum;
	return 0;
}