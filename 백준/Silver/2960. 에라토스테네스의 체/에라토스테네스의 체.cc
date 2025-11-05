#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> arr(1001, true);
int n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	int cnt = 0;

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == false)
		{
			continue;
		}

		else if (arr[i] == true)
		{
			arr[i] = false;
			cnt++;

			if (cnt == k)
			{
				cout << i;
				return 0;
			}
		}

		for (int j = i*i; j <= n; j+=i)
		{
			if (arr[j] == true)
			{
				arr[j] = false;
				cnt++;
			}

			if (cnt == k)
			{
				cout << j;
				return 0;
			}
		}
	}

	return 0;
}