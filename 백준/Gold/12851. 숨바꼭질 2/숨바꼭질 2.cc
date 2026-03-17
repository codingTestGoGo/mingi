#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 100001
using namespace std;

int n, k;
queue<pair<int, int>> distAndPos;
//priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> distAndPos; 
int visitCheck[100001];
int shortestDist = MAX;
int pathNum = 0;

void BFS(int start)
{
	distAndPos.push({ 0, start });

	while (distAndPos.empty() == false)
	{
		int curDist = distAndPos.front().first;
		int curPos = distAndPos.front().second;
		

		distAndPos.pop();

		if (curDist > shortestDist) continue;
		
		// 경로가 현재 최소거리보다 작거나 같고, 목표 지점에 도달했을때만, 경로 추가 및 최단거리갱신
		if (curPos == k)
		{
			pathNum++;
			shortestDist = curDist;
			continue;
		}

		int nexPos[3] = { curPos - 1, curPos + 1, curPos * 2 };

		for (int i = 0; i < 3; i++)
		{
			int next = nexPos[i];
			if (next >= 0 && next <= 100000)
			{
				if (visitCheck[next] >= curDist + 1)
				{
					visitCheck[next] = curDist + 1;
					distAndPos.push({ curDist + 1, next });
				}
			}
		}

		//if (curPos > 0) distAndPos.push({ curDist + 1, curPos - 1 });
		//if (curPos < 100000) distAndPos.push({ curDist + 1, curPos + 1 });
		//if (curPos * 2 <= 100000) distAndPos.push({ curDist + 1, curPos * 2 });
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	fill(visitCheck, visitCheck + 100001, MAX); 

	BFS(n);

	cout << shortestDist << "\n";
	cout << pathNum << "\n";

	return 0;
	
}