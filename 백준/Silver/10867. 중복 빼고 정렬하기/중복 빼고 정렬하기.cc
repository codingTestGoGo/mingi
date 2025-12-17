#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	int nTempInt;

	for (int i = 0; i < n; i++)
	{
		cin >> nTempInt;
		arr.push_back(nTempInt);
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}