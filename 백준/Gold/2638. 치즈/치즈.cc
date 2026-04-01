#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int cheeseBoard[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS()
{
	int visitCheck[101][101] = { 0, };
	queue<pair<int, int>> bfsQueue;

	bfsQueue.push({ 1,1 });

	while (bfsQueue.empty() == false)
	{
		int curX = bfsQueue.front().first;
		int curY = bfsQueue.front().second;
		bfsQueue.pop(); 

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;

			// 0 이고, 방문안한경우
			if (cheeseBoard[nx][ny] == 0 && visitCheck[nx][ny] == 0)
			{
				visitCheck[nx][ny] = 1;
				bfsQueue.push({ nx, ny });
			}
			// 1인 경우 ++ 해줌
			else if (cheeseBoard[nx][ny] == 1)
			{
				visitCheck[nx][ny]++;
			}
		}
	}
	
	// 2번 이상 방문된 치즈의 경우 모두 녹여버리기
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (visitCheck[i][j] >= 2)
			{
				cheeseBoard[i][j] = 0;
			}
		}
	}
}

bool CheckCheeseRemain()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (cheeseBoard[i][j] == 1)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> cheeseBoard[i][j];
		}
	}

	int timer = 0;

	while (1)
	{
		BFS();		// 치즈깎이
		timer++;
		if (CheckCheeseRemain() == false)
			break;
	}

	cout << timer;
	return 0;
}

/*
* 0 인 부분을 bfs로 탐색해서 값이1일때 두번 이상방문하는것만 제거하면된다.
* 이러면 밀폐된 부분을 접근할필요도 없고 같은 방향에서 두번이상접근하지도 못한다.
*/