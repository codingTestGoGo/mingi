#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std; 

int n;
int chessBoard[16];
int answer = 0;

bool isValid(int row)
{
	for (int i = 1; i < row; i++)
	{
		if (chessBoard[i] == chessBoard[row] || abs(chessBoard[i] - chessBoard[row]) == abs(row - i))
		{
			return false;
		}
	}
	return true;
}

void DFS(int row)
{
	if (row == n+1)
	{
		answer++;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		chessBoard[row] = i;
		if (isValid(row) == true)
		{
			DFS(row + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	DFS(1);
	cout << answer;	
	return 0;
	
}