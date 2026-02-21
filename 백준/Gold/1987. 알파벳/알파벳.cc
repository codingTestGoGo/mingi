#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace	std;

int r, c;
char board[21][21];
bool visitCheck[21][21];
bool alphabetCheck[26];
int distBoard[21][21];
int result = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void DFS(pair<int, int> node, int depth)
{
	int curX = node.first;
	int curY = node.second;
	char curAlpha = board[curX][curY];
	alphabetCheck[curAlpha - 'A'] = true;
	visitCheck[curX][curY] = true;

	result = max(result, depth);

	for (int i = 0; i < 4; i++)
	{
		int nx = curX + dx[i];
		int ny = curY + dy[i];

		if (nx<1 || nx >r || ny < 1 || ny >c)
		{
			continue;	
		}

		char nextAlpha = board[nx][ny];
		if (visitCheck[nx][ny] == false && alphabetCheck[nextAlpha - 'A'] == false)
		{
			visitCheck[nx][ny] = true;
			alphabetCheck[nextAlpha -'A'] = true;
			DFS({ nx, ny }, depth + 1);
			visitCheck[nx][ny] = false;
			alphabetCheck[nextAlpha - 'A'] = false;
		}
		
	}
	
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	
	//memset(dist, 0, sizeof(dist));
	for (int i = 1; i <= r; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 1; j <= c; j++)
		{
			board[i][j] = temp[j-1];
		}
	}

	DFS({ 1,1 }, 1);
	cout << result;
	return 0;
}
