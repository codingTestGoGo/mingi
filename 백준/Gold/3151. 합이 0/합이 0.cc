#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int temp;
	long long answer = 0;

	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			long long index1 = lower_bound(arr.begin()+ j + 1, arr.end(), -(arr[i] + arr[j])) - arr.begin();
			long long index2 = upper_bound(arr.begin()+ j + 1, arr.end(), -(arr[i] + arr[j])) - arr.begin();

			answer += index2 - index1;
		}
	}

	cout << answer;
	return 0;
}