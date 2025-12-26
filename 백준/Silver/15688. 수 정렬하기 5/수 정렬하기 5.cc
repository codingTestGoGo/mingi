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
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;
}