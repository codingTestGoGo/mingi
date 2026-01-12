#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void BackTracking(int k, int startIndex)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n"; 
		return;
	}

	for (int i = startIndex; i <= n; i++)
	{
		if (isUsed[i] == false)
		{
			arr[k] = i;
			isUsed[i] = true;
			BackTracking(k + 1, i + 1);
			isUsed[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	cin >> n >> m;
	BackTracking(0, 1);
}