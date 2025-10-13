#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int result = 2000000000;
vector<int> arr;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int temp;
	int a, b, st, en;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());
	
	st = 0;
	en = n - 1;
	while (st < en)
	{
		if (abs(arr[st] + arr[en]) < result)
		{
			a = st;
			b = en;
			result = abs(arr[st] + arr[en]);
		}

		if (arr[st] + arr[en] <= 0)
			st += 1;
		else
			en -= 1;
	}

	cout << arr[a] << " " << arr[b];

	return 0;

}


