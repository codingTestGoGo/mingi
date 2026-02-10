#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_DIST 20000

using namespace std;

int n, m, canDestroy;
int answer = MAX_DIST;
int cityChickenCnt = 0;
int city[51][51];
vector<pair<int, int>> chickenHouses;
vector<pair<int, int>> citizenHouses;
vector<int> picked;

void CalculateChickenDist()
{
	int cityChickenDist = 0;
	vector<pair<int, int>> curChickenHouses;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (city[i][j] == 2)
			{
				
				curChickenHouses.push_back(make_pair(i, j));
			}
		}
	}

	for (auto cityzen : citizenHouses)
	{
		int curChickenDist = MAX_DIST;
		for (auto index : picked)
		{
			int distX = abs(chickenHouses[index].first - cityzen.first);
			int distY = abs(chickenHouses[index].second - cityzen.second);
			curChickenDist = min(curChickenDist, distX + distY);
		}
		cityChickenDist += curChickenDist;
	}

	answer = min(answer, cityChickenDist);
	return;
}

void DFS(int index, int count)
{
	if (count == m)
	{
		CalculateChickenDist();
		return;
	}

	for (int i = index; i < cityChickenCnt; i++)
	{
		picked.push_back(i);
		DFS(i + 1, count + 1);
		picked.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 2)
			{
				cityChickenCnt++;
				chickenHouses.push_back(make_pair(i, j));
			}
			else if (city[i][j] == 1)
			{
				citizenHouses.push_back(make_pair(i, j));
			}
		}
	}

	canDestroy = cityChickenCnt - m;
	//CalculateChickenDist();
	DFS(0, 0);

	cout << answer;
	return 0;

}