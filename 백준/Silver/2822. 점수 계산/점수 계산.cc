#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int n = 8;
int sum = 0;
vector<pair<int, int>> arr;
vector<int> problemNum;

bool Compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second > b.second;
	else
		return a.first > b.first;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	int temp;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		arr.push_back(make_pair(temp, i));
	}

	sort(arr.begin(), arr.end(), Compare);

	for (int i = 0; i < 5; i++)
	{
		sum += arr[i].first;
		problemNum.push_back(arr[i].second + 1);
	}

	sort(problemNum.begin(), problemNum.end());

	cout << sum << endl; 
	for (int i = 0; i < problemNum.size(); i++)
	{
		cout << problemNum[i] << " ";
	}

	return 0;
}