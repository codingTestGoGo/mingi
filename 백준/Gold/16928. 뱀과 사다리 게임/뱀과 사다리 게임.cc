#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<int, int> ladderOrSnake;  // 어차피 전부 방문할거면 그냥 한꺼번에 처리
int minDist[101];						// 턴 수를 세는 것보다 모든 노드까지의 최소거리를 재는 것이 효율적

int n, m;

void BFS()
{
	queue<int> posQueue;
	posQueue.push(1);

	minDist[1] = 0;

	while (posQueue.empty() == false)
	{
		int curPos = posQueue.front();
		posQueue.pop();

		if (curPos == 100)
		{
			cout << minDist[100];
			return;
		}

		for (int i = 1; i < 7; i++)
		{
			int next = curPos + i;
			if (next > 100 ) continue;					// 다음 위치가 100을 넘어서면 무시

			if (ladderOrSnake.count(next) != 0 )		// 사다리나 뱀인경우 타고간 도착지를 next로 지정
			{
				next = ladderOrSnake[next];
			}

			if (minDist[next] == -1)					// next가 미방문 노드일경우에만
			{
				posQueue.push(next);
				minDist[next] = minDist[curPos] + 1;	// 현재 노드까지의 거리 + 1을 기록
			}

		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < 101; i++)
	{
		minDist[i] = -1;	// 방문하지 않음
	}

	for (int i = 0; i < n + m; i++)
	{
		int x, y;
		cin >> x >> y;

		ladderOrSnake.insert(make_pair(x, y));
	}
	
	BFS();

	return 0;
}