#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
bool isUsed[10001];
int arr[10];
vector<int> numbers;

void DFS(int index)
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

	for (int i = 0; i < n; i++)
	{
		if (isUsed[numbers[i]] == false)
		{
			//isUsed[numbers[i]] = true;
			arr[index] = numbers[i];
			DFS(index + 1);
			//isUsed[numbers[i]] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}
	sort(numbers.begin(), numbers.end());
	DFS(0);

	return 0;
}