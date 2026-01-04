#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n; 
vector<pair<int, int>> arr;

bool Compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		arr.push_back(make_pair(a, b)); 
	}

	sort(arr.begin(), arr.end(), Compare);

	int answer = 1;
	int meetingEndTime = arr[0].second;
	for (int i = 1; i < n; i++)
	{
		if (arr[i].first >= meetingEndTime)
		{
			answer++;
			meetingEndTime = arr[i].second; 
		}
	}

	cout << answer;
	return 0;
}