#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[8][8]; 
int n, m;
vector<pair<int, int>> emptySpace;
vector<pair<int, int>> virusSpace;
int result = 0;

void SpreadVirus()
{
	int sum = 0;
	int temp[8][8];
	//bool visitCheck[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			temp[i][j] = board[i][j];
		}
	}

	queue<pair<int, int>> bfsQueue;
	
	for (int i = 0; i < virusSpace.size(); i++)
	{
		int curX = virusSpace[i].first;
		int curY = virusSpace[i].second;
		bfsQueue.push({ curX, curY });
	}

	while (bfsQueue.empty() == false)
	{
		int curX = bfsQueue.front().first;
		int curY = bfsQueue.front().second;
		bfsQueue.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if ( temp[nx][ny] == 0)
			{
				temp[nx][ny] = 2;
				bfsQueue.push({ nx, ny });
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp[i][j] == 0)
				sum++;
		}
	}

	result = max(result, sum);
	return;

}

void MakeWall(int index, int count)
{
	if (count == 3)
	{
		SpreadVirus();
		return;
	}

	for (int i = index; i < emptySpace.size(); i++)
	{
		int curX = emptySpace[i].first;
		int curY = emptySpace[i].second;
		
		board[curX][curY] = 1;
		MakeWall(i + 1, count + 1);
		board[curX][curY] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
				emptySpace.push_back({ i, j });
			else if (board[i][j] == 2)
				virusSpace.push_back({ i, j });
		}
	}

	MakeWall(0, 0);
	cout << result;
	return 0; 


}