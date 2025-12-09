#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
vector<int> arrPoweredNum;
int dp[50001] = { 0, };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n;

	int nDpSize = sizeof(dp) / sizeof(dp[0]);

	fill(dp, dp+50001, 5);

	for (int i = 1; ; i++)
	{
		if (i * i > 50000) break;
		else
		{
			arrPoweredNum.push_back(i * i);
			dp[i * i] = 1;
		}
	}

	dp[1] = 1;
	dp[2] = 2; 
	dp[3] = 3;
	dp[4] = 1;

	for (int i = 5; i < nDpSize ; i++)
	{
		if (dp[i] == 1) continue;
		for (int j = 1; j <= i/2 ;j++)
		{
			dp[i] = min(dp[j] + dp[i - j], dp[i]);
		}
	}


	cout << dp[n];

	return 0;
}


/*
* 4개의 자연수의 합으로 나타내야하는데,.. 
*/