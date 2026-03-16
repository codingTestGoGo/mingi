#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 210000000

using namespace std;

int n, m;
int dist[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int start, end, cost;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = MAX;
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> cost;
		dist[start][end] = min ( dist[start][end],cost);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(dist[i][j] == MAX)
				cout << 0 << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}