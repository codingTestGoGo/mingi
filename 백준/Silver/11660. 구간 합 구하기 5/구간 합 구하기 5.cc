#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int num[1025][1025];
int dp[1025][1025];

int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp;
			cin >> temp;
			num[i][j] = temp;
			dp[i][j] = temp;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i > 0 && j > 0)
			{
				dp[i][j] += (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]);
			}
			else if (i == 0 && j > 0)
			{
				dp[i][j] += dp[i][j - 1];
			}
			else if (i > 0 && j == 0)
			{
				dp[i][j] += dp[i - 1][j];
			}
			else continue;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2; 

		cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << "\n";
	}


	return 0;
}