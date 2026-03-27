#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 16

using namespace std;

int n, m, r;		// 지역, 수색범위, 길개수
int itemValue[101]; 
int dist[101][101];
int maxResult = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> r;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> itemValue[i];

		for (int j = 1; j <= n; j++)
		{
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = MAX;
		}
	}

	// 노드 값입력
	for (int i = 1; i <= r; i++)
	{
		int start, dest, tempDist;
		cin >> start >> dest >> tempDist;
		dist[start][dest] = tempDist;
		dist[dest][start] = tempDist; 
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
		int temp = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] <= m)
			{
				temp += itemValue[j];
			}
		}
		maxResult = max(maxResult, temp);
	}

	cout << maxResult;
	return 0;
}