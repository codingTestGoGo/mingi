#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> arr;

void Solve()
{
	int len = arr.size();
	int st = 0;
	int en = len - 1;
	int answer = 200000000;
	int sum;

	while (st < en)
	{
		sum = arr[st] + arr[en];

		if (abs(answer) >= abs(arr[st] + arr[en]))
		{
			answer = arr[st] + arr[en];
		}

		if (sum == 0)
		{
			break;
		} 

		if (sum > 0)
		{
			en = en - 1;
		}

		else if (sum < 0)
		{
			st = st + 1;
		}
	}
	
	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int temp;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	Solve();

	return 0;
}