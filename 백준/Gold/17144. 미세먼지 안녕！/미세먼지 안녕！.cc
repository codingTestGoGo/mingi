#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int r, c, t;	// 행, 열, 시간
int room[51][51];
int dx[4] = { 1, 0, -1, 0 }; 
int dy[4] = { 0, 1, 0, -1 };
int airTop = 0;
int airBottom = 0;

void ConditioningAir()
{
	// 좌변
	for (int i = airTop; i > 1 ; i--)
	{
		room[i][1] = room[i - 1][1];
	}

	for (int i = 1; i < c; i++)
	{
		room[1][i] = room[1][i + 1];
	}

	for (int i = 1; i < airTop; i++)
	{
		room[i][c] = room[i + 1][c];
	}

	for (int i = c; i > 1 ; i--)
	{
		room[airTop][i] = room[airTop][i - 1];
	}

	room[airTop][2] = 0;
	room[airTop][1] = -1; 

	for (int i = airBottom; i < r; i++)
	{
		room[i][1] = room[i + 1][1];
	}
	for (int i = 1; i < c; i++)
	{
		room[r][i] = room[r][i + 1];
	}
	for (int i = r; i > airBottom; i--)
	{
		room[i][c] = room[i - 1][c]; 
	}
	for (int i = c; i > 1; i--)
	{
		room[airBottom][i] = room[airBottom][i - 1];
	}
	room[airBottom][2] = 0;
	room[airBottom][1] = -1;
}

void DustDiffusion()
{
	int tempRoom[51][51] = { 0, };

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{

			if (room[i][j] >= 5)
			{
				for (int k = 0; k < 4; k++)
				{
					int diffusionValue = room[i][j] / 5;
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 1 || ny < 1 || nx >r || ny >c || room[nx][ny] == -1) continue;

					tempRoom[nx][ny] += diffusionValue;
					tempRoom[i][j] -= diffusionValue;

				}
			}
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (room[i][j] == -1) continue;
			room[i][j] += tempRoom[i][j];
			if (room[i][j] < 0)
				room[i][j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> t;
	int answer = 0;
	
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> room[i][j];

			if (room[i][j] == -1 && airTop == 0)
			{
				airTop = i;
				airBottom = i + 1;
			}
		}
	}
	
	for (int i = 0; i < t; i++)
	{
		DustDiffusion();
		ConditioningAir();
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			answer += room[i][j];
		}
	}

	cout << answer + 2;
	return 0;

}