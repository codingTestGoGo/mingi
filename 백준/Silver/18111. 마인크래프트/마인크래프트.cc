#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m, b;
vector<int> groundInform[501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> b;
	int answerTime = 999999999;
	int answerHeight = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			groundInform[i].push_back(temp);
		}
	}
	
	for (int curHeight = 0; curHeight < 257; curHeight++)
	{
		int blockToStack= 0;
		int blockToPick = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (groundInform[i][j] > curHeight)
				{
					blockToPick += groundInform[i][j] - curHeight;
				}
				else if (groundInform[i][j] < curHeight)
				{
					blockToStack += curHeight - groundInform[i][j];
				}
			}
		}

		if (blockToStack <= blockToPick + b)
		{
			if (2 * blockToPick + blockToStack <= answerTime)
			{
				answerTime = 2 * blockToPick + blockToStack;
				answerHeight = curHeight;
			}
		}
	}

	cout << answerTime << " " << answerHeight;

	return 0;
}

/*
*
* 블럭 제거 인벤++ -> 2초
* 블럭 설치 인벤-- => 1초
*
* 답이 여러개면 땅이 높은걸로
*
* 우선순위
*	- 설치 > 제거
*   -
* 
* 입력에 나와있는 높이 뿐만이 아니라 가능한 모든 높이를 비교할 것
*/