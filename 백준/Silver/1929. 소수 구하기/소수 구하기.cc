#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int m, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	vector<bool> primeState(n + 1, true);
	primeState[0] = false;
	primeState[1] = false;

	for (int i = 2; i < n + 1; i++)
	{
		if (primeState[i] == true)
		{
			for (int j = i * 2; j < n + 1; j += i)
			{
				primeState[j] = false;
			}
		}
	}

	for (int i = m; i < n + 1; i++)
	{
		if (primeState[i] == true)
		{
			cout << i << endl;
		}
	}
	
	return 0;
}