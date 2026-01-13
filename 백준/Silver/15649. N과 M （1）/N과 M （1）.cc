#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
bool visitCheck[9];
int arr[9];

void DFS(int num)
{
	if (num == m)
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
		if (visitCheck[i] == false)
		{
			visitCheck[i] = true;
			arr[num] = i;
			DFS(num + 1);
			visitCheck[i] = false;
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