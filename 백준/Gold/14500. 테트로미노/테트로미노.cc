#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

//tuple<int, int, int> coordAndBlockCnt;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int paperInform[501][501];
bool visitCheck[501][501];
int n, m;

int answer = 0;

//int BFS(int x, int y)
//{
//	int answer = 0; 
//	int startValue = paperInform[x][y];
//	queue<tuple<int, int, int, int>> arrQueue;
//	arrQueue.push(make_tuple(x, y, 1, startValue));
//	visitCheck[x][y] = true;
//
//	while (arrQueue.empty() == false)
//	{
//		int curX = get<0>(arrQueue.front());
//		int curY = get<1>(arrQueue.front());
//		int curSize = get<2>(arrQueue.front());
//		int curValue = get<3>(arrQueue.front());
//
//		arrQueue.pop();
//		if (curSize == 4)
//		{
//			answer = max(answer, curValue);
//		}
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = curX + dx[i];
//			int ny = curY + dy[i];
//			int nSize = curSize + 1;
//			int nValue = curValue + paperInform[nx][ny];
//			bool nVisited = visitCheck[nx][ny];
//
//			if (nx < 0 || ny < 0 || nx >= n || ny >= m || nSize > 4) continue;
//
//			if (nVisited == false)
//			{
//				arrQueue.push(make_tuple(nx, ny, nSize, nValue));
//				visitCheck[nx][ny] = true;
//			}
//		}
//	}
//
//	return answer;
//}

void DFS(int x, int y, int depth, int sum)
{
	if (depth == 4)
	{
		answer = max(sum, answer);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;

		if (visitCheck[nx][ny] == false)
		{
			visitCheck[nx][ny] = true;
			DFS(nx, ny, depth + 1, sum + paperInform[nx][ny]);
			visitCheck[nx][ny] = false;
		}
	}
}

void TCheck(int x, int y)
{
	int wing = 0;
	int minValue = 1001;
	int sum = paperInform[x][y];

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		sum += paperInform[nx][ny];
		minValue = min(minValue, paperInform[nx][ny]);
		wing++;
	}

	if (wing == 4)
	{
		answer = max(answer, sum - minValue); 
	}
	else if (wing == 3)
	{
		answer = max(answer, sum);
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
			paperInform[i][j] = temp;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//memset(visitCheck, false, sizeof(visitCheck));
			//answer = max(BFS(i, j), answer);

			visitCheck[i][j] = true;
			DFS(i, j, 1, paperInform[i][j]);
			visitCheck[i][j] = false;

			TCheck(i, j); 
		}
	}

	cout << answer;

	return 0;
}