#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int arr[16][16];
int vertical[16][16];
int horizontal[16][16];
int diagnal[16][16];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			horizontal[i][j] = 0;
			vertical[i][j] = 0;
			diagnal[i][j] = 0;
		}
	}
		
	horizontal[0][1] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 2; j < n; j++)
		{
			// 도달점에 벽이 세워져있으면 계산안함
			if (arr[i][j] == 1)
			{
				continue;
			}

			// 첫째 행일때
			if (i == 0)
			{
				horizontal[i][j] = horizontal[i][j - 1];
				continue;
			}

			// 세로벽에 도달하는데, 첫째 행이 아닐때
			else if (j == n - 1)
			{
				if (arr[i - 1][j] != 1 && arr[i][j - 1] != 1)
				{
					diagnal[i][j] = diagnal[i - 1][j - 1] + horizontal[i - 1][j - 1] + vertical[i - 1][j - 1];
				}
				vertical[i][j] = diagnal[i - 1][j] + vertical[i - 1][j];
				horizontal[i][j] = diagnal[i][j - 1] + horizontal[i][j - 1];
				continue;
			}

			// 마지막행에 도달하는경우, (마지막 열은 아닌경우)
			else if ( i == n-1)
			{
				if (arr[i - 1][j] != 1 && arr[i][j - 1] != 1)
				{
					diagnal[i][j] = diagnal[i - 1][j - 1] + horizontal[i - 1][j - 1] + vertical[i - 1][j - 1];
				}
				vertical[i][j] = diagnal[i - 1][j] + vertical[i - 1][j];
				horizontal[i][j] = diagnal[i][j - 1] + horizontal[i][j - 1];
				continue;
			}

			// 파이프 도달점이 벽이 아닌 경우 
			else
			{
				if (arr[i - 1][j] != 1 && arr[i][j - 1] != 1)
				{
					diagnal[i][j] = diagnal[i - 1][j - 1] + horizontal[i - 1][j - 1] + vertical[i - 1][j - 1];
				}
				vertical[i][j] = diagnal[i - 1][j] + vertical[i - 1][j];
				horizontal[i][j] = diagnal[i][j - 1] + horizontal[i][j - 1];
				continue;
			}
		}
	}

	int answer = diagnal[n - 1][n - 1] + horizontal[n - 1][n - 1] + vertical[n - 1][n - 1]; 
	cout << answer;

	return 0;

}