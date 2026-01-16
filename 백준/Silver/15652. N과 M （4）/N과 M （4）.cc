#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void DFS(int index, int startNum)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = startNum; i <= n; i++)
	{
		arr[index] = i;
		DFS(index + 1, i);

		//if (isUsed[i] == false)
		//{
		//	arr[index] = i;
		//	isUsed[i] = true;
		//	DFS(index + 1, i);
		//	isUsed[i] = false;
		//}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	DFS(0, 1);

	return 0;
}