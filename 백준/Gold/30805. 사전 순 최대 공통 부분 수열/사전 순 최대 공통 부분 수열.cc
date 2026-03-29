#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int a[100];
int b[100];
vector<int> answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	int i = 0;
	int j = 0;

	while (i < n && j < m)
	{
		int maxVal = -1;

		for (int x = i; x < n; x++)
		{
			for (int y = j; y < m; y++)
			{
				if (a[x] == b[y])
					maxVal = max(maxVal, a[x]);
			}
		}

		if (maxVal == -1) break;

		while (a[i] != maxVal) i++;
		while (b[j] != maxVal) j++;

		answer.push_back(maxVal);
		i++;
		j++;
	}

	cout << answer.size() << "\n";

	if (answer.size() != 0)
	{
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << " ";
		}
	}

	return 0;
}
