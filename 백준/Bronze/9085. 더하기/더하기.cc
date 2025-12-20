#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int t, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	int temp;
	for (int i = 0; i < t; i++)
	{
		int sum = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			sum += temp;
		}
		cout << sum << endl;
	}

	return 0;
}