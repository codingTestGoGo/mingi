#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dist[100001];
int startPos, endPos;

void BFS(int start, int depth)
{
	deque<pair<int, int>> bfsQueue;
	bfsQueue.push_back(make_pair(start, depth));
	dist[start] = 0;

	while (bfsQueue.empty() == false)
	{
		int curPos = bfsQueue.front().first;
		int curDepth = bfsQueue.front().second;
		bfsQueue.pop_front();

		if (curPos == endPos)
		{
			cout << curDepth;
			return;
		}

		if (curPos * 2 <= 100000 && (dist[curPos * 2] == -1 || dist[curPos * 2] > curDepth))
		{
			dist[curPos * 2] = curDepth;
			bfsQueue.push_front(make_pair(curPos * 2, curDepth));
		}

		if (curPos + 1 <= 100000 &&(dist[curPos + 1] == -1 || dist[curPos + 1] > curDepth + 1))
		{
			dist[curPos + 1] = curDepth + 1;
			bfsQueue.push_back(make_pair(curPos + 1, curDepth + 1));
		}

		if (curPos - 1 >= 0 && (dist[curPos -1] == -1 || dist[curPos - 1] > curDepth + 1))
		{
			dist[curPos - 1] = curDepth -1;
			bfsQueue.push_back(make_pair(curPos - 1, curDepth + 1));
		}

	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> startPos >> endPos;
	fill(dist, dist + 100001, -1);
	BFS(startPos, 0);
	return 0;
}