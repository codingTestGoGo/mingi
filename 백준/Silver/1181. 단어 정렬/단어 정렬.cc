#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<string, int>> arr;

bool Compare(const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
		return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	string temp;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(make_pair(temp, temp.length()));
	}

	sort(arr.begin(), arr.end(), Compare);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].first << endl;
	}

	return 0;
}