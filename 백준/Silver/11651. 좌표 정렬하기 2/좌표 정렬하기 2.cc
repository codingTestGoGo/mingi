#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> arr;

bool Compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr.push_back(make_pair(a, b)); 
	}

	sort(arr.begin(), arr.end(), Compare);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i].first << " " << arr[i].second << "\n";
	}

	return 0;
}