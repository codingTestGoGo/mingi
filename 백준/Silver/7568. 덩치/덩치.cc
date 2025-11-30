#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> heightAndWeight;
vector<int> weightRanking;
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tempX, tempY;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tempX >> tempY;
		heightAndWeight.push_back(make_pair(tempX, tempY)); 
	}

	for (int i = 0; i < n; i++)
	{
		int ranking = 1;
		tempX = heightAndWeight[i].first;
		tempY = heightAndWeight[i].second;

		for (int j = 0; j < n; j++)
		{
			if (tempX < heightAndWeight[j].first && tempY < heightAndWeight[j].second)
			{
				ranking++;
			}
		}

		weightRanking.push_back(ranking);
		cout << ranking << " ";
	}

	return 0;

}