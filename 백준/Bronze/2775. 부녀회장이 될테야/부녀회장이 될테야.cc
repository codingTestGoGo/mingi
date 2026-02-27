#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int apart[15][15];

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	int t, n, k;

	cin >> t;
	for (int i = 0; i < 15; i++)
	{
		apart[0][i] = i;
	}

	for (int i = 1; i < 15; i++)
	{	
		for (int j = 1; j < 15; j++)
		{
			apart[i][j] = apart[i - 1][j] + apart[i][j - 1];
		}
	}

	for (int i = 0; i < t; i++)
	{
		cin >> k >> n;
		cout << apart[k][n]<<"\n";
	}

	return 0;
}