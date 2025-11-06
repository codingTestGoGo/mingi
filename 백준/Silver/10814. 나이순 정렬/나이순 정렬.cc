#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

bool Compare(const pair<int, string>& a, const pair<int, string> &b )
{
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tempN;
	string tempStr;

	cin >> n;

	vector<pair<int, string>> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> tempN >> tempStr;

		arr[i].first = tempN;
		arr[i].second = tempStr;
	}

	stable_sort(arr.begin(), arr.end(), Compare);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i].first << " " << arr[i].second << endl;
	}

	return 0;
}
