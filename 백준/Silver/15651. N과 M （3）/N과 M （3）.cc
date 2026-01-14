#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int arr[8];

void DFS(int index)
{
	bool isUsed[8] = { 0, };
	
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (isUsed[i] == false)
		{
			arr[index] = i;
			isUsed[i] = true;
			DFS(index + 1);
			isUsed[i] = false;
		}
	}
	return; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	DFS(0);
	return 0;
}