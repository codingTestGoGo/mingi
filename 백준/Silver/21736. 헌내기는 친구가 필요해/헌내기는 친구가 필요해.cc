#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std; 

int n, m;
vector<vector<char>> campusInfo;
vector<vector<bool>> visitCheck;
queue<pair<int, int>> bfsQueue;
pair<int, int> startPos;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS()
{
	int nPersonCnt = 0; 
	bfsQueue.push(startPos);

	while (!bfsQueue.empty())
	{
		int curX = bfsQueue.front().first;
		int curY = bfsQueue.front().second;
		bfsQueue.pop();

		if (campusInfo[curX][curY] == 'P') nPersonCnt++;

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			else if (visitCheck[nx][ny] == false && campusInfo[nx][ny] != 'X')
			{
				bfsQueue.push(make_pair(nx, ny));
				visitCheck[nx][ny] = true;
			}

		}
	}

	if (nPersonCnt == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << nPersonCnt;
	}

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string tempString;

	cin >> n >> m;

	campusInfo.resize(n);
	visitCheck.resize(n);

	for (int i = 0; i < n; i++)
	{

		cin >> tempString;
		for (int j = 0; j < m; j++)
		{

			if (tempString[j] == 'I')
			{
				startPos.first = i;
				startPos.second = j;
			}

			campusInfo[i].push_back(tempString[j]);
			visitCheck[i].push_back(false);

			//campusInfo[i][j] = tempChar;
			//visitCheck[i][j] = false;
		}
	}

	BFS();
	return 0;

}