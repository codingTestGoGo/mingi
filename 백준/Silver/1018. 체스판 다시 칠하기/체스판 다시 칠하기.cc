#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int minFixCnt = 65;
vector<vector<char>> chessBoard;
void CalculateSquareToFix(int curX, int curY, bool isWhiteBoard)
{
	int haveToFixCnt = 0;
	bool isWhite = isWhiteBoard;

	if ( (curX + 7 )>= n || (curY + 7) >= m)
	{
		return;
	}

	for (int i = curX; i < curX + 8; i++)
	{
		for (int j = curY; j < curY + 8; j++)
		{
			if (isWhite == true && chessBoard[i][j] == 'B')
			{
				isWhite = false;
				haveToFixCnt++;
				continue;
			}

			else if (isWhite == false && chessBoard[i][j] == 'W')
			{
				isWhite = true;
				haveToFixCnt++;
				continue;
			}

			isWhite = !isWhite;
		}
		isWhite = !isWhite;
	}

	minFixCnt = min(minFixCnt, haveToFixCnt); 

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >>m;

	string tempStr;

	chessBoard.resize(n);
	for (int i = 0; i < n; i++)
	{
		chessBoard[i].resize(m);
		cin >> tempStr;

		for (int j = 0; j < m; j++)
		{
			chessBoard[i][j] = tempStr[j];
		}
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << chessBoard[i][j];
	//	}
	//	cout << "\n";
	//}


	for (int i = 0; i < n; i++)
	{	
		for (int j = 0; j < m; j++)
		{
			CalculateSquareToFix(i, j, true);
			CalculateSquareToFix(i, j, false);
		}
	}

	cout << minFixCnt;

	return 0;
}
