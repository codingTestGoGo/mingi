#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int dp[5001] = { -1, };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	memset(dp, -1, 5001);

	dp[3] = 1;
	dp[5] = 1;
	dp[6] = 2;

	for (int i = 7; i <= n; i++)
	{
		if (dp[i - 3] == -1 && dp[i - 5] == -1)
		{
			continue;
		}

		else if (dp[i - 3] == -1)
		{
			dp[i] = dp[i - 5] + 1;
		}

		else if (dp[i - 5] == -1)
		{
			dp[i] = dp[i - 3] + 1;
		}

		else
		{
			dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
		}
	}
	
	cout << dp[n];

	return 0;
}

