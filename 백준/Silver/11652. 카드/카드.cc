#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n; 
unordered_map<long long, int> map;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		long long temp;
		cin >> temp;

		if (map.count(temp) == 0)
		{
			map.insert(make_pair( temp, 1));
		}
		else
		{
			map[temp]++;
		}
	}

	int maxCnt = 0; 
	long long answer = 1000000000000000;

	for (const auto& value : map)
	{
		maxCnt = max(value.second, maxCnt);
	}

	for (const auto& value : map)
	{
		if (value.second == maxCnt)
		{
			answer = min( answer, value.first);
		}
	}

	cout << answer; 

	return 0;
}