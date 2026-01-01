#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int goalX, goalY;

vector<int> placeInform[1001];
bool visitCheck[1001][1001];
int answer[1001][1001];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int startX, int startY)
{
	int movedDistance = 1;
	int addedNodesInThisTurn = 0;
	int lastNodesInThisTurn = 0;
	queue<pair<int, int>> bfsQueue;
	bfsQueue.push(make_pair(startX, startY)); 
	visitCheck[startX][startY] = true;
	answer[startX][startY] = 0;
	lastNodesInThisTurn++;

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

			else if (placeInform[nx][ny] != 0 && visitCheck[nx][ny] == false)
			{
				bfsQueue.push(make_pair(nx, ny));
				visitCheck[nx][ny] = true;
				answer[nx][ny] = movedDistance;
				addedNodesInThisTurn++;
			}
		}

		lastNodesInThisTurn--;

		if (lastNodesInThisTurn == 0)
		{
			lastNodesInThisTurn = addedNodesInThisTurn;
			addedNodesInThisTurn = 0;
			movedDistance++;
		}
	}

	return;
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
			int temp;
			cin >> temp;

			placeInform[i].push_back(temp);

			if (temp == 2)
			{
				goalX = i; 
				goalY = j;
			}

			if (temp != 0)
			{
				answer[i][j] = -1;
			}
		}
	}

	BFS(goalX, goalY);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}


/*
* 도착지점부터 bfs를 계산해서 거리를 재면 1번만 순회해도 됀다.
* 배열의 초기값을 -1로초기화
*/