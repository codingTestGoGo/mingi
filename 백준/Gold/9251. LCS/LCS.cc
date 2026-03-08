#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001]; 
string a, b; // a가로, b 세로

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cin >> a >> b;

	for (int i = 0; i < a.length(); i++)
	{
		for (int j = 0; j < b.length(); j++)
		{
			if (a[i] == b[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else
			{
				dp[i + 1][j + 1] =  max(dp[i][j+1], dp[i+1][j]);
			}
		}
	}

	
	cout << dp[a.length()][b.length()];
	return 0;
}