#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int t, m, n; // n: 문서의 개수 , m: 궁금한 문서가 몇번째에 놓여잇는지
queue<pair<int, int>> document;
int documentImportance[10];

void clearDoc()
{
	for (int i = 0; i < 10; i++)
	{
		documentImportance[i] = 0;
	}

	while (!document.empty())
	{
		document.pop();
	}
}

int FindMostImportance()
{
	for(int i = 9; i> 0; i--)
	{
		if (documentImportance[i] > 0)
		{
			return i;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tempInt;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		int printCnt = 0;

		for (int j = 0; j < n; j++)
		{
			cin >> tempInt; 
			documentImportance[tempInt]++;
			document.push(make_pair(tempInt, j));
		}

		while (!document.empty())
		{
			//cout << "루프체크" << endl;
			if (document.front().first == FindMostImportance())
			{
				printCnt++;
				documentImportance[document.front().first]--;

				if (document.front().second == m)
				{
					cout << printCnt << "\n";
					break;
				}

				document.pop();
			}

			else
			{
				document.push(document.front());
				document.pop();
			}
		}

		clearDoc();
	}

	return 0;
}

/*
* * 큐가 순회하는데 m 번째 인덱스는 어떻게 기억할 것인가
*  - pair 형태의 자료를 queue에 넣는다.
* 
* * 큐에서 가장 큰 숫자임을 어떻게 확인할 것인가
*  - 선형탐색으로 순회 .. => n^2
*  - 크기가 10인 int형 배열을 선언해서 1~9의 중요도 문서 갯수를 기록
* 
* * 중요도가 같은 문서에 대해서 어떻게 처리할 것인가
*  - 브루트 포스로 해보기
*/